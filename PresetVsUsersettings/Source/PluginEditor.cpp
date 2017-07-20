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
PresetVsUsersettingsAudioProcessorEditor::PresetVsUsersettingsAudioProcessorEditor (PresetVsUsersettingsAudioProcessor& proc)
    : AudioProcessorEditor (&proc), proc(proc), params(proc.getParams())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sldPreset1 = new Slider ("preset 1"));
    sldPreset1->setRange (0, 10, 0);
    sldPreset1->setSliderStyle (Slider::LinearHorizontal);
    sldPreset1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblPreset1 = new Label ("preset 1",
                                               TRANS("preset 1")));
    lblPreset1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblPreset1->setJustificationType (Justification::centredLeft);
    lblPreset1->setEditable (false, false, false);
    lblPreset1->setColour (TextEditor::textColourId, Colours::black);
    lblPreset1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sldPreset2 = new Slider ("preset 1"));
    sldPreset2->setRange (0, 10, 0);
    sldPreset2->setSliderStyle (Slider::LinearHorizontal);
    sldPreset2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblPreset2 = new Label ("preset 2",
                                               TRANS("preset 2")));
    lblPreset2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblPreset2->setJustificationType (Justification::centredLeft);
    lblPreset2->setEditable (false, false, false);
    lblPreset2->setColour (TextEditor::textColourId, Colours::black);
    lblPreset2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sldPreset3 = new Slider ("preset 1"));
    sldPreset3->setRange (0, 10, 0);
    sldPreset3->setSliderStyle (Slider::LinearHorizontal);
    sldPreset3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblPreset3 = new Label ("preset 3",
                                               TRANS("preset 3")));
    lblPreset3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblPreset3->setJustificationType (Justification::centredLeft);
    lblPreset3->setEditable (false, false, false);
    lblPreset3->setColour (TextEditor::textColourId, Colours::black);
    lblPreset3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sldSettings1 = new Slider ("settings 1"));
    sldSettings1->setRange (0, 10, 0);
    sldSettings1->setSliderStyle (Slider::LinearHorizontal);
    sldSettings1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblSettings1 = new Label ("settings 1",
                                                 TRANS("settings 1")));
    lblSettings1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblSettings1->setJustificationType (Justification::centredLeft);
    lblSettings1->setEditable (false, false, false);
    lblSettings1->setColour (TextEditor::textColourId, Colours::black);
    lblSettings1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sldSettings2 = new Slider ("settings 2"));
    sldSettings2->setRange (0, 10, 0);
    sldSettings2->setSliderStyle (Slider::LinearHorizontal);
    sldSettings2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblSettings2 = new Label ("settings 2",
                                                 TRANS("settings 2")));
    lblSettings2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblSettings2->setJustificationType (Justification::centredLeft);
    lblSettings2->setEditable (false, false, false);
    lblSettings2->setColour (TextEditor::textColourId, Colours::black);
    lblSettings2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sldSettings3 = new Slider ("settings 3"));
    sldSettings3->setRange (0, 10, 0);
    sldSettings3->setSliderStyle (Slider::LinearHorizontal);
    sldSettings3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    addAndMakeVisible (lblSettings3 = new Label ("settings 3",
                                                 TRANS("settings 3")));
    lblSettings3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblSettings3->setJustificationType (Justification::centredLeft);
    lblSettings3->setEditable (false, false, false);
    lblSettings3->setColour (TextEditor::textColourId, Colours::black);
    lblSettings3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (238, 160);


    //[Constructor] You can add your own custom stuff here..
	attSldPreset1   = new SliderAttachment(params, "preset 1", *sldPreset1);
	attSldPreset2 =   new SliderAttachment(params, "preset 2", *sldPreset2);
	attSldPreset3 =   new SliderAttachment(params, "preset 3", *sldPreset3);
	attSldSettings1 = new SliderAttachment(params, "settings 1", *sldSettings1);
	attSldSettings2 = new SliderAttachment(params, "settings 2", *sldSettings2);
	attSldSettings3 = new SliderAttachment(params, "settings 3", *sldSettings3);
    //[/Constructor]
}

PresetVsUsersettingsAudioProcessorEditor::~PresetVsUsersettingsAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	attSldPreset1 = nullptr;
	attSldPreset2 = nullptr;
	attSldPreset3 = nullptr;
	attSldSettings1 = nullptr;
	attSldSettings2 = nullptr;
	attSldSettings3 = nullptr;
    //[/Destructor_pre]

    sldPreset1 = nullptr;
    lblPreset1 = nullptr;
    sldPreset2 = nullptr;
    lblPreset2 = nullptr;
    sldPreset3 = nullptr;
    lblPreset3 = nullptr;
    sldSettings1 = nullptr;
    lblSettings1 = nullptr;
    sldSettings2 = nullptr;
    lblSettings2 = nullptr;
    sldSettings3 = nullptr;
    lblSettings3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PresetVsUsersettingsAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PresetVsUsersettingsAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sldPreset1->setBounds (80, 0, 150, 24);
    lblPreset1->setBounds (0, 0, 63, 24);
    sldPreset2->setBounds (80, 24, 150, 24);
    lblPreset2->setBounds (0, 24, 63, 24);
    sldPreset3->setBounds (80, 48, 150, 24);
    lblPreset3->setBounds (0, 48, 63, 24);
    sldSettings1->setBounds (80, 80, 150, 24);
    lblSettings1->setBounds (0, 80, 63, 24);
    sldSettings2->setBounds (80, 104, 150, 24);
    lblSettings2->setBounds (0, 104, 63, 24);
    sldSettings3->setBounds (80, 128, 150, 24);
    lblSettings3->setBounds (0, 128, 63, 24);
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

<JUCER_COMPONENT documentType="Component" className="PresetVsUsersettingsAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="PresetVsUsersettingsAudioProcessor&amp; proc"
                 variableInitialisers="AudioProcessorEditor (&amp;proc), proc(proc), params(proc.getParams())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="238" initialHeight="160">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="preset 1" id="ca1d4573a4a3fac" memberName="sldPreset1"
          virtualName="" explicitFocusOrder="0" pos="80 0 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="preset 1" id="9b6aa7a827ab690a" memberName="lblPreset1"
         virtualName="" explicitFocusOrder="0" pos="0 0 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="preset 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="preset 1" id="a9b9cc14ff7c77d8" memberName="sldPreset2"
          virtualName="" explicitFocusOrder="0" pos="80 24 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="preset 2" id="6dc8fba2cb3f19e4" memberName="lblPreset2"
         virtualName="" explicitFocusOrder="0" pos="0 24 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="preset 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="preset 1" id="276be237e26853af" memberName="sldPreset3"
          virtualName="" explicitFocusOrder="0" pos="80 48 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="preset 3" id="4bb54dd910d83cb" memberName="lblPreset3"
         virtualName="" explicitFocusOrder="0" pos="0 48 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="preset 3" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="settings 1" id="6eeb855f1477b605" memberName="sldSettings1"
          virtualName="" explicitFocusOrder="0" pos="80 80 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="settings 1" id="88e99eb7770a5ece" memberName="lblSettings1"
         virtualName="" explicitFocusOrder="0" pos="0 80 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="settings 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="settings 2" id="d3b071425e4f7d6f" memberName="sldSettings2"
          virtualName="" explicitFocusOrder="0" pos="80 104 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="settings 2" id="6c2d67966a3e6579" memberName="lblSettings2"
         virtualName="" explicitFocusOrder="0" pos="0 104 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="settings 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="settings 3" id="8fe1b186e7c99a89" memberName="sldSettings3"
          virtualName="" explicitFocusOrder="0" pos="80 128 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <LABEL name="settings 3" id="f4be63dc6e896475" memberName="lblSettings3"
         virtualName="" explicitFocusOrder="0" pos="0 128 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="settings 3" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
