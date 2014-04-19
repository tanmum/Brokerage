#include "Company.hpp"
#include "Address.hpp"

Company::Company(char *nm, Address *add, char *ph, char *fx)
{
	name = nm; 
	address = add;
	phone = ph;
	fax = fx;
}

Company::~Company()
{
    address = 0;
}

