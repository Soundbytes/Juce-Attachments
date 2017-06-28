/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"

SbTextConverter ConverterWithStateParameters::textConverter("numbers");

static auto f2t = [](float val) {return ConverterWithStateParameters::textConverter.f2t(val); };
static auto t2f = [](const String& text) {return ConverterWithStateParameters::textConverter.t2f(text); };



ConverterWithStateParameters::ConverterWithStateParameters(AudioProcessor& p) 
	: AudioProcessorValueTreeState(p, nullptr)
{
	createAndAddParameter("value", "value", "value",
		NormalisableRange<float>(1.f, 26.f, 1.f),
		1.f, // positive
		f2t,
		t2f
	);

	state = ValueTree(Identifier("CWSParams"));
}