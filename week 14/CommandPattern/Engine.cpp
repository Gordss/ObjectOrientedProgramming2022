#include <iostream>
#include <cstring>
#include "Engine.h"
#include "TurnOffCommand.h"
#include "TurnOnCommand.h"
#include "VolumeUpCommand.h"
#include "VolumeDownCommand.h"
#include "PrintCommands.h"
#include "PrintStatusCommand.h"
#include "QuitCommand.h"

Engine::Engine()
{
    this->mRemoteControl.addCommand(new PrintCommands(mTV));
    this->mRemoteControl.addCommand(new PrintStatusCommand(mTV));
    this->mRemoteControl.addCommand(new TurnOffCommand(mTV));
    this->mRemoteControl.addCommand(new TurnOnCommand(mTV));
    this->mRemoteControl.addCommand(new VolumeUpCommand(mTV));
    this->mRemoteControl.addCommand(new VolumeDownCommand(mTV));
    this->mRemoteControl.addCommand(new QuitCommand(mTV));
}

void Engine::run()
{
#ifdef _WIN32
    system("cls");
#endif

#ifdef __unix__
    system("clear");
#endif

    std::string input;
    while (true)
    {
        std::cout << ">";
        getline(std::cin, input);
#ifdef _WIN32
        system("cls");
#endif

#ifdef __unix__
        system("clear");
#endif

        try
        {
            this->mRemoteControl.execute(input);
        }
        catch (const char *ex)
        {
            if (strcmp(ex, "quit") == 0)
            {
                return; 
            }
            std::cerr << ex;
        }
    }
}