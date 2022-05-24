#pragma once
#include "Account.h"
#include "IStreamable.h"
#include "IStreamingService.h"

class Netflix : public IStreamingService {
	Account** mAccounts;
	size_t mNumberOfAccounts;

	IStreamable** mStreamable;
	size_t mNumberOfStreamables;

	static int mWatchingTime;

	void copyAccounts(Account** accounts, size_t numberOfAccounts);
	void copyStreamables(IStreamable** streamable, size_t numberOfContent);

	void eraseAccounts();
	void eraseStreamables();

	bool accountExists(const Account& account) const;
	bool streamableExists(std::string& streamableName) const;
public:
	Netflix(Account** accounts, size_t numberOfAccounts, IStreamable** streamable, size_t numberOfStreamables);
	~Netflix();
	/**
	* Simulates watching activity for the given user.
    * @param user the user that will watch the video. The user must be registered in the platform in order to access its contents.
    * @param videoContentName the exact name of the video content: movie or series
    * If the content is of type Series, we assume that the user will watch all episodes in it.
	*/
	void watch(const Account user, std::string videoContentName) override;

	/**
	* @return the minutes spent by all users registered in the platform while watching streamable content.
	*/
	int totalWatchedTimeByUsers() const override;
};
