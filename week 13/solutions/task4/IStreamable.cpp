#include "IStreamable.h"

std::string IStreamable::getTitle() const
{
	return mTitle;
}

Genre IStreamable::getGenre() const
{
	return mGenre;
}

PgRating IStreamable::getRating() const
{
	return mRating;
}

void IStreamable::setTitle(std::string title)
{
	mTitle = title;
}

void IStreamable::setGenre(Genre genre)
{
	mGenre = genre;
}

void IStreamable::setRating(PgRating rating)
{
	mRating = rating;
}
