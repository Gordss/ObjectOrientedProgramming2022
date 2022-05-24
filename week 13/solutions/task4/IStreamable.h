#pragma once
#include <string>

enum class Genre {
	ACTION,
	HORROR,
	COMEDY
};

enum class PgRating {
	G,
	PG13,
	NC17
};

class IStreamable {
	std::string mTitle;
	Genre mGenre;
	PgRating mRating;
public:
	std::string getTitle() const;
	Genre getGenre() const;
	PgRating getRating() const;

	virtual int getDuration() const = 0;
	virtual IStreamable* clone() const = 0;

	void setTitle(std::string title);
	void setGenre(Genre genre);
	void setRating(PgRating rating);
};