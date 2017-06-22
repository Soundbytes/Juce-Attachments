PLEASE NOTE: This is only a first draft. The code is still buggy and should certainly NOT be used in a production environment. Instead it is meant as a contribution to an ongoing discussion.
To participate please post your comments to the juce forum at http://forum.juce.com

Juce Attachments

This proposal features two Attachments for the juce::AudioProcessorValueTreeState class
LabelAttachment (new)
ComboboxAttachment (based on the existing version)

Both attachent make use of the user defined valueToTextFunction and textToValueFunction when set as the last 2 parameters from the createAndAddParameter function.

These functions are used to create an updated text entry from a new parameter value and to evaluate text entries in the label or comboBox editor.
It is also possible now to create the Combobox item list by connecting it with a parameter through the Attachment.

The Demo Project:
The AudioProcessorValueTreeState class design does not allow the addition of user defined Attachments from outside the class definition. Because of that I had to modify two files from the juce framework to make things possible.
Before compiling the demo project you will have to replace the two files juce_AudioProcessorValueTreeState.cpp and juce_AudioProcessorValueTreeState.h
with the versions that are supplied with this release.

Known Issues:
- When the text entry evaluates to the previous parameter value the Label is not updated with the proper text that corresponds to that parameter value. 
Instead the text entry is then left unchanged.
(Example MidiCC label: When the a user enter a "7" the label should be updated to show the cc name "Volume (coarse)". This will only work if the previous parameter value was differrent from seven. In that case the label shows "7" instead of the controller name.)
- there is still an issue with text initialization. Text labels do not always show the text that corresponds to the parameter default value when the standdalone app is loaded. 
 