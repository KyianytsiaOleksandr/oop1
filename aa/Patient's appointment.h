#pragma once
#include <iostream>
#include <stdlib.h>
#include "Patient.h"
#include "Doctor.h"


using namespace std;

class Appointment : public Patient

{
private:
	static int objectsCountAppointment;
	int number;
	string disease;

	Doctor* doctor;

public:
	Appointment(string n, int nm, string d, Doctor* dc) : Patient(n)
	{
		this->number = nm;
		this->disease = d;
		this->doctor = dc;
		this->objectsCountAppointment += 1;
	}

	~Appointment()
	{
		this->objectsCountAppointment -= 1;
	}

	static int GetObjectsCountAppointment()
	{
		return objectsCountAppointment;
	}

	int GetNumber()
	{
		return this->number;
	}

	string GetDisease()
	{
		return this->disease;
	}

};

int Appointment::objectsCountAppointment = 0;

