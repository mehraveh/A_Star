#include "bomb.h"

Bomb::Bomb()
{
	upRang=1;
	downRang=1;
	leftRang=1;
	rightRang=1;
    x = 1;
    y = 1;
    bombLocated = false;
}
    void Bomb::setX( int x)
    {
    	this-> x=x;
    }
    int Bomb::getX()
    {
    	return x;
    }
    void Bomb::setY( int y)
    {
    	this-> y = y;
    }
    int Bomb::getY()
    {
    	return y;
    }
    void Bomb::setLeftRang( int leftRang)
    {
    	this->leftRang = leftRang;
    }
    int Bomb::getLeftRang()
    {
    	return leftRang;
    }
    void Bomb::setRightRang( int rightRang)
    {
    	this-> rightRang = rightRang;
    }
    int Bomb::getRightRang()
    {
    	return rightRang;
    }
    void Bomb::setUpRang( int upRang)
    {
    	this -> upRang = upRang;
    }
    int Bomb::getUpRang()
    {
    	return upRang;
    }
    void Bomb::setDownRang( int downRang)
    {
    	this -> downRang = downRang;
    }
    int Bomb::getDownRang()
    {
    	 return downRang; 
    }
    void Bomb::setEXTime( int exTime)
    {
    	this -> exTime = exTime;
    }
    int Bomb::getExTime()
    {
    	return exTime;
    }
    void Bomb::bombIsLocated( Key &key  ,Player &player ,bool bo)
    {
        key.b= bo;
       // int * tmp = new int [2];
        if(key.b)
        {
           // bombLocated=true;
            cout<<"bomb Loacted"<<endl;
            this->setX(player.getX());
            this->setY(player.getY());
            //tmp[0]=this->getX();
           // tmp[1]=this->getY();
            cout<<"bomb x = "<<this->getX()<<endl;
            cout<<"bomb y = "<<this->getY()<<endl;
           // bombLocated=false;
            cout<<"bomb released"<<endl;
            key.b = false;  
            bombLocated = true;    //return tmp;
        }
        
        


    }
   bool Bomb::bombIsExploded()
   {
   Clock cclock;
   Time time1;
   float tt;
    static int t = 0;
    if(bombLocated)
         {if(t==0)
            {time1 = cclock.getElapsedTime();
         cout << time1.asSeconds() << std::endl;
         tt= time1.asSeconds();}
         t++;
         Time time2 =cclock.getElapsedTime();
         if(time2.asSeconds()-tt>1500)
                {
                 bombLocated = false;
                 return true;}
   }}
    void Bomb::boardUpdater(Board &board , Player &p1, Player &p2)
    {
        if(bombIsExploded())
        {   cout<<"exploded"<<endl;
            for (int i = 0; i < rightRang; i++)
            { 
                if (board.game_board[x + i][y]=='e')
                    board.game_board[x + i][y]='n';

                if (p1.getX() == x + i && p1.getY() == y)
                    p1.setLife(p1.getLife()-1);

                if (p2.getX() == x + i && p2.getY() == y)
                    p2.setLife(p2.getLife()-1);

            }

            for (int i = 0; i < leftRang; i++)
            {
                if (board.game_board[x - i][y]=='e')
                    board.game_board[x - i][y]='n';

                if (p1.getX() == x - i && p1.getY() == y)
                    p1.setLife(p1.getLife()-1);


                if (p2.getX() == x - i && p2.getY() == y)
                   p2.setLife(p2.getLife()-1);

            }

            for (int i = 0; i < upRang; i++)
            {
                if (board.game_board[x][y - i]=='e')
                    board.game_board[x][y - i]='n';

                if (p1.getX() == x && p1.getY() == y - i)
                    p1.setLife(p1.getLife()-1);


                if (p2.getX() == x && p2.getY() == y - i)
                   p2.setLife(p2.getLife()-1);
    
            }

            for (int i = 0; i < downRang; i++)
            {
                if (board.game_board[x][y + i]=='e')
                    board.game_board[x][y + i]='n';

                if (p1.getX() == x  && p1.getY() == y + i)
                   p1.setLife(p1.getLife()-1);


                if (p2.getX() == x && p2.getY() == y + i)
                    p2.setLife(p2.getLife()-1);
              
            }

        }
        
    }

