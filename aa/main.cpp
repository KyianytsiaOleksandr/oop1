#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Clinic.h"

using namespace std;

int main()
{
	Clinic* clinic = new Clinic(10, 10);

	Doctor* c1 = clinic->CreateDoctor(01, "Doctor one", "Therapist");
	Doctor* c2 = clinic->CreateDoctor(02, "Doctor two", "Surgeon");

	Appointment* ap1 = clinic->CreateAppointment("Patient one", 001, "Flu", clinic->GetDoctor(01));
	Appointment* ap2 = clinic->CreateAppointment("Patient two", 002, "COVID", clinic->GetDoctor(01));
	Appointment* ap3 = clinic->CreateAppointment("Patient three", 003, "appendicitis", clinic->GetDoctor(02));

	cout << c1->GetDocName() << endl;
	cout << c2->GetSpecialization() << endl;
	cout << ap2->GetNumber() << endl;
	cout << ap2->GetPatientName() << endl;
	cout << ap2->GetDisease() << endl;
	cout << Appointment::GetObjectsCountAppointment() << endl;

	system("pause");
}
