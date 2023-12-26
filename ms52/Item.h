/*Author	patel vrundaben vijaykumar
id - 158605220
date 29-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include <ostream>
#include "iProduct.h"
#include "Status.h"
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#define MAX_SKU_LEN 10

namespace sdds {
    class Item : public iProduct {
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char* m_description;
        bool m_linear;

    protected:
        Status m_state;
        int m_sku;

    public:
        Item();
        ~Item();
        Item(const Item& src);
        Item& operator=(const Item& src);

        void clear();

        int qtyNeeded() const override;
        int qty() const override;
        operator double() const override;
        operator bool() const override;

        int operator-=(int qty) override;
        int operator+=(int qty) override;
        void linear(bool isLinear) override;

        bool operator==(int sku) const override;
        bool operator==(const char* description) const override;

        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;
        std::ostream& display(std::ostream& ostr) const override;

        int readSku(std::istream& istr) override;
        std::istream& read(std::istream& istr) override;

        bool linear() const;
    };
}

#endif // SDDS_ITEM_H