#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Budget.h"
#include "doctest.h"

TEST_CASE("Creating a budget")
{
	Budget fmi(100000);
	CHECK(fmi.getFacultyBydget() == 100000);
	CHECK(fmi.getUniversityBudget() == 100000);

	Budget fhf(20000);
	CHECK(fhf.getUniversityBudget() == 120000);
}

TEST_CASE("Add to faculty  budget")
{
	Budget fmi(100000);
	fmi.addToBudget(5000);
	CHECK(fmi.getFacultyBydget() == 105000);
}

TEST_CASE("Add to university from administration")
{
	Budget::addFromAdministration(20000);
	Budget su;
	CHECK(su.getUniversityBudget() == 345000);
}

TEST_CASE("operator+, operator-, operator==, operator!=") {
	Budget fmi(10000);

	fmi += 5000;
	CHECK(fmi.getFacultyBydget() == 15000);

	fmi -= 5000;
	CHECK(fmi.getFacultyBydget() == 10000);

	Budget fhf(fmi);
	CHECK(fmi == fhf);

	fhf += 7000;
	CHECK(fmi != fhf);
	fhf -= 7000;
	CHECK(fmi == fhf);	
}