/*
  ==============================================================================

    SbMidiMonitor.cpp
    Created: 17 May 2017 4:04:02pm
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "SbSliderMonitor.h"
#include <cstring>


//==============================================================================
SbSliderMonitor::SbSliderMonitor(String name, AudioProcessorValueTreeState& params)
	: paramID(String::empty)
{
	addAndMakeVisible(lblState = new Label("lblState",
		TRANS("Slider Monitor")));
	lblState->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblState->setJustificationType(Justification::centredLeft);
	lblState->setEditable(false, false, false);
	lblState->setColour(TextEditor::textColourId, Colours::black);
	lblState->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	addAndMakeVisible(lblMonitor = new Label("lblMonitor",
		TRANS("www.soundbytes.de")));
	lblMonitor->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblMonitor->setJustificationType(Justification::centredLeft);
	lblMonitor->setEditable(false, false, false);
	lblMonitor->setColour(TextEditor::textColourId, Colours::black);
	lblMonitor->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	attMonitor = new AudioProcessorValueTreeState::LabelAttachment(params, "", *lblMonitor);

	setName(name);
	setSize(258, 24);
}



SbSliderMonitor::~SbSliderMonitor()
{
	attMonitor = nullptr;

	lblState = nullptr;
	lblMonitor = nullptr;
}

//==============================================================================
void SbSliderMonitor::paint(Graphics& g)
{
	g.fillAll(Colour(0xff2d0b0b));
}

void SbSliderMonitor::resized()
{
	lblState->setBounds(0, 0, 76, 24);
	lblMonitor->setBounds(100, 0, 158, 24);
}

void SbSliderMonitor::sliderDragStarted(Slider* slider) {
	if (SbSlider* sl = dynamic_cast<SbSlider*>(slider)) {
		paramID = sl->getAttachedParamId();
		attMonitor->replaceListener(paramID);
	}
	lblState->setText(slider->getName(), NotificationType::dontSendNotification);
	lblMonitor->setEditable(true);
}

