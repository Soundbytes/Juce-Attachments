/*
  ==============================================================================

    SbTextConverters.h
    Created: 28 Jun 2017 9:38:04am
    Author:  gs.asumerauer0608

  ==============================================================================
*/

#pragma once

class SbPitchFilter 
{
public:
	explicit SbPitchFilter(const String& state) : scale(10.f) { setState(state); }

	const String f2t(float value) {
		return String(value * scale, 0) + "ixi";
	}

	const float t2f(const String& text) {
		return text.getFloatValue() / scale;
	}

	void setState(String state) {};
private:
	float scale;
};

