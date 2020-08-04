#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_ 
#include <iostream>
#include "iChessBoard.h"
#include <map>
using namespace std;

class ChessBoard : public IChessBoard{
public:
		void resize(int height,int width) ;
		void init() ;
		void addChess(Chess chess) ;
		int getWhiteScore() ;
		int getBlackScore() ;
		int getWidth() ;
		int getHeight() ;
	    bool isOutranged(int row, int column) ;
		bool isRepeat(int row, int column) ;
		ChessColor chessColor(int row, int column) ;
		bool isWinner(Chess chess) ;
		//与当前棋子连珠的棋子个数, 即连续同色
		int searchChess(Chess chess, Direction direction);
        ChessBoard();
        void select_order(int order);
        int get_order();
        void set_score(ChessColor color);

private:
        int width;
        int height;
        int blackscore;
        int whitescore;
        ChessBoardMap chessBoardMap;
        int oerder_select;
};




#endif 
