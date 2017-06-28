/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"

static SbPitchFilter pitchFilter("noteName");
static auto f2t = [](float val) {return pitchFilter.f2t(val); };
static auto t2f = [](const String& text) {return pitchFilter.t2f(text); };



ConverterWithStateParameters::ConverterWithStateParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{
	createAndAddParameter("pitch", "pitch", "pitch",
		NormalisableRange<float>(0.f, 127.f, 1.f),
		1.f, // positive
		f2t,
		t2f
	);

	state = ValueTree(Identifier("CWSParams"));
}