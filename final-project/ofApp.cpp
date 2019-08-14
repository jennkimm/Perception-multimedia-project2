#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofDisableAlphaBlending();
	ofEnableDepthTest();
	ofSetFrameRate(120);

	//light setup
	light.setDiffuseColor(ofColor(255, 230, 128));
	light.setSpecularColor(light.getDiffuseColor());
	light.setPosition(vec3(120.0f, 100.0f, 120.0f));
	light.setAmbientColor(ofColor(255, 230, 128));

	//book setup
	mybook.setup();

	//space setup
	myspace.setup();

	//page setup
	mypage.setup();

	//videos setup
	myeffect.setup(); 
	myeffect2.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	//movie.update();
	myeffect.update();
	myeffect2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableNormalizedTexCoords();
	
	//set camera movement  
	float tweenvalue = (ofGetElapsedTimeMillis() % 20000) / 20000.f; // this will slowly change from 0.0f to 1.0f, resetting every 2 seconds  

	ofQuaternion startQuat;
	ofQuaternion targetQuat;
	ofVec3f startPos;
	ofVec3f targetPos;

	//orientation  
	startQuat.makeRotate(90, 1, 0, 0);			// zero rotation.  
	targetQuat.makeRotate(90, 1, 0, 0);			// rotation 90 degrees around y-axis.  

	//position  
	startPos.set(-250, -100, -250);
	targetPos.set(0, -1100, 0);


	ofQuaternion tweenedCameraQuaternion;	// this will be the camera's new rotation.  

	// calculate the interpolated orientation  
	tweenedCameraQuaternion.slerp(tweenvalue, startQuat, targetQuat);

	ofVec3f lerpPos;					//this will hold our tweened position.  

	// calculate the interpolated values
	lerpPos.x = startPos.x + ((targetPos.x - startPos.x) * tweenvalue);
	lerpPos.y = startPos.y + ((targetPos.y - startPos.y) * tweenvalue);
	lerpPos.z = startPos.z + ((targetPos.z - startPos.z) * tweenvalue);

	// now update the camera with the calculated orientation and position.  
	myCam.setOrientation(tweenedCameraQuaternion);
	myCam.setGlobalPosition(lerpPos);

	//set current time for video effect
	float curTime = ofGetElapsedTimef();

	//space & a floating book scene
	if (curTime <= 22) {

		//set background color
		ofColor centerColor = ofColor(85, 78, 68);
		ofColor edgeColor(0, 0, 0);
		ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

		myCam.begin();

		//draw space
		ofPushMatrix();
		myspace.draw();
		ofPopMatrix();

		//draw a book
		ofPushMatrix();
		ofTranslate(0, -600, 0);
		ofScale(8);
		ofRotate(ofGetElapsedTimef() * 90 * 0.3, 1, 1, 0);
		mybook.draw();
		ofPopMatrix();
		myCam.end();
	}

	//the floating book is falling on my desk
	if (curTime>22&&curTime<=27) {

		cam.begin();
		ofPushMatrix();
		myeffect.bind();
		myeffect.draw();
		myeffect.unbind();
		ofPopMatrix();

		if (curTime > 22 && curTime <= 23) {
			ofPushMatrix();
			ofTranslate(-20, 70, 50);
			ofRotate(ofGetElapsedTimef() * 70 * 0.3, 1, 1, 0);
			ofScale(4);
			mybook.draw();
			ofPopMatrix();
		}

		if (curTime > 23 && curTime <= 24) {
			ofPushMatrix();
			ofTranslate(-20, 50, 50);
			ofRotate(ofGetElapsedTimef() * 70 * 0.3, 1, 1, 0);
			ofScale(4);
			mybook.draw();
			ofPopMatrix();
		}

		if (curTime > 24 && curTime <= 25) {
			ofPushMatrix();
			ofTranslate(-20, 0, 55);
			ofRotate(ofGetElapsedTimef() * 90 * 0.3, 1, 1, 0);
			ofScale(4);
			mybook.draw();
			ofPopMatrix();
		}

		if (curTime > 25 && curTime <= 26) {
			ofPushMatrix();
			ofTranslate(-20, -25, 60);
			ofRotate(ofGetElapsedTimef() * 70 * 0.3, 1, 1, 0);
			ofScale(4);
			mybook.draw();
			ofPopMatrix();
		}
		
		if (curTime > 26 && curTime <= 27) {
			ofPushMatrix();
			ofTranslate(-30, -50, 65);
			//ofRotate(ofGetElapsedTimef() * 70 * 0.3, 1, 1, 0);
			ofScale(2.8);
			mybook.draw();
			ofPopMatrix();
		}
		
		cam.end();

	}

	//Grab it and start reading
	if(curTime>27 && curTime<=32.5) {

		cam.begin();
		ofPushMatrix();
		myeffect2.bind();
		myeffect2.draw();
		myeffect2.unbind();
		ofPopMatrix();

		cam.end();
	}

	//page curl effect with custom shader
	//you can interact with the page with mouse
	if (curTime > 32.5) {
		ofPushMatrix();
		mypage.draw();
		ofPopMatrix();
	}

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
