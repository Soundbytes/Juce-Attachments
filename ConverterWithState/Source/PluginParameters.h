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

class ConverterWithStateParameters : public AudioProcessorValueTreeState
{
public:
	ConverterWithStateParameters(AudioProcessor& p);
	SbTextConverter textConverter;

	std::function<String(float)> f2t;
	std::function<float(const String&)> t2f;

};
