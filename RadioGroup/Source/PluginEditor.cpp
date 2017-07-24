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

    addAndMakeVisible (rgRow = new SbRadioGroup<TextButton> (48, 24, true));
    rgRow->setName ("rgRow");

    addAndMakeVisible (rgCol = new SbRadioGroup<ToggleButton> (72, 24, false));
    rgCol->setName ("rgCol");

    addAndMakeVisible (colorRect = new ColorRect (params));
    colorRect->setName ("colorRect");


    //[UserPreSize]
	attRgRow = new SbRadioGroupAttachment<TextButton>(params, "color", *rgRow);
	attRgCol = new SbRadioGroupAttachment<ToggleButton>(params, "color", *rgCol);
    //[/UserPreSize]

    setSize (160, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RadioGroupAudioProcessorEditor::~RadioGroupAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rgRow = nullptr;
    rgCol = nullptr;
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

    rgRow->setBounds (8, 8, 144, 24);
    rgCol->setBounds (8, 40, 72, 72);
    colorRect->setBounds (80, 40, 72, 72);
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
                 fixedSize="0" initialWidth="160" initialHeight="120">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="rgRow" id="6c19c5bbb85b34f2" memberName="rgRow" virtualName=""
                    explicitFocusOrder="0" pos="8 8 144 24" class="SbRadioGroup&lt;TextButton&gt;"
                    params="48, 24, true"/>
  <GENERICCOMPONENT name="rgCol" id="e4b8d783bce73fe2" memberName="rgCol" virtualName=""
                    explicitFocusOrder="0" pos="8 40 72 72" class="SbRadioGroup&lt;ToggleButton&gt;"
                    params="72, 24, false"/>
  <GENERICCOMPONENT name="colorRect" id="35cad3974ebd3408" memberName="colorRect"
                    virtualName="" explicitFocusOrder="0" pos="80 40 72 72" class="ColorRect"
                    params="params"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
