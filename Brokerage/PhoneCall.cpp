#include "PhoneCall.hpp"

PhoneCall::PhoneCall(char *cm, char *dt, char *ma, char *mi, double ct)
    : Event(cm, dt, ma, mi)
{
	cost = ct;
}



