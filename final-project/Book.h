#pragma once

#include "ofMain.h"
using namespace glm;

class Book {
public:

	ofMesh mesh;
	ofMesh mesh2;
	ofMesh mesh3;
	ofMesh mesh4;
	ofMesh mesh5;
	ofMesh mesh6;

	ofImage texture;
	ofImage texture2;
	ofImage texture3;
	ofImage texture4;
	ofImage texture5;
	ofImage texture6;

	void setup();
	void draw();

};

static const GLfloat vdata[8][3] = {
	// front
	{-10, -15,  1.5},
{10, -15,  1.5},
{ 10,  15,  1.5},
{ -10,  15,  1.5},

// back
{ -10, -15, -1.5},
{  10, -15, -1.5},
{  10,  15, -1.5},
{ -10,  15, -1.5}
};

static const GLint indices[12][3] = {
	// front
	{0, 1, 2},
	{2, 3, 0},
	// right
   {1, 5, 6},
   {6, 2, 1},
   // back
  {7, 6, 5},
  {5, 4, 7},
  // left
 {4, 0, 3},
 {3, 7, 4},
 // bottom
{4, 5, 1},
{1, 4, 0},
// top
{3, 2, 6},
{6, 7, 3}

};