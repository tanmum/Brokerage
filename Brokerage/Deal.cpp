#include "Deal.hpp"
#include "Customer.hpp"
#include "Event.hpp"
#include "Product.hpp"
#include "SalesConsultant.hpp"

ObjectManager Deal::manager;

int Deal::curNumb = 0;

Deal::Deal(Customer *c, SalesConsultant *sc, Product *p)
{
	manager.addObject(*this);

	number = getNextNumber();

	customer = c;
	customer->addDeal(*this);

	salesConsultant = sc;
	salesConsultant->addDeal(*this);

	product = p;
	product->addDeal(*this);
}

Deal::~Deal()
{
    manager.remove(*this);
}

double Deal::getProfitFor()
{
	double profit = 0;

	for (SmartPtr<Iterator> it(events.getIterator()); it->hasNext(); )
	{
		Event *e = (Event *) it->next();
		if (e)
			profit += e->getProfitFor();
	}
	
	return profit;

}

Event& Deal::getEventAt(int i)
{
	Event *ret = 0;
	
	for (SmartPtr<Iterator> it(events.getIterator()); i >= 0 && it->hasNext(); i--)
	{
		Event *e = (Event *) it->next();
		if (i == 0)
			ret = e;
	}

	return *ret;
}
