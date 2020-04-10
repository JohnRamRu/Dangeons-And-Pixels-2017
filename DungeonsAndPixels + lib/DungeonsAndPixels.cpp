    #include "JRGameLib.h"

    int main (){

    ScreenX = 1280 ; //Set your Length of screen
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

    //CreatePlayer("LENIN");//YOU MUST CREATE PLAYER
    Global.GameIsRunning = true;//Set game to running

    playerHP = 100;//Set defolt Player Healf Point
    playerMaxHP = 100;//Set MAX Player Healf Point

    int buyer = 0; //For didn`t looping the salerman
    int healing = 0;// For Didn`t looping the use Healing
    bool isMainMenu = true;
    bool author = false;
    int authorK = -50;
    PlayerX = ScreenX/5+64+32;//Set defolt Player X
    PlayerY = ScreenY/2-64-64;//Set defolt Player Y
    dmg = 5;//Set Players damage

    //This is first Enemy

    int xEn1;
    int yEn1;
    int hpEn1;

    int xEn2;
    int yEn2;
    int hpEn2;

    int xEn3;
    int yEn3;
    int hpEn3;

    int xEn4;
    int yEn4;
    int hpEn4;

    //make icon of the JRamLib

    bool dooropen = false;
    int enCount=1;
    dmg = 5;
    int music = 0;

    string name;
    cout << "SET YOUR NAME WITHOUT SPACE: ";
    cin >> name;
    int z = 150;
    while(z>0){
        cout << "\n";
        z--;
    }

    CreatePlayer(name);

    if(GetAsyncKeyState (0x20))!GetAsyncKeyState (0x20);
    if(GetAsyncKeyState (0x1B))!GetAsyncKeyState (0x1B);
    if(GetAsyncKeyState (0x45))!GetAsyncKeyState (0x45);
    if(GetAsyncKeyState (0x01))!GetAsyncKeyState (0x01);
    if(GetAsyncKeyState (0x02))!GetAsyncKeyState (0x02);
    if(GetAsyncKeyState (0x48))!GetAsyncKeyState (0x48);


    txBegin();
    /////////////////////
    while (Global.GameIsRunning){

        while(isMainMenu){

        if (music==0){
        txPlaySound("Music\\music0.wav");
        music++;
        }



        txBitBlt (txDC(), 0, 0, ScreenX, ScreenY, MainMenu.MainMenuBackGround, 0, 0);

        if(Buttons(50, ScreenY/8*5, 93, 118, 203, "NEW GAME")){//NEW GAME
                music=0;
                newLevel = true;
                isMainMenu = false;

                }

        if(Buttons(50, ScreenY/8*6, 93, 118, 203, "AUTHOR")){//AUTHOR
                author = true;
                authorK = 0;
                isMainMenu = false;

                }

        if(Buttons(50, ScreenY/8*7, 93, 118, 203, "EXIT")){//EXIT

                Global.GameIsRunning = false;
                isMainMenu = false;
                txDisableAutoPause();

                }

        txSetFillColor(TX_BLACK);
        txSleep(16);
        txClear();

        if(GetAsyncKeyState (0x20))!GetAsyncKeyState (0x20);
        if(GetAsyncKeyState (0x1B))!GetAsyncKeyState (0x1B);
        }

        while(author){

        if(music==1){
        txPlaySound("Music\\music1.wav");
        music++;
        }

        if(GetAsyncKeyState (0x20)) {
        author = false;
        isMainMenu = true;
        music=0;
        }

            if(GetAsyncKeyState (0x1B))!GetAsyncKeyState (0x1B);
            if(GetAsyncKeyState (0x45))!GetAsyncKeyState (0x45);
            if(GetAsyncKeyState (0x01))!GetAsyncKeyState (0x01);
            if(GetAsyncKeyState (0x02))!GetAsyncKeyState (0x02);
            if(GetAsyncKeyState (0x48))!GetAsyncKeyState (0x48);

        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 30, 0);

        if(NamePlayer == "Hitler" || NamePlayer == "HITLER"){

        txDrawText(ScreenX/10, ScreenY-50-authorK, ScreenX/10*9, ScreenY*2-50-authorK, "\"Great revolutions in this world have never been done with the help of a pen.\n"
                                                                                        "No, we can only provide a theoretical justification for the coup.\n"
                                                                                        "From time immemorial, only the magic power of the oral word was the factor\n"
                                                                                        "that set in motion the great historical avalanches of both a religious and a political nature.\"\n"
                                                                                        "\n"
                                                                                        "Adolf Hitler."
					"\n"
					"\n"
					"\n"
					"\n"
					"\"Thanks to:\n"
                                                                                            "Ilya Dedinskii\n"
                                                                                            "\"Compass+\"\n"
                                                                                            "Andrey Litvin\n"
                                                                                            "My classmates in \"Compass+\" school\n"
                                                                                            "\n"
                                                                                            "\n"
                                                                                            "Thanks for playing! :)", DT_CENTER);


        }else if(NamePlayer == "STALIN" || NamePlayer == "Stalin"){

        txDrawText(ScreenX/20, ScreenY-50-authorK, ScreenX/20*19, ScreenY*2-50-authorK,  "\"Imperialism is the most blatant exploitation and the most inhuman oppression\n"
                                                                                        "of hundreds of millions of people in the vast colonies and dependent countries.\n"
                                                                                        "Squeezing superprofits - this is the purpose of this exploitation and this oppression.\"\n"
                                                                                        "\n"
                                                                                        "Iosif Stalin."
					"\n"
					"\n"
					"\n"
					"\n"
					"\"Thanks to:\n"
                                                                                            "Ilya Dedinskii\n"
                                                                                            "\"Compass+\"\n"
                                                                                            "Andrey Litvin\n"
                                                                                            "My classmates in \"Compass+\" school\n"
                                                                                            "\n"
                                                                                            "\n"
                                                                                            "Thanks for playing! :)", DT_CENTER);

        }else if(NamePlayer == "LENIN" || NamePlayer == "Lenin"){

        txDrawText(ScreenX/20, ScreenY-50-authorK, ScreenX/20*19, ScreenY*2-50-authorK,  "\"Disadvantages of a person, as it were, are a continuation of his merits.\n"
                                                                                        "But if the dignity continues more than necessary, they are not found when it is necessary,\n"
                                                                                        "and not where they should, they are shortcomings.\"\n"
                                                                                        "\n"
                                                                                        "Vladimir Lenin."
					"\n"
					"\n"
					"\n"
					"\n"
					"\"Thanks to:\n"
                                                                                            "Ilya Dedinskii\n"
                                                                                            "\"Compass+\"\n"
                                                                                            "Andrey Litvin\n"
                                                                                            "My classmates in \"Compass+\" school\n"
                                                                                            "\n"
                                                                                            "\n"
                                                                                            "Thanks for playing! :)", DT_CENTER);

        }else if(NamePlayer == "Putin" || NamePlayer == "PUTIN"){

        txDrawText(ScreenX/20, ScreenY-50-authorK, ScreenX/20*19, ScreenY*2-50-authorK, "\"You can not promise everything, all at once.\n"
                                                                                       "You can not turn into promises that promise only to spoil people's brains,\n"
                                                                                       "break through to the authorities,\n"
                                                                                       "and then tackle their own problems without thinking about the fulfillment of unrealistic promises.\"\n"
                                                                                        "\n"
                                                                                        "Vladimir Putin."
					"\n"
					"\n"
					"\n"
					"\n"
					"\"Thanks to:\n"
                                                                                            "Ilya Dedinskii\n"
                                                                                            "\"Compass+\"\n"
                                                                                            "Andrey Litvin\n"
                                                                                            "My classmates in \"Compass+\" school\n"
                                                                                            "\n"
                                                                                            "\n"
                                                                                            "Thanks for playing! :)", DT_CENTER );

        }else{
            txDrawText(ScreenX/20, ScreenY-50-authorK, ScreenX/20*19, ScreenY*2-50-authorK, "\"Thanks to:\n"
                                                                                            "Ilya Dedinskii\n"
                                                                                            "\"Compass+\"\n"
                                                                                            "Andrey Litvin\n"
                                                                                            "My classmates in \"Compass+\" school\n"
                                                                                            "\n"
                                                                                            "\n"
                                                                                            "Thanks for playing! :)", DT_CENTER);
            }
        authorK++;
        txSleep(16);
        txClear();
        }

        srand( time(NULL) );
        int rooms=rand()%3+1;

        int a[rooms];

        if(newLevel&&playerHP>0){

        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        int schet = 4;//    !!!!!!!!!POMENYAT` NA 1 !!!!!!!!!!!!
        while(rooms+2>1){
        srand( time(NULL) );

        a[schet] = rand()%9+1;
        txSleep(5);

        schet++;
        rooms --;
        }
        schet=0;
        int textt=0;
        while(playerHP>0.0||schet<=rooms+2){

        if(textt==0){

                    int integer = schet;
                    string str;
                    ostringstream stream;
                    stream << integer;
                    str = stream.str();
                    char nm[1000];
                    strcpy(nm,str.c_str());


                    int integer2 = floors;
                    string str2;
                    ostringstream stream2;
                    stream2 << integer2;
                    str2 = stream2.str();
                    char nm2[1000];
                    strcpy(nm2,str2.c_str());

                    strcat (nm2, "-");
                    strcat (nm2, nm);

                    string all = "LEVEL\n";//+nm+"/"+nm2



                    char nmAll[10000];
                    strcpy(nmAll,all.c_str());

                    strcat (nmAll, nm2);

                    txSetColor(TX_WHITE);
                    txSelectFont ("Arial", 40, 0, FW_BOLD);
                    txDrawText(ScreenX/2-100, ScreenY/2-150, ScreenX/2+100, ScreenY/2+150, nmAll, DT_CENTER);

                    textt=1;

                    txSleep(2000);
                    txSetFillColor(TX_BLACK);
                    txClear();

                    }

        switch (a[schet]){

        case 0:



                if(RoomWall(768, 576, &BlocksBackground.wallBl_Back1, &BlocksBackground.wallBl_Back, true)){
                    textt=0;
                    schet++;
                    PlayerX = ScreenX/5+64+32;
                    PlayerY = ScreenY/2-64-64;
                }

                SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                            &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                            &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);
                bars();

                drawNPC (ScreenX/5*2+32, ScreenY/4, &Global.animationTicRate, &preNPCs.idle_1_0, &preNPCs.idle_2_0, &buyer);

                break;

        case 1:
               /*if(playerHP<=0){
                isMainMenu = true;
                newLevel = false;
               }  *///xz poshemy ne robit



               if(textt==1){
                    xEn1 = ScreenX/5*2;
                    yEn1 = ScreenY/3+32;
                    hpEn1 = 15;

                    xEn2 = ScreenX/5*3;
                    yEn2 = ScreenY/3+32;
                    hpEn2 = 15;

                    xEn3 = ScreenX/5*3;
                    yEn3 = ScreenY/5*4;
                    hpEn3 = 15;

                    textt=2;
                }

               if(textt==2){
                enCount = 3;
               }

               if(enCount==0){
                    dooropen=true;
               }
               if(RoomWall(768, 576, &BlocksBackground.wallBl_Back1, &BlocksBackground.wallBl_Back, dooropen)){
                    textt=0;
                    schet++;
                    PlayerX = ScreenX/5+64+32;
                    PlayerY = ScreenY/2-64-64;
                    dooropen=false;
                }

                SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                            &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                            &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);
                bars();

                WallBlock(ScreenX/3, ScreenY/4, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3, ScreenY/5*4-32, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3*2, ScreenY/4, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3*2, ScreenY/5*4-32, &BlocksBackground.wallBl_Back);


                drawEnemy(&xEn1, &yEn1, &hpEn1, &dmg, 0, 30, 200, 1.0, 1, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn1<=0 && textt==2){
                enCount--;
                textt=3;
                }
                drawEnemy(&xEn2, &yEn2, &hpEn2, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn2<=0 && textt==3){
                enCount--;
                textt=4;
                }
                drawEnemy(&xEn3, &yEn3, &hpEn3, &dmg, 0, 30, 200, 1.0, 3, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn3<=0 && textt==4){
                enCount--;
                textt=5;
                }

                break;

            case 2:

                if(textt==1){
                    xEn1 = ScreenX/4;
                    yEn1 = ScreenY/3+32;
                    hpEn1 =18;

                    xEn2 = ScreenX/5*4;
                    yEn2 = ScreenY/3+32;
                    hpEn2 =18;

                    xEn3 = ScreenX/5*4;
                    yEn3 = ScreenY/5*4;
                    hpEn3 =18;

                    xEn4 = ScreenX/4;
                    yEn4 = ScreenY/5*4;
                    hpEn4 =18;

                    textt=2;
                }

               if(textt==2){
                enCount = 4;
               }

               if(enCount==0){
                    dooropen=true;
               }
               if(RoomWall(768, 576, &BlocksBackground.wallBl_Back1, &BlocksBackground.wallBl_Back, dooropen)){
                    textt=0;
                    schet++;
                    PlayerX = ScreenX/5+64+32;
                    PlayerY = ScreenY/2-64-64;
                    dooropen=false;
                }

                WallBlock(ScreenX/3, ScreenY/4, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3, ScreenY/5*4, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3*2+25, ScreenY/4, &BlocksBackground.wallBl_Back);
                WallBlock(ScreenX/3*2+25, ScreenY/5*4, &BlocksBackground.wallBl_Back);


                spears(ScreenX/3+64, ScreenY/4, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64, ScreenY/4, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64, ScreenY/4, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64, ScreenY/4, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64+64, ScreenY/4, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64+64+64, ScreenY/4, &Global.ticRate, 3, 15, 20);//right

                spears(ScreenX/3+64*7, ScreenY/4+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64*7, ScreenY/4+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64*7, ScreenY/4+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64*7, ScreenY/4+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64*7, ScreenY/4+64+64+64+64+64, &Global.ticRate, 3, 15, 20);//down in right

                spears(ScreenX/3+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3,  15, 20);
                spears(ScreenX/3+64+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3+64+64+64+64+64+64, ScreenY/4+64+64+64+64+64+64, &Global.ticRate, 3, 15, 20);//down

                spears(ScreenX/3, ScreenY/4+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3, ScreenY/4+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3, ScreenY/4+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3, ScreenY/4+64+64+64+64, &Global.ticRate, 3, 15, 20);
                spears(ScreenX/3, ScreenY/4+64+64+64+64+64, &Global.ticRate, 3, 15, 20);//down in right

                SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                            &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                            &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);
                bars();

                drawEnemy(&xEn1, &yEn1, &hpEn1, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn1<=0 && textt==2){
                enCount--;
                textt=3;
                }
                drawEnemy(&xEn2, &yEn2, &hpEn2, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn2<=0 && textt==3){
                enCount--;
                textt=4;
                }
                drawEnemy(&xEn3, &yEn3, &hpEn3, &dmg, 0, 30, 200, 1.0, 3, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn3<=0 && textt==4){
                enCount--;
                textt=5;
                }
                drawEnemy(&xEn4, &yEn4, &hpEn4, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn4<=0 && textt==5){
                enCount--;
                textt=6;
                }


                break;

            case 3:

                if(textt==1){
                    xEn1 = ScreenX/5*2;
                    yEn1 = ScreenY/2;
                    hpEn1 =20;

                    xEn2 = ScreenX/5*3;
                    yEn2 = ScreenY/2;
                    hpEn2 =20;

                    xEn3 = ScreenX/5*4;
                    yEn3 = ScreenY/5*4;
                    hpEn3 =20;

                    xEn4 = ScreenX/4;
                    yEn4 = ScreenY/5*4;
                    hpEn4 =20;

                    textt=2;
                }

               if(textt==2){
                enCount = 2;
               }

               if(enCount==0){
                    dooropen=true;
               }
               if(RoomWall(768, 576, &BlocksBackground.wallBl_Back1, &BlocksBackground.wallBl_Back, dooropen)){
                    textt=0;
                    schet++;
                    PlayerX = ScreenX/5+64+32;
                    PlayerY = ScreenY/2-64-64;
                    dooropen=false;
                }


                int kk = 8;
                int poY = 0;
                while(kk>0){
                WallBlock(ScreenX/3+25, ScreenY/8+64+poY, &BlocksBackground.wallBl_Back);

                poY+= 64;
                kk--;
                }

                spears(ScreenX/3+25, ScreenY/8, &Global.ticRate, 3,  15, 20);

                kk = 7;
                poY = 0;
                while(kk>=0){
                WallBlock(ScreenX/5*2+64*2-32+25, ScreenY/8+poY, &BlocksBackground.wallBl_Back);

                poY+= 64;
                kk--;
                }

                spears(ScreenX/5*2+64*2-32+25, ScreenY/8+64*8, &Global.ticRate, 3,  15, 20);

                kk = 8;
                poY = 0;
                while(kk>0){
                WallBlock(ScreenX/5*3+25, ScreenY/8+64+poY, &BlocksBackground.wallBl_Back);

                poY+= 64;
                kk--;
                }

                spears(ScreenX/5*3+25, ScreenY/8, &Global.ticRate, 3,  15, 20);


                drawEnemy(&xEn1, &yEn1, &hpEn1, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn1<=0 && textt==2){
                enCount--;
                textt=3;
                }
                drawEnemy(&xEn2, &yEn2, &hpEn2, &dmg, 0, 30, 200, 1.0, 2, 7, ScreenX/4, ScreenY/8, ScreenX/4+768, ScreenY/8+576, &Global.ticRate);
                if(hpEn2<=0 && textt==3){
                enCount--;
                textt=4;
                }


                SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                            &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                            &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);
                bars();


                break;

        //default:break;


        }
        //RoomWall(768, 448, &BlocksBackground.wallBl_Back1, &BlocksBackground.wallBl_Back, &hpEn1);

        if(playerHP<playerMaxHP){

        playerHP +=0.005;

        }
        txSleep(16);
        Global.ticRate++;
            if(Global.ticRate==20){
                Global.animationTicRate++;
                    if(Global.animationTicRate==2){
                        Global.animationTicRate=0;
                    }
               Global.ticRate=0;
            }
        txSetFillColor(TX_BLACK);
        txClear();
        }


        }

        if(playerHP<=0)playerHP=-100;

        if(playerHP<=0){

        txSetColor(TX_RED, 10);
        txSelectFont ("Arial", 190, 0, FW_BOLD);
        txDrawText(ScreenX/4, ScreenY/4, ScreenX/4*3, ScreenY/4*3, "GAME\n"
                                                                    "OVER", DT_CENTER);
        txSleep(5000);

        newLevel=false;
        author = true;
        authorK = 0;
        isMainMenu = false;
        music=1;

        coins=0;
        healing = 0;
        playerHP=100;

        }

        //ALWAYS USE THAT FUNCTION TO SET YOUR PLAYER
        /*SetPlayer(&PlayerX, &PlayerY, &healing, &Global.ticRate, &Global.animationTicRate, &PlayerPicture.idle_1FramePlayer, &PlayerPicture.idle_2FramePlayer, &PlayerPicture.up_1FramePlayer, &PlayerPicture.up_2FramePlayer,
                  &PlayerPicture.down_1FramePlayer, &PlayerPicture.down_2FramePlayer, &PlayerPicture.right_1FramePlayer, &PlayerPicture.right_2FramePlayer, &PlayerPicture.left_1FramePlayer, &PlayerPicture.left_2FramePlayer,
                  &PlayerPicture.atk_1FramePlayer, &PlayerPicture.atk_2FramePlayer, &Player.PP);
         */

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
        //if(GetAsyncKeyState (0x1B))Global.GameIsRunning = false; //use keys in codes (this is code of ESC)
        txDisableAutoPause();
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    }

    //DIDN`T MODIFY
    preNPCs.postDestroyNPCs();
    PlayerPicture.destroyPic();
    MainMenu.deleteBack();
    BlocksBackground.deletHdc();
    txEnd();
    ////////////////////////////

    return 0;
    }

