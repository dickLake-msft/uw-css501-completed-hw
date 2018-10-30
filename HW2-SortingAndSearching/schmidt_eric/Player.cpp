/*
In this implementation of the Player class, the player's
jersey number is the sortable property.
*/
#include "Player.h"

Player::Player() {
    // Set all of the private fields to default values.
    this->lastName = "";
    this->firstName = "";
    this->number = 0;
}

Player::Player(string lastName, string firstName, int number) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->number = number;
}

string Player::toString() {
     string result = "#" + to_string(this->number) + ": ";
     result += this->lastName + ", " + this->firstName;
     return result;
}

int Player::getNumber() const {
    return this->number;
}

string Player::getLastName() const {
    return this->lastName;
}

// ### Define the operators for comparing two Player objects ####

bool Player::operator==(const Player &player) {
    if (&player == this) return true;

    if (player.getNumber() == this->number) {
        return true;
    } else {
        return false;
    }
}

bool Player::operator<=(const Player &player) {
    if (*this == player) return true;

    if (this->number < player.getNumber()) {
        return true;
    } else {
        return false;
    }
}

bool Player::operator>=(const Player &player) {
    if (*this == player) return true;

    if (this->number > player.getNumber()) {
        return true;
    } else {
        return false;
    }
}

bool Player::operator>(const Player &player) {
    return !(*this <= player);
}

bool Player::operator<(const Player &player) {
    return !(*this >= player);
}
