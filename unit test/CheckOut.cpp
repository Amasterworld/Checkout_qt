 #include "pch.h"
#include "CheckOut.h"


CheckOut::CheckOut()
{
}

CheckOut::~CheckOut()
{
}
void CheckOut::AddItemPrice(std::string_view item, double price) {

	prices[item] = price;
}

void CheckOut::AddItems(std::string_view item, int nums_of_items) {
	// get the total number of items
	if (nums_of_items >= 0)
		name_and_quantity_items[item] = nums_of_items;
	
	

	//std::cout <<"the number of items is  " << name_and_quantity_items[item] << std::endl;
	
}



void CheckOut::AddDisCount(std::string_view item, int num_of_items, int percentage_discount) {
	
	Discount discount;
	discount.nums_of_items = num_of_items;
	discount.percentage_discount = percentage_discount;
	
	// map the item to the discount structure to know the quantity of items that are discounting
	map_discount[item] = discount;
	
}

double CheckOut::CalcTotalOfDiscountItems()  {
	
	for (auto it_items = name_and_quantity_items.begin(); it_items != name_and_quantity_items.end(); ++it_items) {
		// get name of item
		std::string_view name_item = it_items->first;
		double price_item = prices.find(name_item)->second;
		//std::cout << "price of the " << name_item << " is " << price_item << std::endl;
		int quantity_items = it_items->second;
		//std::cout << "Quantity of the items is "<< quantity_items <<std::endl;
		// find whether the item is available:
		auto items = map_discount.find(name_item);
		// if the item is found
		if (items != map_discount.end()) {
			// because the items->second contains the struct Discount hence
			Discount discount = items->second;
			// if the available items discounting are >= the discount quantity

			std::cout << "Quantity of the DISCOUNT items is " << discount.nums_of_items << std::endl;
			if (quantity_items >= discount.nums_of_items) {
				m_total = (double)discount.nums_of_items * (price_item * ((100.0 - (double)discount.percentage_discount) / 100));
			}
			else {
				m_total = (double)quantity_items * (price_item * ((100.0 - (double)discount.percentage_discount) / 100));
			}
			
		}
		
				
	}
	return m_total;
}


double CheckOut::CalcTotal() {
	double res{};
	for (auto it_items = name_and_quantity_items.begin(); it_items != name_and_quantity_items.end(); ++it_items) {
		// get name of item
		std::string_view name_item = it_items->first;
		//double price_item = prices.find(name_item)->second;
		//std::cout << "price of the " << name_item << " is " << price_item << std::endl;
		int quantity_items = it_items->second;
		//std::cout << "Quantity of the items is "<< quantity_items <<std::endl;
		// find whether the item is available:
	
		res += quantity_items * prices[name_item];

	}
	return res;
}
