#include <iostream>
#include <string>

// Functions
bool login();
bool regist();
void set_admin();
void users_list();
void logged();

void blog_view();
void set_blog();

// Class
class User {
public:
    int             id{};
    std::string     username;
    std::string     password;
};

class Blog {
public:
    int             id{};
    std::string     title;
    std::string     context;
};

// Globals
User USERS[10];
User SESSION;
int USERS_NUM;
Blog BLOG[10];

int main() {

    set_admin();
    set_blog();
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
                    logged();
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

void logged() {

    std::cout << "-------PERFIL-------" << std::endl;
    std::cout << "Olá, " << SESSION.username << std::endl;

    std::cout << "-------MENU DO PERFIL-------" << std::endl;
    std::cout << "1 - Visualizar Blog" << std::endl;
    std::cout << "2 - Postar no Blog" << std::endl;

    int option;
    std::cin >> option;

    switch (option) {

        case 1:
            blog_view();
            break;
    }

}

void blog_view() {

};

void set_blog() {
    //Postagem de id 0
    BLOG[0].id = 0;
    BLOG[0].title = "lorem ipsum";
    BLOG[0].context = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    //Postagem de id 1
    BLOG[1].id = 1;
    BLOG[1].title = "lorem ipsum";
    BLOG[1].context = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
};
