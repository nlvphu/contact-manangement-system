#include "contact.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Contact constructor definition
Contact::Contact(const std::string& n, const std::string& p, const std::string& e)
    : name(n), phone(p), email(e) {}

// Function definitions
void addContact(std::vector<Contact>& contacts) {
    std::string name, phone, email;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    contacts.push_back(Contact(name, phone, email));
    std::cout << "Contact added successfully.\n";
}

void displayContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts to display.\n";
        return;
    }
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << "\n";
        std::cout << "Phone: " << contact.phone << "\n";
        std::cout << "Email: " << contact.email << "\n";
        std::cout << "-------------------\n";
    }
}

void searchContact(const std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Phone: " << contact.phone << "\n";
            std::cout << "Email: " << contact.email << "\n";
            return;
        }
    }
    std::cout << "Contact not found.\n";
}

void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter name to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    auto it = std::remove_if(contacts.begin(), contacts.end(),
                              [&name](const Contact& contact) { return contact.name == name; });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted successfully.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

void saveContacts(const std::vector<Contact>& contacts, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
        }
        file.close();
    } else {
        std::cout << "Unable to open file for saving.\n";
    }
}

void loadContacts(std::vector<Contact>& contacts, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name, phone, email;
        while (std::getline(file, name) && std::getline(file, phone) && std::getline(file, email)) {
            contacts.push_back(Contact(name, phone, email));
        }
        file.close();
    }
}
