#include <iostream>
using namespace std;

#include "Domain.hpp"
#include "Product.hpp"
#include "SalesConsultant.hpp"

int main()
{
	Domain domain;

	List sales = SalesConsultant::getManager()->getAll();
	SmartPtr<Iterator> iterator(sales.getIterator());

	for (SalesConsultant *sale = 0; iterator->hasNext(); )
	{	  
		sale = (SalesConsultant *) iterator->next();

		if (sale)
		{
			cout << sale->getName() << endl;\
            cout << "      total travel cost: $" << sale->getTravelCost() << endl;
			cout << "\n\n";
		}
	}
	//system("PAUSE");
}
