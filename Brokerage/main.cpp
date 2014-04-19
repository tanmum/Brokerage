#include <iostream>
using namespace std;

#include "Domain.hpp"
#include "Product.hpp"

int main()
{
	Domain domain;

	List products = Product::getManager()->getAll();
	SmartPtr<Iterator> iterator(products.getIterator());

	for (Product *product = 0; iterator->hasNext(); )
	{	  
		product = (Product *) iterator->next();

		if (product)
		{
			cout << "Product Name:   " << product->getName() << "\n";
			cout << "        Desc:   " << product->getDescription() << "\n";
			cout << "       Range:   " << product->getPriceRange() << "\n";
            cout << "      Profit:   $" << product->getProfitFor() << endl;
			cout << "\n\n";
		}
	}
	//system("PAUSE");
}
