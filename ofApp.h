#pragma once

#include "ofMain.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofEasyCam myCamera;
		ofShader heightfieldShader;
		ofShader heightfieldPhongShader;
		ofPlanePrimitive terrainMesh;

		float heightScale;
		float noiseScale;
		float waterLevel;

		vec4 terrainAmbient;
		vec4 terrainDiffuse;
		vec4 terrainSpecular;
		float terrainShininess;

		vec4 waterAmbient;
		vec4 waterDiffuse;
		vec4 waterSpecular;
		float waterShininess;

		vec4 lightPosition;
		vec4 lightColor;

		bool usePhongShading;
};
