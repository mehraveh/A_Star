#include <iostream>
#include <ctime>

int main()
{
  int s;
  time_t currentTime;
  struct tm *localTime;
  char m;
  std::cin >> m;
  if(m == 'a') 
  {
    time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );
  int s = localTime->tm_sec;}
  //std::cout <<s << std::endl;
  //std:: cout << ++s;}

while (true)
{
 // time_t currentTime;
  time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );  // Convert the current time to the local time

  
  int Hour   = localTime->tm_hour;
  int Min    = localTime->tm_min;
  int Sec    = localTime->tm_sec;
if ( Sec == s + 1) {std::cout << "kharrrrrrrrrrrrrrrrrrrrrrrr"; return 0;}
  std::cout << "This program was exectued at: " << Hour << ":" << Min << ":" <<  Sec << std::endl;
  }
  return 0;
}
 