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

class SbSliderMonitor : public Component,
                        	public SliderListener
{
public:
	SbSliderMonitor(String name, AudioProcessorValueTreeState& params);
	~SbSliderMonitor();

	void paint(Graphics& g) override;
	void resized() override;
private:

	void sliderValueChanged(Slider* sliderThatWasMoved) override {};
	void sliderDragStarted(Slider* sld) override;

	String paramID;

	//==============================================================================
	ScopedPointer<Label> lblState;
	ScopedPointer<Label> lblMonitor;

	ScopedPointer<AudioProcessorValueTreeState::LabelAttachment> attMonitor;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SbSliderMonitor)
};





