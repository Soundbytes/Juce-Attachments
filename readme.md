# Juce Attachments

This proposal features two Attachments for the juce::AudioProcessorValueTreeState class
- LabelAttachment (new)
- ComboBoxAttachment (based on the existing version)

Both attachents make use of the user defined valueToTextFunction and textToValueFunction when set as the last 2 parameters from the createAndAddParameter function.

These functions are used to create an updated text entry from a new parameter value and to evaluate text entries in the label or comboBox editor.
It is also possible now to create the Combobox item list by connecting it to a parameter through the Attachment.

## The Demo Projects:

### AttachmentsDemo:
The AttachmentsDemo example project illustrates the use of the enhanced ComboBoxAttachment and the new LabelAttachment.

### SliderMonitor
This example features a status bar at the bottom of the UI panel. The status bar shows the value of the most recently moved slider. It can also be used to change the value via text input. the text representation of the status bar is determined by the valueToText function of the parameter that is attached to the selected slider.
The example shows how a complete custom attachment can be implemented outside the framework code. 

### Please note:
The AudioProcessorValueTreeState class design does not allow the addition of user defined Attachments from outside the class definition. Because of that I had to modify two files from the juce framework to make things possible.
Before compiling the demo projects you will have to replace the two files juce_AudioProcessorValueTreeState.cpp and juce_AudioProcessorValueTreeState.h
with the versions that are supplied with this release.

## Changes:
- Bugfix: AttachmentsDemo: Combobox now always shows the correct item text 
- Added a SliderMonitor example 
- Bugfix: Combobox is now initialized correctly.

 
