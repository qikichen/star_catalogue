#include "menu.h"
#include "data.h"

int get_choice(int i, int j) // LOWER BOUND AND UPPER BOUND

//Validates user choices
{
    int choice;
    while (true)
    {
        std::cout << "Enter an integer (" << i << "-" << j << "): ";
        if (!(std::cin >> choice))
        {
            std::cout << "INPUT INVALID! Please enter an integer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice < i || choice > j || std::cin.fail()==true || std::cin.peek() != '\n')
        {
            std::cout << "INPUT INVALID! Please enter an integer between " << i << " and " << j << ".\n";
            continue;
        }
        break;
    }
    return choice;
}

void menu_one() // FIRST MENU INTERFACE
{
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------PLEASE CHOOSE ONE OF THE FOLLOWING!------------------------------------------" << std::endl;
    std::cout << "----------------------------------WELCOME TO THE STAR CATALOGUE---------------------------------------------" << std::endl;
    std::cout << "-----------------------1. Add Galaxy ---------------------2. Add Singular Objects to Existing Galaxies------" << std::endl;
    std::cout << "-----------------------3. Search for Galaxy ------------- 4. Filter/Sort Galaxy Catalogue-------------------" << std::endl;
    std::cout << "-----------------------5. Print Galaxies ---------------- 6. Add File---------------------------------------" << std::endl;
    std::cout << "-----------------------7. Delete Galaxies --------------- 8. Save File--------------------------------------" << std::endl;
    std::cout << "-------------------------------------------9.End Program----------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
}


void filter_menu() // MENU TO ASCEND OR DESCEND MASS
{
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------GALAXY TAB--------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------PLEASE CHOOSE ONE OF THE FOLLOWING!------------------------------------------" << std::endl;
    std::cout << "----------------------1. Descending Name ----------------- 2. Ascending Name--------------------------------" << std::endl;
    std::cout << "----------------------3. Descending Mass ----------------- 4. Ascending Mass--------------------------------" << std::endl;
    std::cout << "----------------------5. Descending Size ----------------- 6. Ascending Size--------------------------------" << std::endl;
    std::cout << "-------------------------------------------7.Go Back--------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
}

void obj_menu(std::shared_ptr<Galaxy> &gal) //GALAXY SPECIFIC MENU 
{
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------"<< gal->get_name() <<"-------------------------------------------" << std::endl;
    std::cout << "-------------------------------PLEASE CHOOSE ONE OF THE FOLLOWING!------------------------------------------" << std::endl;
    std::cout << "---------------1. Sort Constituents Descending  ----------------- 2. Sort Constituents Ascending -----------" << std::endl;
    std::cout << "---------------3. Search Singular Object-------------------------4.Delete Singular Object-------------------" << std::endl;
    std::cout << "----------------------------------------5.Filter Object Type------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------6.Go Back--------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
}

void sort_menu(std::shared_ptr<Galaxy> &gal) //SORTING MENU 
{
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------"<< gal->get_name() <<"-----------------------------------------------" << std::endl;
    std::cout << "-------------------------------PLEASE CHOOSE ONE OF THE FOLLOWING!-------------------------------------------" << std::endl;
    std::cout << "---------------------------WHAT WOULD YOU LIKE TO SORT THE OBJECTS BY?---------------------------------------" << std::endl;
    std::cout << "------------------------1. Mass  --------------------- 2. Name ----------------------------------------------" << std::endl;
    std::cout << "------------------------3. Redshift  ----------------- 4. Object Type ---------------------------------------" << std::endl;
    std::cout << "-------------------------------------------5. Radius---------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------6.Go Back---------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
}