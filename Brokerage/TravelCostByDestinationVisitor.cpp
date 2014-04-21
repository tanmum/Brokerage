//
//  TravelCostByDestinationVisitor.cpp
//  Brokerage
//
//  Created by Tan Bui on 4/21/14.
//  Copyright (c) 2014 tanbui. All rights reserved.
//

#include "TravelCostByDestinationVisitor.hpp"

void TravelCostByDestinationVisitor::execute(Event * event)
{
    if (!event) return;
    auto travel = event->travel;
    if (!travel) return;
    SmartPtr<Iterator> it(this->destinationToCostList.getIterator());
    bool itContainsTravelDestination = false;
    while (it->hasNext()) {
        auto next = (DestinationToCost*) it->next();
        if (next->destination == travel->getDestination()) {
            next->cost += travel->getCost();
            itContainsTravelDestination = true;
        }
    }
    if (!itContainsTravelDestination) {
        auto ndc = new DestinationToCost();
        ndc->destination = travel->getDestination();
        ndc->cost = travel->getCost();
        this->destinationToCostList.append(ndc);
    }
}

void* TravelCostByDestinationVisitor::getState()
{
    totalTravelCost = 0.0;
    SmartPtr<Iterator> it(this->destinationToCostList.getIterator());
    while (it->hasNext()) {
        auto next = (DestinationToCost*) it->next();
        totalTravelCost += next->cost;
    }
    return &totalTravelCost;
}

void TravelCostByDestinationVisitor::foreachDestinationToCost(std::function<void (String, double)> f)
{
    SmartPtr<Iterator> it(this->destinationToCostList.getIterator());
    while (it->hasNext()) {
        auto next = (DestinationToCost*) it->next();
        f(next->destination, next->cost);
    }
}

void TravelCostByDestinationVisitor::removeDestinationToCostList()
{
    SmartPtr<Iterator> it(this->destinationToCostList.getIterator());
    while (it->hasNext()) {
        auto next = (DestinationToCost*) it->next();
        this->destinationToCostList.remove(next);
        delete next, next = 0;
    }
}