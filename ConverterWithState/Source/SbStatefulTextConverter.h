/*
  ==============================================================================

    SbStatefulTextConverter.h
    Created: 28 Jun 2017 9:38:04am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#pragma once

class SbStatefulTextConverter 
{
public:
	explicit SbStatefulTextConverter(const String& state) : state("numbers") { setState(state); }
	/*&((char)(value - 97))*/

	const String f2t(float value) {
		return state == "numbers" ? 
			String(value, 0) : 
			String::charToString(char(value + 96));
	}

	const float t2f(const String& text) {
		return state == "numbers" ?
			text.getFloatValue() :
			text.getLastCharacter() - 96;
	}

	void setState(String newState) { state = newState; };
private:
	String state;
};


