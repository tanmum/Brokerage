#ifndef __TRAVEL_HPP__
#define __TRAVEL_HPP__

#include "../../Common/String.hpp"
#include "ObjectManager.hpp"

class Travel : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	double airfare;
	double car;
	double taxi;
	String destination;

	double getAirfare(){return airfare;}
	void setAirfare(double af) {airfare = af;}

	double getCar(){return car;}
	void setCar(double cr) {car = cr;}

	double getTaxi(){return taxi;}
	void setTaxi(double tx) {taxi = tx;}

	const String& getDestination() {return destination;}
	void setDestination(String& dest) {destination = dest;}

public:
	static ObjectManager *getManager() { return &manager; }	// Get the manager for this class

	Travel(double af, double cr, double tx, char *dest);
	~Travel();
	
	double getCost();
}; 

#endif
