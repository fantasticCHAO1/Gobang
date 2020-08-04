#include "Game.h"


void Game::start()
{
    while(1){
        mainwidow->init();
        mainwidow->showChessBoard();
        mainwidow->readChoice();
        int choice=mainwidow->getChoice();
        string now_color;
        if(choice==BLACK_FIRST)
        {
            now_color=COLOR_BLACK;
        }
        else
        {
            now_color=COLOR_WHITE;
        }
        int row,column;
        while(1)
        {
            cout<<now_color<<"round~"<<" please input a point"<<endl;
            cin>>row>>column;
            ChessPos chesspos(row,column);
            Chess chess(chesspos,now_color);
            mainwidow->readChessPos(now_color,&row,&column);
            mainwidow->update();
            if(mainwidow->iswin(chess))
            {
                cout<<"\n\rGAME OVER!"<<endl;
                break; 
            }
            if(now_color==COLOR_BLACK)
            {
                now_color=COLOR_WHITE;
            }
            else
            {
                now_color=COLOR_BLACK;
            }
        }
        mainwidow->showLastResult();
        int buf;
        mainwidow->showMessageBox("please select:1.resume 2.end");
        cin>>buf;
        if(buf==2){
            break;
        }
        else if(buf==1)
        {
            continue;
        }
    }
}
bool Game::resume()
{
    return 1;
}

/* Game* Game::getGame() */
/* { */
/*     if(Game::gameptr==nullptr) */
/*     { */
/*         Game::gameptr=new Game; */
/*         return Game::gameptr; */
/*     } */
/*     else */
/*     { */
/*         return Game::gameptr; */
/*     } */
/* } */


void Game::end()
{
    

}


