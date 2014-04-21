#include "ProfitVisitor.hpp"
#include "Product.hpp"
#include "Deal.hpp"
#include "Event.hpp"
#include "PhoneCall.hpp"
#include "Meeting.hpp"
#include "Travel.hpp"
#include "Order.hpp"
#include "Terms.hpp"
#include "CompTerms.hpp"

void ProfitVisitor::execute(Product *p)
{
	if (p)
		for (SmartPtr<Iterator> it(p->getDeals().getIterator()); it->hasNext(); )
		{
			Deal *deal = (Deal *) it->next();
			if (deal)
				deal->acceptVisitor(this);
		}
}

void ProfitVisitor::execute(Deal *d)
{
     if (d)
		for (SmartPtr<Iterator> it(d->getEvents().getIterator()); it->hasNext(); )
		{
			Event *evt = (Event *) it->next();
			if (evt)
    			evt->acceptVisitor(this);
		}
}

void ProfitVisitor::execute(Event *e)
{
	if (e)
	{
		profit -= e->getCost();

		if (e->getTravel())
			profit -= e->getTravel()->getCost();

		for (SmartPtr<Iterator> it(e->getOrders().getIterator()); it->hasNext(); )
		{
			Order *ord = (Order *) it->next();
			if (ord)
				ord->acceptVisitor(this);
		}
    }
}

void ProfitVisitor::execute(Order *o)
{
     if (o)
     {
           Terms *terms = o->getTerms();
           if (terms)
           {
              double orderGain = (o->getPrice() * o->getDiscount() - terms->getPrice()) * o->getQuantity();
              CompTerms *ct = o->getCompTerms();
              if (ct)
                 orderGain -= ct->getCommission(orderGain);
              profit += orderGain;
           }
     }
}
