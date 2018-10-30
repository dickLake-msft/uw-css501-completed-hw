#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Color {
public:
    Color();
    Color(int _red, int _green, int _blue);
    ~Color();
    Color& operator+=(const Color &color);
    Color operator+(const Color &color);
    bool operator==(const Color &color);
    bool operator!=(const Color &color);
    int getRed();
    int getGreen();
    int getBlue();
    string printRGB();

private:
    int red;
    int green;
    int blue;
};
#endif