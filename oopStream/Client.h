#pragma once
#include <iostream>
#include <stdlib.h>


using namespace std;

class Client 
{
private:
	static int objectsCountClient;
	int code;
	string name;
public:	


	Client(int c, string n)
	{
		this->code = c;
		this->name = n;
		this->objectsCountClient += 1;
	}
	~Client()
	{
		this->objectsCountClient -= 1;
	}

	static int GetObjectsCountClient()
	{
		return objectsCountClient;
	}

	int GetCode()
	{
		return this->code;
	}
	string GetName()
	{
		return this->name;
	}

};

int Client::objectsCountClient = 0;