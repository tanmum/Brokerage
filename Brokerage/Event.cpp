#include "Event.hpp"
#include "Travel.hpp"
#include "Order.hpp"

ObjectManager Event::manager;

Event::Event(char *cm, char *dt, char *ma, char *mi)
{
	manager.addObject(*this);

	comments = cm;
	date = dt;
	mainAction = ma;
	mainIssue = mi;
	
	travel = 0;
} 

Event::~Event()
{
    manager.remove(*this);
}

double Event::getProfit()
{
    auto eventCost = getCost();
    if (travel) {
        eventCost += travel->getCost();
    }
    auto gain = 0.0;
    SmartPtr<Iterator> it(orders.getIterator());
    while (it->hasNext()) {
        auto next = (Order*)it->next();
        gain += next->getPrice();
    }
    return gain - eventCost;
}

double Event::getTravelCost()
{
    if (travel) {
        return travel->getCost();
    }
    return 0;
}

