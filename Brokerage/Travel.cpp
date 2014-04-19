#include "Travel.hpp"

ObjectManager Travel::manager;

Travel::Travel(double af, double cr, double tx, char *dest)
{
	manager.addObject(*this);
	
	airfare = af;
	car = cr;
	taxi = tx;
	destination = dest;
}

Travel::~Travel()
{
    manager.remove(*this);
}

double Travel::getCost()
{
	return airfare + car + taxi;
}

