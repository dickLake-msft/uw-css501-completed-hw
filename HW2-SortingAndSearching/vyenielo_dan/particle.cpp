/*
Particle is designed as an analog for "real" particles. We can model a subset 
of the world's particles with this class. As an assumption, a particle is 
has non-zero mass and positive volume. One invariant is maintained, a default 
initialized particle will has no mass or volume (singularity).
Author: Dan Vyenielo (dvyenielo@gmail.com)
Note: a useful reference for operator overloading
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading
*/
#include "particle.h"
#include <stdexcept>

/*
Default construction of a particle.
*/
particle::particle() {
	initialize();
}

/*
Paramater construction of a particle. Validates mass and volume paramaters.
*/
particle::particle(const int mass, const int volume) {
	validate_mass(mass);
	validate_volume(volume);
	this->mass = mass;
	this->volume = volume;
}

/*
Default initialization.
*/
void particle::initialize() {
	this->mass = 0;
	this->volume = 0;
}

/*
Validates mass paramater.
*/
void particle::validate_mass(const int mass) {
	if (!is_valid_mass(mass)) {
		throw std::domain_error("mass != 0");
	}
}


/*
Returns true when mass is a non-zero value.
*/
bool particle::is_valid_mass(const int mass) {
	return mass != 0;
}

/*
Validates volume paramater.
*/
void particle::validate_volume(const int volume) {
	if (!is_valid_volume(volume)) {
		throw std::domain_error("volume > 0");
	}
}

/*
Returns true when volume is positive.
*/
bool particle::is_valid_volume(const int volume) {
	return volume > 0;
}

/*
Returns the mass of this particle.
*/
int particle::get_mass() const {
	return mass;
}

/*
Validates and sets the mass of this particle.
*/
void particle::set_mass(const int mass) {
	validate_mass(mass);
	this->mass = mass;
}

/*
Returns the volume of this particle.
*/
int particle::get_volume() const {
	return volume;
}

/*
Validates and sets the volume of this particle.
*/
void particle::set_volume(const int volume) {
	validate_volume(volume);
	this->volume = volume;
}

particle& particle::operator=(particle rhs) {
	this->mass = rhs.get_mass();
	this->volume = rhs.get_volume();
	return *this;
}

particle particle::operator+(const particle& rhs) const {
	particle result = *this;
	result += rhs;
	return result;
}

particle& particle::operator+=(const particle& rhs) {
	this->mass += rhs.get_mass();
	this->volume += rhs.get_volume();
	return *this;
}

bool particle::operator<(const particle& rhs) {
	return !(this->mass >= rhs.get_mass() || this->volume >= rhs.get_volume());
}

bool particle::operator<=(const particle& rhs) {
	return this->operator==(rhs) || this->operator<(rhs);
}

bool particle::operator>(const particle& rhs) {
	return !this->operator<=(rhs);
}

bool particle::operator>=(const particle& rhs) {
	return !this->operator<(rhs);
}

bool particle::operator!=(const particle& rhs) {
	return this->mass != rhs.get_mass() || this->volume != rhs.get_volume();
}

bool particle::operator==(const particle& rhs) {
	return !(this->operator!=(rhs));
}

std::ostream& operator<<(std::ostream& os, const particle& obj)
{
	os << "[m == " << obj.get_mass() << " v == " << obj.get_volume() << ']';
	return os;
}

particle::~particle() {
	//no dynamic memory 
}