#include "DxLib.h"

int titleBGM;
int playBGM;
int clearBGM;
int overBGM;

int jampSE;
int selectSE;
int changeSE;

void soundSet()
{
    titleBGM = LoadSoundMem("sound/title.wav");
    playBGM = LoadSoundMem("sound/play.wav");
    clearBGM = LoadSoundMem("sound/clear.mp3");
    overBGM = LoadSoundMem("sound/dead.wav");
    jampSE = LoadSoundMem("sound/jump.mp3");
    selectSE = LoadSoundMem("sound/select.mp3");
    changeSE = LoadSoundMem("sound/selectChange.mp3");
}

