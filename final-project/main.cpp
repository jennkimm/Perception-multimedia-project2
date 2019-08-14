#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// <-------- setup the GL context
	ofGLFWWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(1280, 720);
	ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
