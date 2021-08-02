#ifndef COLORS_H
#define COLORS_H

#include <string>

class Color{
private:
    static std::string esc;
    static std::string prefix;
    static std::string suffix;
public:
    static void setEsc(std::string e);
    static std::string base(int val);
    static std::string fgbit8(int val);
    static std::string bgbit8(int val);
    static std::string fgrgb(int r, int g, int b);
    static std::string bgrgb(int r, int g, int b);
    static std::string reset();
};

#endif