/*Author	patel vundaben vijaykumar
id - 158605220
date 12-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "Status.h"
#include "Date.h"
#include "iProduct.h"
#include "Perishable.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    const int sdds_max_num_items = 100;
    class AidMan {
  
        char* fileName;
        Menu mainMenu;
        iProduct* products[sdds_max_num_items];
        int numProducts;
    public:
        AidMan();
        AidMan(const char* filename);
        ~AidMan();
        void save() const;
        void run();
        void deallocate();
        bool load(const char* filename);
      
        int list(const char* sub_desc = nullptr);

    

        AidMan(const AidMan& other) = delete;
        AidMan& operator=(const AidMan& other) = delete;

        int search(int sku)const;
        void add();

    private:
        unsigned int menu();
    };
}

#endif