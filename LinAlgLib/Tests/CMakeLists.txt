enable_testing()

add_executable(
	LinAlgTests
	Basic_Tests.cpp
    Operator_Tests.cpp)
target_link_libraries(
	LinAlgTests
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LinAlgTests)