#ifndef __SALES_CONSULTANT_HPP__
#define __SALES_CONSULTANT_HPP__

#include <String>
#include <vector>
using namespace std;
#include "ObjectManager.hpp"
#include "Visitor.hpp"

class Deal;
class CompTerms;
class TravelVisitor;

class SalesConsultant : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager
    friend class TravelVisitor;

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

	List& getDeals() {return deals;}
	void acceptVisitor(Visitor *v) {if (v) v->execute(this);}
}; 

#endif
