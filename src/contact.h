#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;

    Contact(const std::string& n, const std::string& p, const std::string& e);
};

void addContact(std::vector<Contact>& contacts);
void displayContacts(const std::vector<Contact>& contacts);
void searchContact(const std::vector<Contact>& contacts);
void deleteContact(std::vector<Contact>& contacts);
void saveContacts(const std::vector<Contact>& contacts, const std::string& filename);
void loadContacts(std::vector<Contact>& contacts, const std::string& filename);

#endif
