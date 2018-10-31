/*
Author: Dan Vyenielo(dvyenielo@gmail.com)
*/
#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>

class particle
{
public:
	particle();
	particle(const int mass, const int volume);
	int get_mass() const;
	void set_mass(const int mass);
	int get_volume() const;
	void set_volume(const int volume);
	particle& operator=(particle rhs);
	particle operator+(const particle& rhs) const;
	particle& operator+=(const particle& rhs);
	bool operator<(const particle& rhs);
	bool operator<=(const particle& rhs);
	bool operator>(const particle& rhs);
	bool operator>=(const particle& rhs);
	bool operator!=(const particle& rhs);
	bool operator==(const particle& rhs);
	friend std::ostream& operator<<(std::ostream& os, const particle& obj);
	~particle();
private:
	void initialize();
	void validate_mass(const int mass);
	bool is_valid_mass(const int mass);
	void validate_volume(const int volume);
	bool is_valid_volume(const int volume);
	int mass;
	int volume;
};

std::ostream& operator<<(std::ostream& os, const particle& obj);

#endif // PARTICLE_H
