#ifndef __VENDOR_HPP__
#define __VENDOR_HPP__

#include "ObjectManager.hpp"
#include "Company.hpp"

class Terms;
class Address;

class Vendor : public Company
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	List terms;

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	Vendor(char *nm, Address *add, char *ph, char *fx);
	~Vendor();
	
	void addTerms(Terms& t);
	void removeTerms(Terms& t);
};

#endif
