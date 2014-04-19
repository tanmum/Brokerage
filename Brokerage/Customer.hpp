#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__

#include <vector>
using namespace std;
#include "ObjectManager.hpp"
#include "Company.hpp"

class Deal;
class Person;
class Address;

class Customer : public Company
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	Person *contact;
	List deals;

public:
	static ObjectManager *getManager() {return &manager;}	// Get the manager for this class

	Customer(char *cname, Address *add, char *cphone, char *fx, char *nm, char *ph, char *em);
	~Customer();
	
	void addDeal(Deal& d) {deals.append(&d);} 
	Person& getContact() {return *contact;}
	void setContact(Person& p) {contact = &p;}
};

#endif
