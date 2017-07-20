/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PresetVsUsersettingsAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    //==============================================================================
    PresetVsUsersettingsAudioProcessorEditor (PresetVsUsersettingsAudioProcessor& proc);
    ~PresetVsUsersettingsAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	PresetVsUsersettingsAudioProcessor& proc;
	PresetVsUsersettingsParameters & params;

	ScopedPointer<SliderAttachment> attSldPreset1;
	ScopedPointer<SliderAttachment> attSldPreset2;
	ScopedPointer<SliderAttachment> attSldPreset3;
	ScopedPointer<SliderAttachment> attSldSettings1;
	ScopedPointer<SliderAttachment> attSldSettings2;
	ScopedPointer<SliderAttachment> attSldSettings3;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> sldPreset1;
    ScopedPointer<Label> lblPreset1;
    ScopedPointer<Slider> sldPreset2;
    ScopedPointer<Label> lblPreset2;
    ScopedPointer<Slider> sldPreset3;
    ScopedPointer<Label> lblPreset3;
    ScopedPointer<Slider> sldSettings1;
    ScopedPointer<Label> lblSettings1;
    ScopedPointer<Slider> sldSettings2;
    ScopedPointer<Label> lblSettings2;
    ScopedPointer<Slider> sldSettings3;
    ScopedPointer<Label> lblSettings3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetVsUsersettingsAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
