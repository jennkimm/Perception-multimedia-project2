#include "space.h"

//--------------------------------------------------------------
void space::setup() {
	ofDisableAlphaBlending();
	ofEnableDepthTest();

	//sun setup
	sphere.setRadius(200);
	ofDisableArbTex();
	mTex.enableMipmap();
	ofLoadImage(mTex, "sun.jpg");
	mTex.generateMipmap();

	//mercury
	mercury.setRadius(10);
	mercury.setPosition(vec3(230, 0, 0));
	merTex.enableMipmap();
	ofLoadImage(merTex, "mercury.jpg");
	merTex.generateMipmap();

	//venus
	venus.setRadius(30);
	venus.setPosition(vec3(290, 0, 0));
	venTex.enableMipmap();
	ofLoadImage(venTex, "venus.jpg");
	venTex.generateMipmap();

	//earth
	earth.setRadius(40);
	earth.setPosition(vec3(390, 0, 0));
	earTex.enableMipmap();
	ofLoadImage(earTex, "earth.jpg");
	earTex.generateMipmap();

	//mars
	mars.setRadius(25);
	mars.setPosition(vec3(430, 0, 0));
	marTex.enableMipmap();
	ofLoadImage(marTex, "mars.png");
	marTex.generateMipmap();

	//jupiter
	jupiter.setRadius(90);
	jupiter.setPosition(vec3(600, 0, 0));
	jupTex.enableMipmap();
	ofLoadImage(jupTex, "jupiter.jpg");
	jupTex.generateMipmap();

	//saturn
	saturn.setRadius(83);
	saturn.setPosition(vec3(800, 0, 0));
	satTex.enableMipmap();
	ofLoadImage(satTex, "saturn.jpg");
	satTex.generateMipmap();

	//uranus
	uranus.setRadius(71);
	uranus.setPosition(vec3(1000, 0, 0));
	uraTex.enableMipmap();
	ofLoadImage(uraTex, "uranus.jpg");
	uraTex.generateMipmap();

	//neptune
	neptune.setRadius(55);
	neptune.setPosition(vec3(1200, 0, 0));
	nepTex.enableMipmap();
	ofLoadImage(nepTex, "neptune.jpg");
	nepTex.generateMipmap();

	//star
	for (int i = 0; i < 12; ++i) {
		mesh.addVertex(vec3(vertices[i][0], vertices[i][1], vertices[i][2]));
	}
	for (int i = 0; i < 20; ++i)
	{
		mesh.addIndex(indices2[i][0]);
		mesh.addIndex(indices2[i][1]);
		mesh.addIndex(indices2[i][2]);
	}

	numStars = 100;
	for (int i = 0; i < numStars; i++) {
		starPositions.push_back(vec3(ofRandom(-1050.0f, 1050.0f), ofRandom(-600.0f, 600.0f), ofRandom(-600.0f, 600.0f)));
		starRotations.push_back(vec3(ofRandom(-45.0f, 45.0f), ofRandom(360.0f), ofRandom(-45.0f, 45.0f)));
		starScales.push_back(ofRandom(1.0f, 10.0f));
		starColors.push_back(ofFloatColor(1.0f, 1.0f, ofRandom(0.6f, 1.0f), 1.0f));
	}

}

//--------------------------------------------------------------
void space::update() {

}

//--------------------------------------------------------------
void space::draw() {

	//draw sun
	ofPushMatrix();
	mTex.bind();
	ofRotate(ofGetElapsedTimef() * 90 * 0.04, 0, 1, 0);
	sphere.draw();
	mTex.unbind();
	ofPopMatrix();

	//draw mercury
	ofPushMatrix();
	merTex.bind();
	ofRotate(ofGetElapsedTimef() * 40.0*0.15, 0, 1, 0);
	mercury.draw();
	merTex.unbind();
	ofPopMatrix();

	//draw venus
	ofPushMatrix();
	venTex.bind();
	ofRotate(ofGetElapsedTimef() * 90 * 0.18, 0, 1, 0);
	venus.draw();
	venTex.unbind();
	ofPopMatrix();

	//draw earth
	ofPushMatrix();
	earTex.bind();
	ofRotate(ofGetElapsedTimef() * 50 * 0.3, 0, 1, 0);
	earth.draw();
	earTex.unbind();
	ofPopMatrix();

	//draw mars
	ofPushMatrix();
	marTex.bind();
	ofRotate(ofGetElapsedTimef() * 40.0*0.4, 0, 1, 0);
	mars.draw();
	marTex.unbind();
	ofPopMatrix();

	//draw jupiter
	ofPushMatrix();
	jupTex.bind();
	ofRotate(ofGetElapsedTimef() * 80.0*0.12, 0, 1, 0);
	jupiter.draw();
	jupTex.unbind();
	ofPopMatrix();

	//draw saturn
	ofPushMatrix();
	satTex.bind();
	ofRotate(ofGetElapsedTimef() * 90.0*0.09, 0, 1, 0);
	saturn.draw();
	satTex.unbind();
	ofPopMatrix();

	//draw uranus
	ofPushMatrix();
	uraTex.bind();
	ofRotate(ofGetElapsedTimef() * 90.0*0.1, 0, 1, 0);
	uranus.draw();
	uraTex.unbind();
	ofPopMatrix();

	//draw neptune
	ofPushMatrix();
	nepTex.bind();
	ofRotate(ofGetElapsedTimef() * 90.0*0.2, 0, 1, 0);
	neptune.draw();
	nepTex.unbind();
	ofPopMatrix();

	//draw a star

	for (int i = 0; i < numStars; i++) {
		ofPushMatrix();
		ofTranslate(starPositions[i]);
		ofRotateXDeg(starRotations[i].x);
		ofRotateZDeg(starRotations[i].z);
		ofRotateYDeg(starRotations[i].y);
		ofScale(starScales[i]);
		mesh.addColor(starColors[i]);
		mesh.drawFaces();
		ofPopMatrix();
	}

	ofDrawAxis(10.0f);

}
