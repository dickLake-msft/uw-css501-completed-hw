#include "Driver.h"

Driver::Driver() {
}

// FIXED FROM ORIGINAL SUBMISSION
int Driver::main() {

    DeliveryManager* dm = new DeliveryManager();
    cout << "Delivery manager has memory address: " << dm << endl;

    Package* p = new Package("A sock", 0.2);
    cout << *p << endl;

    Package* p2 = new Package("", -0.3);
    cout << *p2 << endl;

    dm->add(p);
    cout << dm->getNumPackages() << endl;
    cout << dm->getNumDrones() << endl;

    dm->add(p2);
    cout << dm->getNumPackages() << endl;
    cout << dm->getNumDrones() << endl;

    dm->add(new Package("Heavy!", 21.0));
    cout << dm->getNumPackages() << endl;
    cout << dm->getNumDrones() << endl;

    cout << "Is p heavier than p2? " << (*p > *p2) << endl;

    cout << *dm << endl;

    return 0;
};