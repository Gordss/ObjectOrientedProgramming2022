#include "Account.h"

Account::Account(std::string username, time_t registrationTime)
{
	mUsername = username;
	mRegistrationTime = registrationTime;
}

std::string Account::getUsername() const
{
	return mUsername;
}

time_t Account::getRegistrationTime() const
{
	return mRegistrationTime;
}
