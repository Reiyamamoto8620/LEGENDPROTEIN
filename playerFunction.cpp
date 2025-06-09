#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "mainHeader.h"
#include "playerHeader.h"
#include "mapHeader.h"
#include "soundHeader.h"

ply player;
int count = 0;
extern maps mapChip[8][22];
extern int backY[2];
extern int jampSE;
int height = 0;
//プレイヤー設定
void playerSet()
{
	player.xSpeed = 5;
	player.x = 380 + 400 - 35;
	player.y = 875;
	player.img = LoadGraph("img/MrSideChast.png");
}

void playerMove()
{
	int i, j;
	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
	{
		player.x -= player.xSpeed * 2;
	}
	if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.x += player.xSpeed * 2;
	}
	playerCollsion();
	if (count > 0)
	{
		player.y += count;
		height -= count;
	}
	else
	{
		if (player.y > 350)
		{
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 22; j++)
				{
					mapChip[i][j].y -= count / 2;
				}
			}
			player.y += count / 2;
			for (i = 0; i < 2; i++)
			{
				backY[i] -= count / 2;
			}
			height -= count;
		}
		else
		{
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 22; j++)
				{
					mapChip[i][j].y -= count;
				}
			}
			for (i = 0; i < 2; i++)
			{
				backY[i] -= count;
			}
			height -= count;
		}
	}
}

void playerCollsion()
{
	int i, j;
	//足判定サイズ23
	if (count > 0)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 21; j++)
			{
				if (mapChip[i][j].flag == 0)
				{
					if (player.x + 35 - 11 > mapChip[i][j].x - 20 && player.x + 35 + 12 < mapChip[i][j].x + 100 + 20
						&& player.y + 151 > mapChip[i][j].y  -5 && player.y + 151 < mapChip[i][j].y + 35)
					{
						count = -40;
					}
				}
			}
		}
		if (count == -40)
		{
			PlaySoundMem(jampSE, DX_PLAYTYPE_BACK);
		}
		count += 2;
	}
	else
	{
		count += 2;
	}
}

void wallLoop()
{
	if (player.x > 1110)
	{
		player.x = 380;
	}
	if (player.x < 380)
	{
		player.x = 1110;
	}
}

void playerAnaMove()
{
	int i, j;
	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
	{
		player.x -= player.xSpeed * 2;
	}
	if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.x += player.xSpeed * 2;
	}
	playerCollsion();
	if ((mapChip[0][21].y > 600))
	{
		player.y += count ; 
		height -= count ;
	}
	else
	{
		if (count > 0)
		{
			player.y += count;
			height -= count;
		}
		else
		{
			if (player.y > 350)
			{
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 22; j++)
					{
						mapChip[i][j].y -= count / 2;
					}
				}
				player.y += count / 2;
				for (i = 0; i < 2; i++)
				{
					backY[i] -= count / 2;
				}
				height -= count;
			}
			else
			{
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 22; j++)
					{
						mapChip[i][j].y -= count;
					}
				}
				for (i = 0; i < 2; i++)
				{
					backY[i] -= count;
				}
				height -= count;
			}

		}
	}
}