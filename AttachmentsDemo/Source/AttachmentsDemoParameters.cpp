/*
  ==============================================================================

    AttachmentsDemoParameters.cpp
    Created: 21 Jun 2017 11:05:59am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "AttachmentsDemoParameters.h"

static const String& fruits(int idx) {
	static const StringArray fruits = { "Bapple! (-1)", "Banana! (0)", "Potato! (1)" };
	idx = jmin(1, jmax(-1, idx));
	return fruits[idx + 1];
}

static const String CcNumber2Name(float value)
{
	if (value >= 0.f) {
		int intVal = (int)value;
		const char* ccName = MidiMessage::getControllerName(intVal);
		return ccName != nullptr ? String(ccName) : String("CC Number: ") + String(intVal);
	}
	return String("ERROR");
}

static const float CcName2Number(const String& text) //Todo - this implementation needs testing! 
{
	if (text == String::empty) return 0.f;
	for (float i = 0; i < 127; ++i) {
		const char* ccName = MidiMessage::getControllerName((int)i);
		if (ccName && text == ccName) {
			return (float)i;
		}
	}
	if (text.substring(0, 11) == "CC Number: ") return text.substring(11).getFloatValue();
	return text.getFloatValue();  
}


static const float MIN_EXP = 5;
static const float MAX_EXP = 10;

static const String exponent2itemText(float value)
{
	value = jmin(MAX_EXP, jmax(MIN_EXP, value));
	return String(powf(2.f, value), 0);
}

static const float itemText2Exponent(const String& text) 
{
	if (text == String::empty) return MIN_EXP;
	for (float i = MIN_EXP, res = powf(2.f, MIN_EXP); i <= MAX_EXP; ++i, res*=2) {
		if (String(res, 0) == text) return i;
	}
	return MIN_EXP;
}


AttachmentsDemoParameters::AttachmentsDemoParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{
	createAndAddParameter("fruits", "fruits", "Fruits",
		NormalisableRange<float>(-1.0f, 1.0f, 1.f), 
		-1.f, // Bapple!
		[](float value) {			// value to text function
		return fruits((int)value);
	},
		[](const String& text) {	// text to value function
		for (int i = -1; i < 2; ++i) {
			if (text == fruits(i)) {
				return (float)i;
			}
		}
		return text.getFloatValue();
	}
	);

	createAndAddParameter("fftWindowSize", "fftWindowSize", "fftWindowSize",
		NormalisableRange<float>(MIN_EXP, MAX_EXP, 1.f), // Controllers + PB
		7.f, // 128
		exponent2itemText,
		itemText2Exponent
	);

	createAndAddParameter("ccSelect", "ccSelect", "ccSelect",
		NormalisableRange<float>(0.f, 127.f, 1.f), // Controllers + PB
		7.f, // Volume
		CcNumber2Name,
		CcName2Number
	);

	state = ValueTree(Identifier("ADParams"));
}

