#ifndef __DEAL_HPP__
#define __DEAL_HPP__

#include "ObjectManager.hpp"
#include "../../Common/List.hpp"

class Customer;
class Event;
class Product;
class SalesConsultant;

class Deal : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager
	static int curNumb;
	static int getNextNumber() {return curNumb++;}
	
protected:
	int number;
	Customer *customer;
	SalesConsultant *salesConsultant;
	Product *product;
	List events;		// Deal contains many events

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	Deal(Customer *c, SalesConsultant *sc, Product *p);
	~Deal();
	
	int getNumber(){return number;}
	void addEvent(Event& e) {events.append(&e);}
	List& getEvents() {return events;}

	Customer& getCustomer() {return *customer;}
	Product& getProduct() {return *product;}
	SalesConsultant& getSalesConsultant() {return *salesConsultant;}

	Event& getEventAt(int i);
    double getProfit();
    double getTravelCost();
}; 

#endif
