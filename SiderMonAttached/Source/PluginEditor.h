/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "TabComponent.h"
#include "SbMidiMonitor.h"
#include "SliderMidiMonParameters.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::LabelAttachment LabelAttachment;


//==============================================================================
/**
*/
class SiderMidiMonCombinedAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SiderMidiMonCombinedAudioProcessorEditor (SiderMidiMonCombinedAudioProcessor&);
    ~SiderMidiMonCombinedAudioProcessorEditor();

    //==============================================================================

    void paint (Graphics&) override;
    void resized() override;

private:
	SliderMidiMonParameters& params;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SiderMidiMonCombinedAudioProcessor& processor;

	ScopedPointer<SbMidiSliderMonitor> midiSldMon;

	ScopedPointer<SbSlider> slider0;
	ScopedPointer<SbSlider> slider1;
	ScopedPointer<SbSlider> slider2;

	ScopedPointer<SbSliderAttachment> att0Percent;
	ScopedPointer<SbSliderAttachment> att1Db;
	ScopedPointer<SbSliderAttachment> att2Freq;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SiderMidiMonCombinedAudioProcessorEditor)
};
