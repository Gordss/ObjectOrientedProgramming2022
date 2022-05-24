#pragma once
#include "Account.h"

class IStreamingService {
public:
	virtual void watch(const Account user, std::string videoContentName) = 0;
	virtual int totalWatchedTimeByUsers() const = 0;
};