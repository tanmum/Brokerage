#include "Customer.hpp"
#include "Address.hpp"
#include "Person.hpp"
#include "Deal.hpp"

ObjectManager Customer::manager;

Customer::Customer(char *cname, Address *add, char *cphone, char *fx, char *nm, char *ph, char *em)
    : Company(cname, add, cphone, fx)
{
	manager.addObject(*this);

	contact = new Person(nm, ph, em); 
}

Customer::~Customer()
{
    manager.remove(*this);
    if (contact) delete contact, contact = 0;
}


