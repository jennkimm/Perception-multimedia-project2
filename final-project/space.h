#pragma once

#include "ofMain.h"

using namespace glm;

class space {

public:
	void setup();
	void update();
	void draw();
	ofSpherePrimitive sphere;
	ofTexture mTex;

	ofSpherePrimitive mercury;
	ofSpherePrimitive venus;
	ofSpherePrimitive earth;
	ofSpherePrimitive mars;
	ofSpherePrimitive jupiter;
	ofSpherePrimitive saturn;
	ofSpherePrimitive uranus;
	ofSpherePrimitive neptune;

	ofTexture merTex;
	ofTexture venTex;
	ofTexture earTex;
	ofTexture marTex;
	ofTexture jupTex;
	ofTexture satTex;
	ofTexture uraTex;
	ofTexture nepTex;

	//star
	vec3 v[12];
	vec3 n[12];
	ofFloatColor c[12];
	ofVbo vbo;
	ofVboMesh mesh;

	//ofShader shader;

	float freqTime;
	float freqSpace;
	float amplitude;
	float time;
	int numStars;
	vector<vec3> starPositions;
	vector<vec3> starRotations;
	vector<float> starScales;
	vector<ofFloatColor> starColors;

};

const GLint indices2[20][3] = {
	{2, 1, 0 },
	{3, 2, 0},
	{4, 3, 0},
	{5, 4, 0},
	{1, 5, 0},
	{11, 6,  7},
	{11, 7,  8},
	{11, 8,  9},
	{11, 9,  10},
	{11, 10, 6},
	{2, 3, 7},
	{3, 4, 8},
	{4, 5, 9},
	{5, 1, 10},
	{2,  7, 6},
	{3,  8, 7},
	{4,  9, 8},
	{5, 10, 9},
	{1, 6, 10}
};

const GLfloat vertices[12][3] = {
	{0.000f,  0.000f,  1.000f},
	{0.894f,  0.000f,  0.447f },
	{0.276f,  0.851f,  0.447f},
	{-0.724f,  0.526f,  0.447f},
   {-0.724f, -0.526f,  0.447f},
   {0.276f, -0.851f,  0.447f},
   {0.724f,  0.526f, -0.447f},
   {-0.276f,  0.851f, -0.447f},
   {-0.894f,  0.000f, -0.447f},
   {-0.276f, -0.851f, -0.447f},
   {0.724f, -0.526f, -0.447f},
   {0.000f,  0.000f, -1.000f}
};
