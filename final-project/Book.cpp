#include "Book.h"
#include "ofMain.h"

void Book::setup() {
	ofDisableArbTex();
	ofDisableAlphaBlending();
	ofEnableDepthTest();

	//front
	for (int i = 0; i < 4; ++i) {
		mesh.addVertex(vec3(vdata[i][0], vdata[i][1], vdata[i][2]));
	}

	for (int i = 0; i < 2; ++i) {
		mesh.addIndex(indices[i][0]);
		mesh.addIndex(indices[i][1]);
		mesh.addIndex(indices[i][2]);
	}

	mesh.addTexCoord(vec2(0, 1));
	mesh.addTexCoord(vec2(1, 1));
	mesh.addTexCoord(vec2(1, 0));
	mesh.addTexCoord(vec2(0, 0));

	//back
	for (int i = 4; i < 8; ++i) {
		mesh2.addVertex(vec3(vdata[i][0], vdata[i][1], vdata[i][2]));
	}

	for (int i = 0; i < 2; ++i) {
		mesh2.addIndex(indices[i][0]);
		mesh2.addIndex(indices[i][1]);
		mesh2.addIndex(indices[i][2]);
	}

	mesh2.addTexCoord(vec2(1, 1));
	mesh2.addTexCoord(vec2(0, 1));
	mesh2.addTexCoord(vec2(0, 0));
	mesh2.addTexCoord(vec2(1, 0));

	//right
	mesh3.addVertex(vec3(vdata[1][0], vdata[1][1], vdata[1][2]));
	mesh3.addVertex(vec3(vdata[5][0], vdata[5][1], vdata[5][2]));
	mesh3.addVertex(vec3(vdata[6][0], vdata[6][1], vdata[6][2]));
	mesh3.addVertex(vec3(vdata[2][0], vdata[2][1], vdata[2][2]));

	for (int i = 0; i < 2; ++i) {
		mesh3.addIndex(indices[i][0]);
		mesh3.addIndex(indices[i][1]);
		mesh3.addIndex(indices[i][2]);
	}

	mesh3.addTexCoord(vec2(0, 1));
	mesh3.addTexCoord(vec2(0.45, 1));
	mesh3.addTexCoord(vec2(0.45, 0));
	mesh3.addTexCoord(vec2(0, 0));

	//left
	mesh4.addVertex(vec3(vdata[4][0], vdata[4][1], vdata[4][2]));
	mesh4.addVertex(vec3(vdata[0][0], vdata[0][1], vdata[0][2]));
	mesh4.addVertex(vec3(vdata[3][0], vdata[3][1], vdata[3][2]));
	mesh4.addVertex(vec3(vdata[7][0], vdata[7][1], vdata[7][2]));

	for (int i = 0; i < 2; ++i) {
		mesh3.addIndex(indices[i][0]);
		mesh3.addIndex(indices[i][1]);
		mesh3.addIndex(indices[i][2]);
	}

	mesh4.addTexCoord(vec2(0, 1));
	mesh4.addTexCoord(vec2(0.4, 1));
	mesh4.addTexCoord(vec2(0.4, 0));
	mesh4.addTexCoord(vec2(0, 0));

	//top
	mesh5.addVertex(vec3(vdata[3][0], vdata[3][1], vdata[3][2]));
	mesh5.addVertex(vec3(vdata[2][0], vdata[3][1], vdata[2][2]));
	mesh5.addVertex(vec3(vdata[6][0], vdata[2][1], vdata[6][2]));
	mesh5.addVertex(vec3(vdata[7][0], vdata[7][1], vdata[7][2]));

	for (int i = 0; i < 2; ++i) {
		mesh5.addIndex(indices[i][0]);
		mesh5.addIndex(indices[i][1]);
		mesh5.addIndex(indices[i][2]);
	}

	mesh5.addTexCoord(vec2(0, 0.36));
	mesh5.addTexCoord(vec2(1, 0.36));
	mesh5.addTexCoord(vec2(1, 0));
	mesh5.addTexCoord(vec2(0, 0));

	//bottom
	mesh6.addVertex(vec3(vdata[0][0], vdata[0][1], vdata[0][2]));
	mesh6.addVertex(vec3(vdata[1][0], vdata[1][1], vdata[1][2]));
	mesh6.addVertex(vec3(vdata[5][0], vdata[5][1], vdata[5][2]));
	mesh6.addVertex(vec3(vdata[4][0], vdata[4][1], vdata[4][2]));

	for (int i = 0; i < 2; ++i) {
		mesh6.addIndex(indices[i][0]);
		mesh6.addIndex(indices[i][1]);
		mesh6.addIndex(indices[i][2]);
	}

	mesh6.addTexCoord(vec2(0, 0.3));
	mesh6.addTexCoord(vec2(1, 0.3));
	mesh6.addTexCoord(vec2(1, 0));
	mesh6.addTexCoord(vec2(0, 0));


	texture.loadImage("book_front.jpg");
	texture.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);

	texture2.loadImage("book_back.jpg");
	texture2.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture2.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);

	texture3.loadImage("book_right.jpg");
	texture3.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture3.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);

	texture4.loadImage("book_left.jpg");
	texture4.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture4.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);

	texture5.loadImage("book_top.jpg");
	texture5.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture5.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);

	texture6.loadImage("book_bottom.jpg");
	texture6.getTextureReference().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
	texture6.getTextureReference().setTextureWrap(GL_LINEAR, GL_LINEAR);


	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh2.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh3.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh4.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	mesh5.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	mesh6.setMode(OF_PRIMITIVE_TRIANGLE_FAN);

}

void Book::draw() {
	
	
	texture.bind();
	mesh.draw();
	texture.unbind();

	texture2.bind();
	mesh2.draw();
	texture2.unbind();

	texture3.bind();
	mesh3.draw();
	texture3.unbind();

	texture4.bind();
	mesh4.draw();
	texture4.unbind();

	texture5.bind();
	mesh5.draw();
	texture5.unbind();

	texture6.bind();
	mesh6.draw();
	texture6.unbind();


}
