#include "Email.h"
#include "Utils.h"
#include <fstream>
#include <cstring>

void Email::copy(const Email& other)
{
    this->mCreateDate = other.mCreateDate;
    this->mCreatorName = Utils::copyDyn(other.mCreatorName);
    this->mReceiverName = Utils::copyDyn(other.mReceiverName);
    this->mLastReadDate = other.mLastReadDate;
    this->mFileName = Utils::copyDyn(other.mFileName);
    this->mContent = Utils::copyDyn(other.mContent);
}

void Email::erase()
{
    delete this->mCreateDate;
    delete[] this->mCreatorName;
    delete[] this->mReceiverName;
    delete this->mLastReadDate;
    delete[] this->mFileName;
    delete[] this->mContent;
}

Email::Email()
{
    this->mCreateDate = nullptr;
    this->mCreatorName = nullptr;
    this->mReceiverName = nullptr;
    this->mLastReadDate = nullptr;
    this->mFileName = nullptr;
    this->mContent = nullptr;
}

Email::Email(const char* creator, const char* receiver, const char* content)
{
    this->mCreateDate = Date::getCurrentDate();
    this->mCreatorName = Utils::copyDyn(creator);
    this->mReceiverName = Utils::copyDyn(receiver);
    this->mLastReadDate = nullptr;
    this->mFileName = Utils::copyDyn("no_name.mail");
    this->mContent = Utils::copyDyn(content);
}

Email::Email(const Email& other)
{
    this->copy(other);
}

Email& Email::operator=(const Email& other)
{
    if( this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

Email::~Email()
{
    this->erase();
}

void Email::setFileName(const char* filename)
{
    delete[] this->mFileName;
    this->mFileName = Utils::copyDyn(filename);
}

void Email::updateReadDate()
{
    this->mLastReadDate = Date::getCurrentDate();
}

void Email::display()
{
    std::cout << "\n\nFilename: " << this->mFileName << '\n';
    std::cout << "Create date: ";
    this->mCreateDate->writeDate(std::cout);

    std::cout << "Creator: " << this->mCreatorName << '\n';
    std::cout << "Receiver: " << this->mReceiverName << '\n';
    std::cout << "Content:\n";
    std::cout << this->mContent << "\n";

    if (this->mLastReadDate != nullptr)
    {
        this->mLastReadDate->writeDate(std::cout);
    }

    std::cout << "\n\n";
}

Email* Email::open(const char* filename)
{
    Email* result = new Email();
    std::ifstream openFile;
    openFile.open(filename, std::ios::binary);

    Date* createDate = Date::readDateBinary(openFile);
    result->mCreateDate = createDate;
    
    int buffSize;
	openFile.read((char*)&buffSize, sizeof(int));
	result->mCreatorName = new char[buffSize + 1];
	openFile.read(result->mCreatorName, sizeof(char) * buffSize);
	result->mCreatorName[buffSize] = 0;

    openFile.read((char*)&buffSize, sizeof(int));
	result->mReceiverName = new char[buffSize + 1];
	openFile.read(result->mReceiverName, sizeof(char) * buffSize);
	result->mReceiverName[buffSize] = 0;

    openFile.read((char*)&buffSize, sizeof(int));
	result->mContent = new char[buffSize + 1];
	openFile.read(result->mContent, sizeof(char) * buffSize);
	result->mContent[buffSize] = 0;

    result->mLastReadDate = openFile.eof() ? nullptr : Date::readDateBinary(openFile);
    result->mFileName = Utils::copyDyn(filename);
    openFile.close();
    return result;
}

void Email::save()
{
    std::ofstream saveFile;
    saveFile.open(this->mFileName, std::ios::trunc | std::ios::binary);

    this->mCreateDate->writeDateBinary(saveFile);

    int buffSize = strlen(this->mCreatorName);
	saveFile.write((char*)&buffSize, sizeof(buffSize));
	saveFile.write(this->mCreatorName, sizeof(char) * buffSize);

    buffSize = strlen(this->mReceiverName);
    saveFile.write((char*)&buffSize, sizeof(buffSize));
	saveFile.write(this->mReceiverName, sizeof(char) * buffSize);

    buffSize = strlen(this->mContent);
    saveFile.write((char*)&buffSize, sizeof(buffSize));
	saveFile.write(this->mContent, sizeof(char) * buffSize);

    if (this->mLastReadDate != nullptr)
    {
        this->mLastReadDate->writeDateBinary(saveFile);
    }

    saveFile.close();
}