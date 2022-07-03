#ifndef CALCPRICE_H
#define CALCPRICE_H

#include <string>
#include<string_view>
#include<map>

class CalcPrice
{

protected:
    struct Discount {
            int nums_of_items{};
            int percentage_discount{};

    };

    std::map<std::string_view, double > prices;
    std::map<std::string_view, Discount > map_discount;
    std::map<std::string_view, int > name_and_quantity_items;

    double m_total{};

public:
    CalcPrice();


    void AddItemPrice(std::string_view item, double price);
    void AddItems(std::string_view item, int nums_of_items);
    double CalcTotalOfDiscountItems();
    double CalcTotal();
    void AddDisCount(std::string_view item, int num_of_items, int percentage_discount);
};

#endif // CALCPRICE_H
