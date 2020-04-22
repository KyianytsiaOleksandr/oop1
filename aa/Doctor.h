#pragma once
#include <iostream>
#include <stdlib.h>


using namespace std;

class Doctor
{
private:

	static int objectsCountDoctor;
	int doccode;
	string docname;
	string specialization;

public:

	Doctor(int dc, string dn, string ds)
	{
		this->doccode = dc;
		this->docname = dn;
		this->specialization = ds;
		this->objectsCountDoctor += 1;
	}

	~Doctor()
	{
		this->objectsCountDoctor -= 1;
	}

	static int GetObjectsCountDoctor()
	{
		return objectsCountDoctor;
	}

	int GetDocCode()
	{
		return this->doccode;
	}
	string GetDocName()
	{
		return this->docname;
	}

	string GetSpecialization()
	{
		return this->specialization;
	}

};

int Doctor::objectsCountDoctor = 0;
