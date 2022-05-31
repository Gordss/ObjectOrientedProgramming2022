/*

SRP

Single Responsibility Principle

A class should have one and only one reason to change,
meaning that a class should have only one job.

*/

#include <vector>
class Image;

// don't
class PhotoUploader
{
	std::vector<Image> images;

public:
	Image getImageById(size_t id);
	Image resizeImage(int x, int y, const Image &image);
	void uploadImage(Image &image);
};

// do
class PhotoUploader
{
	PhotoCloud cloud;

public:
	void uploadImage(Image &image);
};

class PhotoResizer
{
	Image resizeImage(int x, int y, const Image &image);
};

class PhotoCloud
{
	std::vector<Image> images;

public:
	Image getImageById(size_t id);
};