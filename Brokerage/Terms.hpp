#ifndef __TERMS_HPP__
#define __TERMS_HPP__

#include "ObjectManager.hpp"

class Vendor;
class Product;

class Terms : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	Product *product;
	Vendor *vendor;
	double price;
	String delay;
	String refund;

public:
	static ObjectManager *getManager() {return &manager;}	// Get the manager for this class

	Terms(Vendor *v, Product *p, double prc, char *dl, char *rfd);
	~Terms();
	
	static void removeTerms(Terms& t);

	double getPrice() {return price;}
	void setPrice(double pr) {price = pr;}

	Product& getProduct() {return *product;}
	void setProduct(Product& pr) {product = &pr;}

	Vendor& getVendor() {return *vendor;}
	void setVendor(Vendor& vd) {vendor = &vd;}

	const String& getDelay() {return delay;}
	void setDelay(String& dl) {delay = dl;}

	const String& getRefund() {return refund;}
	void setRefund(String& rf) {refund = rf;}
};

#endif
