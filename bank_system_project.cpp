#include <iostream>
#include "main_screens/clsMainScreen.h"
#include "login_screens/global.h"
#include "login_screens/clsLoginScreen.h"
using namespace std;

int main()
{
    while (true)
    {
        if (!clsLoginScreen::showLogin())
            break;
    }
    return 0;
}
