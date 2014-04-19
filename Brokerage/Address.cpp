#include "Address.hpp"
#include "State.hpp"

ObjectManager Address::manager;

Address::Address(char *l1, char *l2, char *ct, State *st, char *zp)
{
	manager.addObject(*this);

	lineOne = l1; 
	lineTwo = l2;
	city = ct;
	state = st;
	zip = zp;
}

Address::~Address()
{
    manager.remove(*this);
    state = 0;
}


