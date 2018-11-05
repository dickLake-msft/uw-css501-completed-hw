#ifndef CREATURES_H
#define CREATURES_H
//-------------------------------------------------------------------------------------------------
// Filename: Creatures.h
// Title: CSS 501 Homework 1 - Operator Overloading
// Programmer: Katrina Swanson
// Date Completed: 10/06/2018
// Description: This header file contains the interface for the BattleCreatures class, which 
//		describes Battle Creature objects.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <map>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: BattleCreature
//
// Methods: 
//		BattleCreature operator+(const BattleCreature &creature) const
//		BattleCreature& operator+=(const BattleCreature &creature);
//			-overloads defining addition of two creatures of any level
//
//		BattleCreature operator-(const BattleCreature &creature) const;
//		BattleCreature& operator-=(const BattleCreature &creature);
//			- overloads defining subtraction of low-level creatures from high-level ones
//
//		bool operator==(const BattleCreature &creature) const;
//		bool operator!=(const BattleCreature &creature) const;
//			- overloads defining in/equality of Battle Creatures
//-------------------------------------------------------------------------------------------------
class BattleCreature {
	//Class utilities
	friend ostream& operator<<(ostream &outStream, const BattleCreature &creature);
	static map<int, string> Colors;
	static map<int, string> Powers;

public:
	//Constructors & destructor
	BattleCreature();
	BattleCreature(string name, int col, int pow, int strength);
	~BattleCreature();

	//Access & mutate
	string getName() const { return name; }
	string getColor() const { return color; }
	string getPowerType() const { return power; }
	int getStrength() const { return strength; }
	int getLevel() const { return level; }
	void giveName(string i_name)
	{ name = i_name; }
	void changeColor(string i_color)
	{ color = i_color; }
	void changePower(string i_power)
	{ power = i_power; }
	void changeStrength(int i_strength)
	{ strength = i_strength; }

	//Operator overloads

	BattleCreature operator+(const BattleCreature &creature) const;
	BattleCreature& operator+=(const BattleCreature &creature);
	
	BattleCreature operator-(const BattleCreature &creature) const;
	BattleCreature& operator-=(const BattleCreature &creature);

	bool operator==(const BattleCreature &creature) const;
	bool operator!=(const BattleCreature &creature) const;


private:
	//Creature features
	string name;
	string color;
	string power;
	int strength;
	int level;
};

#endif // !CREATURES_H