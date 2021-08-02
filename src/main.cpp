#include <iostream>
#include <iomanip>

#include "colors.h"





void out(int n){
     std::cout << Color::base(n) <<std::setw(4)<< n << Color::reset(); 
}
void out8bit(int n){
     std::cout << Color::fgbit8(16) <<Color::bgbit8(n) <<std::setw(4)<< n << Color::reset(); 
}



void colortable()
{
    int i, j, n;

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 10; j++)
        {
            n = 10 * i + j;
            if (n > 108)
                break;
            out(n);
        }
     std::cout << std::endl;

    }

    std::cout << Color::reset();
}




int main(int argc, char *argv[])
{    
     std::cout << Color::base(36);
	std::cout << R"(
 _____                   _____       _            
|_   _|                 /  __ \     | |           
  | | ___ _ __ _ __ ___ | /  \/ ___ | | ___  _ __ 
  | |/ _ \ '__| '_ ` _ \| |    / _ \| |/ _ \| '__|
  | |  __/ |  | | | | | | \__/\ (_) | | (_) | |   
  \_/\___|_|  |_| |_| |_|\____/\___/|_|\___/|_|     

                                  .-.
     (___________________________()6 `-,
     (   ______________________   /''"`
     //\\                      //\\
     "" ""                     "" ""            
------------------------------------------------



)" << std::endl;

     std::cout << Color::reset();



     // ============================ Printing base colors =============================
     for(int i=30;i<=37;i++){
          out(i);
     }
     std::cout << std::endl;
     for(int i=40;i<=47;i++){
          out(i);
     }
     std::cout << std::endl;
     for(int i=90;i<=97;i++){
          out(i);
     }
     std::cout << std::endl;
     for(int i=100;i<=107;i++){
          out(i);
     }
     std::cout << "\n\n";

     //===============================Printing 256 colors===================

     for(int i=0;i<=7;i++){
          out8bit(i);
     }
     std::cout << std::endl;

     for(int i=8;i<=15;i++){
          out8bit(i);
     }
     std::cout << "\n\n";
     int y=16;
     while(y<231){
          for(int i=0;i<6;i++){
               out8bit(y);
               y++;
          } 
          std::cout << std::endl;
     }

     std::cout << std::endl;

     //=======printing shades of b&w=========

     y = 232;
     while(y<256){
          for(int i=0;i<6;i++){
               out8bit(y);
               y++;
          } 
          std::cout << std::endl;
     }
     std::cout << std::endl;

     //===============================Printing 256 colors===================
     
     colortable();
     std::cout << std::endl;
     //======================= Testing escape characters ==================
     
     std::cout << Color::base(96);
     //\e, \E, \33, \033, \x1b
     
     Color::setEsc("\x1b");
     std::cout << R"(Testing \x1b)" << std::endl;

     Color::setEsc("\e");
     std::cout << R"(Testing \e)" << std::endl;
     
     Color::setEsc("\E");
     std::cout << R"(Testing \E)" << std::endl;

     Color::setEsc("\33");
     std::cout << R"(Testing \33)" << std::endl;

     Color::setEsc("\033");
     std::cout << R"(Testing \033)" << std::endl;

     std::cout << "Resetting text formatting" << std::endl;
     std::cout << Color::reset();

}




//References
//https://github.com/segaleran/eran-dotfiles/blob/master/bin/terminalcolors.py