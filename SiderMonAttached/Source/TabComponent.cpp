/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TabComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabComponent::TabComponent (Slider::Listener* sliderMonitor)
    : sliderMonitor(sliderMonitor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tabSlider0 = new Slider ("tabSlider0"));
    tabSlider0->setRange (0, 10, 0);
    tabSlider0->setSliderStyle (Slider::LinearHorizontal);
    tabSlider0->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    tabSlider0->setColour (Slider::textBoxBackgroundColourId, Colour (0x60263238));

    addAndMakeVisible (tabSlider1 = new Slider ("tabSlider1"));
    tabSlider1->setRange (0, 10, 0);
    tabSlider1->setSliderStyle (Slider::LinearHorizontal);
    tabSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    tabSlider1->setColour (Slider::textBoxBackgroundColourId, Colour (0x60263238));


    //[UserPreSize]
    tabSlider0->addListener (sliderMonitor);
    tabSlider1->addListener (sliderMonitor);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabComponent::~TabComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabSlider0 = nullptr;
    tabSlider1 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff774444));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabSlider0->setBounds (16, 16, 216, 24);
    tabSlider1->setBounds (16, 48, 216, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabComponent" componentName=""
                 parentClasses="public Component" constructorParams="Slider::Listener* sliderMonitor"
                 variableInitialisers="sliderMonitor(sliderMonitor)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff774444"/>
  <SLIDER name="tabSlider0" id="8f4206143e8f2745" memberName="tabSlider0"
          virtualName="" explicitFocusOrder="0" pos="16 16 216 24" textboxbkgd="60263238"
          min="0" max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
  <SLIDER name="tabSlider1" id="757bd965867d3768" memberName="tabSlider1"
          virtualName="" explicitFocusOrder="0" pos="16 48 216 24" textboxbkgd="60263238"
          min="0" max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
