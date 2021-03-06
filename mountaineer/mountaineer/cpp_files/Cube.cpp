#include "../header_files/Cube.hpp"
#include <cstdio>

extern Camera myCamera;
//extern GLint shading;
//extern GLint GLface;
//extern GLint textured;
//extern GLint GLlighting;

//extern Light myLight;
Cube::Cube()
{  
	vertex[0][0] = -1; vertex[0][1] = -1; vertex[0][2] = -1;
	vertex[1][0] = -1; vertex[1][1] = 1; vertex[1][2] = -1;
	vertex[2][0] = 1; vertex[2][1] = 1; vertex[2][2] = -1;
	vertex[3][0] = 1; vertex[3][1] = -1; vertex[3][2] = -1;
	vertex[4][0] = -1; vertex[4][1] = -1; vertex[4][2] = 1;
	vertex[5][0] = -1; vertex[5][1] = 1; vertex[5][2] = 1;
	vertex[6][0] = 1; vertex[6][1] = 1; vertex[6][2] = 1;
	vertex[7][0] = 1; vertex[7][1] = -1; vertex[7][2] = 1;

	face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
	face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
	face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
	face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

	faceColor[0][0] = 1.0; faceColor[0][1] = 1.0; faceColor[0][2] = 0.0;
	faceColor[1][0] = 1.0; faceColor[1][1] = 0.0; faceColor[1][2] = 0.0;
	faceColor[2][0] = 1.0; faceColor[2][1] = 1.0; faceColor[2][2] = 0.0;
	faceColor[3][0] = 1.0; faceColor[3][1] = 0.0; faceColor[3][2] = 0.0;
	faceColor[4][0] = 1.0; faceColor[4][1] = 1.0; faceColor[4][2] = 0.0;
	faceColor[5][0] = 1.0; faceColor[5][1] = 0.0; faceColor[5][2] = 0.0;

	faceNormal[0][0] = 0.0; faceNormal[0][1] = 0.0; faceNormal[0][2] = -1.0;
	faceNormal[1][0] = 0.0; faceNormal[1][1] = 0.0; faceNormal[1][2] = 1.0;
	faceNormal[2][0] = -1.0; faceNormal[2][1] = 0.0; faceNormal[2][2] = 0.0;
	faceNormal[3][0] = 0.0; faceNormal[3][1] = 1.0; faceNormal[3][2] = 0.0;
	faceNormal[4][0] = 1.0; faceNormal[4][1] = 0.0; faceNormal[4][2] = 0.0;
	faceNormal[5][0] = 0.0; faceNormal[5][1] = -1.0; faceNormal[5][2] = 0.0;
	
    r = 1.0; g = 1.0; b = 1.0;
}



void Cube::draw_face(int i)
{
    glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);

	glBegin(GL_POLYGON);
	glVertex3fv(vertex[face[i][0]]);
	glVertex3fv(vertex[face[i][1]]);
	glVertex3fv(vertex[face[i][2]]);
	glVertex3fv(vertex[face[i][3]]);
	glEnd();
}




void Cube::drawMC()
{
	for(int face_index = 0; face_index < 6; face_index++) {
		if(isFrontface(face_index, myCamera)) {
			draw_face(face_index);
		}
	}
}

void Cube::draw()
{
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    for(int face_index = 0; face_index < 6; face_index++) {
    	if(isFrontface(face_index, myCamera)) {
    		draw_face(face_index);
    	}

    }
    glPopMatrix();
}


bool Cube::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;

	mc.multiplyVector(v);
	return (camera.ref.x - camera.eye.x)*v[0] + (camera.ref.y - camera.eye.y)*v[1] + (camera.ref.z - camera.eye.z) *v[2] < 0;


}




