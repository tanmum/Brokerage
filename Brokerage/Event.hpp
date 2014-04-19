#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <String>
#include <vector>
using namespace std;
#include "ObjectManager.hpp"

class Travel;
class Order;

class Event : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager

protected:
	String comments;
	String date;
	String mainAction;
	String mainIssue;

	Travel *travel;
	List orders;

public:
	static ObjectManager *getManager() { return &manager;}	// Get the manager for this class

	Event(char *cm, char *dt, char *ma, char *mi);
	virtual ~Event();
	
	String& getComments() {return comments;}
	void setComments(String& cm) {comments = cm;}

	String& getDate() {return date;}
	void setDate(String& dt) {date = dt;}

	String& getMainAction() {return mainAction;}
	void setMainAction(String& ma) {mainAction = ma;}

	String& getMainIssue() {return mainIssue;}
	void setMainIssue(String& mi) {mainIssue = mi;}

	void setTravel(Travel& tr) {travel = &tr;}
	Travel& getTravel() {return *travel;}

	List& getOrders() {return orders;}

    void addOrder(Order& order) {orders.append(&order);}
    
    double getProfit();
    virtual double getCost() = 0;
    double getTravelCost();
}; 

#endif
