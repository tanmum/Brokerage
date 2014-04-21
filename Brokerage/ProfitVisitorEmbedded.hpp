#ifndef _ProfitVisitorEmbedded
#define _ProfitVisitorEmbedded

#include "Visitor.hpp"
#include <iostream>

class ProfitVisitorEmbedded : public Visitor
{
private:
        double profit;
public:             
		ProfitVisitorEmbedded() : profit(0){};
		void execute(SalesConsultant *){};
        void execute(Product *);        
		void execute(Deal *){};
		void execute(Event *){};
		void execute(Order *){};
        void *getState() {return &profit;}
};

#endif
