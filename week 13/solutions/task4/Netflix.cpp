#include "Netflix.h"
#include <exception>

int Netflix::mWatchingTime = 0;

void Netflix::copyAccounts(Account** accounts, size_t numberOfAccounts)
{
    mNumberOfAccounts = numberOfAccounts;
    mAccounts = new Account * [mNumberOfAccounts];
    for (size_t i = 0; i < mNumberOfAccounts; i++) {
        mAccounts[i] = new Account(accounts[i]->getUsername(), accounts[i]->getRegistrationTime());
    }
}

void Netflix::copyStreamables(IStreamable** streamable, size_t numberOfStreamables)
{
    mNumberOfStreamables = numberOfStreamables;
    mStreamable = new IStreamable * [mNumberOfStreamables];
    for (size_t i = 0; i < mNumberOfStreamables; i++) {
        mStreamable[i] = streamable[i]->clone(); 
    }
}

void Netflix::eraseAccounts()
{
    for (size_t i = 0; i < mNumberOfAccounts; i++) {
        delete mAccounts[i];
    }
    delete[] mAccounts;
}

void Netflix::eraseStreamables()
{
    for (size_t i = 0; i < mNumberOfStreamables; i++) {
        delete mStreamable[i];
    }
    delete[] mStreamable;
}

bool Netflix::accountExists(const Account& account) const
{
    for (size_t i = 0; i < mNumberOfAccounts; i++) {
        if (mAccounts[i]->getUsername() == account.getUsername()) {
            return true;
        }
    }
}

bool Netflix::streamableExists(std::string& streamableName) const
{
    for (size_t i = 0; i < mNumberOfStreamables; i++) {
        if (mStreamable[i]->getTitle() == streamableName) {
            return true;
        }
    }
}

Netflix::Netflix(Account** accounts, size_t numberOfAccounts, IStreamable** streamables, size_t numberOfStreamables)
{
    copyAccounts(accounts, numberOfAccounts);
    copyStreamables(streamables, numberOfStreamables);
}

Netflix::~Netflix()
{
    eraseAccounts();
    eraseStreamables();
}

void Netflix::watch(const Account user, std::string videoContentName)
{
    bool userIsRegistered = accountExists(user);
    if (!userIsRegistered) {
        throw std::exception ("User not found!");
    }

    bool videoIsAvailable = streamableExists(videoContentName);
    if (!videoIsAvailable) {
        throw std::exception("Content not found!");
    }

    for (size_t i = 0; i < mNumberOfStreamables; i++) {
        if (mStreamable[i]->getTitle() == videoContentName) {
            mWatchingTime += mStreamable[i]->getDuration();
            break;
        }
    }
}

int Netflix::totalWatchedTimeByUsers() const
{
    return mWatchingTime;
}
