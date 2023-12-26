/*Author	patel vrundaben vijaykumar
id - 158605220
date 29-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include "Item.h"
#include "Date.h"
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

namespace sdds {

    class Perishable :public Item {
    private:
        Date m_expiry;
        char* m_handling;

    public:
        Perishable();
        Perishable(const Perishable& src);
        ~Perishable();
        Perishable& operator=(const Perishable& src);
        operator bool() const override;
        const Date& expiry() const;
        std::ostream& display(std::ostream& ostr) const override;

        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;

        int readSku(std::istream& istr) override;
        std::istream& read(std::istream& istr) override;
    };


}

#endif // SDDS_PERISHABLE_H