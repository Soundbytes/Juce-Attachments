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
	createAndAddParameter("value", "value", "value",
		NormalisableRange<float>(1.f, 26.f, 1.f),
		1.f, // positive
		[this](float val) {return textConverter.f2t(val); },
		[this](const String& text) {return textConverter.t2f(text); }
	);

	state = ValueTree(Identifier("CWSParams"));
}

