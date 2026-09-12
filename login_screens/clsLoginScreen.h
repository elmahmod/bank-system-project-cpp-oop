#include <iostream>
#include "../objects/clsUser.h"
#include "global.h"
#include "../inheritance_screen/clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
    static void _login()
    {
        bool loginFailed = false;
        string username;
        string password;
        do
        {
            if (loginFailed)
                cout << "\nInvalid username/password!\n\n";

            username = clsInputValidate::readString("Enter username: ");
            password = clsInputValidate::readString("Enter password: ");

            currentUser = clsUser::find(username, password);

            loginFailed = currentUser.isEmpty();

        } while (loginFailed);
        clsMainScreen::showMainMenu();
    }

public:
    static void showLogin()
    {
        _drawScreenHeader("Login Screen");
        _login();
    }
};