#include <iostream>

// Functions
bool login();
bool regist();
void set_admin();
bool set_new_user(char username[20], char password[20]);
void users_list();

// Class
class User {
public:
    int             id;
    std::string     username;
    std::string     password;
};

// Globals
User users[10];
User session;
int users_num;

int main() {
    set_admin();

    std::cout << "-------MENU-------" << std::endl;
    std::cout << "1 - Login" << std::endl;
    std::cout << "2 - Register" << std::endl;

    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            if (login()) {
                break;
            } else {
                std::cout << "Username or password incorrect!" << std::endl;
                return 0;
            };

        case 2:
            regist();
            main();
            break;

        case 9:
            users_list();
            return 0;

        default:
            std::cout << "Option not displayable" << std::endl;
    }
    std::cout << "Logged!" << std::endl;
    return 0;
}

bool login() {

    char username[20];
    char password[20];

    std::cout << "Username:";
    std::cin >> username;

    std::cout << "Password:";
    std::cin >> password;

    // Verify user
    for(int i = 0; i < sizeof(users); i++) {
        if(username == users[i].username && password == users[i].password) {
            session = users[i];
            return true;
        } else return false;
    }
};

bool regist() {

    char username[20];
    char password[20];
    char conf_password[20];

    std::cout << "-------REGISTRO-------" << std::endl;

    std::cout << "Set username" << std::endl;
    std::cin >> username;

    std::cout << "Set password" << std::endl;
    std::cin >> password;

//    std::cout << "Confirm password" << std::endl;
//    std::cin >> conf_password;

//    if (password != conf_password) {
//        std::cout << "*Passwords not checked" << std::endl;
//        regist();
//    }

    set_new_user(username, password);
}

bool set_new_user(char username[20], char password[20]) {

    users[users_num].id = users_num;
    users[users_num].username = username;
    users[users_num].password = password;
};

void set_admin() {
    users[0] = {1, "admin", "admin"};
    users_num = 1;
}

void users_list() {
    for (int i = 0; i < users_num; i++) {
        std::cout << "User: " << i << std::endl;
        std::cout << "Id: " << users[i].id << std::endl;
        std::cout << "Username: " << users[i].username << std::endl;
        std::cout << std::endl;
    }
}
