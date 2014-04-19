#pragma once

#include <iostream>
#include "../../Common/String.hpp"
#include "Vendor.hpp"
#include "Product.hpp"
using namespace std;

class Term
{
	double price;
	String delay;
	String refund;
	Vendor& vendor;
	Product& product;
public:
	Term(Vendor& v, Product& p, double pr, char* d, char* r)
		: vendor(v), product(p), price(pr), delay(d), refund(r)
	{
		vendor.addTerm(*this);
		//product.addTerm(*this);
	}

	double getPrice() { return price; }

	operator const char* () const
	{
		static char res[999];
		const char* format = "%s, %s, Terms: --> %.2f, %s, %s";
		//sprintf(res, format, vendor.getName(), product.getName(), price, delay.getStr(), refund.getStr());
		return res;
	}
};