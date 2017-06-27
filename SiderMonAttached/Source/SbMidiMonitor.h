/*
  ==============================================================================

    SbMidiMonitor.h
    Created: 17 May 2017 4:04:02pm
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#pragma once
#include<atomic>
#include "../JuceLibraryCode/JuceHeader.h"
#include "SbSlider.h"

class SbMidiMonitorListener;

class FlashingButton : public ShapeButton,
					   private Timer
{
public:
	explicit FlashingButton(const String& buttonName)
		: ShapeButton(buttonName, colNormal, colOver, colDown), isFlashing(false)
	{
		static const float r1 = 120, r2 = 82, r3 = 24,	r4 = 35;
		static const float ang = 0.1 * float_Pi;
		static const float dlt1 = r1 - r2 - r3,
			dlt2 = r1 - r3,
			dlt3 = r1 + r2 - r3;
		static const float
			dlt5 = r1 - r2 * 0.707107f - r3,
			dlt6 = r1 + r2 * 0.707107f - r3;

		Path shape;
		shape.startNewSubPath(r1 + r3, r1 + r1 - r4);
		shape.lineTo(r1 - r3, r1 + r1 - r4);
		shape.addArc(0, 0, 2 * r1, 2 * r1, float_Pi + ang, 3 * float_Pi - ang);
		shape.closeSubPath();

		shape.addArc(dlt1, dlt2, 2 * r3, 2 * r3, 2 * float_Pi, 0, true);
		shape.addArc(dlt2, dlt1, 2 * r3, 2 * r3, 2 * float_Pi, 0, true);
		shape.addArc(dlt3, dlt2, 2 * r3, 2 * r3, 2 * float_Pi, 0, true);

		shape.addArc(dlt5, dlt5, 2 * r3, 2 * r3, 2 * float_Pi, 0, true);
		shape.addArc(dlt6, dlt5, 2 * r3, 2 * r3, 2 * float_Pi, 0, true);

		this->setShape(shape, true, true, true);

		setClickingTogglesState(true);

		setColours(colNormal, colOver, colDown);
	}

	void flash() {
		isFlashing = true;
		setColours(colFlash, colFlash, colFlash);
		repaint();
	}

	void paint(Graphics& g) override {
		if (isFlashing) {
			isFlashing = false;
			startTimer(100);
		}
		ShapeButton::paint(g);
	}

	// timer callback resets button highlight
	void timerCallback() override {
		stopTimer();
		setColours(colNormal, colOver, colDown);
		repaint();
	}

	//Todo - define these colors outside the button class (custom lookAndFeel?)
	const Colour colNormal{Colours::blue.brighter(0.3f)};
	const Colour colFlash{Colours::yellow};
	const Colour colOver{Colours::blue.brighter(0.5f)};
	const Colour colDown{Colours::blue.brighter(0.2f)};

	bool isFlashing;
};


class SbMidiMonitorState : public ActionBroadcaster // the state object lives in the audio processor
{
public:
	void processNextMidiBuffer(MidiBuffer& buffer,
		const int startSample,
		const int numSamples);

private:
	Array <SbMidiMonitorListener*> listeners;
	char chBuf[64];
};


class SbMidiSliderMonitor : public Component,
							public ActionListener,
							public ButtonListener,
                        	public SliderListener
{
public:
	SbMidiSliderMonitor(String name, SbMidiMonitorState* monState, AudioProcessorValueTreeState& params);
	~SbMidiSliderMonitor();

	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* buttonThatWasClicked) override;

private:

	void setMode(bool midiMonState) {
		lblMonitor->setText(String(), NotificationType::dontSendNotification);
		if (midiMonState) {
			attMonitor->removeListener();
			lblState->setText("MidiMonitor", NotificationType::dontSendNotification);
			pProcMidiMsg = &SbMidiSliderMonitor::procMidiMsgOn;
			pSliderDragStarted = &SbMidiSliderMonitor::sliderDragStartedOff;
			lblMonitor->setEditable(false);
		}
		else {
			lblState->setText("SliderStatus", NotificationType::dontSendNotification);
			pProcMidiMsg = &SbMidiSliderMonitor::procMidiMsgOff;
			pSliderDragStarted = &SbMidiSliderMonitor::sliderDragStartedOn;
		}
	}

	void processMidiMessage(const String& message) { (this->*pProcMidiMsg)(message); }
	void (SbMidiSliderMonitor::* pProcMidiMsg) (const String& message);
	// show midi message 
	void procMidiMsgOn(const String& message);
	// animate button only
	void procMidiMsgOff(const String& message);

	void sliderValueChanged(Slider* sliderThatWasMoved) override {};

	void sliderDragStarted(Slider* sld) override { (this->*pSliderDragStarted)(sld); }
	void  (SbMidiSliderMonitor::* pSliderDragStarted)(Slider* sld);
	//prepare to show Slider action in status bar
	void sliderDragStartedOn(Slider* sld);
	//do nothing
	void sliderDragStartedOff(Slider* sld);


	// react on incoming midi message
	void actionListenerCallback(const String& message) override {
		processMidiMessage(message);
	}

	// Midi Button Colors 
	//Todo - move into button class, make static
	SbMidiMonitorState* monState;

	String paramID;

	//==============================================================================
	ScopedPointer<Label> lblState;
	ScopedPointer<FlashingButton> btnPulse;
	ScopedPointer<Label> lblMonitor;

	ScopedPointer<AudioProcessorValueTreeState::LabelAttachment> attMonitor;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbMidiSliderMonitor)
};





