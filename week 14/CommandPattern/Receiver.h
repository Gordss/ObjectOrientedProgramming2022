#ifndef __RECEIVER_H
#define __RECEIVER_H

// the tv is the receiver
class Receiver
{
private:
	int mVolume;
	bool mOn;

public:
	Receiver();
	
	void turnOn();
	void turnOff();
	void volumeUp();
	void volumeDown();
	void printStatus() const;
	void printCommands() const;

	bool isOn();
};

#endif