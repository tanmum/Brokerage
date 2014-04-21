#ifndef _Visitor
#define _Visitor

class Product;
class Deal;
class Event;
class Order;
class SalesConsultant;
class Customer;

class Visitor
{
public:
    virtual void execute(SalesConsultant *) = 0;
	virtual void execute(Product *) = 0;
	virtual void execute(Deal *) = 0;
	virtual void execute(Event *) = 0;
	virtual void execute(Order *) = 0;
       
    virtual void *getState() = 0;
};

#endif
