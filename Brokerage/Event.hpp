#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <String>
#include <vector>
using namespace std;
#include "ObjectManager.hpp"
#include "Visitor.hpp"

class Travel;
class Order;
class ProfitVisitorEmbedded;
class TravelVisitor;
class TravelCostByDestinationVisitor;

class Event : public PersistentObject
{
private:
	static ObjectManager manager;	// This class' manager
	friend class ProfitVisitorEmbedded;
    friend class TravelVisitor;
    friend class TravelCostByDestinationVisitor;

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

	double getProfitFor();
	virtual double getCost() {return 0;}

	void setTravel(Travel& tr) {travel = &tr;}
	Travel *getTravel() {return travel;}

	List& getOrders() {return orders;}

    void addOrder(Order& order) {orders.append(&order);}
	void acceptVisitor(Visitor *v) {if (v) v->execute(this);}
}; 

#endif
