#pragma once

#include <string>
#include<string_view>
#include<map>
class CheckOut
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
	// declare constructor. normally constructor is public, if it is private or protected
	// that mean it is possible that the author want to create a singleton
	CheckOut();

	~CheckOut();

	// declare function

	void AddItemPrice(std::string_view item, double price);
	void AddItems(std::string_view item, int nums_of_items);
	double CalcTotalOfDiscountItems();
	double CalcTotal();
	void AddDisCount(std::string_view item, int num_of_items, int percentage_discount);
	
};

