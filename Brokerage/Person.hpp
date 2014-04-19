#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include "../../Common/String.hpp"
#include "PersistentObject.hpp"

class Person : public PersistentObject
{
protected:
	String name;
	String phone;
	String email;

public:
	Person(char *nm, char *ph, char *em);
	
	String& getName() {return name;}
	void setName(String& s) {name = s;}

	String& getPhone() {return phone;}
	void setPhone(String& s) {phone = s;}

	String& getEmail() {return email;}
	void setEmail(String& s) {email = s;}
}; 

#endif
