#include "SliderMonParameters.h"

static const String floatToTxtNoDecimals(float value)
{
	return String(value, 0);
}

static const String percentToText(float value)
{
	return String(value * 100, 2) + "%";
}

static const float textToPercent(const String& text)
{
	return 0.01f * text.getFloatValue();
}

static const String dbToText(float value)
{
	return String(value, 2) + "db";
}

static const String hzToText(float value)
{
	int decimals = 1;
	for (float tmpVal = value; tmpVal < 100000; tmpVal *= 10.f) ++decimals;

	return String(value, decimals) + "Hz";
}



SliderMidiMonParameters::SliderMidiMonParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{
	createAndAddParameter(
		"percent", // parameterID
		"percent", // parameter name
		"percent Gain", // parameter label (suffix)
		NormalisableRange<float>(0.0f, 1.0f, 0.f), // range
		0.5f,		// default value
		percentToText,	// value to text function
		textToPercent	// text to value function
	);
	createAndAddParameter("db", "db", "db",
		NormalisableRange<float>(-96.0f, 24.0f, 0.f),
		0.0f, 
		dbToText,
		nullptr);
	createAndAddParameter("freq", "freq", "freq",
		NormalisableRange<float>(10.0f, 20000.0f, 0.f,0.25f),
		880.f,
		hzToText,
		nullptr);
	createAndAddParameter("int", "int", "int",
		NormalisableRange<float>(0.0f, 100.0f, 1.f),
		50.f,
		floatToTxtNoDecimals,
		nullptr);

	state = ValueTree(Identifier("SMMParams"));
}