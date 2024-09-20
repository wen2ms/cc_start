#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

const int kNumContacts = 1000;

struct Contact {
    std::string name;
    char gender;
    int age;
    std::string telephone;
    std::string address;
};

struct ContactList {
    Contact contacts[kNumContacts];
    int num_contacts = 0;
};

int search_contact(const ContactList& contact_list, std::string target_name) {
    for (int i = 0; i < contact_list.num_contacts; i ++) {
        if (target_name == contact_list.contacts[i].name)
            return i;
    }

    return 40400;
}

int add_contact(ContactList& contact_list, Contact new_contact) {
    if (contact_list.num_contacts == kNumContacts)
    {
        return 406;
    } else if (search_contact(contact_list, new_contact.name) != 40400) {
        return 407;
    }

    contact_list.contacts[contact_list.num_contacts++] = new_contact;

    return 200;
}

void print_contacts(const ContactList& contact_list) {
    std::cout << std::left << std::setw(13) << "name"
              << std::setw(8) << "gender"
              << std::setw(5) << "age"
              << std::setw(15) << "telephone"
              << "address" << '\n';

    std::cout << std::string(50, '-') << '\n';
    for (int i = 0; i < contact_list.num_contacts; i ++)
    {
        std::cout << std::left << std::setw(13) << contact_list.contacts[i].name
                    << std::setw(8) << (contact_list.contacts[i].gender == 'F' ? "Female" : "Male") 
                    << std::setw(5) << contact_list.contacts[i].age
                    << std::setw(15) << contact_list.contacts[i].telephone
                    << contact_list.contacts[i].address << '\n';
    }
}

int remove_contact(ContactList& contact_list, std::string target_name) {
    if (contact_list.num_contacts == 0)
    {
        return 101;
    } else if (search_contact(contact_list, target_name) == 40400) {
        return 102;
    }

    for (int i = search_contact(contact_list, target_name); i < contact_list.num_contacts - 1; i ++) {
        contact_list.contacts[i] = contact_list.contacts[i+1];
    }

    contact_list.num_contacts --;

    return 200;
}

int clear_contacts(ContactList& contact_list) {
    contact_list.num_contacts = 0;
    return 200;
}

void view_title(void) {
    std::cout << "------------------------------\n";
    std::cout << "------     1. Add a contact     ------\n";
    std::cout << "------     2. Print a contact     ------\n";
    std::cout << "------     3. Remove a contact     ------\n";
    std::cout << "------     4. Search a contact     ------\n";
    std::cout << "------     5. Modify a contact     ------\n";
    std::cout << "------     6. Clear contacts     ------\n";
    std::cout << "------      0. Exit system     ------\n";
    std::cout << "------------------------------\n";
}

void view_input(Contact& new_contact) {
    std::cout << "Please input a contact name: ";
    std::cin >> new_contact.name;

    while (true) {
        std::cout << "Please input a contact gender(F or M): ";
        std::cin >> new_contact.gender;

        if (new_contact.gender == 'F' || new_contact.gender == 'M') {
            break;
        } else {
            std::cout << "input error!\n";
        }
    }

    std::cout << "Please input a contact age: ";
    std::cin >> new_contact.age;

    std::cout << "Please input a contact telephone: ";
    std::cin >> new_contact.telephone;

    std::cout << "Please input a contact address: ";
    std::cin >> new_contact.address; 
}

void view_add_contact(ContactList& contact_list) {
    Contact new_contact;

    view_input(new_contact);
    
    int state_code = add_contact(contact_list, new_contact);

    if (state_code == 200) {
        std::cout << "add contact successfully\n";
    } else if (state_code == 406) {
        std::cout << "add contact fail. contacts full\n";
    } else if (state_code == 407) {
        std::cout << "add contact fail. duplicate contacts\n";
    }
}

void view_remove_contact(ContactList& contact_list) {
    std::string target_name;

    std::cout << "Please input a contact name: ";
    std::cin >> target_name; 

    int state_code = remove_contact(contact_list, target_name);

    if (state_code == 200) {
        std::cout << "remove contact successfully\n";
    } else if (state_code == 101) {
        std::cout << "remove contact fail. contacts empty\n";
    } else if (state_code == 102) {
        std::cout << "remove contact fail. contact not found\n";
    }
}

void view_search_contact(const ContactList& contact_list) {
    std::string search_name;

    std::cout << "Please input a contact name: ";
    std::cin >> search_name; 

    int search_index = search_contact(contact_list, search_name);

    if (search_index != 40400) {
        std::cout << "search contact successfully\n";

        std::cout << std::left << std::setw(13) << "name"
        << std::setw(8) << "gender"
        << std::setw(5) << "age"
        << std::setw(15) << "telephone"
        << "address" << '\n';

        std::cout << std::string(50, '-') << '\n';
        std::cout << std::left << std::setw(13) << contact_list.contacts[search_index].name
                << std::setw(8) << contact_list.contacts[search_index].gender
                << std::setw(5) << contact_list.contacts[search_index].age
                << std::setw(15) << contact_list.contacts[search_index].telephone
                << contact_list.contacts[search_index].address << '\n';
    } else if (search_index == 40400) {
        std::cout << "search contact fail. contact not found\n";
    }
}

void view_modify_contact(ContactList& contact_list) {
    std::string search_name;
    Contact modified_contact;

    std::cout << "Please input the name of the contact you want to modify: ";
    std::cin >> search_name; 

    int search_index = search_contact(contact_list, search_name);

    if (search_index != 40400) {
        view_input(modified_contact);

        contact_list.contacts[search_index] = modified_contact;

        std::cout << "modify contact successfully\n";
    } else if (search_index == 40400) {
        std::cout << "modify contact fail. contact not found\n";
    }
}

void view_clear_contacts(ContactList& contact_list) {
    int state_code = clear_contacts(contact_list);

    if (state_code == 200) {
        std::cout << "clear contacts successfully\n";
    }
}

void exit_application(void) {
    std::cout << "exit the program..." << std::endl;
    std::exit(0);
}

void wait_for_keypress(void) {
    std::cout << "Press any key to return the menu...\n";
    std::cin.ignore();
    std::cin.get();
}

void menu_navigation(ContactList& contact_list) {
    char option_number;

    while (true) {
        system("clear");
        view_title();

        std::cin >> option_number;

        if (option_number == '1') {
            view_add_contact(contact_list);
        } else if (option_number == '2') {
            print_contacts(contact_list);
        } else if (option_number == '3') {
            view_remove_contact(contact_list);
        } else if (option_number == '4') {
            view_search_contact(contact_list);
        } else if (option_number == '5') {
            view_modify_contact(contact_list);
        } else if (option_number == '6') {
            view_clear_contacts(contact_list);
        } else if (option_number == '0') {
            exit_application();
        } else {
            std::cout << "error, input the number again\n";
        }

        wait_for_keypress();
    }
}

int main(void) {
    ContactList contact_list;

    menu_navigation(contact_list);

    return 0;
}