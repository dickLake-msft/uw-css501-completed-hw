#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>
#include <string>

using namespace std;

class Player {
public:
    Player();
    Player(string lastName, string firstName, int number);
    string toString();
    int getNumber() const;
    string getLastName() const;
    bool operator==(const Player &player);
    bool operator<(const Player &player);
    bool operator>(const Player &player);
    bool operator>=(const Player &player);
    bool operator<=(const Player &player);
private:
    string lastName;
    string firstName;
    int number;
};

#endif