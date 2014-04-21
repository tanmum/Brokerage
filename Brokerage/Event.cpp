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

double Event::getProfitFor()
{
	double profit = 0;

	profit -= getCost();

	if (travel)
		profit -= travel->getCost();
	
	for(SmartPtr<Iterator> iterator(orders.getIterator()); iterator->hasNext(); )
    {
		Order *order = (Order *) iterator->next();

		if (order)
			profit += order->getProfit();
	}

	return profit;  
}
