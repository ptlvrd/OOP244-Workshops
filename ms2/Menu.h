/*Author	patel vundaben vijaykumar
id - 158605220
date 12-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
    const int maxNumber = 7;
    class Menu {
        char* menuContent;
        int numOptions;

    public:
        Menu(const char* content);
        ~Menu();
        unsigned int run();

        // Add a member function to set the content
        void setContent(const char* content);

        Menu(const Menu& other) = delete;
        Menu& operator=(const Menu& other) = delete;
    };
}
#endif
