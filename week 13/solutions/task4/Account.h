#pragma once
#include <string>

class Account {
	std::string mUsername;
	time_t mRegistrationTime;
public:
	Account(std::string username, time_t registrationTime);

	std::string getUsername() const;
	time_t getRegistrationTime() const;

	// don't put setters since we don't want our accounts to be changable
};
