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

double Deal::getProfit()
{
    SmartPtr<Iterator> it(events.getIterator());
    auto dealProfit = 0.0;
    while (it->hasNext()) {
        auto next = (Event*)it->next();
        auto eventProfit = next->getProfit();
        dealProfit += eventProfit;
    }
    return dealProfit;
}

double Deal::getTravelCost()
{
    SmartPtr<Iterator> it(events.getIterator());
    auto cost = 0.0;
    while (it->hasNext()) {
        auto next = (Event*)it->next();
        cost += next->getTravelCost();
    }
    return cost;
}
