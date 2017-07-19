/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"


static const String f2color(float value) {
	if (value < 0.5) return "red";
	return value < 1.5 ? "green" : "blue";
}

static const float color2f(const String& text) {
	if (text == "blue") return 2.f;
	return text == "green" ? 1.f : 0.f;
}



RadioGroupParameters::RadioGroupParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{
	createAndAddParameter("color", "color", "color",
		NormalisableRange<float>(0.f, 2.f, 1.f),
		1.f, // positive
		f2color,
		color2f
	);
	stateInit();
}