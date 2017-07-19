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
#include "SbRadioGroup.h"


class ColorRect : public Component, public AudioProcessorValueTreeState::Listener
{
public:
	ColorRect(AudioProcessorValueTreeState& params) {
		params.addParameterListener("color", this);
		if (float* val = params.getRawParameterValue("color"))
			setColor(*val);
	}

	void parameterChanged(const String& parameterID, float newValue) override {
		setColor(newValue);
	}

	void paint(Graphics& g) override {
		g.fillAll(bg);
	}
private:
	void setColor(float val) {
		if (val < 0.5) bg = Colours::red;
		else if (val < 1.5) bg = Colours::green;
		else bg = Colours::blue;
		repaint();
	}

	Colour bg;
};
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RadioGroupAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    //==============================================================================
    RadioGroupAudioProcessorEditor (RadioGroupAudioProcessor& proc);
    ~RadioGroupAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	RadioGroupAudioProcessor& proc;
	RadioGroupParameters & params;

	ScopedPointer<SbRadioGroupAttachment>attLfSelect;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<SbRadioGroup> lfSelect;
    ScopedPointer<ColorRect> colorRect;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RadioGroupAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
