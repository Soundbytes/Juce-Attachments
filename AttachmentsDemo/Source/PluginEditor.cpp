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
AttachmentsDemoAudioProcessorEditor::AttachmentsDemoAudioProcessorEditor (AttachmentsDemoAudioProcessor& p)
    : AudioProcessorEditor (&p), p (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (cmbFruits = new ComboBox ("cmbFruits"));
    cmbFruits->setTooltip (TRANS("This Combobox has an editor. Enter a number!"));
    cmbFruits->setEditableText (true);
    cmbFruits->setJustificationType (Justification::centredLeft);
    cmbFruits->setTextWhenNothingSelected (TRANS("papagena"));
    cmbFruits->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    cmbFruits->addListener (this);

    addAndMakeVisible (lblFruits = new Label ("lblFruits",
                                              TRANS("Fruits")));
    lblFruits->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblFruits->setJustificationType (Justification::centredLeft);
    lblFruits->setEditable (false, false, false);
    lblFruits->setColour (TextEditor::textColourId, Colours::black);
    lblFruits->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lblMidiCc = new Label ("lblMidiCc",
                                              TRANS("Midi CC")));
    lblMidiCc->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblMidiCc->setJustificationType (Justification::centredLeft);
    lblMidiCc->setEditable (false, false, false);
    lblMidiCc->setColour (TextEditor::textColourId, Colours::black);
    lblMidiCc->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lblEditMidiCc = new Label ("lblEditMidiCc",
                                                  TRANS("---")));
    lblEditMidiCc->setTooltip (TRANS("to select a new midi cc enter its number."));
    lblEditMidiCc->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblEditMidiCc->setJustificationType (Justification::centredLeft);
    lblEditMidiCc->setEditable (true, true, false);
    lblEditMidiCc->setColour (TextEditor::textColourId, Colours::black);
    lblEditMidiCc->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    lblEditMidiCc->addListener (this);

    addAndMakeVisible (cmbWindowSize = new ComboBox ("cmbWindowSize"));
    cmbWindowSize->setEditableText (false);
    cmbWindowSize->setJustificationType (Justification::centredLeft);
    cmbWindowSize->setTextWhenNothingSelected (String());
    cmbWindowSize->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    cmbWindowSize->addListener (this);

    addAndMakeVisible (lblWindowSize = new Label ("lblWindowSize",
                                                  TRANS("FFT wnd size")));
    lblWindowSize->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblWindowSize->setJustificationType (Justification::centredLeft);
    lblWindowSize->setEditable (false, false, false);
    lblWindowSize->setColour (TextEditor::textColourId, Colours::black);
    lblWindowSize->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lblTitle = new Label ("lblTitle",
                                             TRANS("Attachments Demo")));
    lblTitle->setFont (Font (18.00f, Font::plain).withTypefaceStyle ("Bold"));
    lblTitle->setJustificationType (Justification::centredLeft);
    lblTitle->setEditable (false, false, false);
    lblTitle->setColour (TextEditor::textColourId, Colours::black);
    lblTitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	AttCmbFruits =		new ComboBoxAttachment(p.getParams(), "fruits", *cmbFruits, true);
	AttCmbWindowSize =	new ComboBoxAttachment(p.getParams(), "fftWindowSize", *cmbWindowSize, true);
	AttLblMidiCc =		new LabelAttachment(p.getParams(), "ccSelect", *lblEditMidiCc);
    //[/UserPreSize]

    setSize (280, 170);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AttachmentsDemoAudioProcessorEditor::~AttachmentsDemoAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	AttCmbFruits =		nullptr;
	AttCmbWindowSize =	nullptr;
	AttLblMidiCc =		nullptr;
    //[/Destructor_pre]

    cmbFruits = nullptr;
    lblFruits = nullptr;
    lblMidiCc = nullptr;
    lblEditMidiCc = nullptr;
    cmbWindowSize = nullptr;
    lblWindowSize = nullptr;
    lblTitle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AttachmentsDemoAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AttachmentsDemoAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    cmbFruits->setBounds (114, 50, 150, 24);
    lblFruits->setBounds (16, 50, 89, 24);
    lblMidiCc->setBounds (16, 130, 89, 24);
    lblEditMidiCc->setBounds (114, 130, 150, 24);
    cmbWindowSize->setBounds (114, 90, 150, 24);
    lblWindowSize->setBounds (16, 90, 89, 24);
    lblTitle->setBounds (15, 16, 256, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AttachmentsDemoAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == cmbFruits)
    {
        //[UserComboBoxCode_cmbFruits] -- add your combo box handling code here..
        //[/UserComboBoxCode_cmbFruits]
    }
    else if (comboBoxThatHasChanged == cmbWindowSize)
    {
        //[UserComboBoxCode_cmbWindowSize] -- add your combo box handling code here..
        //[/UserComboBoxCode_cmbWindowSize]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void AttachmentsDemoAudioProcessorEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == lblEditMidiCc)
    {
        //[UserLabelCode_lblEditMidiCc] -- add your label text handling code here..
        //[/UserLabelCode_lblEditMidiCc]
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

<JUCER_COMPONENT documentType="Component" className="AttachmentsDemoAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="AttachmentsDemoAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), p (p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="280" initialHeight="170">
  <BACKGROUND backgroundColour="ff323e44"/>
  <COMBOBOX name="cmbFruits" id="e36e2000d59f9c17" memberName="cmbFruits"
            virtualName="" explicitFocusOrder="0" pos="114 50 150 24" tooltip="This Combobox has an editor. Enter a number!"
            editable="1" layout="33" items="" textWhenNonSelected="papagena"
            textWhenNoItems="(no choices)"/>
  <LABEL name="lblFruits" id="d9e15aa8427a9299" memberName="lblFruits"
         virtualName="" explicitFocusOrder="0" pos="16 50 89 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Fruits" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="lblMidiCc" id="1fa600c27ef66236" memberName="lblMidiCc"
         virtualName="" explicitFocusOrder="0" pos="16 130 89 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi CC" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="lblEditMidiCc" id="cffb9a92cf235b78" memberName="lblEditMidiCc"
         virtualName="" explicitFocusOrder="0" pos="114 130 150 24" tooltip="to select a new midi cc enter its number."
         edTextCol="ff000000" edBkgCol="0" labelText="---" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="cmbWindowSize" id="83c7500cafcc19ca" memberName="cmbWindowSize"
            virtualName="" explicitFocusOrder="0" pos="114 90 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="lblWindowSize" id="2fe0285d8f78a6db" memberName="lblWindowSize"
         virtualName="" explicitFocusOrder="0" pos="16 90 89 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FFT wnd size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="lblTitle" id="806227292663be0d" memberName="lblTitle" virtualName=""
         explicitFocusOrder="0" pos="15 16 256 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attachments Demo" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="18" kerning="0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
