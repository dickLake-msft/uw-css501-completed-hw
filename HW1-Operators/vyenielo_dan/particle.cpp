/*
Note: please recognize that I have left comments in some member functions.
I have done this to see when these functions are called by the driver. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "particle.h"

/*
Heap allocates new memory for mass and volume pointers.
post-condition: default constructed object with 0 volume and mass.
*/
particle::particle() {
	std::cout << "Default construction ";	//see note above^
	this->mass = new int;
	*(this->mass) = 0;
	this->volume = new unsigned;
	*(this->volume) = 0;
}

/*
Heap allocates new memory for mass and volume pointers.
post-condition: pass by value constructed object with param volume and mass.
*/
particle::particle(const int mass, const unsigned volume) {
	std::cout << "Param construction ";
	validate_mass(mass);
	this->mass = new int;
	*(this->mass) = mass;
	validate_volume(volume);
	this->volume = new unsigned;
	*(this->volume) = volume;
}

/*
Heap allocates new memory for mass and volume pointers. Note, assumes source 
particle is valid.
post-condition: copy constructed object with param volume and mass.
*/
particle::particle(const particle& source) {
	std::cout << "Copy construction ";
	this->mass = new int;
	this->volume = new unsigned;
	*(this->mass) = source.get_mass();
	*(this->volume) = source.get_volume();
}

//throw a domain error if volume is not positive
void particle::validate_volume(const unsigned volume) const {
	if (!is_valid_volume(volume))
		throw std::domain_error("volume must be > 0");
}

//valid particles have volume
bool particle::is_valid_volume(const unsigned volume) const {
	return volume > 0;
}

//throw a domain error if mass is zero
void particle::validate_mass(const int mass) const {
	if (!is_valid_mass(mass))
		throw std::domain_error("mass != 0");
}

//valid particles have mass
bool particle::is_valid_mass(const int mass) const {
	return mass != 0;
}

void particle::set_mass(const int mass) {
	validate_mass(mass); //enforce invariant
	*(this->mass) = mass;
}

int particle::get_mass() const {
	return *(this->mass);
}

void particle::set_volume(const unsigned volume) {
	validate_mass(volume); //enforce invariant
	*(this->volume) = volume;
}

unsigned particle::get_volume() const {
	return *(this->volume);
}

particle& particle::operator=(const particle& rhs) {
	std::cout << "Assignment." << std::endl;
	*(this->mass) = rhs.get_mass();
	*(this->volume) = rhs.get_volume();
	return *this;
}

particle particle::operator+(const particle& rhs) const {
	return particle(*(this->mass) + rhs.get_mass(), 
					*(this->volume) + rhs.get_volume());
}

particle& particle::operator+=(const particle& rhs) {
	*(this->mass) += rhs.get_mass();
	*(this->volume) += rhs.get_volume();
	return *this;
}

bool particle::operator!=(const particle& rhs) const {
	return *(this->mass) != rhs.get_mass() || 
		*(this->volume) != rhs.get_volume();
}

bool particle::operator==(const particle& rhs) const {
	return !(*this != rhs);
}

//return memory to the free store
particle::~particle() {
	std::cout << "Delete" << std::endl;
	delete this->mass;
	delete this->volume;
}