#include "simpleExampleEffect.h"

//--------------------------------------------------------------
void simpleExampleEffect::setup() {
	myVideo.load("movie3.mp4");
	myVideo.setUseTexture(true);
	myVideo.play();
	plane.set(820,504);
	plane.setPosition(0,0,-50);
}
void simpleExampleEffect::update() {
	myVideo.update();
} 
void simpleExampleEffect::draw() {
	ofRotate(180);
	plane.draw();
}

void simpleExampleEffect::bind() {
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
void simpleExampleEffect::unbind() {
	myVideo.getTextureReference().unbind();

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------
