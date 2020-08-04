#include <iostream>
#include "MainWindow.h"
#include "ChessBoard.h"
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

MainWindow::MainWindow()
{
    chessboard=new ChessBoard;
}
MainWindow::~MainWindow()
{
    delete chessboard;
}
void MainWindow::init()
{
    string ch;
    string height;
    string width;
    string message="pelase select size of the chessbord! such as 10 * 10";
    showMessageBox(message);
    cin>>height>>ch>>width;    
    chessboard->resize(stoi(height),stoi(width));
    chessboard->init();
}

void MainWindow::showChessBoard()
{
    char buf[32]={0};
    char head[32]={0};
    for(int row=-1;row<chessboard->getHeight();row++)
    {
        if(row==-1)  //首行打印坐标信息
        {
            string firstline;

            for(int column=0;column<chessboard->getWidth();column++)
            {
                sprintf(buf,"%5d",column);
                firstline+=buf;
            }
            cout<<firstline<<endl;
        }
        else if (row==chessboard->getHeight()-1)
        {
            
            string midline;
            string lastline;
            sprintf(head,"%2d ",row);
            midline+=head;
            midline+=COLOR_BLANK;
            sprintf(buf,"---%s",COLOR_BLANK);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                midline+=buf;
            }
            cout<<midline<<endl;
        }
        else
        {
            string midline;
            sprintf(head,"%2d ",row);
            midline+=head;
            midline+=COLOR_BLANK;
            bzero(buf,sizeof(buf));
            sprintf(buf,"---%s",COLOR_BLANK);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                midline+=buf;
            }
            cout<<midline<<endl;
            bzero(buf,sizeof(buf));
            bzero(head,sizeof(head));
            sprintf(head,"   %2s",COLOR_BLANK);
            sprintf(buf,"%5s",COLOR_BLANK);
            string gapline(head);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                gapline+=buf;
            }
            cout<<gapline<<endl;

        }

    }
}


void MainWindow::update()
{
    char buf[32]={0};
    char head[32]={0};
    for(int row=-1;row<chessboard->getHeight();row++)
    {
        if(row==-1)  //首行打印坐标信息
        {
            string firstline;

            for(int column=0;column<chessboard->getWidth();column++)
            {
                sprintf(buf,"%5d",column);
                firstline+=buf;
            }
            cout<<firstline<<endl;
        }
        else if (row==chessboard->getHeight()-1)
        {
            
            string midline;
            string lastline;
            sprintf(head,"%2d ",row);
            midline+=head;
            //midline+=COLOR_BLANK;
            midline+=chessboard->chessColor(row,0);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                //bzero(buf,sizeof(buf));
                //sprintf(buf,"---%s",chessboard->chessColor(row,column));
                midline=midline+"---"+chessboard->chessColor(row,column);
            }
            cout<<midline<<endl;
        }
        else
        {
            string midline;
            sprintf(head,"%2d ",row);
            midline+=head;
            midline+=chessboard->chessColor(row,0);
            //midline+=COLOR_BLANK;
            //bzero(buf,sizeof(buf));
            //sprintf(buf,"---%s",COLOR_BLANK);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                midline=midline+"---"+chessboard->chessColor(row,column);
                //midline+=buf;
            }
            cout<<midline<<endl;
            bzero(buf,sizeof(buf));
            bzero(head,sizeof(head));
            sprintf(head,"   %2s",COLOR_BLANK);
            sprintf(buf,"%5s",COLOR_BLANK);
            string gapline(head);
            for(int column=1;column<chessboard->getWidth();column++)
            {
                gapline+=buf;
            }
            cout<<gapline<<endl;

        }

    }
    

}
void MainWindow::showMessageBox(string message) 
{
    cout<<"======================="<<endl;
    cout<<message<<endl;
    cout<<"======================="<<endl;
}

void MainWindow::set_score(ChessColor color)
{
    chessboard->set_score(color);
}

void MainWindow::showLastResult() 
{
    if(chessboard->getBlackScore()>chessboard->getWhiteScore())
    {
        cout<<"black win!"<<endl;
    }
    else
    {
        cout<<"white win!"<<endl;
    }
    cout<<"blackscore : whitescore"<<endl;
    cout<<chessboard->getBlackScore()<<" : "<<chessboard->getWhiteScore()<<endl;
}

void MainWindow::readChoice(int *choice)
{

}

void MainWindow::readChoice() 
{
    string ch;
    showMessageBox("please select who is first:0.black 1.white");
    cin>>ch;
    chessboard->select_order(stoi(ch));
}
int MainWindow::getChoice()
{
    int order=chessboard->get_order();
    return order;
}

void MainWindow::readChessPos(ChessColor chessColor, int* row, int* column)
{
    ChessPos chesspos(*row,*column);
    Chess chess(chesspos,chessColor);
    if(chessboard->isRepeat(*row,*column)||chessboard->isOutranged(*row,*column)==true)
    {
        cout<<"position error!"<<endl;
    }
    chessboard->addChess(chess);
} 

bool MainWindow::iswin(Chess chess)
{
    return chessboard->isWinner(chess);
}

void MainWindow::readChessBoardSize(int* rows, int* columns)
{


}
#if 0
int main()
{
    MainWindow mainWindow;
    mainWindow.init();
    mainWindow.showChessBoard();
}
#endif







