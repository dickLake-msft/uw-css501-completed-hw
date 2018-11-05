//-------------------------------------------------------------------------------------------------
// Filename: Creatures.cpp
// Title: CSS 501 Homework 1 - Operator Overloading
// Programmer: Katrina Swanson
// Date Completed: 10/06/2018
// Description: This .cpp file contains the implementation of the BattleCreatures class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include "Creatures.h"
using namespace std;

#define DEFAULT_STRENGTH 5
#define DEFAULT_LEVEL 1
//Constructors & destructor

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature() - default constructor
// Description: assigns default values to a new Battle Creature.
//-------------------------------------------------------------------------------------------------
BattleCreature::BattleCreature()
{
	//Default values for the new creature
	name = "Default Creature";
	color = "red";
	power = "fire";
	strength = DEFAULT_STRENGTH;
	//All newly-created creatures are level 1
	level = DEFAULT_LEVEL;
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature() - explicit constructor
// Description: assigns user-specified values to a new Battle Creature.
// Calls - Colors.at() and Powers.at() - extracts color and power strings from their
//		respective maps
//-------------------------------------------------------------------------------------------------
BattleCreature::BattleCreature(string i_name, int i_color, int i_power, int i_strength)
{
	//Custom values for the new creature
	name = i_name;
	color = Colors.at(i_color);
	power = Powers.at(i_power);
	strength = i_strength;
	//All newly-created creatures are level 1
	level = DEFAULT_LEVEL;
}


//-------------------------------------------------------------------------------------------------
// Method: ~BattleCreature() - destructor
// Description: prints a message whenever a creature object is destroyed. Not terribly exciting.
//-------------------------------------------------------------------------------------------------
BattleCreature::~BattleCreature()
{
	cout << "Creature Object destructor called." << endl << endl;
}

//Operator overloads

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature operator+(const BattleCreature &creature) const
// Description: adds two creatures to create a higher-level creature
// Calls: BattleCreature& operator+=(const BattleCreature &creature)
//-------------------------------------------------------------------------------------------------
BattleCreature BattleCreature::operator+(const BattleCreature &creature) const
{
	BattleCreature newCreature = *this;
	newCreature += creature;
	return newCreature;
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature& operator+=(const BattleCreature &creature)
// Description: adds two creatures to create a higher-level creature
//-------------------------------------------------------------------------------------------------
BattleCreature& BattleCreature::operator+=(const BattleCreature &creature)
{
	name = name + " " + creature.name;

	//only need to update color and power if the second parent is stronger
	if (strength < creature.strength)
	{
		color = creature.color;
		power = creature.power;
	}

	strength += creature.strength;
	level++;
	return *this;
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature operator-(const BattleCreature &creature) const
// Description: subtracts a low-level creature from a higher-level one
// Calls: BattleCreature& operator-=(const BattleCreature &creature)
//-------------------------------------------------------------------------------------------------
BattleCreature BattleCreature::operator-(const BattleCreature &creature) const
{
	BattleCreature newCreature = *this;
	if (newCreature.level > creature.level) //if you've done it right, modify newCreature
	{
		newCreature -= creature;
	}
	else //if you've done it wrong, don't modify newCreature
	{
		cout << "You can't subtract a higher-level creature from a lower-level one." << endl;
	}
	
	return newCreature;
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature& operator-=(const BattleCreature &creature)
// Description: subtracts a low-level creature from a higher-level one
//-------------------------------------------------------------------------------------------------
BattleCreature& BattleCreature::operator-=(const BattleCreature &creature)
{
	if (level > creature.level) //if you've done it right, modify *this
	{
		//Power, color, and name stay the same for the sub-creature
		strength -= creature.strength;
		if (strength <= 0) //lowest "possible strength" is 1
			strength = 1;

		level -= creature.level;
		if (level <= 0) //lowest "possible level" is 1
			level = 1;
	}
	else //if you've done it wrong, don't modify *this
	{
		cout << "You can't subtract a higher-level creature from a lower-level one." << endl;
	}
	
	return *this;
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature& operator==(const BattleCreature &creature)
// Description: compares two creatures to determine creature equality
//-------------------------------------------------------------------------------------------------
bool BattleCreature::operator==(const BattleCreature &creature) const
{
	return ((strength == creature.strength) && (power.compare(creature.power) == 0) 
		&& (color.compare(creature.color) == 0) && (level == creature.level));
}

//-------------------------------------------------------------------------------------------------
// Method: BattleCreature& operator!=(const BattleCreature &creature)
// Description: compares two creatures to determine creature equality
// Calls: bool operator==(const BattleCreature &creature) const
//-------------------------------------------------------------------------------------------------
bool BattleCreature::operator!=(const BattleCreature &creature) const
{
	return (!(*this == creature));
}

//Class Utilities

//-------------------------------------------------------------------------------------------------
// Function: ostream& operator<<(ostream &outstream, const BattleCreature &creature)
// Description: ostream overload for Battle Creature objects
//-------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &outStream, const BattleCreature &creature)
{
	outStream << "Name:\t\t" << creature.name << endl
		<< "Color:\t\t" << creature.color << endl
		<< "Power Type:\t" << creature.power << endl
		<< "Strength:\t" << creature.strength << endl
		<< "Level:\t\t" << creature.level << endl;
	return outStream;
}

//-------------------------------------------------------------------------------------------------
// Description: map of int-to-string for allowable Battle Creature colors
//-------------------------------------------------------------------------------------------------
map<int, string> BattleCreature::Colors{
	{0, "red"}, 
	{1, "blue"}, 
	{2, "yellow"}, 
	{3, "green"},
	{4, "purple"}, 
	{5, "orange"}
};

//-------------------------------------------------------------------------------------------------
// Description: map of int-to-string for allowable Battle Creature power types
//-------------------------------------------------------------------------------------------------
map<int, string> BattleCreature::Powers{
	{ 0, "fire" },
	{ 1, "water" },
	{ 2, "air" },
	{ 3, "fighting" },
	{ 4, "psychic" },
	{ 5, "electric" }
};