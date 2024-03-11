enable_testing()

add_executable(
	Basic_Tests
	Basic_Tests.cpp
)
target_link_libraries(
	Basic_Tests
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Basic_Tests)