/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SbSliderMonitor.h"
#include "SliderMonParameters.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::LabelAttachment LabelAttachment;


//==============================================================================
/**
*/
class SliderMonitorAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SliderMonitorAudioProcessorEditor (SliderMonitorAudioProcessor&);
    ~SliderMonitorAudioProcessorEditor();

    //==============================================================================

    void paint (Graphics&) override;
    void resized() override;

private:
	SliderMidiMonParameters& params;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SliderMonitorAudioProcessor& processor;

	ScopedPointer<SbSliderMonitor> sldMon;

	ScopedPointer<SbSlider> slider0;
	ScopedPointer<SbSlider> slider1;
	ScopedPointer<SbSlider> slider2;

	ScopedPointer<SbSliderAttachment> att0Percent;
	ScopedPointer<SbSliderAttachment> att1Db;
	ScopedPointer<SbSliderAttachment> att2Freq;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderMonitorAudioProcessorEditor)
};
