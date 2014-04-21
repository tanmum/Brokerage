#include "Order.hpp"
#include "Terms.hpp"
#include "CompTerms.hpp"

ObjectManager Order::manager;

Order::Order(double pr, double disc, int qty, char *tm, CompTerms *ct)
{
	manager.addObject(*this);

	price = pr;
	discount = disc;
	quantity = qty;
	paymentTerms = tm;
	compTerms = ct;
}

Order::~Order()
{
    manager.remove(*this);
    terms = 0;
    compTerms = 0;
}

void Order::setTerms(Terms& t, CompTerms& ct)
{
	terms = &t;
	compTerms = &ct;
}

double Order::getProfit()
{
	double profit = 0;

	double orderGain = (price * discount - terms->getPrice()) * quantity;
	profit = orderGain - compTerms->getCommission(orderGain);

	return profit;
}
