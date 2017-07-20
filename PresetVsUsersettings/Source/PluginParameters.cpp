/*
  ==============================================================================

    PluginParameters.cpp
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#include "PluginParameters.h"


PresetVsUsersettingsParameters::PresetVsUsersettingsParameters(AudioProcessor& p) : AudioProcessorValueTreeState(p, nullptr)
{

	createAndAddParameter("preset 1", "preset 1", "preset 1",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr
	);
	createAndAddParameter("preset 2", "preset 2", "preset 2",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr
	);
	createAndAddParameter("preset 3", "preset 3", "preset 3",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr
	);


	createAndAddParameter("settings 1", "settings 1", "settings 1",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr,
		false, // canAutomate
		false  // saveStateWithPreset
	);
	createAndAddParameter("settings 2", "settings 2", "settings 2",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr,
		false, // canAutomate
		false  // saveStateWithPreset
	);
	createAndAddParameter("settings 3", "settings 3", "settings 3",
		NormalisableRange<float>(0.f, 1.f),
		0.f, nullptr, nullptr,
		false, // canAutomate
		false  // saveStateWithPreset
	);

	stateInit();
}