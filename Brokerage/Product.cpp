#include "Product.hpp"
#include "Terms.hpp"
#include "Deal.hpp"
#include <iostream>
using namespace std;

ObjectManager Product::manager;

Product::Product(char *nm, char *ds)
{
	manager.addObject(*this);

	name = nm;
	description = ds; 
}

Product::~Product()
{
	cout << "Product::~Product()\n";
    manager.remove(*this);
}

void Product::addTerms(Terms& t)
{
	terms.append(&t);
}

void Product::removeTerms(Terms& t)
{
    terms.remove(&t);
}

void Product::addDeal(Deal& d)
{
	deals.append(&d);
}

String Product::getPriceRange()
{
	String ret("");
	double min = 0;
	double max = 0;

	for (SmartPtr<Iterator> it(terms.getIterator()); it->hasNext(); )
	{
		Terms* t = (Terms *) it->next();
		if (t)
		{
			double price = t->getPrice();
			max = (price > max) ? price : max;
			min = ( price < min  || min == 0) ? price : min;
		}
	}
	
	char minStr[50];
	char maxStr[50];

	sprintf(minStr, "$%f", min);
    sprintf(maxStr, " -- $%f", max);
    
    ret << minStr;

	if (min != max)
		ret << maxStr;

	return ret;
}

double Product::getProfitFor()
{
	double profit = 0;

	// TODO: DONE
    SmartPtr<Iterator> it(deals.getIterator());
    while (it->hasNext()) {
        auto next = (Deal*)it->next();
        auto dealProfit = next->getProfit();
        profit += dealProfit;
    }

	return profit;
}
