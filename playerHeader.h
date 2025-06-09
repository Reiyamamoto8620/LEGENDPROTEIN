#pragma once

struct ply
{
	int x;
	int y;
	int xSpeed;
	int HP;
	int img;
};



void playerSet();
void playerMove();
void playerCollsion();
void wallLoop();
void playerAnaMove();