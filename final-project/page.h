#pragma once

#include "ofMain.h"
using namespace glm;

class page {
public:
	void setup();
	void draw();

	ofShader distortShader;
	ofImage page;
	ofImage page2;

};