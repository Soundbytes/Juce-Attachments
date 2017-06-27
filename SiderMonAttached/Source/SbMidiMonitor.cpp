/*
  ==============================================================================

    SbMidiMonitor.cpp
    Created: 17 May 2017 4:04:02pm
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "SbMidiMonitor.h"
#include <cstring>




double mulexp10(const double value, int exponent) noexcept
{
	if (exponent == 0)
		return value;

	if (value == 0.0)
		return 0;

	const bool negative = (exponent < 0);
	if (negative)
		exponent = -exponent;

	double result = 1.0, power = 10.0;
	for (int bit = 1; exponent != 0; bit <<= 1)
	{
		if ((exponent & bit) != 0)
		{
			exponent ^= bit;
			result *= power;
			if (exponent == 0)
				break;
		}
		power *= power;
	}

	return negative ? (value / result) : (value * result);
}


//==============================================================================
/** Parses a character string to read a floating-point number.
Note that this will advance the pointer that is passed in, leaving it at
the end of the number.

modified on base of the readDoubleValue() function in juce_CharacterFunctions.h

differences: accepts ',' as decimal sign
optional parameter digitsFound: true if digits Found

*/

static bool dummyVal;
template <typename CharPointerType>
static double readDoubleValue(CharPointerType& text, bool& digitsFound = dummyVal) noexcept
{
	double result[3] = { 0 }, accumulator[2] = { 0 };
	int exponentAdjustment[2] = { 0 }, exponentAccumulator[2] = { -1, -1 };
	int exponent = 0, decPointIndex = 0, digit = 0;
	int lastDigit = 0, numSignificantDigits = 0;
	bool isNegative = false;
	const int maxSignificantDigits = 15 + 2;

	text = text.findEndOfWhitespace();
	juce_wchar c = *text;

	switch (c)
	{
	case '-':   isNegative = true; // fall-through..
	case '+':   c = *++text;
	}

	switch (c)
	{
	case 'n':
	case 'N':
		if ((text[1] == 'a' || text[1] == 'A') && (text[2] == 'n' || text[2] == 'N'))
			return std::numeric_limits<double>::quiet_NaN();
		break;

	case 'i':
	case 'I':
		if ((text[1] == 'n' || text[1] == 'N') && (text[2] == 'f' || text[2] == 'F'))
			return std::numeric_limits<double>::infinity();
		break;
	}

	for (;;)
	{
		if (text.isDigit())
		{
			lastDigit = digit;
			digit = (int)text.getAndAdvance() - '0';
			digitsFound = true;

			if (decPointIndex != 0)
				exponentAdjustment[1]++;

			if (numSignificantDigits == 0 && digit == 0)
				continue;

			if (++numSignificantDigits > maxSignificantDigits)
			{
				if (digit > 5)
					++accumulator[decPointIndex];
				else if (digit == 5 && (lastDigit & 1) != 0)
					++accumulator[decPointIndex];

				if (decPointIndex > 0)
					exponentAdjustment[1]--;
				else
					exponentAdjustment[0]++;

				while (text.isDigit())
				{
					++text;
					if (decPointIndex == 0)
						exponentAdjustment[0]++;
				}
			}
			else
			{
				const double maxAccumulatorValue = (double)((std::numeric_limits<unsigned int>::max() - 9) / 10);
				if (accumulator[decPointIndex] > maxAccumulatorValue)
				{
					result[decPointIndex] = mulexp10(result[decPointIndex], exponentAccumulator[decPointIndex])
						+ accumulator[decPointIndex];
					accumulator[decPointIndex] = 0;
					exponentAccumulator[decPointIndex] = 0;
				}

				accumulator[decPointIndex] = accumulator[decPointIndex] * 10 + digit;
				exponentAccumulator[decPointIndex]++;
			}
		}
		else if (decPointIndex == 0 && (*text == '.' || *text == ','))
		{
			++text;
			decPointIndex = 1;

			if (numSignificantDigits > maxSignificantDigits)
			{
				while (text.isDigit())
					++text;
				break;
			}
		}
		else
		{
			break;
		}
	}

	result[0] = mulexp10(result[0], exponentAccumulator[0]) + accumulator[0];

	if (decPointIndex != 0)
		result[1] = mulexp10(result[1], exponentAccumulator[1]) + accumulator[1];

	c = *text;
	if ((c == 'e' || c == 'E') && digitsFound)
	{
		bool negativeExponent = false;

		switch (*++text)
		{
		case '-':   negativeExponent = true; // fall-through..
		case '+':   ++text;
		}

		while (text.isDigit())
			exponent = (exponent * 10) + ((int)text.getAndAdvance() - '0');

		if (negativeExponent)
			exponent = -exponent;
	}

	double r = mulexp10(result[0], exponent + exponentAdjustment[0]);
	if (decPointIndex != 0)
		r += mulexp10(result[1], exponent - exponentAdjustment[1]);

	return isNegative ? -r : r;
}



void SbMidiMonitorState::processNextMidiBuffer(MidiBuffer& buffer,
	const int startSample,
	const int numSamples)

{
	if (buffer.isEmpty()) return;

	MidiBuffer::Iterator it(buffer);
	MidiMessage msg;
	int time;

	while (it.getNextEvent(msg, time)){} // get last midi message in this Block;
	bool isHandled = true;
	auto msgStatus = *msg.getRawData() & 0xF0;
	

	switch (msgStatus) {
	case 0x80: // Note off
		{ 
			int noteNum = msg.getNoteNumber();
			snprintf(chBuf, 48, "Note Off: %3s (%i) Vel: %3i",
				MidiMessage::getMidiNoteName(noteNum, true, true, 3).getCharPointer(),
				noteNum, msg.getVelocity());
		}
		break;
	case 0x90: // Note-on 
		{
			int noteNum = msg.getNoteNumber();
			snprintf(chBuf, 48, "Note On: %3s (%i) Vel: %3i",
				MidiMessage::getMidiNoteName(noteNum, true, true, 3).getCharPointer(),
				noteNum, msg.getVelocity());
		}
		break;
	case 0xA0: // Aftertouch
		snprintf(chBuf, 48, "Aftertouch: %3i",
				msg.getAfterTouchValue());
		break;
	case 0xB0: // Continuous Controller
		snprintf(chBuf, 48, "Ctrl  Num: %3i Value: %3i",
			msg.getControllerNumber(),
			msg.getControllerValue());
		break;
	case 0xC0: // Patch Change
		snprintf(chBuf, 48, "Program Change: %3i",
			msg.getProgramChangeNumber());
		break;
	case 0xD0: // Channel Pressure
		snprintf(chBuf, 48, "Channel Pressure: %3i",
			msg.getChannelPressureValue());
		break;
	case 0xE0: // Pitch Wheel
		snprintf(chBuf, 48, "Pitch Wheel: %7i",
			msg.getPitchWheelValue() - 8192);
		break;
	default: 
		isHandled = false;
	}

	//Todo - this implementation can loose a valid midi message if the last message in the list is not valid but a previous one is!

	if (isHandled){
		sendActionMessage(String(chBuf));
	}
}


//==============================================================================
SbMidiSliderMonitor::SbMidiSliderMonitor(String name, SbMidiMonitorState* monState, AudioProcessorValueTreeState& params)
	: monState(monState), paramID(String::empty)
{
	addAndMakeVisible(lblState = new Label("lblState",
		TRANS("Midi Monitor")));
	lblState->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblState->setJustificationType(Justification::centredLeft);
	lblState->setEditable(false, false, false);
	lblState->setColour(TextEditor::textColourId, Colours::black);
	lblState->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	addAndMakeVisible(btnPulse = new FlashingButton("btnPulse"));
	btnPulse->addListener(this);
	btnPulse->setToggleState(true, dontSendNotification);

	//[UserPreSize]
	addAndMakeVisible(lblMonitor = new Label("lblMonitor",
		TRANS("Pulse!")));
	lblMonitor->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblMonitor->setJustificationType(Justification::centredLeft);
	lblMonitor->setEditable(false, false, false);
	lblMonitor->setColour(TextEditor::textColourId, Colours::black);
	lblMonitor->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	attMonitor = new AudioProcessorValueTreeState::LabelAttachment(params, "", *lblMonitor);

	monState->addActionListener(this);
	setName(name);
	setMode(true);
	setSize(258, 24);
}



SbMidiSliderMonitor::~SbMidiSliderMonitor()
{
	monState->removeActionListener(this);

	attMonitor = nullptr;

	lblState = nullptr;
	btnPulse = nullptr;
	lblMonitor = nullptr;
}

//==============================================================================
void SbMidiSliderMonitor::paint(Graphics& g)
{
	g.fillAll(Colour(0xff2d0b0b));
}

void SbMidiSliderMonitor::resized()
{
	lblState->setBounds(0, 0, 76, 24);
	btnPulse->setBounds(76, 0, 24, 24);
	lblMonitor->setBounds(100, 0, 158, 24);
}

void SbMidiSliderMonitor::buttonClicked(Button* buttonThatWasClicked)
{
	if (buttonThatWasClicked != btnPulse) return;
	setMode(btnPulse->getToggleState());
}

void SbMidiSliderMonitor::procMidiMsgOn(const String& message) {
	btnPulse->flash();
	lblMonitor->setText(String(message), NotificationType::dontSendNotification);
}
// animate button only
void SbMidiSliderMonitor::procMidiMsgOff(const String& message) {
	btnPulse->flash();
}

void SbMidiSliderMonitor::sliderDragStartedOn(Slider* slider) {
	if (SbSlider* sl = dynamic_cast<SbSlider*>(slider)) {
		paramID = sl->getAttachedParamId();
		attMonitor->replaceListener(paramID);
	}
	lblState->setText(slider->getName(), NotificationType::dontSendNotification);
	lblMonitor->setEditable(true);
}

void SbMidiSliderMonitor::sliderDragStartedOff(Slider* slider) {}

