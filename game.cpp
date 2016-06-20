#include "game.h"
#include  <iostream>
#include <string>
#include <fstream>
using namespace std;
Game::Game()
{

}
void Game::Board_Cout( Board &board)
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			cout<<board.game_board[i][j]<<" ";
		}
		cout<<endl;
	}
}
Key* Game::setKeys(GraphicBomber &graphic ,Key &key)
{
	key.right=graphic.rightKeyPressed();
	key.left=graphic.leftKeyPressed();
	key.up=graphic.upKeyPressed();
	key.down = graphic.downKeyPressed();
	return &key;
}
void Game::run(GraphicBomber &graphic, Key &key , Player &player , Board &board ,Bomb &bomb)
{
		while(true)
	{
    player.moveControl(*(setKeys(graphic ,key)),board);
    if(bomb.bombIsLocated(key ,graphic))
    {

    }
    cout<<player.getX()<<endl;
    cout<<player.getY()<<endl;
    
    }
}

