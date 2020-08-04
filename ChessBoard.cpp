#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
   this->width=0;
   this->height=0;
   this->blackscore=0;
   this->whitescore=0;
}


void ChessBoard::select_order(int order)
{
    this->oerder_select=order;
}

int ChessBoard::get_order()
{
    return oerder_select;
}

void ChessBoard::resize(int height,int width)
{
   this->width=width;
   this->height=height;

}
int ChessBoard::getWidth()
{
    return  this->width;
}
int ChessBoard::getHeight() 
{   
    return this->height;
}

void ChessBoard::init()
{
    chessBoardMap.clear();
    for(int row=0;row<height;row++)
    {
        for(int column=0;column<width;column++)
        {
            ChessPos chesspos(row,column);
            Chess chess(chesspos,COLOR_BLANK);
            chessBoardMap.insert(chess);
        }
    }

}

void ChessBoard::set_score(ChessColor color)
{
    if(color==COLOR_BLACK)
    {
        blackscore++;
    }
    else{
        whitescore++;
    }
}

void ChessBoard::addChess(Chess chess)
{
    chessBoardMap.erase(chess.first);
    chessBoardMap.insert(chess);

}
int ChessBoard::getWhiteScore(){
    return whitescore;
}
int ChessBoard::getBlackScore(){
    return blackscore;
}
bool ChessBoard::isOutranged(int row, int column) {
    if(row<0||row>height||column<0||column>width)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ChessBoard::isRepeat(int row, int column) {
    if(chessBoardMap.at(ChessPos(row,column))==COLOR_BLANK)
    {
        return false;
    }
    else
    {
        return true;
    }
}
ChessColor ChessBoard::chessColor(int row, int column) {
     return chessBoardMap.at(ChessPos(row,column));
}
bool ChessBoard::isWinner(Chess chess) {
	int direction = 0;
	int count = 0;
	for(direction = 0; direction < 4; direction++){
		count = 1 + searchChess(chess, (Direction)direction) 
			+ searchChess(chess, (Direction)(direction + 4));
		if(count > 4){
			if(chess.second == COLOR_BLACK){
				blackscore += 1;
			}else{
				whitescore += 1;
			}
			return true;
		}
	}
	return false; 

}
//与当前棋子连珠的棋子个数, 即连续同色
int ChessBoard::searchChess(Chess chess, Direction direction){
	int row = chess.first.first;
	int column = chess.first.second;
	ChessColor chessColor = chess.second;
	ChessPos chessPos;
	int count = 0;
	switch (direction)
	{
		case LEFT:
			chessPos = ChessPos(row, column - 1); //左边位置
			if((column > 0) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case LEFTTOP:
			chessPos = ChessPos(row - 1, column - 1); //左上边角位置
			if((row > 0) && (column > 0) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor),direction);
			}
			break;
		case TOP:
			chessPos = ChessPos(row - 1, column); //上
			if((row > 0) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case RIGHTTOP:
			chessPos = ChessPos(row - 1, column + 1); //右上
			if((column < width - 1) && ( row > 0) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case RIGHT:
			chessPos = ChessPos(row, column + 1); //右方位置
			if((column < width - 1) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case RIGHTBOTTOM:
			chessPos = ChessPos(row + 1, column + 1); //右下角位置
			if((column < width - 1) && (row < height - 1) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case BOTTOM:
			chessPos = ChessPos(row + 1, column); //下方位置
			if((row < height - 1) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
		case LEFTBOTTOM:
			chessPos = ChessPos(row + 1, column - 1); //左下角位置
			if((column > 0) && (row < height - 1) && (chessBoardMap.at(chessPos) == chessColor))
			{
				count = 1 + searchChess(Chess(chessPos, chessColor), direction);
			}
			break;
	}
	return count;


}











