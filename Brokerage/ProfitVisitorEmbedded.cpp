#include "ProfitVisitorEmbedded.hpp"
#include "Product.hpp"
#include "Deal.hpp"
#include "Event.hpp"
#include "PhoneCall.hpp"
#include "Meeting.hpp"
#include "Travel.hpp"
#include "Order.hpp"
#include "Terms.hpp"
#include "CompTerms.hpp"

void ProfitVisitorEmbedded::execute(Product *p)
{
	if (p)
		for (SmartPtr<Iterator> it(p->deals.getIterator()); it->hasNext(); )
		{
			Deal *d = (Deal *) it->next();
			if (d)
				for (SmartPtr<Iterator> it(d->events.getIterator()); it->hasNext(); )
				{				
					Event *e = (Event *) it->next();
					if (e)
					{
						profit -= e->getCost();

						if (e->travel)
							profit -= e->travel->getCost();

						for (SmartPtr<Iterator> it(e->orders.getIterator()); it->hasNext(); )
						{				
							Order *o = (Order *) it->next();
							if (o)
							{
								Terms *terms = o->terms;
								if (terms)
								{
									double orderGain = (o->price * o->discount - terms->getPrice()) * o->quantity;
									CompTerms *ct = o->compTerms;
									if (ct)
										orderGain -= ct->getCommission(orderGain);
									profit += orderGain;
								}

							 }
						}
					}
			 }
		}
}


