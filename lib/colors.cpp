#include <iostream>
#include <string>

#include "colors.h"






std::string Color::esc = "\033";              //\e, \E, \33, \033, \x1b
std::string Color::prefix =    Color::esc + "[";
std::string Color::suffix = "m";

//========================== setting esc =============================
// \e, \E, \33, \033, \x1b
void Color::setEsc(std::string e){
        Color::esc = e;
        Color::prefix =    Color::esc + "[";
    }


//========================== basic colors ============================

std::string Color::base(int val){
    std::string col = prefix + std::to_string(val)+ suffix;
    return col;
}

//========================== 8 bit colors ============================
std::string Color::fgbit8(int val){
    std::string col = prefix + "38;5;"+ std::to_string(val)+ suffix;
    return col;
}
std::string Color::bgbit8(int val){
    std::string col = prefix + "48;5;"+ std::to_string(val)+ suffix;
    return col;
}



//========================== 24 bit colors ============================
std::string Color::fgrgb(int r=190, int g=190, int b=190){
        std::string col = prefix +"38;2;"+ std::to_string(r)+";"+ std::to_string(g)+";"+ std::to_string(b) +suffix;

        return col;
    }

std::string Color::bgrgb(int r=190, int g=190, int b=190){
        std::string col = prefix +"48;2;"+ std::to_string(r)+";"+ std::to_string(g)+";"+ std::to_string(b) +suffix;

        return col;
    }


//========================== Style reset ============================
std::string Color::reset(){
        std::string col = prefix + "0" + suffix;
        return col;
    }






//References 
//https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
