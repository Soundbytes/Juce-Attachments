/*
  ==============================================================================

    PluginParameters.h
    Created: 28 Jun 2017 9:38:57am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SbTextConverters.h"

class PresetVsUsersettingsParameters : public AudioProcessorValueTreeState
{
public:
	PresetVsUsersettingsParameters(AudioProcessor& p);
};

