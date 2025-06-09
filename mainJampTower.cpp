#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "mainHeader.h"
#include "playerHeader.h"
#include "mapHeader.h"
#include "soundHeader.h"

extern int rePlayFlag;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //変数宣言

    //画像読み込み
    // 画面モードの設定
    SetGraphMode(1920, 1080, 16);


    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが発生したら終了
    }
    fontSet();
    soundSet();
    while (1)
    {
        title();
        if (rePlayFlag == 1)
        {
            break;
        }
        gameMain();
    }
    end();

    DxLib_End();
    return 0;
}