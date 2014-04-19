#include "CompTerms.hpp"
#include "SalesConsultant.hpp"
#include "Deal.hpp"

ObjectManager CompTerms::manager;

CompTerms::CompTerms(double cp, SalesConsultant *sc)
{
	manager.addObject(*this);

	commissionPercent = cp;
	sc->setCompTerms(*this);
}

CompTerms::~CompTerms()
{
    manager.remove(*this);
}



