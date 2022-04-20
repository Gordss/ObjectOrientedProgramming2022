#include <iostream>
#include <cstring>
#include "MailService.h"

#define MAX_COMMAND_SIZE 32

int main() {
	
	char input[MAX_COMMAND_SIZE];

	MailService::help();

	do
	{
		std::cout << ">";
		std::cin.getline(input, MAX_COMMAND_SIZE);

		if (strcmp(input, "ls") == 0)
		{
			MailService::listEmails();
		}
		else if (strcmp(input, "read") == 0)
		{
			std::cout << "Input filename: ";
			std::cin.getline(input, MAX_COMMAND_SIZE);
			MailService::readMail(input);
		}
		else if (strcmp(input, "create") == 0)
		{
			MailService::createNewMail();
		}
		else if (strcmp(input, "help") == 0)
		{
			MailService::help();
		}
		
	} while (strcmp(input, "quit") != 0);
	
	return 0;
}