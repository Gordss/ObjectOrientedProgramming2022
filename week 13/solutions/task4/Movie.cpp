#include "Movie.h"

Movie::Movie(std::string title, Genre genre, PgRating rating, int duration)
{
	setTitle(title);
	setGenre(genre);
	setRating(rating);
	mDuration = duration;
}

int Movie::getDuration() const
{
	return mDuration;
}

IStreamable* Movie::clone() const
{
	return new Movie(*this);
}
