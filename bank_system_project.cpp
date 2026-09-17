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

// The project is still missing some features, like adding permissions to some options
// But logically, the main part of the project is completed.
// Maybe I'll add them later, maybe not.

// I'm the kind of person who likes to rewrite the whole code again
// to make sure I really understand everything.

// So maybe I'll share the project again later with all the missing features.
