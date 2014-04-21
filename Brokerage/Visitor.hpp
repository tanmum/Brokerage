//
//  Visitor.h
//  Brokerage
//
//  Created by Tan Bui on 4/20/14.
//  Copyright (c) 2014 tanbui. All rights reserved.
//

#ifndef __Brokerage__Visitor__
#define __Brokerage__Visitor__

#include <iostream>
#include "Product.hpp"
#include "Deal.hpp"
#include "Event.hpp"
#include "Order.hpp"
#include "SalesConsultant.hpp"
#include "Customer.hpp"

class Visitor
{
public:
    virtual void execute(Product* product){}
    virtual void execute(Deal* deal){}
    virtual void execute(Event* event){}
    virtual void execute(Order* order){}
    virtual void execute(SalesConsultant* salesConsultant){}
    virtual void execute(Customer* customer){}
    virtual void* getState() = 0;
};

#endif /* defined(__Brokerage__Visitor__) */
