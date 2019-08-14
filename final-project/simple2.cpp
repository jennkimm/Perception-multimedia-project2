#include "simple2.h"

//--------------------------------------------------------------
void simple2::setup() {
	myVideo.load("movie1.mp4");
	myVideo.setUseTexture(true);
	myVideo.play();
	plane.set(820,504);
	plane.setPosition(0,0,-50);
}
void simple2::update() {
	myVideo.update();
} 
void simple2::draw() {
	ofRotate(180);
	plane.draw();
}

void simple2::bind() {
	ofTexture &tex = myVideo.getTextureReference();
	tex.bind();

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	ofTextureData texData = tex.getTextureData();
	if (texData.textureTarget == GL_TEXTURE_RECTANGLE_ARB) {
		glScalef(tex.getWidth(), tex.getHeight(), 1.0f);
	}
	else {
		glScalef(tex.getWidth() / texData.tex_w, tex.getHeight() / texData.tex_h, 1.0f);
	}

	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------
void simple2::unbind() {
	myVideo.getTextureReference().unbind();

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------
