#pragma once
#include "Episode.h"
#include "IStreamable.h"

class Series : public IStreamable {
	Episode** mEpisodes;
	size_t mNumberOfEpisodes;

	void copySeries(std::string title, Genre genre, PgRating rating, Episode** episodes, size_t numberOfEpisodes);
	void copyEpisodes(Episode** episodes, size_t numberOfEpisodes);
	void erase();
public:
	Series(std::string title, Genre genre, PgRating rating, Episode** episodes, size_t numberOfEpisodes);
	~Series();
	Series(const Series& other);
	Series& operator=(const Series& other);

	Episode** getEpisodes() const;
	size_t getNumberOfEpisodes() const;

	int getDuration() const override;
	IStreamable* clone() const override;
};
