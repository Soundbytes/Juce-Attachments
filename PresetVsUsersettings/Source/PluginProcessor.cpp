/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PresetVsUsersettingsAudioProcessor::PresetVsUsersettingsAudioProcessor()
	: params(*this)
#ifndef JucePlugin_PreferredChannelConfigurations
	, AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	)
#endif
{
}

PresetVsUsersettingsAudioProcessor::~PresetVsUsersettingsAudioProcessor()
{
}

//==============================================================================
const String PresetVsUsersettingsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PresetVsUsersettingsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PresetVsUsersettingsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double PresetVsUsersettingsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PresetVsUsersettingsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PresetVsUsersettingsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PresetVsUsersettingsAudioProcessor::setCurrentProgram (int index)
{
}

const String PresetVsUsersettingsAudioProcessor::getProgramName (int index)
{
    return {};
}

void PresetVsUsersettingsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PresetVsUsersettingsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void PresetVsUsersettingsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PresetVsUsersettingsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PresetVsUsersettingsAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool PresetVsUsersettingsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PresetVsUsersettingsAudioProcessor::createEditor()
{
    return new PresetVsUsersettingsAudioProcessorEditor (*this);
}

//==============================================================================
void PresetVsUsersettingsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    params.getPresetState(destData);
}

void PresetVsUsersettingsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    params.setPresetState(data, sizeInBytes);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PresetVsUsersettingsAudioProcessor();
}
