#ifndef _ProfitVisitor
#define _ProfitVisitor

#include "Visitor.hpp"
#include <iostream>

class ProfitVisitor : public Visitor
{
private:
        double profit;
public:             
		ProfitVisitor() : profit(0) {};
		void execute(SalesConsultant *) {}; 
        void execute(Product *);
        void execute(Deal *);
        void execute(Event *);
        void execute(Order *);
        
        void *getState() {return &profit;}
};

#endif
