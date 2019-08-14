#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofDisableArbTex();

	distortShader.load("base.vert", "noiseDistort.frag");

	image.load("book2.jpg");
	image.getTexture().setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);

	image2.load("book1.png");
	image2.getTexture().setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Use the shader to distort the image. The mouse x and y values are used to control
	// the scaling and ampilitude of the noise used for the distortion.
	distortShader.begin();
	distortShader.setUniformTexture("tex0", image.getTexture(), 0);
	distortShader.setUniformTexture("tex1", image2.getTexture(), 1);
	distortShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	distortShader.setUniform4f("u_mouse", ofGetMouseX(),ofGetMouseY(),ofGetPreviousMouseX(),ofGetPreviousMouseY());
	distortShader.setUniform1f("u_time", ofGetElapsedTimef());

	ofPushMatrix();
	image.getTexture().bind();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofPopMatrix();

	distortShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (button == 0) {
		zP = x;
		wPos = y;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	xPos = x;
	yPos = y;
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
