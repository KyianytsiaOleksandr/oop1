#pragma once
#include <iostream>
#include <stdlib.h>
#include "Account.h"


using namespace std;

class PartnerAccount : public Account
{
private:
	Client* partner;

public:
	PartnerAccount(int n, Client* o, Client* p) : Account(n,o)
	{
		this->partner = p;
	}
	PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir)
	{
		this->partner = p;
	}
};

