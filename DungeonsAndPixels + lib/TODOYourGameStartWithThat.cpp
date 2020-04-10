    #include "JRGameLib.h"

    int main (){

    ScreenX = 1280; //Set your Length of screen
    ScreenY = 720;  //Set your Weight of screen

    txCreateWindow(ScreenX, ScreenY); //always needed

    ////////////////////////////////////////////
    PlayerPicture PlayerPicture;
    NPCsPosition NPCsPosition;
    preNPCs preNPCs;
    Player Player;
    Global Global;
    MainMenu MainMenu;                // All in(//) is classes methodicals
    BlocksBackground BlocksBackground;
    preNPCs.preLoadNPCs();
    BlocksBackground.preBlock();
    PlayerPicture.checkPic();
    MainMenu.launchBack();
    ///////////////////////////////////////////

    CreatePlayer("HITLER");//YOU MUST CREATE PLAYER
    Global.GameIsRunning = true;//Set game to running

    playerHP = 100;//Set defolt Player Healf Point
    playerMaxHP = 100;//Set MAX Player Healf Point

    int buyer = 0; //For didn`t looping the salerman
    int healing = 0;// For Didn`t looping the use Healing

    PlayerX = 500;//Set defolt Player X
    PlayerY = 250;//Set defolt Player Y
    dmg = 5;//Set Players damage

    //This is first Enemy
    int xEn1 = 800;
    int yEn1 = 300;
    int hpEn1 = 15;
    /////////////////////
    while (Global.GameIsRunning){

        //ALWAYS USE THAT FUNCTION TO SET YOUR PLAYER
        SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                  &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                  &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);


            txSleep (16);//your tickrate (1000 = 1 frame per second)
            //DIDN`T MODIFY
            Global.ticRate++;
            if(Global.ticRate==20){
                Global.animationTicRate++;
                    if(Global.animationTicRate==2){
                        Global.animationTicRate=0;
                    }
               Global.ticRate=0;
            }
            txSetFillColor(TX_BLACK);//or set yours back color
            txClear();
            //////////////

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(GetAsyncKeyState (0x1B))Global.GameIsRunning = false; //use keys in codes (this is code of ESC)
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    }

    //DIDN`T MODIFY
    preNPCs.postDestroyNPCs();
    PlayerPicture.destroyPic();
    MainMenu.deleteBack();
    BlocksBackground.deletHdc();
    ////////////////////////////

    return 0;
    }
