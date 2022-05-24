#include "Series.h"

void Series::copySeries(std::string title, Genre genre, PgRating rating, Episode** episodes, size_t numberOfEpisodes)
{
	setTitle(title);
	setGenre(genre);
	setRating(rating);
	copyEpisodes(episodes, numberOfEpisodes);
}

void Series::copyEpisodes(Episode** episodes, size_t numberOfEpisodes)
{
	mNumberOfEpisodes = numberOfEpisodes;
	mEpisodes = new Episode * [mNumberOfEpisodes];
	for (size_t i = 0; i < mNumberOfEpisodes; i++) {
		mEpisodes[i] = new Episode(episodes[i]->getName(), episodes[i]->getDuration());
	}
}

void Series::erase()
{
	for (size_t i = 0; i < mNumberOfEpisodes; i++) {
		delete mEpisodes[i];
	}
	delete[] mEpisodes;
}

Series::Series(std::string title, Genre genre, PgRating rating, Episode** episodes, size_t numberOfEpisodes)
{
	copySeries(title, genre, rating, episodes, numberOfEpisodes);
}

Series::~Series()
{
	erase();
}

Series::Series(const Series& other)
{
	copySeries(other.getTitle(), other.getGenre(), other.getRating(), other.getEpisodes(), other.getNumberOfEpisodes());
}

Series& Series::operator=(const Series& other)
{
	if (this != &other) {
		erase();

		copySeries(other.getTitle(), other.getGenre(), other.getRating(), other.getEpisodes(), other.getNumberOfEpisodes());
	}
	return *this;
}

Episode** Series::getEpisodes() const
{
	return mEpisodes;
}

size_t Series::getNumberOfEpisodes() const
{
	return mNumberOfEpisodes;
}

int Series::getDuration() const
{
	int totalDuration = 0;
	for (size_t i = 0; i < mNumberOfEpisodes; i++) {
		totalDuration += mEpisodes[i]->getDuration();
	}
	return totalDuration;
}

IStreamable* Series::clone() const
{
	return new Series(*this);
}
