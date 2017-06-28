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
ConverterWithStateAudioProcessorEditor::ConverterWithStateAudioProcessorEditor (ConverterWithStateAudioProcessor& proc)
    : AudioProcessorEditor (&proc), proc(proc), params(proc.getParams())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tglNoteNumber = new ToggleButton ("noteNumber"));
    tglNoteNumber->setButtonText (TRANS("note number"));
    tglNoteNumber->setRadioGroupId (11);
    tglNoteNumber->addListener (this);
    tglNoteNumber->setToggleState (true, dontSendNotification);

    addAndMakeVisible (tglNoteName = new ToggleButton ("noteName"));
    tglNoteName->setButtonText (TRANS("note name"));
    tglNoteName->setRadioGroupId (11);
    tglNoteName->addListener (this);

    addAndMakeVisible (tglFrequency = new ToggleButton ("frequency"));
    tglFrequency->setRadioGroupId (11);
    tglFrequency->addListener (this);

    addAndMakeVisible (lblPitch = new Label ("pitch",
                                             TRANS("pitch")));
    lblPitch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblPitch->setJustificationType (Justification::centredLeft);
    lblPitch->setEditable (false, false, false);
    lblPitch->setColour (TextEditor::textColourId, Colours::black);
    lblPitch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	attLblPitch = new LabelAttachment(params, "pitch", *lblPitch);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ConverterWithStateAudioProcessorEditor::~ConverterWithStateAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	attLblPitch = nullptr;
    //[/Destructor_pre]

    tglNoteNumber = nullptr;
    tglNoteName = nullptr;
    tglFrequency = nullptr;
    lblPitch = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ConverterWithStateAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ConverterWithStateAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tglNoteNumber->setBounds (16, 16, 150, 24);
    tglNoteName->setBounds (16, 40, 150, 24);
    tglFrequency->setBounds (16, 64, 150, 24);
    lblPitch->setBounds (184, 64, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ConverterWithStateAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == tglNoteNumber)
    {
        //[UserButtonCode_tglNoteNumber] -- add your button handler code here..
        //[/UserButtonCode_tglNoteNumber]
    }
    else if (buttonThatWasClicked == tglNoteName)
    {
        //[UserButtonCode_tglNoteName] -- add your button handler code here..
        //[/UserButtonCode_tglNoteName]
    }
    else if (buttonThatWasClicked == tglFrequency)
    {
        //[UserButtonCode_tglFrequency] -- add your button handler code here..
        //[/UserButtonCode_tglFrequency]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ConverterWithStateAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="ConverterWithStateAudioProcessor&amp; proc"
                 variableInitialisers="AudioProcessorEditor (&amp;proc), proc(proc), params(proc.getParams())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TOGGLEBUTTON name="noteNumber" id="bcf4ee54fb05521" memberName="tglNoteNumber"
                virtualName="" explicitFocusOrder="0" pos="16 16 150 24" buttonText="note number"
                connectedEdges="0" needsCallback="1" radioGroupId="11" state="1"/>
  <TOGGLEBUTTON name="noteName" id="2f9b3e64e90a0a65" memberName="tglNoteName"
                virtualName="" explicitFocusOrder="0" pos="16 40 150 24" buttonText="note name"
                connectedEdges="0" needsCallback="1" radioGroupId="11" state="0"/>
  <TOGGLEBUTTON name="frequency" id="310c6fc3e67d1afe" memberName="tglFrequency"
                virtualName="" explicitFocusOrder="0" pos="16 64 150 24" buttonText="frequency"
                connectedEdges="0" needsCallback="1" radioGroupId="11" state="0"/>
  <LABEL name="pitch" id="b62505c47b1d28fd" memberName="lblPitch" virtualName=""
         explicitFocusOrder="0" pos="184 64 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
