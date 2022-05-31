#ifndef __VOLUME_DOWN_COMMAND_H
#define __VOLUME_DOWN_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"
class VolumeDownCommand : public ICommand
{
private:
    Receiver &mReceiver;

public:
    VolumeDownCommand(Receiver &);

    void execute() override;
    std::string toString() const override;
};

#endif