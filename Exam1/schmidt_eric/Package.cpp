#include "Package.h"

Package::Package(string _desc, double _weight) {
    if (_desc != "") {
        this->desc = _desc;
    } else {
        this->desc = "[No description]";
    }

    cout << _weight << endl;
    if (_weight > 0) {
        this->weight = _weight;
    } else {
        this->weight = 0.1;
    }
}

string Package::getDesc() const {
    return this->desc;
}

double Package::getWeight() const {
    return this->weight;
}

bool Package::operator>(const Package &other) {
    return this->weight > other.weight;
}

ostream& operator<<(ostream &outstream, const Package &pkg) {
    outstream << "Package: " << pkg.getDesc() << "; ";
    outstream << "weight: " << pkg.getWeight();
    outstream << " lbs. ";
    return outstream;
}