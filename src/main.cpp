#include "contact.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Contact> contacts;
    std::string filename = "contacts.txt";
    loadContacts(contacts, filename);

    int choice;
    do {
        std::cout << "Contact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Delete Contact\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                saveContacts(contacts, filename);
                std::cout << "Contacts saved. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
