#ifndef __PHONECALL_HPP__
#define __PHONECALL_HPP__

#include "Event.hpp"

class PhoneCall : public Event
{
protected:
	double cost;

public:
	PhoneCall(char *cm, char *dt, char *ma, char *mi, double ct);
	
	double getCost() {return cost;}
	void setCost(double ct) {cost = ct;}
}; 

#endif
