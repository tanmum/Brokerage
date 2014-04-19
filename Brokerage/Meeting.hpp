#ifndef __MEETING_HPP__
#define __MEETING_HPP__

#include "Event.hpp"

class Meeting : public Event
{
protected:
	double equipRent;
	double foodCost;
	double roomRental;
	double teleConfCost;

public:
	Meeting(char *cm, char *dt, char *ma, char *mi, double er, double fc, double rr, double tc);
	
	double getEquipRent() {return equipRent;}
	void setEquipRent(double er) {equipRent = er;}

	double getFoodCost() {return foodCost;}
	void setFoodCost(double er) {foodCost = er;}

	double getRoomRental() {return roomRental;}
	void setRoomRental(double er) {roomRental = er;}

	double getTeleConfCost() {return teleConfCost;}
	void setTeleConfCost(double er) {teleConfCost = er;}
    
    double getCost();
}; 

#endif
