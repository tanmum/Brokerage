#include "TravelVisitor.hpp"

void TravelVisitor::execute(SalesConsultant * sc)
{
    if (!sc) return;
    SmartPtr<Iterator> it(sc->deals.getIterator());
    while (it->hasNext()) {
        ((Deal*)it->next())->acceptVisitor(this);
    }
}

void TravelVisitor::execute(Deal * deal)
{
    if (!deal) return;
    SmartPtr<Iterator> it(deal->events.getIterator());
    while (it->hasNext()) {
        ((Event*)it->next())->acceptVisitor(this);
    }
}

void TravelVisitor::execute(Event *event)
{
    auto travel = event->travel;
    if (travel) {
        travelCost += travel->getCost();
    }
}

void* TravelVisitor::getState()
{
    return &travelCost;
}