#pragma once
#include <iostream>
#include <stdlib.h>
#include "Client.h"


using namespace std;

class Account 
{
private:
	static int objectsCountAccount;
	int number;
	double balance;
	double interestRate;
	static double unknownInterestRate;

	Client* owner;
	Client* partner;
public:
	Account(int n, Client* o)
	{
		this->number = n;
		this->owner = o;
		this->interestRate = this->unknownInterestRate;
		this->objectsCountAccount += 1;
	}
	Account(int n, Client* o, double ir)
	{
		this->number = n;
		this->owner = o;
		this->interestRate = ir;
		this->objectsCountAccount += 1;
	}

	~Account()
	{
		this->objectsCountAccount -= 1;
	}

	static void ChangeUnknownInterestRate(double newInterestRate)
	{
		unknownInterestRate = newInterestRate;
	}

	static int GetObjectsCountAccount()
	{
		return objectsCountAccount;
	}
	int GetNumber()
	{
		return this->number;
	}
	double GetBalance()
	{
		return this->balance;
	}
	double GetInterestRate()
	{
		return this->interestRate;
	}
	Client* GetOwner()
	{
		return this->owner;
	}
	Client* GetPartner()
	{
		return this->partner;
	}
	bool CanWithdraw(double a)
	{
		if (a <= this->balance)
		{
			return 1;
		}

		else
		{
			cout << "not enough money" << endl;
			return 0;
		}
	}

	void Deposit(double a)
	{
		if (a <= 0) 
		{
			cout << "wrong amount of money" << endl;
		}
		this->balance += a;
		
	}
	bool Withdraw(double a)
	{
		if (CanWithdraw(a)) 
		{
			this->balance -= a;
			return 1;
		}

		return 0;
	}

	void AddInterest() 
	{
		double summ = interestRate * balance;
		this->balance += summ;
	}

};

int Account::objectsCountAccount = 0;
double Account::unknownInterestRate = 0.1;