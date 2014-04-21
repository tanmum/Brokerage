//
//  TravelCostByDestinationVisitor.h
//  Brokerage
//
//  Created by Tan Bui on 4/21/14.
//  Copyright (c) 2014 tanbui. All rights reserved.
//

#ifndef __Brokerage__TravelCostByDestinationVisitor__
#define __Brokerage__TravelCostByDestinationVisitor__

#include <iostream>
#include <functional>
#include "TravelVisitor.hpp"

class TravelCostByDestinationVisitor : public TravelVisitor
{
    struct DestinationToCost
    {
        String destination;
        double cost;
    };
    List destinationToCostList;
    double totalTravelCost;
public:
    TravelCostByDestinationVisitor() :totalTravelCost(0.0) {}
    virtual ~TravelCostByDestinationVisitor() { removeDestinationToCostList(); }
    void execute(SalesConsultant *sc) { removeDestinationToCostList(); TravelVisitor::execute(sc); }
    void execute(Event *);
    void* getState();
    void foreachDestinationToCost(std::function<void (String, double)> f);
private:
    void removeDestinationToCostList();
};

#endif /* defined(__Brokerage__TravelCostByDestinationVisitor__) */
