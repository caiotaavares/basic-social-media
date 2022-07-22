#include <iostream>
#include <string>

// Functions
bool login();
bool regist();
void set_admin();
void users_list();

// Class
class User {
public:
    int             id{};
    std::string     username;
    std::string     password;
};

// Globals
User USERS[10];
User SESSION;
int USERS_NUM;

int main() {

    set_admin();
    while(true) {
        std::cout << "-------MENU-------" << std::endl;
        std::cout << "1 - Login" << std::endl;
        std::cout << "2 - Register" << std::endl;

        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                if (login()) {
                    std::cout << "Logged!" << std::endl;
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
    }
    return 0;
}

bool login() {

    std::string username;
    std::string password;

    std::cout << "Username:";
    std::cin >> username;

    std::cout << "Password:";
    std::cin >> password;

    // Verify user
    for(const auto& user: USERS) {
        if(username == user.username && password == user.password) {
            SESSION = user;
            return true;
        } else return false;
    }

//    for (int i = 0; i < 10; i++) {
//        if(username == users[i].username && password == users[i].password) {
//            SESSION = users[i];
//            return true;
//        } else return false;
//    }
    return false;
};

bool regist() {

    char username[20];
    char password[20];
//    char conf_password[20];

    std::cout << "--------REGISTRO--------" << std::endl;

    std::cout << "Set username" << std::endl;
    std::cin >> username;

    std::cout << "Set password" << std::endl;
    std::cin >> password;

    //  FIX THE SECOND PASSWORD
//    std::cout << "Confirm password" << std::endl;
//    std::cin >> conf_password;

//    if (password != conf_password) {
//        std::cout << "*Passwords not checked" << std::endl;
//        regist();
//    }

    USERS_NUM++;
    USERS[USERS_NUM].id = USERS_NUM;
    USERS[USERS_NUM].username = username;
    USERS[USERS_NUM].password = password;

    for (auto & user : USERS) {
        std::cout << user.id << std::endl;
        std::cout << user.username << std::endl;
        std::cout << user.password << std::endl;
    };
    return false;
}

void set_admin() {
    USERS[0] = {1, "admin", "admin"};
    USERS_NUM = 1;
}

void users_list() {
    for (int i = 0; i < USERS_NUM; i++) {
        std::cout << "User: " << i << std::endl;
        std::cout << "Id: " << USERS[i].id << std::endl;
        std::cout << "Username: " << USERS[i].username << std::endl;
        std::cout << std::endl;
    }
}
