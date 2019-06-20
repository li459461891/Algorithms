#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ReverseNumber/ReverseNum.hpp>

// INT_MAX = 2147483647
// INT_MIN = -2147483648

class ReverseNumberShould : public testing::Test
{
public:
    ReverseNumberShould()
    {
	}
	ReverseNumber::Solution sut_;

};

TEST_F(ReverseNumberShould, ReverseNumerTestCases)
{
	EXPECT_EQ(654321, sut_.reverse(123456));
	EXPECT_EQ(0, sut_.reverse(2147483647));
	EXPECT_EQ(0, sut_.reverse(-2147483648));
	EXPECT_EQ(-54321, sut_.reverse(-123450));
}
