/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SbSlider.h"


//==============================================================================
SliderMonitorAudioProcessorEditor::SliderMonitorAudioProcessorEditor (SliderMonitorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), params(p.getParams())
{
	addAndMakeVisible(sldMon = new SbSliderMonitor("sldMon", p.getParams()));

	addAndMakeVisible(slider0 = new SbSlider("slider0"));
	slider0->setRange(0, 10, 0);
	slider0->setSliderStyle(Slider::Rotary);
	slider0->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	slider0->setColour(Slider::textBoxBackgroundColourId, Colour(0x60263238));
	slider0->addListener(sldMon);

	att0Percent = new SbSliderAttachment(params, "percent", *slider0);

	addAndMakeVisible(slider1 = new SbSlider("slider1"));
	slider1->setRange(0, 10, 0);
	slider1->setSliderStyle(Slider::Rotary);
	slider1->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	slider1->setColour(Slider::textBoxBackgroundColourId, Colour(0x60263238));
	slider1->addListener(sldMon);

	att1Db = new SbSliderAttachment(params, "db", *slider1);


	addAndMakeVisible(slider2 = new SbSlider("slider2"));
	slider2->setRange(0, 10, 0);
	slider2->setSliderStyle(Slider::Rotary);
	slider2->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	slider2->setColour(Slider::textBoxBackgroundColourId, Colour(0x60263238));
	slider2->addListener(sldMon);

	att2Freq = new SbSliderAttachment(params, "freq", *slider2);

	setSize(274, 168);
}

SliderMonitorAudioProcessorEditor::~SliderMonitorAudioProcessorEditor()
{
	att0Percent = nullptr;
	att1Db = nullptr;
	att2Freq = nullptr;

	sldMon = nullptr;

	slider0 = nullptr;
	slider1 = nullptr;
	slider2 = nullptr;
}

//==============================================================================
void SliderMonitorAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll(Colour(0xff693d3d));
}

void SliderMonitorAudioProcessorEditor::resized()
{
	slider0->setBounds(8, 16, 80, 96);
	slider1->setBounds(96, 16, 80, 96);
	slider2->setBounds(184, 16, 80, 96);
	sldMon->setBounds(8, 128, 258, 24);
}
