#include <iostream>
#include "../objects/clsUser.h"
#include "global.h"
#include "../inheritance_screen/clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
    static bool _login()
    {
        bool loginFailed = false;
        int failedLoginCount = 0;
        string username;
        string password;

        do
        {
            if (loginFailed)
            {
                failedLoginCount++;
                cout << "\nInvalid username/password!\n";
                cout << "you have " << 3 - failedLoginCount << " Trails to login.\n\n";
            }

            if (failedLoginCount == 3)
            {
                cout << "\nYour are locked after " << failedLoginCount << "\n\n";
                return false;
            }

            username = clsInputValidate::readString("Enter username: ");
            password = clsInputValidate::readString("Enter password: ");
            currentUser = clsUser::find(username, password);

            loginFailed = currentUser.isEmpty();

        } while (loginFailed);

        currentUser.loginRegister();
        clsMainScreen::showMainMenu();

        return true;
    }

public:
    static bool showLogin()
    {
        _drawScreenHeader("Login Screen");
        return _login();
    }
};