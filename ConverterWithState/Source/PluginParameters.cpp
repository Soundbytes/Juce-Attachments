/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"



ConverterWithStateParameters::ConverterWithStateParameters(AudioProcessor& p) 
	: AudioProcessorValueTreeState(p, nullptr), textConverter("numbers")
{
	f2t = [this](float val) {return textConverter.f2t(val); };
	t2f = [this](const String& text) {return textConverter.t2f(text); };

	createAndAddParameter("value", "value", "value",
		NormalisableRange<float>(1.f, 26.f, 1.f),
		1.f, // positive
		f2t,
		t2f
	);

	state = ValueTree(Identifier("CWSParams"));
}