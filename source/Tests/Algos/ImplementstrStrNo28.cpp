#include <Common.hpp>


//Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// 
// Example 1:
// 
// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:
// 
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Clarification:
// 
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. 
// This is consistent to C's strstr() and Java's indexOf().


class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;

		// The simple algorithm		
		for (int i = 0 ; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[0])
            {
                int j = 1;
                for ( ; j < needle.size(); ++j )
                {
                    if ( haystack[j+i] != needle[j]) break;
                }
                if (j == needle.size())
                {
                    return i;
                }
            }
        }

        return -1;
    }
};

// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
class ImplementstrStrNo28Tests: public testing::Test
{
public:
    Solution sut_;

};


TEST_F(ImplementstrStrNo28Tests, tests)
{
    // if needle is null 
    int result = sut_.strStr("abc", "");
    EXPECT_EQ(0, result);

    result = sut_.strStr("hello", "ll");
    EXPECT_EQ(2, result);

    result = sut_.strStr("aaaaa", "bba");
    EXPECT_EQ(-1, result);

    result = sut_.strStr("aaa", "aaaa");
    EXPECT_EQ(-1, result);

    result = sut_.strStr("mississippi", "issip");
    EXPECT_EQ(4, result);


}

TEST_F(ImplementstrStrNo28Tests, tests2)
{

    int result = sut_.strStr("aaa", "aaaa");
    EXPECT_EQ(-1, result);
}
