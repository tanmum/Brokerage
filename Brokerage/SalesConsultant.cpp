#include "SalesConsultant.hpp"
#include "Deal.hpp"
#include "CompTerms.hpp"

ObjectManager SalesConsultant::manager;

SalesConsultant::SalesConsultant(char *nm, char *ph)
{
	manager.addObject(*this);

	name = nm;
	phoneNumber = ph;
}

SalesConsultant::~SalesConsultant()
{
    manager.remove(*this);
}

void SalesConsultant::addDeal(Deal& d)
{
	deals.append(&d);
}

void SalesConsultant::setCompTerms(CompTerms& ct)
{
    ct.setPrevious(*compTerms);
	compTerms = &ct;
}

double SalesConsultant::getTravelCost()
{
    SmartPtr<Iterator> it(deals.getIterator());
    auto cost = 0.0;
    while (it->hasNext()) {
        auto next = (Deal*)it->next();
        cost += next->getTravelCost();
    }
    return cost;
}


