#pragma once
#include <iostream>
#include <stdlib.h>
#include "PartnerAccount.h"


using namespace std;

class Bank
{
private:

	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;
public:

	Bank(int c, int a)
	{
		this->clientsCount = c;
		this->clients = new Client * [c];

		for (int i = 0; i < c; i++)
		{
			clients[i] = NULL;
		}

		this->accountsCount = a;
		this->accounts = new Account * [a];

		for (int i = 0; i <a; i++)
		{
			accounts[i] = NULL;
		}
	}

	~Bank()
	{
		delete this->accounts;
		delete this->clients;
	}


	Client* GetClient(int c)
	{
		for (int i = 0; i < this->clientsCount; i++)
		{
			if (c == clients[i]->GetCode())
			{
				return clients[i];
			}
		}
		cout << "No client with this code" << endl;
		return NULL;
	}


	Account* GetAccount(int n)
	{
		for (int i = 0; i < this->accountsCount; i++)
		{
			if (n == accounts[i]->GetNumber())
			{
				return accounts[i];
			}
		}
		cout << "No account with this number" << endl;
		return NULL;
	}

	Client* CreateClient(int c, string n)
	{
		Client* cl = new Client(c,n);
		for (int i = 0; i < clientsCount; i++)
		{
			if (clients[i] == NULL) 
			{
				clients[i] = cl;
				return cl;
			}

		}
		return NULL;
	}

	Account* CreateAccount(int n, Client* o)
	{
		Account* ac = new Account(n,o);

		for (int i = 0; i < accountsCount; i++)
		{
			if (accounts[i] == NULL) 
			{
				accounts[i] = ac;
				return ac;
			}

		}
		
		return NULL;
	}
	Account* CreateAccount(int n, Client* o, double ir)
	{
		Account* ac = new Account(n, o, ir);

		for (int i = 0; i < accountsCount; i++)
		{
			if (accounts[i] == nullptr) 
			{
				accounts[i] = ac;
				return ac;
			}

		}
		
		return nullptr;
	}
	PartnerAccount* CreateAccount(int n, Client* o, Client* p)
	{
		PartnerAccount* pac = new PartnerAccount(n, o, p);

		for (int i = 0; i < accountsCount; i++)
		{
			if (accounts[i] == NULL) 
			{
				accounts[i] = pac;
				return pac;
			}

		}
		
		return nullptr;
	}
	PartnerAccount* CreateAccount(int n, Client* o, Client* p,double ir)
	{
		PartnerAccount* pac = new PartnerAccount(n, o, p,ir);

		for (int i = 0; i < accountsCount; i++)
		{
			if (accounts[i] == NULL) 
			{
				accounts[i] = pac;
				return pac;
			}

		}

		return nullptr;
	}


	void AddInterest()
	{
		for (int i = 0; i < accountsCount; i++)
		{
			accounts[i]->AddInterest();
			
		}
	}
};