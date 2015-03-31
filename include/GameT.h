#ifndef GAMET_H_INCLUDED
#define GAMET_H_INCLUDED
#include "Target.h"
#include <iostream>
using namespace std;
class GameT
{
    public:
        GameT();
        GameT(int w, int h);
        void draw();
        bool checkHit(char pos, char playerColor);
        void wReshape(int w, int h);
        void changeLevel(int l);

    private:
        Target game[10] =  {Target(600,480,1), Target(600,480,1), Target(600,480,1), Target(600,480,1), Target(600,480,1)};
        int level;

};

GameT::GameT(){
    level = 1;
}

void GameT::draw(){
/* Moves all the targets in the game.*/
    if(level == 1 || level == 2){
        for(int i = 0; i < 1; i++){
            game[i].moveL1();
        }
    } else if(level == 3){
        for(int i = 0; i < 1; i++){
            game[i].moveL3();
        }
    }
}

bool GameT::checkHit(char pos, char playerColor){
/* Checks all the targets in the game to see if the user hit any of them, in case it did it returns true, otherwise it
* returns false. Still missing: color. */
    for(int i = 0; i < 1; i++){
        if(game[i].hit(pos, playerColor)){
            return true;
        }
    }
    return false;
}

void GameT::wReshape(int w, int h){
    for(int i = 0; i < 5; i++){
        game[i].setWindow(w, h);
    }
}

void GameT::changeLevel(int l){
    level = l;
    for(int i = 0; i < 5; i++){
        game[i].setLevel(l);
    }
}
#endif // GAMET_H_INCLUDED
