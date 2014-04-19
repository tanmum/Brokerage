#include "Terms.hpp"
#include "Vendor.hpp"
#include "Product.hpp"

ObjectManager Terms::manager;

Terms::Terms(Vendor *v, Product *p, double prc, char *dl, char *rfd)
{
	manager.addObject(*this);

	product = p;
	vendor = v;
	price = prc;
	delay = dl;
	refund = rfd;

	product->addTerms(*this);
	vendor->addTerms(*this);
}

Terms::~Terms()
{
    manager.remove(*this);
    vendor = 0;
    product = 0;
}

void Terms::removeTerms(Terms& t)
{
	t.product->removeTerms(t);
	t.vendor->removeTerms(t);
	manager.remove(t);
}



