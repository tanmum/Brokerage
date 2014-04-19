#ifndef ___HPP__
#define ___HPP__

#include "../../Common/String.hpp"
#include "PersistentObject.hpp"

class Address;

class Company : public PersistentObject
{
protected:
	String name;
	Address *address;
	String phone;
	String fax;

public:
	Company(char *nm, Address *add, char *ph, char *fx);
	virtual ~Company();
	
	const String& getName() {return name;}
	void setName(String& s) {name = s;}

	Address& getAddress() {return *address;}
	void setAddress(Address& s) {address = &s;}

	const String& getPhone() {return phone;}
	void setPhone(String& s) {phone = s;}

	const String& getFax() {return fax;}
	void setFax(String& s) {fax = s;}
};

#endif
