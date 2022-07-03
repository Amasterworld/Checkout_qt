#include "pch.h" // pch include #include "gtest/gtest.h" 

#include "CheckOut.h"

// unit tests contain 3 phase: RED -> GREEN-> REFACTOR-> RED-> ....

// check 


// creae co object one time and use many times in the test
class CheckOutTest : public ::testing::Test {
public:
	
protected:
	CheckOut co;
};

TEST_F(CheckOutTest, CanAddItemPrice) {

	co.AddItemPrice("Cephalexin", 3.0);
}

TEST_F(CheckOutTest, CanAddItems) {


	
	co.AddItems("Cephalexin", 1);
}
TEST_F(CheckOutTest, CanAddNewItems) { // should change TEST to TEST_F = test fixture


	//CheckOut co; // no need it anymore
	co.AddItems("Amoxicillin", 1);
}

TEST_F(CheckOutTest, CanCalTotal) { // should change TEST to TEST_F = test fixture
	
	co.AddItemPrice("Cephalexin", 3.0);
	co.AddItemPrice("Amoxicillin",  2.0);
	co.AddItems("Cephalexin", 1);
	co.AddItems("Amoxicillin", 2);
	double total = co.CalcTotal();
	ASSERT_DOUBLE_EQ(7.0, total); // ASSERT DOUBLE number  5.0 == total
	//ASSERT_NEAR(4.9, 0.1, total); // ASSERT that 5.1.0 near  total around +-0,1, that means from 4.9 to 5.1
	// is acceptable result.
		
}

TEST_F(CheckOutTest, CanAddDiscount) {
	co.AddDisCount("Cephalexin", 3, 15);
}   

TEST_F(CheckOutTest, CanCalcWithDiscount) {
	double total = 0.0;
	co.AddItemPrice("Cephalexin", 3.0);
	//co.AddItemPrice("Apple", 2.0);
	co.AddDisCount("Cephalexin", 3, 15);

	co.AddItems("Cephalexin", 4);

	// calc  the total price with discount so far
	total = co.CalcTotalOfDiscountItems();
	double expect_value = 7.65;
	//std::cout<<"the price with discount is "<<total<<std::endl;

	ASSERT_DOUBLE_EQ(expect_value, total);
}