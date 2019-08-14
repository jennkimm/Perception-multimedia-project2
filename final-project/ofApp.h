#pragma once

#include "ofMain.h"
#include "Book.h"
#include "space.h"
#include "simpleExampleEffect.h"
#include "simple2.h"
#include "page.h"

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

		ofLight light;
		ofEasyCam cam;
		ofCamera myCam;
	
		//my book object
		Book mybook;

		//my space object
		space myspace;

		// two videos
		simpleExampleEffect myeffect;
		simple2 myeffect2;

		//page curl effect class
		page mypage;
};

