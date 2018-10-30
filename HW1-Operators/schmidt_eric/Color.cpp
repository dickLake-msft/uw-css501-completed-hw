#include "Color.h"

Color::Color() {
    this->red = 0;
    this->green = 0;
    this-> blue = 0;
}

Color::Color(int _red, int _green, int _blue) {
    // Class invariant: hue value must be 0 <= value <= 255
    this->red = (_red < 0) ? 0 : (_red > 255) ? 255 : _red;
    this->green = (_green < 0) ? 0 : (_green > 255) ? 255 : _green;
    this->blue = (_blue < 0) ? 0 : (_blue > 255) ? 255 : _blue;
}

Color::~Color() {
    cout << "Destructor called" << endl;
}

string Color::printRGB() {
    char result[50];
    sprintf(result, "red: %d, green: %d, blue: %d\n",
        this->red, this->green, this->blue);
    return result;
}

Color& Color::operator+=(const Color &color) {
    // Class invariant: hue values cannot exceed 255
    this->red += color.red;
    this->red = (this->red <= 255) ? this->red : 255;

    this->blue += color.blue;
    this->blue = (this->blue <= 255) ? this->blue : 255;

    this->green += color.green;
    this->green = (this->green <= 255) ? this->green : 255;
    return *this;
}

Color Color::operator+(const Color &color) {
    Color result = *this;
    result += color;
    return result;
}

bool Color::operator==(const Color &color) {
    // Check if this is the same instance
    if (this == &color) return true;

    if (this->red != color.red) return false;

    if (this->green != color.green) return false;

    if (this->blue != color.blue) return false;

    return true;
}

bool Color::operator!=(const Color &color) {
    return !(*this == color);
}

int Color::getRed() {
    return this->red;
}

int Color::getGreen() {
    return this->green;
}

int Color::getBlue() {
    return this->blue;
}