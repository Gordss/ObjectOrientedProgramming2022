#pragma once
#include "IStreamable.h"

class Movie : public IStreamable {
	int mDuration;
public:
	Movie(std::string title, Genre genre, PgRating rating, int Duration);

	int getDuration() const override;
	IStreamable* clone() const override;
};
