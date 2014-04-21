#include <iostream>
using namespace std;
#include "Domain.hpp"
#include "SalesConsultant.hpp"
#include "Product.hpp"
#include "Terms.hpp"
#include "State.hpp"
#include "ProfitVisitor.hpp"
#include "ProfitVisitorEmbedded.hpp"
#include "TravelVisitor.hpp"
#include "TravelCostByDestinationVisitor.hpp"

int main()
{
    Domain domain;

	ObjectManager& pm = *Product::getManager();

	for(int i = 0; i < pm.numberOfObjects(); i++)
	{
	    Product *product = (Product*) pm[i];
	    
	    if (product)
	    {
            cout << i+1 << ". Product:\n";
            cout << "   Name:   " << product->getName() << "\n";
            cout << "   Desc:   " << product->getDescription() << "\n";
    	    cout << "   Range:  " << product->getPriceRange() << "\n";
    	    cout << "   Profit: $" << product->getProfitFor() << "\n\n";
    	    
            ProfitVisitor profitVisitor;
    	    product->acceptVisitor(&profitVisitor);
    	    double *profit = (double *) profitVisitor.getState();
       	    cout << "   Profit (using Visitor): $" << *profit << "\n\n";
 	    
            ProfitVisitorEmbedded profitVisitorEmbedded;
    	    product->acceptVisitor(&profitVisitorEmbedded);
    	    double *profitEmbedded = (double *) profitVisitorEmbedded.getState();
       	    cout << "   Profit (using EmbeddedVisitor): $" << *profitEmbedded << "\n\n";
	    }
	}
 	
	ObjectManager& scm = *SalesConsultant::getManager();

	for(int i = 0; i < scm.numberOfObjects(); i++)
	{
	    SalesConsultant *salesConsultant = (SalesConsultant*) scm[i];
	    
	    if (salesConsultant)
	    {
            cout << i+1 << ". SalesConsultant:\n";
            cout << "   Name:   " << salesConsultant->getName() << "\n";
            cout << "   Phone:  " << salesConsultant->getPhoneNumber() << "\n";

			TravelVisitor travelVisitor;
			salesConsultant->acceptVisitor(&travelVisitor);
			double *travelTotal = (double *) travelVisitor.getState();
			cout << "   Travel Total: $" << *travelTotal << "\n\n";
		}
	}
    
	for(int i = 0; i < scm.numberOfObjects(); i++)
	{
	    SalesConsultant *salesConsultant = (SalesConsultant*) scm[i];
	    
	    if (salesConsultant)
	    {
            cout << salesConsultant->getName() << "\n";
            
			TravelCostByDestinationVisitor travelVisitor;
			salesConsultant->acceptVisitor(&travelVisitor);
            travelVisitor.foreachDestinationToCost(
               [](String destination, double cost)
               {
                   printf("%25s%f\n", (const char*)(destination<< " cost: $"), cost);
               });
			double *travelTotal = (double *) travelVisitor.getState();
			printf("%25s%f\n\n", "Total travel cost: $", *travelTotal);
		}
	}
	//system("PAUSE");
	return 0;
}
