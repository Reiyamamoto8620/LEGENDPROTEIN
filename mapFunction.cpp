#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "mainHeader.h"
#include "playerHeader.h"
#include "mapHeader.h"

maps mapChip[8][22];

int backImg;
int footImg;
int cloudImg;
int sideTitle;
int backY[2] = { 20 ,-1020 };
int backX[2] = { 380,1180 };

void mapSet()
{
    backImg = LoadGraph("img/towerWall.png");
    footImg = LoadGraph("img/footing.png");
    sideTitle = LoadGraph("img/rogo2.png");
}

void map()
{
    int i, j, x;

    if (backY[0] >= 1060)
    {
        for (i = 0; i < 2; i++)
        {
            backY[i] -= 1040;
        }
    }
    DrawBox(380, 20, 1180, 1060, GetColor(0, 0, 255), TRUE);
    srand((unsigned int)time(NULL));
    //‰æ‘œ•\Ž¦
    DrawBox(360, 0, 1560, 1080, GetColor(255, 255, 255), TRUE);
    if (backX[0] <= -420)
    {
        for (i = 0; i < 2; i++)
        {
            backX[i] += 800;
        }
    }
    for (i = 0; i < 2; i++)
    {
        backX[i] -= 2;
        DrawGraph(backX[i], 20, cloudImg, TRUE);
    }
    for (i = 0; i < 2; i++)
    {
        DrawGraph(380, backY[i], backImg, TRUE);
    }
    DrawBox(1220, 400, 1520, 1000, GetColor(255, 0, 0), TRUE);

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 21; j++)
        {
            if (mapChip[i][j].y > 1040)
            {
                x = rand() % 8;
                x = i + x;
                if (x > 7)
                {
                    x = x - 7;
                }
                mapChip[i][j].x = 100 * x + 380;
                mapChip[i][j].y = 20;
            }
            if (mapChip[i][j].flag == 0)
            {
                DrawGraph(mapChip[i][j].x, mapChip[i][j].y, footImg, TRUE);
            }
        }
    }
    DrawBox(360, 0, 1560, 20, GetColor(0, 0, 0), TRUE);
    DrawBox(360, 1060, 1560, 1080, GetColor(0, 0, 0), TRUE);
    DrawBox(0, 0, 380, 1080, GetColor(0, 0, 0), TRUE);
    DrawBox(1180, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
    DrawGraph(0, 0, sideTitle, TRUE);
    DrawGraph(1560, 0, sideTitle, TRUE);
}

void firstMap()
{
    srand((unsigned int)time(NULL));
    int i, j;
    int num;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 8; j++)
        {
            mapChip[j][i].flag = rand() % 15;
            if (mapChip[j][i].flag == 0)
            {
                mapChip[j][i].x = 100 * j + 380;
                mapChip[j][i].y = 50 * i + 20;
                DrawGraph(mapChip[j][i].x, mapChip[j][i].y, footImg, TRUE);
            }
            else
            {
                num++;
            }
        }
        if (num == 40)
        {
            num = 0;
            j = rand() % 4 + 2;
            mapChip[j][i].flag = 0;
            mapChip[j][i].x = 100 * j + 380;
            mapChip[j][i].y = 50 * i + 20;
            DrawGraph(mapChip[j][i].x, mapChip[j][i].y, footImg, TRUE);
        }
    }
    for (i = 3; i < 5; i++)
    {
        mapChip[i][20].flag = 0;
        mapChip[i][20].x = 100 * i + 380;
        mapChip[i][20].y = 50 * 20 + 20;
        DrawGraph(mapChip[i][20].x, mapChip[i][20].y, footImg, TRUE);
    }
    for (i = 14; i < 18; i += 2)
    {
        j = rand() % 4 + 2;
        mapChip[j][i].flag = 0;
        mapChip[j][i].x = 100 * j + 380;
        mapChip[j][i].y = 50 * i + 20;
        DrawGraph(mapChip[j][i].x, mapChip[j][i].y, footImg, TRUE);
    }
}

void mapAna()
{
    int i, j, x;

    if (backY[0] >= 1060)
    {
        for (i = 0; i < 2; i++)
        {
            backY[i] -= 1040;
        }
    }
    DrawBox(380, 20, 1180, 1060, GetColor(0, 0, 255), TRUE);
    srand((unsigned int)time(NULL));
    //‰æ‘œ•\Ž¦
    DrawBox(360, 0, 1560, 1080, GetColor(255, 255, 255), TRUE);
    if (backX[0] <= -420)
    {
        for (i = 0; i < 2; i++)
        {
            backX[i] += 800;
        }
    }
    for (i = 0; i < 2; i++)
    {
        backX[i] -= 2;
        DrawGraph(backX[i], 20, cloudImg, TRUE);
    }
    for (i = 0; i < 2; i++)
    {
        DrawGraph(380, backY[i], backImg, TRUE);
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 22; j++)
        {
            if (mapChip[i][j].flag == 0)
            {
                DrawGraph(mapChip[i][j].x, mapChip[i][j].y, footImg, TRUE);
            }
        }
    }
    DrawBox(1220, 400, 1520, 1000, GetColor(255, 0, 0), TRUE);
    DrawBox(360, 0, 1560, 20, GetColor(0, 0, 0), TRUE);
    DrawBox(360, 1060, 1560, 1080, GetColor(0, 0, 0), TRUE);
    DrawBox(0, 0, 380, 1080, GetColor(0, 0, 0), TRUE);
    DrawBox(1180, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
    DrawGraph(0, 0, sideTitle, TRUE);
    DrawGraph(1560, 0, sideTitle, TRUE);
}