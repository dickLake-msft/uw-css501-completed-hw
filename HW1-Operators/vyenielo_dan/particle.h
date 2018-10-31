/*
The particle class is an educational exploration of heap memory allocation, 
operator overloading, and the assorted interactions of these programming
concepts with abstract data types. A particle is composed of mass and volume
pointers. Memory is allocated during construction, and freed during 
destruction. Particles maintain two invariants. A non-default initialized 
particle has non-zero mass and positive volume. Default initialized particles
have 0 mass and volume. Accessor and mutator functions preserve this invariant.
Author: Dan Vyenielo (dvyenielo@gmail.com).
*/
#ifndef PARTICLE_H
#define PARTICLE_H
#include <stdexcept>
#include <iostream>
class particle {
public:
	particle();
	particle(const int mass, const unsigned volume);
	particle(const particle& source);
	
	void set_mass(const int mass);
	int get_mass() const;

	void set_volume(const unsigned volume);
	unsigned get_volume() const;

	particle& operator=(const particle& rhs);
	particle operator+(const particle& rhs) const;
	particle& operator+=(const particle& rhs);
	bool operator!=(const particle& rhs) const;
	bool operator==(const particle& rhs) const;

	~particle();
private:
	void validate_mass(const int mass) const;
	bool is_valid_mass(const int mass) const;
	void validate_volume(const unsigned volume) const;
	bool is_valid_volume(const unsigned volume) const;
	
	int* mass;
	unsigned* volume;
};
#endif // !PARTICLE_H