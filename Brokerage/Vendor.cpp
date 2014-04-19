#include "Vendor.hpp"
#include "Terms.hpp"
#include "Address.hpp"

ObjectManager Vendor::manager;	// This class' manager

Vendor::Vendor(char *nm, Address *add, char *ph, char *fx)
    : Company(nm, add, ph, fx)
{ 
	manager.addObject(*this);
}

Vendor::~Vendor()
{
    manager.remove(*this);
}

void Vendor::addTerms(Terms& t)
{
	terms.append(&t);
}

void Vendor::removeTerms(Terms& t)
{
    terms.remove(&t);
}


