#ifndef __ORDER_HPP__
#define __ORDER_HPP__

#include "ObjectManager.hpp"
#include "Visitor.hpp"

class Terms;
class CompTerms;
class ProfitVisitorEmbedded;

class Order : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager
	friend class ProfitVisitorEmbedded;

protected:
	String paymentTerms;	// Customer's payment terms
	double price;			// What the customer will pay
	double discount;		// Discount % offered to the customer
	int quantity;			// Quantity ordered
	Terms *terms;			// Vendor Terms
	CompTerms *compTerms;	// Salesperson's compensation terms active at the time of the order

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	Order(double pr, double disc, int qty, char *tm, CompTerms *ct);
	~Order();
	
	double getPrice() {return price;}
	void setPrice(double pr) {price = pr;}

	double getDiscount() {return discount;}
	void setDiscount(double ds) {discount = ds;}

	int getQuantity() {return quantity;}
	void setQuantity(int qty) {quantity = qty;}

	String& getPaymentTerms() {return paymentTerms;}
	void setPaymentTerms(String& str) {paymentTerms = str;}

	Terms *getTerms() {return terms;}
	void setTerms(Terms& tm) {terms = &tm;}

	CompTerms *getCompTerms() {return compTerms;}
	void setCompTerms(CompTerms& tm) {compTerms = &tm;}

	void setTerms(Terms& t, CompTerms& ct);

	double getProfit();
	void acceptVisitor(Visitor *v) {if (v) v->execute(this);}
}; 

#endif
