#ifndef __TRAVEL_VISITOR_HPP__
#define __TRAVEL_VISITOR_HPP__

#include "Visitor.hpp"
#include "SalesConsultant.hpp"
#include "Deal.hpp"
#include "Event.hpp"
#include "Travel.hpp"
#include "../../Common/List.hpp"
#include "../../Common/String.hpp"
#include <iostream>
using namespace std;

class TravelVisitor : public Visitor
{
    double travelCost;
public:
    TravelVisitor() :travelCost(0.0) {}
    void execute(SalesConsultant *);
	void execute(Product *) {}
	void execute(Deal *);
    void execute(Event *);
    void execute(Order *) {};
    
    void *getState();
};

#endif
