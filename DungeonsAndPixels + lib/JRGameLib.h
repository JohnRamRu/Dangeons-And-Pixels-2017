    #include "TXLib.h"
    #include <iostream>
    #include "string.h"
    #include <iostream> //нужен для вывода строк "cout<<"
    #include "conio.h" //нужен намеренно для "getche()", а не "cin>>"
    #include "windows.h"
    #include <cstdlib>
    #include<string>
    #include<sstream>

    using namespace std;




/////////////////////
                   //GLOBAL
    string NamePlayer = "DOYOURNAME";
    int PlayerX;
    int PlayerY;


    int ScreenX;
    int ScreenY;

    int floors = 0;
    float playerHP;
    int playerMaxHP;
    int coins = 30;
    int healers = 0;
    int dmg;
    bool newLevel=false;

            //CLASSES (CAN MODIFY TO ADD YOUR TEXTURE)
/////////////////////
    class PlayerPicture{


    public:


        const char* atk_1=("PlayerBox\\atk_1.bmp");
        const char* atk_2=("PlayerBox\\atk_2.bmp");

        const char* idle_1=("PlayerBox\\idle_1.bmp");
        const char* idle_2=("PlayerBox\\idle_2.bmp");
        const char* up_1=("PlayerBox\\up_1.bmp");
        const char* up_2=("PlayerBox\\up_2.bmp");
        const char* down_1=("PlayerBox\\down_1.bmp");
        const char* down_2=("PlayerBox\\down_2.bmp");
        const char* right_1=("PlayerBox\\right_1.bmp");
        const char* right_2=("PlayerBox\\right_2.bmp");
        const char* left_1=("PlayerBox\\left_1.bmp");
        const char* left_2=("PlayerBox\\left_2.bmp");

        HDC atk_1FramePlayer;
        HDC atk_2FramePlayer;

        HDC  idle_1FramePlayer;
        HDC  idle_2FramePlayer;
        HDC  up_1FramePlayer;
        HDC  up_2FramePlayer;
        HDC  down_1FramePlayer;
        HDC  down_2FramePlayer;
        HDC  right_1FramePlayer;
        HDC  right_2FramePlayer;
        HDC  left_1FramePlayer;
        HDC  left_2FramePlayer;

        int k=0;
        int kend =0;
            void checkPic(){
                while(k==0){
                atk_1FramePlayer = txLoadImage(atk_1);
                atk_2FramePlayer = txLoadImage(atk_2);

                idle_1FramePlayer = txLoadImage (idle_1);
                idle_2FramePlayer = txLoadImage (idle_2);
                up_1FramePlayer = txLoadImage (up_1);
                up_2FramePlayer = txLoadImage (up_2);
                down_1FramePlayer= txLoadImage (down_1);
                down_2FramePlayer= txLoadImage (down_2);
                right_1FramePlayer= txLoadImage (right_1);
                right_2FramePlayer= txLoadImage (right_2);
                left_1FramePlayer= txLoadImage (left_1);
                left_2FramePlayer= txLoadImage (left_2);
                k=1;
                kend=0;
                }
             }

            void destroyPic(){
                while(kend==0){
                txDeleteDC (atk_1FramePlayer);
                txDeleteDC (atk_2FramePlayer);

                txDeleteDC (idle_1FramePlayer);
                txDeleteDC (idle_2FramePlayer);
                txDeleteDC (up_1FramePlayer);
                txDeleteDC (up_2FramePlayer);
                txDeleteDC (down_1FramePlayer);
                txDeleteDC (down_2FramePlayer);
                txDeleteDC (right_1FramePlayer);
                txDeleteDC (right_2FramePlayer);
                txDeleteDC (left_1FramePlayer);
                txDeleteDC (left_2FramePlayer);

                kend=1;
                k=0;
             }

            }



    };
/////////////////////
    class NPCsPosition{
                        public:
                            int x_0;
                            int y_0;
                    };
/////////////////////
    class preNPCs {

        public:

            HDC idle_1_0;
            HDC idle_2_0;

            const char* idle_1_0_c = ("NPC\\0_BOX\\idle_1.bmp");
            const char* idle_2_0_c = ("NPC\\0_BOX\\idle_2.bmp");

            int prek=0;
            int postk=0;

            void preLoadNPCs(){
            if(prek==0){

            idle_1_0 = txLoadImage (idle_1_0_c);
            idle_2_0 = txLoadImage (idle_2_0_c);

            prek=1;
            postk=0;
            }
            }

            void postDestroyNPCs(){
            if(postk==0){

                   txDeleteDC (idle_1_0);
                   txDeleteDC (idle_2_0);

            postk=1;
            prek=0;
            }

            }


        };
/////////////////////
    class Global{
    public:
    bool GameIsRunning;
    int ticRate = 0;
    int animationTicRate = 0;

    };
/////////////////////
    class Player{
    public:
    int x;
    int y;
    int lastX;
    int lastY;
    int PP = 0;
    int run;


    };
/////////////////////
    class MainMenu{
    public:
    HDC MainMenuBackGround;

    void launchBack(){
    MainMenuBackGround = txLoadImage("MainMenuBackGround.bmp");
    }

    void deleteBack(){
    txDeleteDC (MainMenuBackGround);
    }


    };
/////////////////////
    class BlocksBackground{
    public:

        HDC wallBl_Back;
        HDC wallBl_Back1;

        void preBlock(){

        wallBl_Back = txLoadImage("Blocks\\wall_0.bmp");
        wallBl_Back1 = txLoadImage("Blocks\\wall_1.bmp");
        }


        void deletHdc(){

                txDeleteDC (wallBl_Back);
                txDeleteDC (wallBl_Back1);


        }


    };
/////////////////////
    class Enemy{
public:
    int countOfEnemy = 1;

    };



/////////////////////
        //FUNCTION

    void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){

        POINT triangle[3] = {{x1, y1}, {x2, y2}, {x3, y3}};
        txPolygon (triangle, 3);


    }
/////////////////////
    void drawSpears(int x, int y){

        txSetColor(TX_BLACK, 4);
        txSetFillColor(TX_GRAY);

        drawTriangle(x+16, y, x+20, y+16, x+12, y+16);
        drawTriangle(x+16+16, y, x+20+16, y+16, x+12+16, y+16);
        drawTriangle(x+16+16+16, y, x+20+16+16, y+16, x+12+16+16, y+16);

        drawTriangle(x+16-8, y+16, x+20-8, y+16+16, x+12-8, y+16+16);
        drawTriangle(x+16-8+16, y+16, x+20-8+16, y+16+16, x+12-8+16, y+16+16);
        drawTriangle(x+16-8+16+16, y+16, x+20-8+16+16, y+16+16, x+12-8+16+16, y+16+16);
        drawTriangle(x+16-8+16+16+16, y+16, x+20-8+16+16+16, y+16+16, x+12-8+16+16+16, y+16+16);

        drawTriangle(x+16, y+16+16, x+20, y+16+16+16, x+12, y+16+16+16);
        drawTriangle(x+16+16, y+16+16, x+20+16, y+16+16+16, x+12+16, y+16+16+16);
        drawTriangle(x+16+16+16, y+16+16, x+20+16+16, y+16+16+16, x+12+16+16, y+16+16+16);

        drawTriangle(x+16-8, y+16+16+16, x+20-8, y+16+16+16+16, x+12-8, y+16+16+16+16);
        drawTriangle(x+16-8+16, y+16+16+16, x+20-8+16, y+16+16+16+16, x+12-8+16, y+16+16+16+16);
        drawTriangle(x+16-8+16+16, y+16+16+16, x+20-8+16+16, y+16+16+16+16, x+12-8+16+16, y+16+16+16+16);
        drawTriangle(x+16-8+16+16+16, y+16+16+16, x+20-8+16+16+16, y+16+16+16+16, x+12-8+16+16+16, y+16+16+16+16);

    }
/////////////////////
    void drawSpearsHole(int x, int y){

        txSetColor(TX_BLACK, 4);
        txSetFillColor(TX_BLACK);

        txLine(x+12, y+16, x+20, y+16);
        txLine(x+12+16, y+16, x+20+16, y+16);
        txLine(x+12+16+16, y+16, x+20+16+16, y+16);

        txLine(x+12-8, y+16+16, x+20-8, y+16+16);
        txLine(x+12-8+16, y+16+16, x+20-8+16, y+16+16);
        txLine(x+12-8+16+16, y+16+16, x+20-8+16+16, y+16+16);
        txLine(x+12-8+16+16+16, y+16+16, x+20-8+16+16+16, y+16+16);

        txLine(x+12, y+16+16+16, x+20, y+16+16+16);
        txLine(x+12+16, y+16+16+16, x+20+16, y+16+16+16);
        txLine(x+12+16+16, y+16+16+16, x+20+16+16, y+16+16+16);

        txLine(x+12-8, y+16+16+16+16, x+20-8, y+16+16+16+16);
        txLine(x+12-8+16, y+16+16+16+16, x+20-8+16, y+16+16+16+16);
        txLine(x+12-8+16+16, y+16+16+16+16, x+20-8+16+16, y+16+16+16+16);
        txLine(x+12-8+16+16+16, y+16+16+16+16, x+20-8+16+16+16, y+16+16+16+16);



    }
/////////////////////
    void spears(int x, int y, int* animtick, int dmg, int of, int to){

    Global Global;


    int k=0;

    if((*animtick)>=of&&(*animtick)<=to){
    if(PlayerX+32>=x && PlayerX<=x+64 && PlayerY+64>=y && PlayerY<=y+64 && (*animtick)==((of+to)/2)){

        playerHP-=dmg;

    }

    drawSpears(x, y);

    }else{

    drawSpearsHole(x, y);

    }





    }


/////////////////////
    void firstEnemy(int x, int y){

    txSetColor(TX_WHITE, 5);
    txSetFillColor(TX_WHITE);
    txRectangle(x, y, x+20, y+30);
    txCircle(x+10, y+10, 5);
    txLine(x, y, x-10, y+10);
    txLine(x+20, y, x+30, y+10);

    }

/////////////////////
    void drawEnemy(int* x, int* y, int* HP, int* plDmg, int numberOfEnemy, int shootRng, int agroRng, float dmg, int run, int timeToHit, int roomX, int roomY, int xSize, int ySize, int *animtick){
        Global Global;


        int xM = PlayerX, yM = PlayerY;

        int rasst;

        rasst = sqrt((xM-(*x))*(xM-(*x))+ (yM-(*y))*(yM-(*y)) );

        if((*HP)>0){

        switch(numberOfEnemy){
        //put yours enemy here:
    case 0:
        //draw enemy

        firstEnemy(*x, *y);
        //LOGIC, DON`T TOUCH
        srand( time(NULL) );

        int xyPl = rand()%2;

        int k1 = rand()%3;
        int k2 = rand()%3;
        int k3 = rand()%3;
        int k4 = rand()%3;




        if(rasst>agroRng && rasst>=shootRng){
            if(k1==0 && (*x)<=roomX+xSize-30){

            (*x)+=xyPl;

            }
            if(k2==1 && (*x)>=roomX){

            (*x)-=xyPl;

            }
            if(k3==0 && (*y)<=roomY+ySize-20){

            (*y)+=xyPl;

            }
            if(k4==1 && (*y)>=roomY){

            (*y)-=xyPl;

            }

        }

        if( rasst<=agroRng && rasst>=shootRng && xM>=(*x)){

        (*x)+=run;

        }else if(rasst<=agroRng && xM<=(*x) && rasst>=shootRng ){

        (*x)-=run;

        }
        if( rasst<=agroRng && yM>=(*y) && rasst>=shootRng ){

        (*y)+=run;

        }else if(rasst<=agroRng && yM<=(*y) && rasst>=shootRng ){

        (*y)-=run;

        }

        if(timeToHit>20)timeToHit=20;

        if(rasst<=shootRng && (*animtick)==timeToHit){

        if(GetAsyncKeyState (0x01)){
                if((*x)>=PlayerX-32-32  && (*x)<=PlayerX+32 && (*y)>=PlayerY-32 && (*y)<=PlayerY+64+32)(*HP)-= (*plDmg);
        }
        if(GetAsyncKeyState (0x02)){
                if((*x)<=PlayerX+32+32 && (*x)>=PlayerX && (*y)>=PlayerY-32 && (*y)<=PlayerY+64+32)(*HP)-= (*plDmg);
        }

        if((*HP)<=0){
            coins+=5;
        }

        playerHP = playerHP-dmg;

        }


        break;


        }
        }
    }

/////////////////////

    void drawNPC (int x, int y, int* animTick, HDC* Idle_1, HDC* Idle_2, int* k){
        NPCsPosition NPCsPosition;
        preNPCs preNPCs;


                        if((*animTick)==0) txTransparentBlt (txDC(), x, y, 32, 64, *Idle_1, 0, 0);
                        else if((*animTick)==1) txTransparentBlt (txDC(), x, y, 32, 64, *Idle_2, 0, 0);
        if(txMouseX()>=x && txMouseX()<=x+32 && txMouseY()>=y && txMouseY()<=y+64 && PlayerX>=x-100 && PlayerX<=x+100+32 && PlayerY>=y-100 && PlayerY<=y+100+64){
            if(GetAsyncKeyState (0x45)&&(*k)>=20&&coins>=25){

                txPlaySound ("Music\\shop.wav", SND_NODEFAULT);


                healers++;
                coins = coins-25;
                (*k)=0;
            }

        }

        (*k)++;

    }

/////////////////////
    int checkOfKill(int enemyCount, int* enemyHP){
        int x=0;
        int y=0;

        int k=0;
        if((*enemyHP)<=0){

        x=1;

        }
        int enCou = enemyCount;

        if((*enemyHP)<=0){
        y = 1;
        }


        return(y);
    }
/////////////////////
    void healPotion(int x, int y){
        txSetColor(TX_BLACK, 1);
        txSetFillColour(TX_RED);
        txRectangle(x+10, y+5, x+40, y+10);
        txRectangle(x+22, y, x+28, y+20);
        txSetColour(TX_RED);
        txCircle(x+25, y+40, 25);

    }
/////////////////////
    void bars(){

        //HEALERS
        healPotion(10, 10);

        txSetColor(TX_BLACK, 2);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(15, 30, 55, 85, "HP", DT_CENTER);

        int integer = healers;
        string str;
        ostringstream stream;
        stream << integer;
        str = stream.str();
        char nm[100];
        strcpy(nm,str.c_str());
        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(70, 25, 120, 80, nm, DT_CENTER);


        //COINS
        txSetFillColour(TX_YELLOW);
        txSetColor(TX_RED, 2);

        txCircle(35, 125, 25);
        txSetColor(TX_BLACK, 2);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(20, 105, 50, 150, "C", DT_CENTER);//the "C" on coin

        integer = coins;
        ostringstream stream2;
        stream2 << integer;
        str = stream2.str();
        char nm1[100];
        strcpy(nm1,str.c_str());

        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(70, 100, 250, 180, nm1, DT_LEFT);

        //HP BAR

        txSetFillColour(TX_RED);
        txSetColor(TX_WHITE, 2);
        txRectangle(10, 180, 110, 210);

        integer = playerHP;
        ostringstream stream3;
        stream3 << integer;
        str = stream3.str();

        integer = playerMaxHP;
        ostringstream stream4;
        stream4 << integer;

        str = str+"/"+stream4.str();

        char nm2[100];
        strcpy(nm2,str.c_str());

        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(50, 170, 320, 270, nm2, DT_CENTER);


    }

/////////////////////
    void drawdoor(int x, int y, int x1, int y1){
    txSetFillColor(TX_BROWN);
    txSetColor(TX_BROWN, 2);
    txRectangle(x, y, x1, y1);


    }
    void CreatePlayer(string NameOfPlayer){

    ::NamePlayer = NameOfPlayer;

    char nm[100];
    strcpy(nm,::NamePlayer.c_str());

    cout << nm;

    //txMessageBox (nm, "Your name is:");

    }
/////////////////////
    void WallBlock(int wall_x, int wall_y, HDC* block_background){

        txSetFillColor(TX_GREEN);

        //txRectangle(wall_x, wall_y, wall_x+64, wall_y+64);

        txBitBlt (txDC(), wall_x, wall_y, 64, 64, *block_background, 0, 0);



        if(PlayerX <= wall_x+64 && PlayerX >= wall_x-32 && PlayerY >=wall_y-64 && PlayerY <=wall_y+64 && GetAsyncKeyState (0x44)){
            PlayerX-=4;
        }
        if(PlayerX <= wall_x+64 && PlayerX >= wall_x-32 && PlayerY >=wall_y-64 && PlayerY <=wall_y+64 && GetAsyncKeyState (0x41)){
            PlayerX+=4;
        }

         if(PlayerY >= wall_y-64 && PlayerY <= wall_y+64 && PlayerX >=wall_x-32 && PlayerX<=wall_x+64 && GetAsyncKeyState (0x53)){
            if(GetAsyncKeyState (0x44))PlayerX+=10;
            if(GetAsyncKeyState (0x41))PlayerX-=10;

            PlayerY-=4;
        }
         if(PlayerY >= wall_y-64 && PlayerY <= wall_y+64 && PlayerX >=wall_x-32 && PlayerX <=wall_x+64 && GetAsyncKeyState (0x57)){
            if(GetAsyncKeyState (0x44))PlayerX+=10;
            if(GetAsyncKeyState (0x41))PlayerX-=10;
            PlayerY+=4;
        }



    }
/////////////////////
    bool RoomWall(int sizesX, int sizesY, HDC* wall_background, HDC* outside_background, bool diedEnemy){

        // x - 1/4 screenX ; y - 1/4screenY
        bool ret=false;


        //txLine(ScreenX/4+sizesX, (ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8-32, ScreenX/4+sizesX+100, (ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8-32);
        //txLine(ScreenX/4+sizesX, (ScreenY/8+sizesY-ScreenY/8)/2+64+ScreenY/8+32, ScreenX/4+sizesX+100, (ScreenY/8+sizesY-ScreenY/8)/2+64+ScreenY/8+32);
        //txCircle(ScreenX/4+sizesX, (ScreenY/8+sizesY-ScreenY/8)/2+ScreenY/8, 10);//middle
        txSetColor(TX_GRAY, 5);
        //txLine(ScreenX/4+sizesX+64+64+62, (ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8-28, ScreenX/4+sizesX+64+64+62, (ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8+64*2+45);

        int k = 0;
        int z = 0;


        while(z<((ScreenX/4+sizesX+64)-(ScreenX/4-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);

            z++;
        }

        z=0;

        while(k<((ScreenY/8+sizesY+64)-(ScreenY/8-64))/64-1){

           txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);
            k++;
        }

        while(z<((ScreenX/4+sizesX+64)-(ScreenX/4-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);

            z++;
        }
        k=0;

        z =((ScreenX/4+sizesX+64)-(ScreenX/4-64))/64 - 1;

        while(k<((ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8-(ScreenY/8-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);
            k++;
        }

        k = ((ScreenY/8+sizesY+64)-(ScreenY/8-64))/64 - 1;

        while(k>((ScreenY/8+sizesY-ScreenY/8)/2+64+ScreenY/8-(ScreenY/8-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);

            k--;
        }

        k++;

        while(z<((ScreenX/4+sizesX+64+64*2)-(ScreenX/4-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);

            z++;
        }

        z =((ScreenX/4+sizesX+64)-(ScreenX/4-64))/64 - 1;
        k=((ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8-(ScreenY/8-64))/64 - 1;

        while(z<((ScreenX/4+sizesX+64+64*2)-(ScreenX/4-64))/64){

            txBitBlt (txDC(), ScreenX/4-64+(z*64), ScreenY/8-64+(k*64), 64, 64, *outside_background, 0, 0);

            z++;
            PlayerX+32 >= ScreenX/4+sizesX;
        }




        k=0;
        z=0;





        while(k<(ScreenY/8+sizesY-ScreenY/8)/64){
            while(z<(ScreenX/4+sizesX-ScreenX/4)/64){

                txBitBlt (txDC(), ScreenX/4+(z*64), ScreenY/8+(k*64), 64, 64, *wall_background, 0, 0);

                z++;
            }
            z=0;
            k++;
        }


        if(PlayerX+32 >= ScreenX/4+sizesX && GetAsyncKeyState (0x44) && PlayerY >= (ScreenY/8+sizesY-ScreenY/8)/2-64-32+ScreenY/8
        && PlayerY <= (ScreenY/8+sizesY-ScreenY/8)/2+64+32+ScreenY/8 && !diedEnemy){
            PlayerX-=4;

        }

        txSetColor(TX_GRAY, 5);
        txLine(ScreenX/4, ScreenY/8, ScreenX/4+sizesX, ScreenY/8);
        txLine(ScreenX/4+sizesX, ScreenY/8, ScreenX/4+sizesX, ScreenY/8+sizesY);
        txLine(ScreenX/4+sizesX, ScreenY/8+sizesY, ScreenX/4, ScreenY/8+sizesY);
        txLine(ScreenX/4, ScreenY/8+sizesY, ScreenX/4, ScreenY/8);

        int door;

        if(!diedEnemy){
        door = 128;
        drawdoor(ScreenX/4+sizesX-10, (ScreenY/8+sizesY-ScreenY/8)/2-64-32+ScreenY/8, ScreenX/4+sizesX+10, (ScreenY/8+sizesY-ScreenY/8)/2+64+32+ScreenY/8);
        }else{

        door = 0;
        }

        if(PlayerX+32 >= ScreenX/4+sizesX+32){

        ret = true;

        }

        if(PlayerX+32 >= ScreenX/4+sizesX && PlayerY <= (ScreenY/8+sizesY-ScreenY/8)/2-64+ScreenY/8 && GetAsyncKeyState (0x44)){//right
            PlayerX-=4;
        }
        if(PlayerX+32 >= ScreenX/4+sizesX && PlayerY+64 >= (ScreenY/8+sizesY-ScreenY/8)/2+64+ScreenY/8 && GetAsyncKeyState (0x44)){//right
            PlayerX-=4;
        }

        if(PlayerX <= ScreenX/4 && GetAsyncKeyState (0x41)){//left
            PlayerX+=4;
        }

         if(PlayerY+64 >= ScreenY/8+sizesY && GetAsyncKeyState (0x53)){//down
            if(GetAsyncKeyState (0x44))PlayerX+=5;
            if(GetAsyncKeyState (0x41))PlayerX-=5;

            PlayerY-=4;
        }
         if(PlayerY <= ScreenY/8 && GetAsyncKeyState (0x57)){
            if(GetAsyncKeyState (0x44))PlayerX+=5;
            if(GetAsyncKeyState (0x41))PlayerX-=5;
            PlayerY+=4;
        }


        /////////////


    return(ret);


    }

/////////////////////

    void drawButtons(int x, int y, int Red, int Green, int Blue, string textt){

    txSetFillColor(RGB(Red, Green, Blue));
    txSetColor(TX_BLACK, 2);
    POINT ButtoN[4] = { {x, y}, {x+25, y-50}, {x+25+200, y-50}, {x+200, y} };
    txPolygon (ButtoN, 4);

        char nm[100];
        strcpy(nm,textt.c_str());
        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 30, 0, FW_BOLD);
        txDrawText(x+10, y-40, x+220, y, nm, DT_CENTER);



    }

/////////////////////

    bool Buttons(int x, int y, int Red, int Green, int Blue, string textt){
    bool K=false;
    drawButtons(x, y, Red, Green, Blue, textt);
    if(txMouseX()>=x && txMouseX()<=x+200+25 && txMouseY()>=y-50 && txMouseY()<=y ){

    drawButtons(x, y, Red+30, Green+30, Blue+30, textt);

        if(GetAsyncKeyState (0x01)){
            K=true;
        }

    }
    return(K);
    }



/////////////////////

    void SetPlayer(int* x, int* y, int* k, int* atkTick, int* animTick, HDC* Idle_1, HDC* Idle_2, HDC* Up_1, HDC* Up_2, HDC* Down_1, HDC* Down_2, HDC* Right_1, HDC* Right_2, HDC* Left_1, HDC* Left_2, HDC* Atk_1, HDC* Atk_2,int* PlPP){

            Player Player;
            //USE HEAL
            if(GetAsyncKeyState (0x48)){//H
            if(healers>0&&(*k)>=20){
              healers--;
              playerHP+=20;
              if(playerHP>playerMaxHP){
                playerHP=playerMaxHP;
              }
              (*k)=0;
            }


            }
            (*k)++;
            //HIT


            //MOVEMENT
        if(!GetAsyncKeyState (0x02) && !GetAsyncKeyState (0x01) && !GetAsyncKeyState (0x57) && !GetAsyncKeyState (0x53) && !GetAsyncKeyState (0x44) && !GetAsyncKeyState (0x41)){
            if((*animTick)==0){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Idle_1, 0, 0);
                (*PlPP)=0;
                txPlaySound (NULL);

            }
            if((*animTick)==1){

                txTransparentBlt (txDC(), *x, *y, 32, 64, *Idle_2, 0, 0);
                if((*PlPP)==0){
                    (*PlPP)++;
                }
            }

        }else if(GetAsyncKeyState (0x02)){//right
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Atk_2, 0, 0);
                txSetColor(RGB(255, 200, 125), 10);
                if((*atkTick)>=10&&(*atkTick)<=20)txArc ((*x)+32, (*y), (*x)+32+32, (*y)+64, -90, 180);

        }else if(GetAsyncKeyState (0x01)){//left
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Atk_1, 0, 0);
                txSetColor(RGB(255, 200, 125), 10);
                if((*atkTick)>=10&&(*atkTick)<=20)txArc ((*x), (*y), (*x)-32, (*y)+64, 90, 180);

        }else if(GetAsyncKeyState (0x57)){ //up
            (*y)-=4;
            if((*animTick)==0){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Up_1, 0, 0);
                txPlaySound (NULL);
                (*PlPP)=0;
            }

            if((*animTick)==1){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Up_2, 0, 0);
                if((*PlPP)==0){
                    txPlaySound ("Music\\move.wav");
                    (*PlPP)++;
                }
            }

        }else if(GetAsyncKeyState (0x53)){ //down
            (*y)+=4;
            if((*animTick)==0){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Down_1, 0, 0);
                txPlaySound (NULL);
               (*PlPP)=0;
            }

            if((*animTick)==1){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Down_2, 0, 0);
                if((*PlPP)==0){
                    txPlaySound ("Music\\move.wav");
                    (*PlPP)++;
                }
            }

        }else if(GetAsyncKeyState (0x44)){ //right
            (*x)+=4;
            if((*animTick)==0){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Right_1, 0, 0);
                txPlaySound (NULL);
               (*PlPP)=0;
            }

            if((*animTick)==1){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Right_2, 0, 0);
               if((*PlPP)==0){
                    txPlaySound ("Music\\move.wav");
                    (*PlPP)++;
                }
            }

        }else if(GetAsyncKeyState (0x41)){ //left
            (*x)-=4;
            if((*animTick)==0){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Left_1, 0, 0);
                txPlaySound (NULL);
               (*PlPP)=0;
            }

            if((*animTick)==1){
                txTransparentBlt (txDC(), *x, *y, 32, 64, *Left_2, 0, 0);
                if((*PlPP)==0){
                    txPlaySound ("Music\\move.wav");
                    (*PlPP)++;
                }
            }

        }



    }
