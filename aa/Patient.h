#pragma once
#include <iostream>
#include <stdlib.h>


using namespace std;

class Patient
{
private:

	static int objectsCountPatient;
	string name;

public:

	Patient(string n)
	{
		this->name = n;
		this->objectsCountPatient += 1;
	}

	string GetPatientName()
	{
		return this->name;
	}

	~Patient()
	{
		this->objectsCountPatient -= 1;
	}

	static int GetObjectsCountPatient()
	{
		return objectsCountPatient;
	}

};

int Patient::objectsCountPatient = 0;
