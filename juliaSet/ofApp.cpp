#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	juliaShader.load("julia"); //juliaShader look for files called julia*
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	juliaShader.begin();
	
	//juliaShader.setUniform1f("complexRange", 6.0);

	if (ws==1) {
		juliaShader.setUniform1f("complexRange", 8.0); //zoom in
	}
	else if (ws == 2) {
		juliaShader.setUniform1f("complexRange", 4.0); //zoom out
	}
	

	juliaShader.setUniform2f("mousePos", vec2(ofGetMouseX(), ofGetMouseY()));
	juliaShader.setUniform2f("windowSize", vec2(ofGetWidth(), ofGetHeight()));
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	juliaShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		ws = 1;
	}
	if (key == 's') {
		ws = 2;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
