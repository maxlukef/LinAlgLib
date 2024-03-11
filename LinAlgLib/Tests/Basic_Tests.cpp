#include <gtest/gtest.h>
#include <vector>
#include "../Matrix.hpp"

//Tests that all values in the basic(row,col) constructor are initialized to zero, and tests the get_element(row,col) function.
TEST(BasicTests, SmallCtorTest) {
	LinAlgLib::Matrix<double> m(3, 3);
	ASSERT_EQ(m.get_element(0, 0), 0.0);
	ASSERT_EQ(m.get_element(0, 1), 0.0);
	ASSERT_EQ(m.get_element(1, 0), 0.0);
	ASSERT_EQ(m.get_element(1, 1), 0.0);
	ASSERT_EQ(m.get_element(2, 2), 0.0);
}

//Tests that all values in the constructor with data are initialized to the specified values, and tests the get element(row,col) function.
TEST(BasicTests, SmallCtorValueTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	ASSERT_EQ(m.get_element(0, 0), 1.0);
	ASSERT_EQ(m.get_element(0, 1), 2.0);
	ASSERT_EQ(m.get_element(1, 0), 3.0);
	ASSERT_EQ(m.get_element(1, 1), 4.0);
}
