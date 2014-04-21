#include "ObjectManager.hpp"
#include "Domain.hpp"
#include "State.hpp"
#include "Address.hpp"
#include "Product.hpp"
#include "Vendor.hpp"
#include "Terms.hpp"
#include "Customer.hpp"
#include "SalesConsultant.hpp"
#include "CompTerms.hpp"
#include "Deal.hpp"
#include "Event.hpp"
#include "Travel.hpp"
#include "Meeting.hpp"
#include "PhoneCall.hpp"
#include "Order.hpp"

Domain::Domain()
{
	createDomainObjects();
}

Domain::~Domain()
{
}

void Domain::createDomainObjects() 
{
    new State("IL", "Illinois");
	new State("DC", "Washington DC");
	new State("MA", "Massachussetts");
	new State("MN", "Minnesota");
	new State("WA", "Washington");
	ObjectManager& states = *State::getManager();

    new Address("1245 Parkway Dr.", "", "Chicago", (State *)states[0], "60685");
    new Address("134 South Michigan Ave.", "Appartment 3-B", "Chicago", (State *)states[0], "60685");
    new Address("205 North Monroe", "Suite 307", "Chicago", (State *)states[0], "60685");
    new Address("134 North Jefferson", "", "Minneapolis", (State *)states[3], "55350");
    new Address("5410 South Kirkwood", "", "Cambridge", (State *)states[2], "02142");
    ObjectManager& addresses = *Address::getManager();    
    
    new Product("Laptop 2001", "400 MB RAM - 750 MHZ - 15 GB");
    new Product("Dell Latitude", "220 MB RAM - 350 MHZ - 10 GB");
    new Product("Desktop 9801", "650 MB RAM - 900 MHZ - 30 GB - Linux");
    new Product("HP 8100 DN", "Duplex installed - Network ready");
    ObjectManager& products = *Product::getManager();
    
    new Vendor("Gateway Outlet", (Address *)addresses[3], "(320) 567 9987", "(320) 977 0889");
    new Vendor("Net Office", (Address *)addresses[1], "(312) 755 8998", "(312 933 8008)");
    new Vendor("Sam's Roads", (Address *)addresses[0], "(312) 765 9778", "(312) 734 9557");
    new Vendor("Ben & Jenny's", (Address *)addresses[4], "(617) 456 9878", "(617) 234 0478");
    ObjectManager& vendors = *Vendor::getManager();
    
    new Terms((Vendor *)vendors[0], (Product *)products[0], 6500.00, "Overnight", "30 days");
    new Terms((Vendor *)vendors[3], (Product *)products[0], 6700.00, "2-day", "15 days");
    new Terms((Vendor *)vendors[1], (Product *)products[0], 6300.00, "3-day", "No refund");
    new Terms((Vendor *)vendors[0], (Product *)products[1], 6500.00, "Overnight", "30 days");
    new Terms((Vendor *)vendors[2], (Product *)products[1], 6100.00, "3-day", "60 days");
    new Terms((Vendor *)vendors[1], (Product *)products[2], 6500.00, "Overnight", "20 days");
    new Terms((Vendor *)vendors[2], (Product *)products[2], 6200.00, "3-day", "No refund");
    new Terms((Vendor *)vendors[3], (Product *)products[2], 6350.00, "5-day", "45 days");
    new Terms((Vendor *)vendors[0], (Product *)products[3], 6500.00, "Overnight", "1 Year");
    ObjectManager& terms = *Terms::getManager();
    
    new Customer("IBM", (Address *)addresses[0], "312 467 9899", "312 467 9890", "Bill Smith", "312 467 1200", "bills@ibm.com");
    new Customer("E-Office", (Address *)addresses[1], "312 243 6541", "312 243 6540", "Joelle Reynolds", "312 243 6769", "joelle.r@e-office.com");
    new Customer("Copy Max Corp.", (Address *)addresses[2], "312 320 9085", "312 320 9086", "Randy Burts", "312 320 9085 xt. 501", "randy@cmc.com");
    new Customer("Best Buy", (Address *)addresses[3], "320-587-1809", "320-587-1810", "Jeff Curls", "320-587-1839", "jeffc@bestbuy.com");
    new Customer("Science Institute", (Address *)addresses[4], "617.250.2631", "617.250.2098", "Max Randal", "617.250.2631", "maxr@scii.com");
	ObjectManager& customers = *Customer::getManager();

	new SalesConsultant("John Smith", "(312) 345 9378");
	new SalesConsultant("Jane Bloomfield","(234) 243 2220");
	new SalesConsultant("Mike Schimmel","(612) 345 3222");
	new SalesConsultant("Frank Doer","(737) 266 2256");
	new SalesConsultant("Savio Lobo","(312) 123 4556");
	new SalesConsultant("Mary Garden","(768) 533 9889");
	ObjectManager& salesConsultants = *SalesConsultant::getManager();

	new CompTerms(.06, (SalesConsultant *)salesConsultants[0]);
	new CompTerms(.10, (SalesConsultant *)salesConsultants[0]);
	new CompTerms(.15, (SalesConsultant *)salesConsultants[1]);
	new CompTerms(.06, (SalesConsultant *)salesConsultants[2]);
	new CompTerms(.18, (SalesConsultant *)salesConsultants[2]);
	new CompTerms(.12, (SalesConsultant *)salesConsultants[3]);
	new CompTerms(.20, (SalesConsultant *)salesConsultants[3]);
	new CompTerms(.10, (SalesConsultant *)salesConsultants[3]);
	new CompTerms(.11, (SalesConsultant *)salesConsultants[4]);
	new CompTerms(.08, (SalesConsultant *)salesConsultants[4]);
	new CompTerms(.07, (SalesConsultant *)salesConsultants[5]);
	new CompTerms(.25, (SalesConsultant *)salesConsultants[5]);
	new CompTerms(.12, (SalesConsultant *)salesConsultants[5]);
	ObjectManager& compTerms = *CompTerms::getManager();

	new Deal((Customer *)customers[0], (SalesConsultant *)salesConsultants[0], (Product *)products[0]);
	new Deal((Customer *)customers[0], (SalesConsultant *)salesConsultants[0], (Product *)products[0]);
	new Deal((Customer *)customers[1], (SalesConsultant *)salesConsultants[1], (Product *)products[1]);
	new Deal((Customer *)customers[2], (SalesConsultant *)salesConsultants[2], (Product *)products[2]);
	new Deal((Customer *)customers[2], (SalesConsultant *)salesConsultants[2], (Product *)products[2]);
	new Deal((Customer *)customers[2], (SalesConsultant *)salesConsultants[2], (Product *)products[2]);
	new Deal((Customer *)customers[3], (SalesConsultant *)salesConsultants[3], (Product *)products[3]);
	new Deal((Customer *)customers[4], (SalesConsultant *)salesConsultants[4], (Product *)products[0]);
	new Deal((Customer *)customers[4], (SalesConsultant *)salesConsultants[4], (Product *)products[0]);
	new Deal((Customer *)customers[4], (SalesConsultant *)salesConsultants[4], (Product *)products[1]);
	new Deal((Customer *)customers[3], (SalesConsultant *)salesConsultants[5], (Product *)products[1]);
	new Deal((Customer *)customers[3], (SalesConsultant *)salesConsultants[5], (Product *)products[2]);
	new Deal((Customer *)customers[2], (SalesConsultant *)salesConsultants[5], (Product *)products[2]);
	ObjectManager& deals = *Deal::getManager();

	new PhoneCall("1 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 12.08);
	new Meeting("2 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 35.03, 59.43, 120.98, 80.78);
	new Meeting("3 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 37.03, 53.43, 190.98, 86.78);
	new Meeting("4 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 55.03, 79.43, 60.98, 20.78);
	new PhoneCall("5 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 20.07);
	new Meeting("6 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 45.03, 51.43, 15.98, 10.78);
	new Meeting("7 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 125.03, 149.43, 30.98, 70.78);
	new PhoneCall("8 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 45.92);
	new Meeting("9 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 23.03, 55.43, 60.98, 70.78);
	new PhoneCall("10 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 52.10);
	new Meeting("11 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 23.12, 56.43, 62.98, 78.78);
	new Meeting("12 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 23.03, 55.43, 60.98, 70.78);
	new PhoneCall("13 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 12.03);
	new Meeting("14 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 24.03, 54.43, 65.98, 72.78);
	new PhoneCall("15 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 7.98);
	new Meeting("16 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 25.03, 57.43, 61.98, 90.78);
	new Meeting("17 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 23.03, 22.43, 670.98, 98.78);
	new PhoneCall("18 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 18.29);
	new Meeting("19 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 15.03, 515.43, 150.98, 715.78);
	new Meeting("20 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 23.03, 55.43, 60.98, 70.78);
	new PhoneCall("21 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 62.70);
	new Meeting("22 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 23.153, 515.43, 615.98, 150.78);
	new Meeting("23 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 212.03, 512.43, 612.98, 120.78);
	new PhoneCall("24 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 45.25);
	new Meeting("25 Nice fellow to work with.", "1999 May 3", "Identification of product", "Doesn't seem to be a rich guy.", 212.03, 125.43, 612.98, 120.78);
	new PhoneCall("26 Strange fellow to work with.", "1998 May 3", "Identification of needs", "Doesn't seem to be a poor guy.", 32.61);
	new Meeting("27 Nice company to work with.", "1997 June 3", "Comments about product", "Doesn't look to be a real guy.", 153.03, 515.43, 615.98, 150.78);
	new PhoneCall("28 Obscure situation.", "1997 March 1", "Product for identification", "Doesn't identify as being a poor fellow.", 41.90);
	new Meeting("29 Make sure to speak with Mike Donn", "2000 May 3", "Reviewed the whole line", "Should yield results soon.", 932.03, 123.43, 43.98, 121.78);
	new PhoneCall("30 Interesting position.", "2000 April 1", "Product review", "Good confidence level.", 23);
	ObjectManager& events = *Event::getManager();

	int dealInd = 0;
	int eventIndex = 0;
	int maxD = deals.numberOfObjects() - 1;
	int maxE = events.numberOfObjects() - 1;
	for (; dealInd <= maxD && eventIndex <= maxE; dealInd++)
		{
			((Deal *)deals[dealInd])->addEvent(*(Event*)events[eventIndex++]);
			((Deal *)deals[dealInd])->addEvent(*(Event*)events[eventIndex++]);
		}
	((Deal *)deals[0])->addEvent(*(Event*)events[28]);
	((Deal *)deals[0])->addEvent(*(Event*)events[29]);

	new Travel(1200, 302.0, 43, "Chicago");
	new Travel(800, 290.0, 10, "Ann Arbor");
	new Travel(1929, 381.0, 10, "St Louis");
	new Travel(1022, 112.0, 0, "Fairfield");
	new Travel(1322, 123.0, 12, "Minneapolis");
	new Travel(1234, 321.0, 11, "New York");
	new Travel(908, 12.0, 413, "Santa Clara");
	new Travel(1243, 8.0, 23, "Santa Anna");
	new Travel(1123, 165.0, 23, "Palo Alto");
	new Travel(1109, 143.0, 43, "Santa Barbara");
	new Travel(990, 190.0, 34, "San Francisco");
	new Travel(1200, 0.0, 0, "Eureka");
	new Travel(1230, 234.0, 0, "Arcada");
	ObjectManager& travels = *Travel::getManager();

	((Event*)events[0])->setTravel(*(Travel*)travels[0]); 
    ((Event*)events[2])->setTravel(*(Travel*)travels[1]); 
    ((Event*)events[3])->setTravel(*(Travel*)travels[2]);
	((Event*)events[4])->setTravel(*(Travel*)travels[3]); 
    ((Event*)events[7])->setTravel(*(Travel*)travels[4]); 
    ((Event*)events[8])->setTravel(*(Travel*)travels[5]);
	((Event*)events[10])->setTravel(*(Travel*)travels[6]); 
    ((Event*)events[12])->setTravel(*(Travel*)travels[7]); 
    ((Event*)events[13])->setTravel(*(Travel*)travels[8]);
	((Event*)events[16])->setTravel(*(Travel*)travels[9]); 
    ((Event*)events[18])->setTravel(*(Travel*)travels[10]); 
    ((Event*)events[22])->setTravel(*(Travel*)travels[11]);
	((Event*)events[25])->setTravel(*(Travel*)travels[12]);

	new Order(8580, 0.9, 10, "30 days", (CompTerms*)compTerms[1]);
	new Order(8540, 0.8, 20, "15 days", (CompTerms*)compTerms[2]);
	new Order(8270, 0.9, 10, "30 days", (CompTerms*)compTerms[4]);
	new Order(8720, 0.8, 25, "20 days", (CompTerms*)compTerms[6]);
	new Order(8170, 0.8, 45, "30 days", (CompTerms*)compTerms[8]);
	new Order(8630, 1.0, 10, "15 days", (CompTerms*)compTerms[9]);
	new Order(8440, 0.9, 123, "30 days", (CompTerms*)compTerms[10]);
	new Order(8470, 0.8, 32, "10 days", (CompTerms*)compTerms[11]);
	new Order(8170, 0.9, 110, "30 days", (CompTerms*)compTerms[12]);
	new Order(8750, 1.0, 3, "15 days", (CompTerms*)compTerms[12]);
	ObjectManager& orders = *Order::getManager();

    ((Order*)orders[0])->setTerms(*(Terms*)terms[0]);
    ((Order*)orders[1])->setTerms(*(Terms*)terms[0]);
    ((Order*)orders[2])->setTerms(*(Terms*)terms[1]);
    ((Order*)orders[3])->setTerms(*(Terms*)terms[2]);
    ((Order*)orders[4])->setTerms(*(Terms*)terms[3]); 
    ((Order*)orders[5])->setTerms(*(Terms*)terms[4]);
    ((Order*)orders[6])->setTerms(*(Terms*)terms[5]);
    ((Order*)orders[7])->setTerms(*(Terms*)terms[6]);
    ((Order*)orders[8])->setTerms(*(Terms*)terms[7]);
    ((Order*)orders[9])->setTerms(*(Terms*)terms[8]);
    
    ((Event*)events[0])->addOrder(*(Order*)orders[0]);
    ((Event*)events[5])->addOrder(*(Order*)orders[1]);
    ((Event*)events[9])->addOrder(*(Order*)orders[2]);
    ((Event*)events[12])->addOrder(*(Order*)orders[3]);
    ((Event*)events[16])->addOrder(*(Order*)orders[4]);
    ((Event*)events[16])->addOrder(*(Order*)orders[5]);
    ((Event*)events[24])->addOrder(*(Order*)orders[6]);
    ((Event*)events[25])->addOrder(*(Order*)orders[7]);
    ((Event*)events[27])->addOrder(*(Order*)orders[8]);
    ((Event*)events[27])->addOrder(*(Order*)orders[9]);
}



