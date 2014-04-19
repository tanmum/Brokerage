#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include "../../Common/String.hpp"
#include "../../Common/List.hpp"

#include "PersistentObject.hpp"
#include "ObjectManager.hpp"

class Terms;
class Deal;

class Product : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	String name;
	String description;
	List terms;
	List deals;

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	Product(char *nm, char *ds);
	~Product();
	
	void addTerms(Terms& t);
	void removeTerms(Terms& t);
    void addDeal(Deal& d);
	
	const String& getName() { return name; }	
	void setName(String& nm) { name = nm; }

	const String& getDescription() { return description; }
	void setDescription(String& str) { description = str; }

	String getPriceRange();
	double getProfitFor();
};

#endif
