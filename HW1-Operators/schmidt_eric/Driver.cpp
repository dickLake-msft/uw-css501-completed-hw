#include "Driver.h"

int Driver::main() {
    Color color1(40, 40, 100);
    Color color2(100, 40, 40);
    Color color2a(100, 40, 40);
    Color* color1Ptr = &color1;

    cout << "It creates a Color object with the correct RGB values... ";
    assert(color1.getRed() == 40);
    assert(color1.getGreen() == 40);
    assert(color1.getBlue() == 100);
    cout << "PASS" << endl;

    cout << "It prints out its RGB values ... ";
    string rgbStr = color1.printRGB();
    int redPos = rgbStr.find("red");
    assert(redPos > -1);
    cout << "PASS" << endl;

    cout << "It uses += operator to add one color to another... ";
    color1 += color2;
    assert(color1.getRed() == 140);
    assert(color1.getGreen() == 80);
    assert(color1.getBlue() == 140);
    assert(color1Ptr == &color1);
    cout << "PASS" << endl;

    cout << "It uses the + operator to create a new color from 2 colors... ";
    Color color3 = color1 + color2;
    assert(color3.getRed() == 240);
    assert(color3.getGreen() == 120);
    assert(color3.getBlue() == 180);
    cout << "PASS" << endl;

    cout << "It uses the == operator to determine equivalent colors... ";
    assert(color1 == color1);
    assert(color2 == color2a);
    assert(!(color1 == color2));
    cout << "PASS" << endl;

    cout << "It uses the != operator to determine non-equivalency... ";
    assert(color1 != color2);
    assert(!(color1 != color1));
    assert(!(color2 != color2a));
    cout << "PASS" << endl;

    cout << "It has a defined destructor... ";
    Color* color4 = new Color();
    delete color4;
    cout << "PASS" << endl;

    return 0;
}