#include "Cube.h"


//#include <stdio.h>
//#include <Math.h>

Texture* myTexture;
Mesh* myMesh;

void setup_program()
{
	myTexture = new Texture();
	myTexture->load("ey");
}

void draw_program()
{
	myPlayer.update();

	background(0, 0, 0, 1.0f);
	pushMap(0, 0, -3.0);
	myTexture->render(0, 0, 1.0, 1.0);
}

bool Player::isPlayerMouse()
{
	float mx = mouseX / float(WIDTH);
	float my = mouseY / float(HEIGHT);
	return mx < 0.3 && my>0.6;
}
void Player::move2D(float add_ang, float speed)
{

	float ang = angx + add_ang;
	//pz -= speed * cosf(ang);
	//px += speed * sin(ang);
}

#include <iostream>
#include <cmath>

int mainii()
{

}