/*
  ==============================================================================
  SbRadioGroup
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

static const int radioGroupId = 99; // there is only one group in the component. Other radiogroups can use the same ID as long as they live in a different component.

class SbRadioGroup : public Component, public ButtonListener
{
public:
	//==============================================================================
	SbRadioGroup(int width)
		: width(width), numButtons(0)
	{}
	virtual ~SbRadioGroup() {}
	void addButton(const String& name) {
		buttons.add(new ToggleButton(name));
		addAndMakeVisible(buttons[numButtons]);
		buttons[numButtons]->setRadioGroupId(radioGroupId);
		buttons[numButtons]->addListener(this);
		++numButtons;
	}

	void clear() {
		numButtons = 0;
		buttons.clear();
	}

	class Listener {
	public:
		virtual void radioGroupStateChanged(SbRadioGroup* s, int state) = 0;
	};

	void buttonClicked(Button* buttonThatWasClicked) override {
		if (buttonThatWasClicked->getToggleState()) {
			jassert(dynamic_cast<ToggleButton*>(buttonThatWasClicked));
			ToggleButton* tb = static_cast<ToggleButton*>(buttonThatWasClicked);
			state = buttons.indexOf(tb);
			listeners.call(&Listener::radioGroupStateChanged, this, state);
		}
	}

	void setState(int btnIdx, const NotificationType notification) {
		if (btnIdx >= 0)
		state = btnIdx >= 0 && btnIdx < numButtons ? btnIdx : defaultState;
		buttons[state]->setToggleState(true, dontSendNotification);
		if (notification != dontSendNotification)
			listeners.call(&Listener::radioGroupStateChanged, this, state);
	}

	void setState() {
		state = defaultState;
		buttons[state]->setToggleState(true, dontSendNotification);
	}
	int getState() {
		return state;
	}

	void paint(Graphics& g) override {}
	void resized() override {
		for (int idx = 0; idx < numButtons; ++idx) {
			buttons[idx]->setBounds(0, idx * 24, width, 24);
		}
	}


	void addListener(Listener* lst) { listeners.add(lst); }
	void removeListener(Listener* lst) { listeners.remove(lst); }
	void setDefaultState(float newDefaultState){ defaultState = newDefaultState; }
protected:
	int numButtons;
	OwnedArray<ToggleButton> buttons;
	ListenerList<Listener> listeners;
	int state, defaultState;
	int width;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbRadioGroup)
};



class JUCE_API  SbRadioGroupAttachment : private AttachedControlBase,
	private SbRadioGroup::Listener
{
public:
	SbRadioGroupAttachment(AudioProcessorValueTreeState& s, const String& p, SbRadioGroup& rg) 
		: AttachedControlBase(s, p), rg(rg),  ignoreCallbacks(false)
	{
		range = new NormalisableRange<float>(s.getParameterRange(p));
		if (range->interval == 0.f) return;
		rangScale = 1.f / range->interval;
		rg.clear();
		for (float btnVal = range->start; btnVal <= range->end; btnVal += range->interval) {
			rg.addButton(getParameter()->getText(range->convertTo0to1(btnVal), 64));
		}
		rg.setDefaultState(getBtnIdx(getParameter()->defaultValue));
		rg.resized();
		sendInitialUpdate();
		rg.addListener(this);
	}

	~SbRadioGroupAttachment() {
		removeListener();
	}

	void removeListener() {
		AttachedControlBase::removeListener();
		rg.removeListener(this);
	}

	void setValue(float newValue) override {
		const ScopedLock selfCallbackLock(selfCallbackMutex);
		{
			ScopedValueSetter<bool> svs(ignoreCallbacks, true);
			rg.setState(getBtnIdx(newValue), sendNotificationSync);
		}
	}
	void radioGroupStateChanged(SbRadioGroup* s, int newState) override {
		const ScopedLock selfCallbackLock(selfCallbackMutex);
		if ((!ignoreCallbacks) && (!ModifierKeys::getCurrentModifiers().isRightButtonDown()))
			setNewUnnormalisedValue(btnIdxToValue(newState));
	}
private:
	SbRadioGroup& rg;
	ScopedPointer<NormalisableRange<float>>range;
	float rangScale;
	int getBtnIdx(float btnVal) {
		return roundFloatToInt(rangScale * (btnVal - range->start));
	}
	float btnIdxToValue(int btnIdx) {
		return range->start + (float)btnIdx * range->interval;
	}

	bool ignoreCallbacks;
	CriticalSection selfCallbackMutex;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbRadioGroupAttachment)
};

