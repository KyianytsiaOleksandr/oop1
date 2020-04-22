#pragma once
#include <iostream>
#include <stdlib.h>
#include "Patient.h"
#include "Doctor.h"
#include "Patient's appointment.h"


using namespace std;

class Clinic
{
private:

	Appointment** appointments;
	int appointmentsCount;

	Doctor** doctors;
	int doctorsCount;

public:

	Clinic(int c, int a)
	{

		this->appointmentsCount = c;
		this->appointments = new Appointment * [c];
		for (int i = 0; i < c; i++)
		{
			appointments[i] = NULL;
		}

		this->doctorsCount = a;
		this->doctors = new Doctor * [a];
		for (int i = 0; i < a; i++)
		{
			doctors[i] = NULL;
		}
	}
	~Clinic()
	{
		delete this->appointments;
		delete this->doctors;
	}

	Appointment* GetAppointment(int nm)
	{
		for (int i = 0; i < this->appointmentsCount; i++)
		{
			if (nm == appointments[i]->GetNumber())
			{
				return appointments[i];
			}
		}
		cout << "No appointment with this number" << endl;
		return NULL;
	}

	Doctor* GetDoctor(int dc)
	{
		for (int i = 0; i < this->doctorsCount; i++)
		{
			if (dc == doctors[i]->GetDocCode())
			{
				return doctors[i];
			}
		}
		cout << "No doctors with this number" << endl;
		return NULL;
	}

	Appointment* CreateAppointment(string n, int nm, string ds, Doctor* d)
	{
		Appointment* ap = new Appointment(n, nm, ds, d);

		for (int i = 0; i < appointmentsCount; i++)
		{
			if (appointments[i] == NULL) {
				appointments[i] = ap;
				return ap;
			}

		}

		return NULL;
	}


	Doctor* CreateDoctor(int dc, string dn, string ds)
	{
		Doctor* cl = new Doctor(dc, dn, ds);
		for (int i = 0; i < doctorsCount; i++)
		{
			if (doctors[i] == NULL)
			{
				doctors[i] = cl;
				return cl;
			}

		}
		return NULL;
	}
};
