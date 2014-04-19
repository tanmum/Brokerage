#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "../../Common/String.hpp"
#include "ObjectManager.hpp"

class State : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
 	String abrev;
	String name;

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class
	
	State(char *abr, char *nm);
	~State();
	
	const String& getAbrev() {return abrev;}
	void setAbrev(String& s) {abrev = s;}

	const String& getName() {return name;}
	void setName(String& s) {name = s;}
};

#endif
