#include "Episode.h"

Episode::Episode(std::string name, int duration)
{
	mName = name;
	mDuration = duration;
}

std::string Episode::getName() const
{
	return mName;
}

int Episode::getDuration() const
{
	return mDuration;
}
