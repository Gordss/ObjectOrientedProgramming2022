#pragma once
#include "doctest.h"
#include "Movie.h"
#include "Series.h"
#include "Netflix.h"

#define NAME_MAX_SIZE 28

TEST_CASE("Creating a series") {
	size_t numberOfEpisodes = 3;
	Episode** episodes = new Episode * [numberOfEpisodes];
	for (size_t i = 0; i < numberOfEpisodes; i++) {
		char* episodeName = new char[NAME_MAX_SIZE];
		episodes[i] = new Episode(_itoa(i, episodeName, 10), (i + 1) * 10);
		delete[] episodeName;
	}

	Series series("Some very mini-series", Genre::ACTION, PgRating::PG13, episodes, numberOfEpisodes);
	CHECK(series.getNumberOfEpisodes() == 3);
	CHECK(series.getDuration() == 60);

	for (size_t i = 0; i < numberOfEpisodes; i++) {
		delete episodes[i];
	}
	delete[] episodes;
}

#define ACCOUNTS_NUMBER 2
#define STREAMABLES_NUMBER 3

TEST_CASE("Creation and watching in Netflix") {
	Account** accounts = new Account * [ACCOUNTS_NUMBER];
	accounts[0] = new Account("proud_mary", time(0));
	accounts[1] = new Account("jack123", time(0) + 1);

	IStreamable** streamables = new IStreamable * [STREAMABLES_NUMBER];
	streamables[0] = new Movie("Seven", Genre::ACTION, PgRating::PG13, 120);
	streamables[1] = new Movie("Shrek", Genre::COMEDY, PgRating::G, 98);

	size_t numberOfEpisodes = 6;
	Episode** episodes = new Episode * [numberOfEpisodes];
	for (size_t i = 0; i < numberOfEpisodes; i++) {
		char* episodeName = new char[NAME_MAX_SIZE];
		episodes[i] = new Episode(_itoa(i, episodeName, 10), (i + 1) * 10);
		delete[] episodeName;
	}
	streamables[2] = new Series("Behind her eyes", Genre::HORROR, PgRating::PG13, episodes, numberOfEpisodes);

	Netflix netflix(accounts, ACCOUNTS_NUMBER, streamables, STREAMABLES_NUMBER);
	CHECK(netflix.totalWatchedTimeByUsers() == 0);
	
	netflix.watch(*accounts[0], "Seven");
	CHECK(netflix.totalWatchedTimeByUsers() == 120);

	for (size_t i = 0; i < numberOfEpisodes; i++) {
		delete episodes[i];
	}
	delete[] episodes;

	for (size_t i = 0; i < ACCOUNTS_NUMBER; i++) {
		delete accounts[i];
	}
	delete[] accounts;

	for (size_t i = 0; i < STREAMABLES_NUMBER; i++) {
		delete streamables[i];
	}
	delete[] streamables;
}
