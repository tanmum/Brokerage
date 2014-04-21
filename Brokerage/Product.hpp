#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include "../../Common/String.hpp"
#include "../../Common/List.hpp"

#include "PersistentObject.hpp"
#include "ObjectManager.hpp"
#include "Visitor.hpp"

class Terms;
class Deal;
class ProfitVisitorEmbedded;

class Product : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager
	friend class ProfitVisitorEmbedded;

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

	List& getDeals() {return deals;}
	List& getTerms() {return terms;}
	void acceptVisitor(Visitor *v) {if (v) v->execute(this);}
};

#endif
