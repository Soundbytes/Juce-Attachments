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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RadioGroupAudioProcessorEditor::RadioGroupAudioProcessorEditor (RadioGroupAudioProcessor& proc)
    : AudioProcessorEditor (&proc), proc(proc), params(proc.getParams())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (lfSelect = new SbRadioGroup (72));
    lfSelect->setName ("lfSelect");

    addAndMakeVisible (colorRect = new ColorRect (params));
    colorRect->setName ("colorRect");


    //[UserPreSize]
	attLfSelect = new SbRadioGroupAttachment(params, "color", *lfSelect);
    //[/UserPreSize]

    setSize (160, 88);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RadioGroupAudioProcessorEditor::~RadioGroupAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    lfSelect = nullptr;
    colorRect = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RadioGroupAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RadioGroupAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    lfSelect->setBounds (8, 8, 72, 72);
    colorRect->setBounds (80, 8, 72, 72);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RadioGroupAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="RadioGroupAudioProcessor&amp; proc" variableInitialisers="AudioProcessorEditor (&amp;proc), proc(proc), params(proc.getParams())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="160" initialHeight="88">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="lfSelect" id="e4b8d783bce73fe2" memberName="lfSelect" virtualName=""
                    explicitFocusOrder="0" pos="8 8 72 72" class="SbRadioGroup" params="72"/>
  <GENERICCOMPONENT name="colorRect" id="35cad3974ebd3408" memberName="colorRect"
                    virtualName="" explicitFocusOrder="0" pos="80 8 72 72" class="ColorRect"
                    params="params"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
