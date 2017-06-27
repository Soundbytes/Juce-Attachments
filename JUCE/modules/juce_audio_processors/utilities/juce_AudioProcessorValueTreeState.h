/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2017 - ROLI Ltd.

   JUCE is an open source library subject to commercial or open-source
   licensing.

   By using JUCE, you agree to the terms of both the JUCE 5 End-User License
   Agreement and JUCE 5 Privacy Policy (both updated and effective as of the
   27th April 2017).

   End User License Agreement: www.juce.com/juce-5-licence
   Privacy Policy: www.juce.com/juce-5-privacy-policy

   Or: You may also use this code under the terms of the GPL v3 (see
   www.gnu.org/licenses).

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

#pragma once

/**
    This class contains a ValueTree which is used to manage an AudioProcessor's entire state.

    It has its own internal class of parameter object which are linked to values
    within its ValueTree, and which are each identified by a string ID.

    You can get access to the underlying ValueTree object via the state member variable,
    so you can add extra properties to it as necessary.

    It also provides some utility child classes for connecting parameters directly to
    GUI controls like sliders.

    To use:
    1) Create an AudioProcessorValueTreeState, and give it some parameters using createAndAddParameter().
    2) Initialise the state member variable with a type name.
*/
class JUCE_API  AudioProcessorValueTreeState  : private Timer,
                                                private ValueTree::Listener
{
public:
    /** Creates a state object for a given processor.

        The UndoManager is optional and can be a nullptr.
        After creating your state object, you should add parameters with the
        createAndAddParameter() method. Note that each AudioProcessorValueTreeState
        should be attached to only one processor, and must have the same lifetime as the
        processor, as they will have dependencies on each other.
    */
    AudioProcessorValueTreeState (AudioProcessor& processorToConnectTo,
                                  UndoManager* undoManagerToUse);

    /** Destructor. */
    ~AudioProcessorValueTreeState();

    /** Creates and returns a new parameter object for controlling a parameter
        with the given ID.

        Calling this will create and add a special type of AudioProcessorParameter to the
        AudioProcessor to which this state is attached.

        @param parameterID          A unique string ID for the new parameter
        @param parameterName        The name that the parameter will return from AudioProcessorParameter::getName()
        @param labelText            The label that the parameter will return from AudioProcessorParameter::getLabel()
        @param valueRange           A mapping that will be used to determine the value range which this parameter uses
        @param defaultValue         A default value for the parameter (in non-normalised units)
        @param valueToTextFunction  A function that will convert a non-normalised value to a string for the
                                    AudioProcessorParameter::getText() method. This can be nullptr to use the
                                    default implementation
        @param textToValueFunction  The inverse of valueToTextFunction
        @returns the parameter object that was created
    */
    AudioProcessorParameterWithID* createAndAddParameter (const String& parameterID,
                                                          const String& parameterName,
                                                          const String& labelText,
                                                          NormalisableRange<float> valueRange,
                                                          float defaultValue,
                                                          std::function<String (float)> valueToTextFunction,
                                                          std::function<float (const String&)> textToValueFunction);

    /** Returns a parameter by its ID string. */
    AudioProcessorParameterWithID* getParameter (StringRef parameterID) const noexcept;

    /** Returns a pointer to a floating point representation of a particular
        parameter which a realtime process can read to find out its current value.
    */
    float* getRawParameterValue (StringRef parameterID) const noexcept;

    /** A listener class that can be attached to an AudioProcessorValueTreeState.
        Use AudioProcessorValueTreeState::addParameterListener() to register a callback.
    */
    struct JUCE_API  Listener
    {
        Listener();
        virtual ~Listener();

        /** This callback method is called by the AudioProcessorValueTreeState when a parameter changes. */
        virtual void parameterChanged (const String& parameterID, float newValue) = 0;
    };

    /** Attaches a callback to one of the parameters, which will be called when the parameter changes. */
    void addParameterListener (StringRef parameterID, Listener* listener);

    /** Removes a callback that was previously added with addParameterCallback(). */
    void removeParameterListener (StringRef parameterID, Listener* listener);

    /** Returns a Value object that can be used to control a particular parameter. */
    Value getParameterAsValue (StringRef parameterID) const;

    /** Returns the range that was set when the given parameter was created. */
    NormalisableRange<float> getParameterRange (StringRef parameterID) const noexcept;

    /** A reference to the processor with which this state is associated. */
    AudioProcessor& processor;

    /** The state of the whole processor.

        This must be initialised after all calls to createAndAddParameter().
        You can replace this with your own ValueTree object, and can add properties and
        children to the tree. This class will automatically add children for each of the
        parameter objects that are created by createAndAddParameter().
    */
    ValueTree state;

    /** Provides access to the undo manager that this object is using. */
    UndoManager* const undoManager;

    //==============================================================================
    /** An object of this class maintains a connection between a Slider and a parameter
        in an AudioProcessorValueTreeState.

        During the lifetime of this SliderAttachment object, it keeps the two things in
        sync, making it easy to connect a slider to a parameter. When this object is
        deleted, the connection is broken. Make sure that your AudioProcessorValueTreeState
        and Slider aren't deleted before this object!
    */
    class JUCE_API  SliderAttachment
    {
    public:
        SliderAttachment (AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID,
                          Slider& sliderToControl);
        ~SliderAttachment();

    private:
        struct Pimpl;
        friend struct ContainerDeletePolicy<Pimpl>;
        ScopedPointer<Pimpl> pimpl;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderAttachment)
    };

	//==============================================================================
	/** An object of this class maintains a connection between a ComboBox and a parameter
	in an AudioProcessorValueTreeState.

	During the lifetime of this ComboBoxAttachment object, it keeps the two things in
	sync, making it easy to connect a combo box to a parameter. When this object is
	deleted, the connection is broken. Make sure that your AudioProcessorValueTreeState
	and ComboBox aren't deleted before this object!
	*/
	class JUCE_API  ComboBoxAttachment
	{
	public:
		ComboBoxAttachment(AudioProcessorValueTreeState& stateToControl,
			const String& parameterID,
			ComboBox& comboBoxToControl,
			bool populateCombobox = false);
		~ComboBoxAttachment();

	private:
		struct Pimpl;
		friend struct ContainerDeletePolicy<Pimpl>;
		ScopedPointer<Pimpl> pimpl;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxAttachment)
	};

	//==============================================================================
	/** An object of this class maintains a connection between a Label and a parameter
	in an AudioProcessorValueTreeState.

	During the lifetime of this LabelAttachment object, it keeps the two things in
	sync, making it easy to connect a label to a parameter. When this object is
	deleted, the connection is broken. Make sure that your AudioProcessorValueTreeState
	and Label aren't deleted before this object!
	*/
	class JUCE_API  LabelAttachment
	{
	public:
		LabelAttachment(AudioProcessorValueTreeState& stateToControl,
			            const String& parameterID,
			            Label& labelToControl);
		~LabelAttachment();

	private:
		struct Pimpl;
		friend struct ContainerDeletePolicy<Pimpl>;
		ScopedPointer<Pimpl> pimpl;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LabelAttachment)
	};

	//==============================================================================
	/** An object of this class maintains a connection between a Button and a parameter
	in an AudioProcessorValueTreeState.

	During the lifetime of this ButtonAttachment object, it keeps the two things in
	sync, making it easy to connect a button to a parameter. When this object is
	deleted, the connection is broken. Make sure that your AudioProcessorValueTreeState
	and Button aren't deleted before this object!
	*/
	class JUCE_API  ButtonAttachment
	{
	public:
		ButtonAttachment(AudioProcessorValueTreeState& stateToControl,
			const String& parameterID,
			Button& buttonToControl);
		~ButtonAttachment();

	private:
		struct Pimpl;
		friend struct ContainerDeletePolicy<Pimpl>;
		ScopedPointer<Pimpl> pimpl;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAttachment)
	};

//	//==============================================================================
//	/** An object of this class maintains a connection between a ToggleButton and a parameter
//	in an AudioProcessorValueTreeState.
//
//	During the lifetime of this ToggleButtonAttachment object, it keeps the two things in
//	sync, making it easy to connect a togglebutton to a parameter. When this object is
//	deleted, the connection is broken. Make sure that your AudioProcessorValueTreeState
//	and ToggleButton aren't deleted before this object!
//	*/
//	class JUCE_API  ToggleButtonAttachment
//	{
//	public:
//		ButtonAttachment(AudioProcessorValueTreeState& stateToControl,
//			const String& parameterID,
//			Button& buttonToControl);
//		~ButtonAttachment();
//
//	private:
//		struct Pimpl;
//		friend struct ContainerDeletePolicy<Pimpl>;
//		ScopedPointer<Pimpl> pimpl;
//		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAttachment)
//	};

    struct Parameter; // declared here to allow public access
private:
    //==============================================================================
    friend struct Parameter;

    ValueTree getOrCreateChildValueTree (const String&);
    void timerCallback() override;

    void valueTreePropertyChanged (ValueTree&, const Identifier&) override;
    void valueTreeChildAdded (ValueTree&, ValueTree&) override;
    void valueTreeChildRemoved (ValueTree&, ValueTree&, int) override;
    void valueTreeChildOrderChanged (ValueTree&, int, int) override;
    void valueTreeParentChanged (ValueTree&) override;
    void valueTreeRedirected (ValueTree&) override;
    void updateParameterConnectionsToChildTrees();

    Identifier valueType, valuePropertyID, idPropertyID;
    bool updatingConnections;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProcessorValueTreeState)
};

struct AudioProcessorValueTreeState::Parameter : public AudioProcessorParameterWithID,
	private ValueTree::Listener
{
	Parameter(AudioProcessorValueTreeState& s,
		const String& parameterID, const String& paramName, const String& labelText,
		NormalisableRange<float> r, float defaultVal,
		std::function<String(float)> valueToText,
		std::function<float(const String&)> textToValue)
		: AudioProcessorParameterWithID(parameterID, paramName, labelText),
		owner(s), valueToTextFunction(valueToText), textToValueFunction(textToValue),
		range(r), value(defaultVal), defaultValue(defaultVal),
		listenersNeedCalling(true)
	{
		state.addListener(this);
		needsUpdate.set(1);
	}

	~Parameter()
	{
		// should have detached all callbacks before destroying the parameters!
		jassert(listeners.size() <= 1);
	}

	float getValue() const override { return range.convertTo0to1(value); }
	float getDefaultValue() const override { return range.convertTo0to1(defaultValue); }

	float getValueForText(const String& text) const override
	{
		return range.convertTo0to1(textToValueFunction != nullptr ? textToValueFunction(text)
			: text.getFloatValue());
	}

	String getText(float v, int length) const override
	{
		return valueToTextFunction != nullptr ? valueToTextFunction(range.convertFrom0to1(v))
			: AudioProcessorParameter::getText(v, length);
	}

	int getNumSteps() const override
	{
		if (range.interval > 0)
			return (static_cast<int> ((range.end - range.start) / range.interval) + 1);

		return AudioProcessor::getDefaultNumParameterSteps();
	}

	void setValue(float newValue) override
	{
		newValue = range.snapToLegalValue(range.convertFrom0to1(newValue));

		if (value != newValue || listenersNeedCalling)
		{
			value = newValue;

			listeners.call(&AudioProcessorValueTreeState::Listener::parameterChanged, paramID, value);
			listenersNeedCalling = false;

			needsUpdate.set(1);
		}
	}

	void setNewState(const ValueTree& v)
	{
		state = v;
		updateFromValueTree();
	}

	void setUnnormalisedValue(float newUnnormalisedValue)
	{
		if (value != newUnnormalisedValue)
		{
			const float newValue = range.convertTo0to1(newUnnormalisedValue);
			setValueNotifyingHost(newValue);
		}
	}

	void updateFromValueTree()
	{
		setUnnormalisedValue(state.getProperty(owner.valuePropertyID, defaultValue));
	}

	void copyValueToValueTree()
	{
		if (state.isValid())
			state.setPropertyExcludingListener(this, owner.valuePropertyID, value, owner.undoManager);
	}

	void valueTreePropertyChanged(ValueTree&, const Identifier& property) override
	{
		if (property == owner.valuePropertyID)
			updateFromValueTree();
	}

	void valueTreeChildAdded(ValueTree&, ValueTree&) override {}
	void valueTreeChildRemoved(ValueTree&, ValueTree&, int) override {}
	void valueTreeChildOrderChanged(ValueTree&, int, int) override {}
	void valueTreeParentChanged(ValueTree&) override {}

	static Parameter* getParameterForID(AudioProcessor& processor, StringRef paramID) noexcept
	{
		const int numParams = processor.getParameters().size();

		for (int i = 0; i < numParams; ++i)
		{
			AudioProcessorParameter* const ap = processor.getParameters().getUnchecked(i);

			// When using this class, you must allow it to manage all the parameters in your AudioProcessor, and
			// not add any parameter objects of other types!
			jassert(dynamic_cast<Parameter*> (ap) != nullptr);

			Parameter* const p = static_cast<Parameter*> (ap);

			if (paramID == p->paramID)
				return p;
		}

		return nullptr;
	}

	AudioProcessorValueTreeState& owner;
	ValueTree state;
	ListenerList<AudioProcessorValueTreeState::Listener> listeners;
	std::function<String(float)> valueToTextFunction;
	std::function<float(const String&)> textToValueFunction;
	NormalisableRange<float> range;
	float value, defaultValue;
	Atomic<int> needsUpdate;
	bool listenersNeedCalling;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameter)
};