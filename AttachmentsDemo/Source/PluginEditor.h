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


typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
typedef AudioProcessorValueTreeState::LabelAttachment LabelAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AttachmentsDemoAudioProcessorEditor  : public AudioProcessorEditor,
                                             public ComboBoxListener,
                                             public LabelListener
{
public:
    //==============================================================================
    AttachmentsDemoAudioProcessorEditor (AttachmentsDemoAudioProcessor& p);
    ~AttachmentsDemoAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void labelTextChanged (Label* labelThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AttachmentsDemoAudioProcessor& p;


	ScopedPointer<ComboBoxAttachment> AttCmbFruits;
	ScopedPointer<ComboBoxAttachment> AttCmbWindowSize;
	ScopedPointer<LabelAttachment> AttLblMidiCc;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> cmbFruits;
    ScopedPointer<Label> lblFruits;
    ScopedPointer<Label> lblMidiCc;
    ScopedPointer<Label> lblEditMidiCc;
    ScopedPointer<ComboBox> cmbWindowSize;
    ScopedPointer<Label> lblWindowSize;
    ScopedPointer<Label> lblTitle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AttachmentsDemoAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
