#pragma once

#include "ofMain.h"

class simpleExampleEffect {

public:
	void setup();
	void update();
	void draw();
	void bind();
	void unbind();

	ofVideoPlayer myVideo;
	ofPlanePrimitive plane;
	ofVboMesh mesh;
};
