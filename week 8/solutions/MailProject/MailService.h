#ifndef __MAILSERVICE_H
#define __MAILSERVICE_H

class MailService
{
public:
    static void listEmails();
    static void readMail(const char*);
    static void createNewMail();
    static void help();
};

#endif