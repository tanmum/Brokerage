#include "Meeting.hpp"

Meeting::Meeting(char *cm, char *dt, char *ma, char *mi, double er, double fc, double rr, double tc)
    : Event(cm,dt,ma,mi)
{
	equipRent = er;
	foodCost = fc;
	roomRental = rr;
	teleConfCost = tc;
}

double Meeting::getCost()
{
	return equipRent + foodCost + roomRental + teleConfCost;
}

