#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	usePhongShading = false;

	ofDisableArbTex();
	ofBackground(0);

	heightfieldShader.load("heightfieldFbm.vert", "heightfieldFbm.frag");
	heightfieldPhongShader.load("heightfieldFbm.vert", "heightfieldFbm_phong.frag");

	myCamera.setPosition(vec3(0.0f, 10.0f, 40.0f));
	myCamera.setTarget(vec3(0.0f, 0.0f, 0.0f));
	myCamera.setFov(32.0f);
	myCamera.setNearClip(0.05f);
	myCamera.setFarClip(100.0f);
	myCamera.setAutoDistance(false);

	terrainMesh.set(40, 30, 200, 150);

	heightScale = 7.0f;
	noiseScale = 0.05f;
	waterLevel = -8.0f;

	terrainDiffuse = vec4(0.2f, 0.7f, 0.1f, 1.0f);
	terrainSpecular = vec4(vec3(0.1f, 0.1f, 0.1f), 1.0f);
	terrainAmbient = vec4(0.1f, 0.1f, 0.2f, 1.0f);
	terrainShininess = 10.0f;

	waterDiffuse = vec4(0.1f, 0.4f, 0.9f, 1.0f);
	waterSpecular = vec4(vec3(1.0f, 1.0f, 1.0f), 1.0f);
	waterAmbient = vec4(0.1f, 0.1f, 0.2f, 1.0f);
	waterShininess = 500.0f;

	lightPosition = vec4(100.0f, 200.0f, 100.0f, 1.0f);
	lightColor = vec4(1.0f, 1.0f, 0.8f, 1.0f);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();

	myCamera.begin();

	if (usePhongShading) {
		heightfieldPhongShader.begin();
		heightfieldPhongShader.setUniform1f("heightScale", heightScale);
		heightfieldPhongShader.setUniform1f("noiseScale", noiseScale);
		heightfieldPhongShader.setUniform1f("waterLevel", waterLevel);
		heightfieldPhongShader.setUniform4f("terrainAmbient", terrainAmbient);
		heightfieldPhongShader.setUniform4f("terrainDiffuse", terrainDiffuse);
		heightfieldPhongShader.setUniform4f("terrainSpecular", terrainSpecular);
		heightfieldPhongShader.setUniform1f("terrainShininess", terrainShininess);
		heightfieldPhongShader.setUniform4f("waterAmbient", waterAmbient);
		heightfieldPhongShader.setUniform4f("waterDiffuse", waterDiffuse);
		heightfieldPhongShader.setUniform4f("waterSpecular", waterSpecular);
		heightfieldPhongShader.setUniform1f("waterShininess", waterShininess);
		heightfieldPhongShader.setUniform4f("lightPosition", lightPosition);
		heightfieldPhongShader.setUniform4f("lightColor", lightColor);
		ofPushMatrix();
		ofRotateXDeg(-90.0f);
		terrainMesh.draw();
		ofPopMatrix();
		heightfieldPhongShader.end();
	}
	else {
		heightfieldShader.begin();
		heightfieldShader.setUniform1f("heightScale", heightScale);
		heightfieldShader.setUniform1f("noiseScale", noiseScale);
		heightfieldShader.setUniform1f("waterLevel", waterLevel);
		ofPushMatrix();
		ofRotateXDeg(-90.0f);
		terrainMesh.drawWireframe();
		ofPopMatrix();
		heightfieldShader.end();
	}

	myCamera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// Use the 'q' and 'w' keys to change the height of the mountainscape
	// Use the 'a' and 's' keys to change the water level
	// Use the 'p' key to switch between wireframe and Phong shaded mode

	switch (key) {
	case 'q':
		heightScale /= 1.2;
		break;
	case 'w':
		heightScale *= 1.2f;
		break;
	case 'a':
		waterLevel -= 0.1f;
		break;
	case 's':
		waterLevel += 0.1f;
		break;
	case 'p':
		usePhongShading = !usePhongShading;
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
