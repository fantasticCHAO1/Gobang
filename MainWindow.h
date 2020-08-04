#ifndef _MAINWINDOW_H 
#define _MAINWINDOW_H
#include <string>
#include "global.h"
#include "iMainWindow.h"
#include "ChessBoard.h"

class MainWindow : public IMainWindow{
	public:
		void init();
		void update();
		void showChessBoard() ;
		void showMessageBox(string message) ;
		void showLastResult() ;
		void readChoice(int *choice) ;
		void readChoice() ;
        int getChoice();
		void readChessPos(ChessColor chessColor, int* row, int* column) ;
		void readChessBoardSize(int* rows, int* columns);
        bool iswin(Chess chess);
        void set_score(ChessColor color);
        ~MainWindow();
        MainWindow();
    private:
    ChessBoard* chessboard;        
};
#endif
