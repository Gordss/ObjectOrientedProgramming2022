#pragma once
#include <string>

class Episode {
	std::string mName;
	int mDuration;
public:
	Episode(std::string name, int duration);

	std::string getName() const;
	int getDuration() const;
};