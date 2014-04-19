#ifndef __COMPTERMS_HPP__
#define __COMPTERMS_HPP__

#include "ObjectManager.hpp"

class SalesConsultant;

class CompTerms : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	double commissionPercent;
	CompTerms *previous;		// The CompTerms this object is replacing

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	CompTerms(double cp, SalesConsultant *sc);
	~CompTerms();
	
	double getCommissionPercent() {return commissionPercent;}
	void setCommissionPercent(double value) {commissionPercent = value;}

	CompTerms& getPrevious() {return *previous;}
	void setPrevious(CompTerms& prev) {previous = &prev;}

	double getCommission(double amount) {return amount * commissionPercent;}
}; 

#endif
