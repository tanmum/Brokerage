#include "State.hpp"

ObjectManager State::manager;	// This class' manager

State::State(char *abr, char *nm)
{
	manager.addObject(*this);

	abrev = abr;  
	name = nm;
}

State::~State()
{
    manager.remove(*this);
}


