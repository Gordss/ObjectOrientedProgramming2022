#include <dirent.h>
#include <iostream>
#include <cstring>
#include "MailService.h"
#include "Email.h"
#define MAX_CONTENT_SIZE 1024

void MailService::listEmails()
{
    struct dirent *d;
    DIR* dr;

    dr = opendir("./");

    if (dr != nullptr)
    {
        std::cout << "List of emails:\n";
        for(d=readdir(dr); d!=nullptr; d=readdir(dr))
        {
            if (strstr(d->d_name, ".mail") != nullptr)
            {
                std::cout << d->d_name << '\n';
            }
        }
        closedir(dr);
    }
}

void MailService::readMail(const char* filename)
{
    Email* mail = Email::open(filename);
    mail->display();
    mail->updateReadDate();
    mail->save();
}

void MailService::createNewMail()
{
    char creator[MAX_CONTENT_SIZE];
    std::cout << "Input creator name: ";
    std::cin.getline(creator, MAX_CONTENT_SIZE);
    
    char receiver[MAX_CONTENT_SIZE];
    std::cout << "Input receiver name: ";
    std::cin.getline(receiver, MAX_CONTENT_SIZE);

    char content[MAX_CONTENT_SIZE];
    std::cout << "Input content: ";
    std::cin.getline(content, MAX_CONTENT_SIZE);

    Email* mail = new Email(creator, receiver, content);

    char filename[MAX_CONTENT_SIZE];
    std::cout << "Input filename: ";
    std::cin.getline(filename, MAX_CONTENT_SIZE);
    mail->setFileName(filename);

    mail->save();

    delete mail;
}

void MailService::help()
{
    std::cout << "Commands:\n";
    std::cout << "ls - list all mails in current dir\n";
    std::cout << "read <filename> - open mail\n";
    std::cout << "create - create new mail\n";
    std::cout << "quit - quit program\n";
}