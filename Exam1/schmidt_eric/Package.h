#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

class Package {
    friend ostream& operator<<(ostream &outstream,
        const Package &pkg);
public:
    Package(string _desc, double _weight);
    string getDesc() const;
    double getWeight() const;
    bool operator<(const Package &other);
    bool operator>(const Package &other);
private:
    string desc;
    double weight;
};

#endif