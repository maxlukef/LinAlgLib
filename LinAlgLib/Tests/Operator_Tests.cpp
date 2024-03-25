#include <gtest/gtest.h>
#include <vector>
#include "../Matrix.hpp"

//Tests the + operator
TEST(OperatorTests, AddTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	LinAlgLib::Matrix<double> m2(2, 2, d);
	LinAlgLib::Matrix<double> res = m + m2;
	ASSERT_EQ(res.get_element(0, 0), 2.0);
	ASSERT_EQ(res.get_element(0, 1), 4.0);
	ASSERT_EQ(res.get_element(1, 0), 6.0);
	ASSERT_EQ(res.get_element(1, 1), 8.0);
}

//Tests the * operator for scalar multiplication
TEST(OperatorTests, ScalarMultTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	LinAlgLib::Matrix<double> res = m * 2;
	ASSERT_EQ(res.get_element(0, 0), 2.0);
	ASSERT_EQ(res.get_element(0, 1), 4.0);
	ASSERT_EQ(res.get_element(1, 0), 6.0);
	ASSERT_EQ(res.get_element(1, 1), 8.0);
}

//Tests the *= operator for scalar multiplication
TEST(OperatorTests, ScalarMultEqTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> res(2, 2, d);
	res *= 2;
	ASSERT_EQ(res.get_element(0, 0), 2.0);
	ASSERT_EQ(res.get_element(0, 1), 4.0);
	ASSERT_EQ(res.get_element(1, 0), 6.0);
	ASSERT_EQ(res.get_element(1, 1), 8.0);
}

//Tests +=
TEST(OperatorTests, AddEqTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	LinAlgLib::Matrix<double> m2(2, 2, d);
	m += m2;
	ASSERT_EQ(m.get_element(0, 0), 2.0);
	ASSERT_EQ(m.get_element(0, 1), 4.0);
	ASSERT_EQ(m.get_element(1, 0), 6.0);
	ASSERT_EQ(m.get_element(1, 1), 8.0);
}

//Tests -
TEST(OperatorTests, SubtractTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	LinAlgLib::Matrix<double> m2(2, 2, d);
	LinAlgLib::Matrix<double> res = m - m2;
	ASSERT_EQ(res.get_element(0, 0), 0.0);
	ASSERT_EQ(res.get_element(0, 1), 0.0);
	ASSERT_EQ(res.get_element(1, 0), 0.0);
	ASSERT_EQ(res.get_element(1, 1), 0.0);
}

//Tests *
TEST(OperatorTests, MultTest) {
	std::vector<std::vector<double>> d = { {1,2,3},{4,5,6} };
	std::vector<std::vector<double>> d2 = { {10,11},{20,21},{30,31} };
	LinAlgLib::Matrix<double> m(2, 3, d);
	LinAlgLib::Matrix<double> m2(3, 2, d2);
	LinAlgLib::Matrix<double> res = m * m2;
	ASSERT_EQ(res.get_rows(), 2);
	ASSERT_EQ(res.get_cols(), 2);
	ASSERT_EQ(res.get_element(0, 0), 140.0);
	ASSERT_EQ(res.get_element(0, 1), 146.0);
	ASSERT_EQ(res.get_element(1, 0), 320.0);
	ASSERT_EQ(res.get_element(1, 1), 335.0);
}

//Tests -=
TEST(OperatorTests, SubtractEqTest) {
	std::vector<std::vector<double>> d = { {1,2},{3,4} };
	LinAlgLib::Matrix<double> m(2, 2, d);
	LinAlgLib::Matrix<double> m2(2, 2, d);
	m -= m2;
	ASSERT_EQ(m.get_element(0, 0), 0.0);
	ASSERT_EQ(m.get_element(0, 1), 0.0);
	ASSERT_EQ(m.get_element(1, 0), 0.0);
	ASSERT_EQ(m.get_element(1, 1), 0.0);
}

//Tests *=
TEST(OperatorTests, MultEqTest) {
	std::vector<std::vector<double>> d = { {1,2,3},{4,5,6} };
	std::vector<std::vector<double>> d2 = { {10,11},{20,21},{30,31} };
	LinAlgLib::Matrix<double> m(2, 3, d);
	LinAlgLib::Matrix<double> m2(3, 2, d2);
	m *= m2;
	ASSERT_EQ(m.get_rows(), 2);
	ASSERT_EQ(m.get_cols(), 2);
	ASSERT_EQ(m.get_element(0, 0), 140.0);
	ASSERT_EQ(m.get_element(0, 1), 146.0);
	ASSERT_EQ(m.get_element(1, 0), 320.0);
	ASSERT_EQ(m.get_element(1, 1), 335.0);
}
