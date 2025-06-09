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
    //�ϐ��錾

    //�摜�ǂݍ���
    // ��ʃ��[�h�̐ݒ�
    SetGraphMode(1920, 1080, 16);


    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[������������I��
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