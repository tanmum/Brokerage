#ifndef __SALES_CONSULTANT_HPP__
#define __SALES_CONSULTANT_HPP__

#include <String>
#include <vector>
using namespace std;
#include "ObjectManager.hpp"

class Deal;
class CompTerms;

class SalesConsultant : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	String name;
	String phoneNumber;
	CompTerms *compTerms;

	List deals;

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	SalesConsultant(char *nm, char *ph);
	~SalesConsultant();
	
	void addDeal(Deal& d);

	const String& getName() {return name;}
	void setName(String& str) {name = str;}

	const String& getPhoneNumber() {return phoneNumber;}
	void setPhoneNumber(String& pn) {phoneNumber = pn;}

	void setCompTerms(CompTerms& ct);
	CompTerms& getCompTerms() {return *compTerms;}
    
    double getTravelCost();
}; 

#endif
