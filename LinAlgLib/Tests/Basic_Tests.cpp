#include <gtest/gtest.h>
#include <vector>
#include "../Matrix.hpp"

//Some tests for the basic constructors, getters and setters.

//Tests that all values in the basic(row,col) constructor are initialized to zero, and tests the get_element(row,col) function. Also tests get_rows, get_cols
TEST(BasicTests, SmallCtorTest) {
	LinAlgLib::Matrix<double> m(3, 3);
	ASSERT_EQ(m.get_element(0, 0), 0.0);
	ASSERT_EQ(m.get_element(0, 1), 0.0);
	ASSERT_EQ(m.get_element(1, 0), 0.0);
	ASSERT_EQ(m.get_element(1, 1), 0.0);
	ASSERT_EQ(m.get_element(2, 2), 0.0);
	ASSERT_EQ(m.get_rows(), 3);
	ASSERT_EQ(m.get_cols(), 3);
}

//Tests that all values in the constructor with data are initialized to the specified values, and tests the get element(row,col) function. Also tests get_rows, get_cols
TEST(BasicTests, SmallCtorValueTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	ASSERT_EQ(m.get_element(0, 0), 1.0);
	ASSERT_EQ(m.get_element(0, 1), 2.0);
	ASSERT_EQ(m.get_element(1, 0), 3.0);
	ASSERT_EQ(m.get_element(1, 1), 4.0);
	ASSERT_EQ(m.get_rows(), 2);
	ASSERT_EQ(m.get_cols(), 2);
}


TEST(BasicTests, SetterTest) {
	LinAlgLib::Matrix<double> m(3, 3);
	m.set_element(2, 2, 5);
	m.set_element(1, 0, -5);
	m.set_element(0, 1, 10);
	ASSERT_EQ(m.get_element(2, 2), 5.0);
	ASSERT_EQ(m.get_element(1, 0), -5.0);
	ASSERT_EQ(m.get_element(0, 1), 10.0);
}

TEST(BasicTests, GetterThrowTest) {
	LinAlgLib::Matrix<double> m(3, 3);
	ASSERT_THROW(m.get_element(2, 3), LinAlgLib::DimensionException);
	ASSERT_THROW(m.get_element(3, 2), LinAlgLib::DimensionException);
	ASSERT_THROW(m.get_element(2, -1), LinAlgLib::DimensionException);
	ASSERT_THROW(m.get_element(-1, 2), LinAlgLib::DimensionException);
}

TEST(BasicTests, SetterThrowTest) {
	LinAlgLib::Matrix<double> m(3, 3);
	ASSERT_THROW(m.set_element(2, 3, 3), LinAlgLib::DimensionException);
	ASSERT_THROW(m.set_element(3, 2, 3), LinAlgLib::DimensionException);
	ASSERT_THROW(m.set_element(2, -1, 3), LinAlgLib::DimensionException);
	ASSERT_THROW(m.set_element(-1, 2, 3), LinAlgLib::DimensionException);
}

TEST(BasicTests, SmallCtorValueThrowTest) {
	std::vector<std::vector<double>> d = { {1,2,3},{3,4} };
	ASSERT_THROW(LinAlgLib::Matrix<double>(2, 2, d), LinAlgLib::DimensionException);
}

TEST(BasicTests, SmallCtorValueThrowTest2) {
	std::vector<std::vector<double>> d = { {1,2},{3,4},{5,6} };
	ASSERT_THROW(LinAlgLib::Matrix<double>(2, 2, d), LinAlgLib::DimensionException);
}