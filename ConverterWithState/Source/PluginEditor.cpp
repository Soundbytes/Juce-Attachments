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

    addAndMakeVisible (tglNumbers = new ToggleButton ("numbers"));
    tglNumbers->setRadioGroupId (11);
    tglNumbers->addListener (this);
    tglNumbers->setToggleState (true, dontSendNotification);

    addAndMakeVisible (tglLetters = new ToggleButton ("letters"));
    tglLetters->setRadioGroupId (11);
    tglLetters->addListener (this);

    addAndMakeVisible (lblValue = new Label ("value",
                                             TRANS("value")));
    lblValue->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblValue->setJustificationType (Justification::centredLeft);
    lblValue->setEditable (true, true, false);
    lblValue->setColour (TextEditor::textColourId, Colours::black);
    lblValue->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    lblValue->addListener (this);


    //[UserPreSize]
	attLblPitch = new LabelAttachment(params, "value", *lblValue);
    //[/UserPreSize]

    setSize (128, 128);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ConverterWithStateAudioProcessorEditor::~ConverterWithStateAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	attLblPitch = nullptr;
    //[/Destructor_pre]

    tglNumbers = nullptr;
    tglLetters = nullptr;
    lblValue = nullptr;


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

    tglNumbers->setBounds (16, 16, 96, 24);
    tglLetters->setBounds (16, 40, 96, 24);
    lblValue->setBounds (16, 88, 96, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ConverterWithStateAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	if (buttonThatWasClicked->getToggleState() == false) return;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == tglNumbers)
    {
        //[UserButtonCode_tglNumbers] -- add your button handler code here..
		params.textConverter.setState("numbers");
        //[/UserButtonCode_tglNumbers]
    }
    else if (buttonThatWasClicked == tglLetters)
    {
        //[UserButtonCode_tglLetters] -- add your button handler code here..
		params.textConverter.setState("letters");
        //[/UserButtonCode_tglLetters]
    }

    //[UserbuttonClicked_Post]
	attLblPitch->sendInitialUpdate();
    //[/UserbuttonClicked_Post]
}

void ConverterWithStateAudioProcessorEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == lblValue)
    {
        //[UserLabelCode_lblValue] -- add your label text handling code here..
        //[/UserLabelCode_lblValue]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
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
                 fixedSize="0" initialWidth="128" initialHeight="128">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TOGGLEBUTTON name="numbers" id="bcf4ee54fb05521" memberName="tglNumbers" virtualName=""
                explicitFocusOrder="0" pos="16 16 96 24" buttonText="numbers"
                connectedEdges="0" needsCallback="1" radioGroupId="11" state="1"/>
  <TOGGLEBUTTON name="letters" id="2f9b3e64e90a0a65" memberName="tglLetters"
                virtualName="" explicitFocusOrder="0" pos="16 40 96 24" buttonText="letters"
                connectedEdges="0" needsCallback="1" radioGroupId="11" state="0"/>
  <LABEL name="value" id="b62505c47b1d28fd" memberName="lblValue" virtualName=""
         explicitFocusOrder="0" pos="16 88 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="value" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
