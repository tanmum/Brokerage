#ifndef __ADDRESS_HPP__
#define __ADDRESS_HPP__

#include "../../Common/String.hpp"
#include "ObjectManager.hpp"

class State;

class Address : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	String lineOne;
	String lineTwo;
	String city;
	State *state;
	String zip;

public:
	static ObjectManager *getManager() { return &manager; }	// Get the manager for this class

	Address(char *l1, char *l2, char *ct, State *st, char *zp);
	~Address();
	
	const String& getLineOne() {return lineOne;}
	const String& getLineTwo() {return lineTwo;}
	const String& getCity()    {return city;}
	const State&  getState()   {return *state;}
	const String& getZip()     {return zip;}

	void setLineOne(String& s) {lineOne = s;}
	void setLineTwo(String& s) {lineTwo = s;}
	void setCity(String& s)    {city = s;}
	void setState(State& s)    {state = &s;}
	void setZip(String& s)     {zip = s;}
};

#endif
