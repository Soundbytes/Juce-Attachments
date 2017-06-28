/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"


ConverterWithStateParameters::ConverterWithStateParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{

	createAndAddParameter("dummy", "dummy", "dummy",
		NormalisableRange<float>(-1.f, 1.f, 2.f),
		1.f, // positive
		nullptr,
		nullptr
	);

	createAndAddParameter("default", "default", "default",
		NormalisableRange<float>(0.f, 1.f, 1.f),
		1.f, // 
		nullptr,
		nullptr
	);


	state = ValueTree(Identifier("CWSParams"));
}