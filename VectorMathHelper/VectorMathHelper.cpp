#include <iostream>
#include "VectorCalculator.h";
#include "Menu.h";

Menu menu;

bool usingCalc = true;

int main()
{
    //Main menu manager
    while (usingCalc)
    {
        switch (menu.DrawMainScreen())
        {
        case 1:
            menu.DrawVecMagScreen();
            break;
        case 2:
            menu.DrawDotProductScreen();
            break;
        case 3:
            menu.DrawAngleBetweenScreen();
            break;
        case 4:
            menu.DrawCrossProductScreen();
            break;
        }

        std::cout << "Would you like to perform another operation? y/n" << std::endl;
        std::string yesno = "";
        while (yesno != "y" && yesno != "n")
        {
            std::cin >> yesno;
            if (yesno == "y" || yesno == "n")
            {
                break;
            }
            std::cout << "Make sure to enter a valid input" << std::endl;
        }

        if (yesno == "n")
        {
            usingCalc = false;
        }

    }

}