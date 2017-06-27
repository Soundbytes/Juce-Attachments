/*
  ==============================================================================

    SbSlider.h
    Created: 26 Jun 2017 4:43:01pm
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SbSlider;

class SbSliderAttachment : private AttachedControlBase,
	private Slider::Listener
{
public:
	SbSliderAttachment(AudioProcessorValueTreeState& s, const String& p, SbSlider& sl);

	~SbSliderAttachment(){
		removeListener();
	}

	void removeListener() override;
	void replaceListener(String newParamID) override;
	void setValue(float newValue) override;
	void sliderValueChanged(Slider* s) override;

	void sliderDragStarted(Slider*) override { beginParameterChange(); }
	void sliderDragEnded(Slider*) override { endParameterChange(); }

private:
	SbSlider& slider;
	bool ignoreCallbacks;
	CriticalSection selfCallbackMutex;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbSliderAttachment)
};

class SbSlider : public Slider
{
public:
	SbSlider() {}
	explicit SbSlider(const String& componentName) : Slider (componentName) {}
	SbSlider(SliderStyle style, TextEntryBoxPosition textBoxPosition) : Slider(style, textBoxPosition) {}
	void setAttachedParamId(StringRef paramID) { this->paramID = paramID; }
	const String& getAttachedParamId(){ return paramID; }
private:
	String paramID;
};

inline SbSliderAttachment::SbSliderAttachment(AudioProcessorValueTreeState& s, const String& p, SbSlider& sl)
	: AttachedControlBase(s, p), slider(sl), ignoreCallbacks(false)
{
	NormalisableRange<float> range(s.getParameterRange(paramID));
	slider.setRange(range.start, range.end, range.interval);
	slider.setSkewFactor(range.skew, range.symmetricSkew);

	if (AudioProcessorParameter* param = state.getParameter(paramID))
		slider.setDoubleClickReturnValue(true, range.convertFrom0to1(param->getDefaultValue()));

	sendInitialUpdate();
	slider.addListener(this);
	slider.setAttachedParamId(paramID);
}

inline void SbSliderAttachment::removeListener() {
	AttachedControlBase::removeListener();
	slider.removeListener(this);
	slider.setAttachedParamId(paramID);
}

inline void SbSliderAttachment::replaceListener(String newParamID) {
	AttachedControlBase::replaceListener(newParamID);
	slider.setAttachedParamId(newParamID);
}

inline void SbSliderAttachment::setValue(float newValue) {
	const ScopedLock selfCallbackLock(selfCallbackMutex);
	{
		ScopedValueSetter<bool> svs(ignoreCallbacks, true);
		slider.setValue(newValue, sendNotificationSync);
	}
}

inline void SbSliderAttachment::sliderValueChanged(Slider* s){
	const ScopedLock selfCallbackLock(selfCallbackMutex);
	if ((!ignoreCallbacks) && (!ModifierKeys::getCurrentModifiers().isRightButtonDown()))
		setNewUnnormalisedValue((float)s->getValue());
}

class JUCE_API  SbLabelAttachment : public AttachedControlBase,
									private Label::Listener
{
public:
	SbLabelAttachment(AudioProcessorValueTreeState& s,
		const String& p,
		Label& lbl)
		: AttachedControlBase(s, p), label(lbl), ignoreCallbacks(false), s(s), paramID(p)
	{
		NormalisableRange<float> range(s.getParameterRange(paramID));
		sendInitialUpdate();
		label.addListener(this);
	}

	~SbLabelAttachment() {
		label.removeListener(this);
		removeListener();
	}


	void labelTextChanged(Label* lbl) override
	{
		if (lbl != &label) return;
		const ScopedLock selfCallbackLock(selfCallbackMutex);
		if (AudioProcessorParameter* p = getParameter()) {
			float newNormalizedValue = p->getValueForText(label.getText());
			if (p->getValue() != newNormalizedValue)
				p->setValueNotifyingHost(newNormalizedValue);
		}
	}

	/** Called when a Label goes into editing mode and displays a TextEditor. */
	void editorShown(Label*, TextEditor&)  override { beginParameterChange(); }

	/** Called when a Label is about to delete its TextEditor and exit editing mode. */
	void editorHidden(Label*, TextEditor&)override { endParameterChange(); }

	void setValue(float newValue) override	{
		const ScopedLock selfCallbackLock(selfCallbackMutex);
		{
			ScopedValueSetter<bool> svs(ignoreCallbacks, true);
			if (AudioProcessorValueTreeState::Parameter* p = getParameter())
				label.setText(p->getText(p->range.convertTo0to1(newValue), 64), sendNotificationSync);
		}
	}

private:
	friend struct ContainerDeletePolicy<SbLabelAttachment>;

	bool ignoreCallbacks;
	const String& paramID;
	Label& label;
	AudioProcessorValueTreeState& s;
	CriticalSection selfCallbackMutex;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbLabelAttachment)
};