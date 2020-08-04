#ifndef _GAME_H 
#define _GAME_H
#include "iGame.h"
#include "ChessBoard.h"
#include "MainWindow.h"
using namespace std;
class Game {
	public:
		void start();
		bool resume();
        //static Game* getGame();
		void end();
        Game(){
            mainwidow=new MainWindow;
        };
        ~Game(){
            delete mainwidow;
        };
        
    private:
        
        Game(const Game& that){
            that;
        };
        //ChessBoard* chessboard;
        MainWindow* mainwidow;
        //static Game* gameptr;
};
//Game* Game::gameptr=nullptr;

#endif 
