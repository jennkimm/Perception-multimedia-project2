#include "page.h"

void page::setup() {
	ofDisableArbTex();

	distortShader.load("base.vert", "base.frag");
	page.load("book2.jpg");

	page2.load("book1.png");

	page.getTexture().setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
	page2.getTexture().setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);

	
}

void page::draw() {

	distortShader.begin();

	distortShader.setUniformTexture("tex0", page.getTexture(), 0);
	distortShader.setUniformTexture("tex1", page2.getTexture(), 1);
	distortShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	distortShader.setUniform4f("u_mouse", ofGetMouseX(), ofGetMouseY(), ofGetPreviousMouseX(), ofGetPreviousMouseY());
	distortShader.setUniform1f("u_time", ofGetElapsedTimef());
	ofPushMatrix();
	page.getTexture().bind();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	page.getTexture().unbind();
	ofPopMatrix();

	distortShader.end();
}