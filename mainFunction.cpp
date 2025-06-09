#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "mainHeader.h"
#include "playerHeader.h"
#include "mapHeader.h"
#include "soundHeader.h"

extern maps mapChip[8][22];
extern ply player;
extern int count;
extern int backImg;
extern int footImg;
extern int height;
extern int cloudImg;
extern int backX[2];
extern int backY[2];
extern int sideTitle;
int titleRogoImg;

extern int titleBGM;
extern int playBGM;
extern int clearBGM;
extern int overBGM;
extern int jampSE;
extern int fallSE;
extern int selectSE;
extern int changeSE;

int titleImg;
int rePlayFlag = 0;

double timer[2] = { 0,16000 };
int fontHandle150;
int fontHandle100;
int fontHandle50;
int fontHandle30;

void fontSet()
{
    fontHandle150 = CreateFontToHandle(NULL, 150, 6);
    fontHandle100 = CreateFontToHandle(NULL, 100, 6);
    fontHandle50 = CreateFontToHandle(NULL, 50, 6);
    fontHandle30 = CreateFontToHandle(NULL, 30, 6);
}
void title()
{
    int i = 0;
    int y[2] = { 0 };
    int checker = 0;
    y[1] = -2496;
    cloudImg = LoadGraph("img/cloud.png");
    titleImg = LoadGraph("img/title.png");
    titleRogoImg = LoadGraph("img/titleRogo.png");
    rePlayFlag = 0;
    PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP);
    while (1)
    {
        timer[0] = GetNowHiPerformanceCount();
        if (y[0] >= 2496)
        {
            for (i = 0; i < 2; i++)
            {
                y[i] -= 2496;
            }
        }
        DrawGraph(0, y[0], titleImg, TRUE);
        DrawGraph(0, y[1], titleImg, TRUE);
        for (i = 0; i < 2; i++)
        {
            y[i] += 30;
        }
        DrawGraph(520, 200, titleRogoImg, TRUE);
        DrawStringToHandle(0, 0, "クリアBGM：魔王魂", GetColor(0, 0, 0), fontHandle30, FALSE);
        DrawStringToHandle(500, 800, "START", GetColor(255, 100, 0), fontHandle100, TRUE);
        DrawStringToHandle(1200, 800, "END", GetColor(255, 100, 0), fontHandle100, TRUE);
        if (rePlayFlag == 0)
        {
            DrawTriangle(450, 800, 450, 900, 490, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 1;
            }
        }
        if (rePlayFlag == 1)
        {
            DrawTriangle(1150, 800, 1150, 900, 1190, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 0;
            }
        }
        while (GetNowHiPerformanceCount() - timer[0] < timer[1])
        {

        }
        if (checker == 0 )
        {
            if (CheckHitKey(KEY_INPUT_SPACE) == 0)
            {
                checker = 1;
            }
        }
        else
        {
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                PlaySoundMem(selectSE, DX_PLAYTYPE_BACK);
                ClearDrawScreen();
                break;
            }
        }
        ScreenFlip();
        ClearDrawScreen();
    }
    StopSoundMem(titleBGM);
}
void gameOver()
{
    int blend = 255;
    int counter = 0;
    rePlayFlag = 0;
    PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP);
    while (1)
    {
        ClearDrawScreen();
        player.y -= 2;
        timer[0] = GetNowHiPerformanceCount();
        map();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);
        if (counter == 1)
        {
            blend--;
            counter = 0;
        }
        else
        {
            counter++;
        }
        DrawGraph(player.x, player.y, player.img, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        DrawFormatStringToHandle(1250, 100, GetColor(255, 255, 255), fontHandle100, "%d", height / 10);
        DrawStringToHandle(1220, 50, "height", GetColor(255, 255, 255), fontHandle30, TRUE);
        DrawStringToHandle(350, 300, "G A M E O V E R", GetColor(255, 0, 255), fontHandle150, TRUE);
        DrawStringToHandle(500, 800, "REPLAY", GetColor(255, 100, 0), fontHandle100, TRUE);
        DrawStringToHandle(1200, 800, "TITLE", GetColor(255, 100, 0), fontHandle100, TRUE);
        DrawBox(360, 0, 1540, 20, GetColor(0, 0, 0), TRUE);
        DrawBox(360, 1060, 1540, 1080, GetColor(0, 0, 0), TRUE);
        if (rePlayFlag == 0)
        {
            DrawTriangle(450, 800, 450, 900, 490, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 1;
            }
        }
        if (rePlayFlag == 1)
        {
            DrawTriangle(1150, 800, 1150, 900, 1190, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 0;
            }
        }
        while (GetNowHiPerformanceCount() - timer[0] < timer[1])
        {

        }
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            PlaySoundMem(selectSE, DX_PLAYTYPE_BACK);
            break;
        }
        ScreenFlip();
    }
    StopSoundMem(overBGM);
}
void gameClear()
{
    int playTime = 0;
    int playTimeFlag = 0;
    rePlayFlag = 0;
    PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP);
    player.y = mapChip[0][21].y -151;
    while (1)
    {
        ClearDrawScreen();
        timer[0] = GetNowHiPerformanceCount();
        mapAna();
        player.x += 5;
        if (playTime <= 0)
        {
            playTimeFlag = 0;
        }
        if (playTime >= 20)
        {
            playTimeFlag = 1;
        }
        if (playTimeFlag == 0)
        {
            DrawGraph(player.x, player.y, player.img, TRUE);
            playTime++;
        }
        else
        {
            DrawTurnGraph(player.x, player.y, player.img, TRUE);
            playTime--;
        }
        DrawBox(1181, 0, 1560, 1080, GetColor(0, 0, 0), TRUE);
        DrawGraph(1560, 0, sideTitle, TRUE);
        DrawFormatStringToHandle(1250, 100, GetColor(255, 255, 255), fontHandle100, "%d", height / 10);
        DrawStringToHandle(1220, 50, "height", GetColor(255, 255, 255), fontHandle30, TRUE);
        DrawStringToHandle(300, 300, "G A M E C L E A R", GetColor(255, 0, 255), fontHandle150, TRUE);
        DrawStringToHandle(500, 800, "REPLAY", GetColor(255, 100, 0), fontHandle100, TRUE);
        DrawStringToHandle(1200, 800, "TITLE", GetColor(255, 100, 0), fontHandle100, TRUE);
        if (rePlayFlag == 0)
        {
            DrawTriangle(450, 800, 450, 900, 490, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 1;
            }
        }
        if (rePlayFlag == 1)
        {
            DrawTriangle(1150, 800, 1150, 900, 1190, 850, GetColor(255, 100, 0), TRUE);
            if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
                rePlayFlag = 0;
            }
        }
        while (GetNowHiPerformanceCount() - timer[0] < timer[1])
        {

        }
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            PlaySoundMem(selectSE, DX_PLAYTYPE_BACK);
            break;
        }
        ScreenFlip();
    }
    StopSoundMem(clearBGM);
}
void gameMain()
{
    while (1)
    {
        PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP);
        firstMap();
        playerSet();
        mapSet();
        int i, j;
        int flg = 0;
        int sum = 0;
        while (1)
        {
            ClearDrawScreen();
            map();
            DrawGraph(player.x, player.y, player.img, TRUE);
            DrawFormatStringToHandle(1250, 100, GetColor(255, 255, 255), fontHandle100, "%d", height / 10);
            DrawStringToHandle(1220, 50, "height", GetColor(255, 255, 255), fontHandle30, TRUE);
            DrawBox(360, 0, 1540, 20, GetColor(0, 0, 0), TRUE);
            timer[0] = GetNowHiPerformanceCount();
            if (sum == 0 || sum == 60 || sum == 120)
            {
                PlaySoundMem(changeSE, DX_PLAYTYPE_BACK);
            }
            else if (sum == 180)
            {
                PlaySoundMem(selectSE, DX_PLAYTYPE_BACK);
            }
            if (sum < 60)
            {
                DrawStringToHandle(740,540,"3",GetColor(255, 0, 0), fontHandle150, TRUE);
            }
            else if (sum < 120)
            {
                DrawStringToHandle(740, 540, "2", GetColor(255, 0, 0), fontHandle150, TRUE);
            }
            else if (sum < 180)
            {
                DrawStringToHandle(740, 540, "1", GetColor(255, 0, 0), fontHandle150, TRUE);
            }
            else if(sum < 240)
            {
                DrawStringToHandle(600, 540, "START", GetColor(255, 0, 0), fontHandle150, TRUE);
            }
            else
            {
                break;
            }
            sum++;
            while (GetNowHiPerformanceCount() - timer[0] < timer[1])
            {

            }
            ScreenFlip();
        }
        while (1)
        {
            timer[0] = GetNowHiPerformanceCount();
            playerMove();
            wallLoop();
            ClearDrawScreen();
            map();
            DrawGraph(player.x, player.y, player.img, TRUE);
            DrawFormatStringToHandle(1250, 100, GetColor(255, 255, 255), fontHandle100, "%d", height / 10);
            DrawStringToHandle(1220, 50, "height", GetColor(255, 255, 255), fontHandle30, TRUE);
            DrawBox(360, 0, 1540, 20, GetColor(0, 0, 0), TRUE);
            while (GetNowHiPerformanceCount() - timer[0] < timer[1])
            {

            }
            if (player.y > 919)
            {
                StopSoundMem(playBGM);
                ClearDrawScreen();
                gameOver();
                break;
            }
            if (height >= 50000)
            {
                for (i = 0; i < 8; i++)
                {
                    mapChip[i][21].flag = 0;
                    mapChip[i][21].x = 100 * i + 380;
                    mapChip[i][21].y = 50 * 0 + 20;
                    DrawGraph(mapChip[i][21].x, mapChip[i][21].y, footImg, TRUE);
                }
                while (1)
                {
                    timer[0] = GetNowHiPerformanceCount();
                    playerAnaMove();
                    wallLoop();
                    ClearDrawScreen();
                    mapAna();
                    DrawGraph(player.x, player.y, player.img, TRUE);
                    DrawFormatStringToHandle(1250, 100, GetColor(255, 255, 255), fontHandle100, "%d", height / 10);
                    DrawStringToHandle(1220, 50, "height", GetColor(255, 255, 255), fontHandle30, TRUE);
                    DrawBox(360, 0, 1540, 20, GetColor(0, 0, 0), TRUE);
                    DrawBox(360, 1060, 1540, 1080, GetColor(0, 0, 0), TRUE);
                    while (GetNowHiPerformanceCount() - timer[0] < timer[1])
                    {

                    }
                    if ((mapChip[0][21].y >= 600))
                    {
                        for (i = 0; i < 8; i++)
                        {
                            if (player.x + 35 - 11 >= mapChip[i][21].x - 20 && player.x + 35 + 12 <= mapChip[i][21].x + 100 + 20
                                && player.y + 151 >= mapChip[i][21].y && player.y + 151 <= mapChip[i][21].y + 35)
                            {
                                StopSoundMem(playBGM);
                                ClearDrawScreen();
                                gameClear();
                                flg = 1;
                                break;
                            }
                        }
                        if (flg == 1)
                        {
                            break;
                        }
                    }
                    if (player.y > 919)
                    {
                        StopSoundMem(playBGM);
                        ClearDrawScreen();
                        gameOver();
                        break;
                    }
                    ScreenFlip();
                }
                break;
            }
            ScreenFlip();
        }
        //データの初期化
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 22; j++)
            {
                mapChip[i][j].flag = 1;
            }
        }
        height = 0;
        count = 0;
        if (rePlayFlag == 1)//Title
        {
            break;
        }
    }
}

void end()
{
    int i, j;
    if (rePlayFlag == 1)//END
    {
        //メモリの開放
        DeleteGraph(player.img);
        DeleteGraph(footImg);
        DeleteGraph(backImg);
        DeleteGraph(titleImg);
        DeleteGraph(cloudImg);
        DeleteGraph(titleRogoImg);
        DeleteGraph(sideTitle);
        InitSoundMem();
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 22; j++)
            {
                mapChip[i][j].flag = 0;
                mapChip[i][j].x = 0;
                mapChip[i][j].y = 0;
            }
        }
        player.xSpeed = 0;
        player.x = 0;
        player.y = 0;
        count = 0;
        rePlayFlag = 0;
        height = 0;
        for (i = 0; i < 2; i++)
        {
            backX[i] = 0;
            backY[i] = 0;
            timer[i] = 0;
        }
    }
}