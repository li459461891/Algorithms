#include <iostream>
#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <deque>
using std::vector;
using std::deque;

// Given an array of integers A sorted in non-decreasing order,
// return an array of the squares of each number, also in sorted non-decreasing order.

// Example 1:

// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Example 2:

// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        deque<int> negativeDeque;
        vector<int> resultVec;
        int index = 0;
        for ( ; index < A.size(); ++index)
        {
            if (A[index] < 0) { negativeDeque.emplace_front(A[index]); }
            else { break; }
        }
        while(!negativeDeque.empty() && index < A.size())
        {
            if (-1 * negativeDeque.front() <= A[index])
            {
                resultVec.emplace_back(negativeDeque.front() * negativeDeque.front());
                negativeDeque.pop_front();
            }
            else
            {
                resultVec.emplace_back(A[index] * A[index]);
                ++index;
            }
        }
        if (index == A.size())
        {
            while(!negativeDeque.empty())
            {
                resultVec.emplace_back(negativeDeque.front() * negativeDeque.front());
                negativeDeque.pop_front();
            }
        }
        else
        {
            for (;index < A.size() ; ++index) { resultVec.emplace_back(A[index] * A[index]); }
        }
        return resultVec;
    }
};

// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
class SquaresOfASortedArrayNo977Tests : public testing::Test
{
public:
    Solution sut_;
}; // class SquaresOfASortedArrayNo977Tests

TEST_F(SquaresOfASortedArrayNo977Tests, testcases)
{
    std::vector<int> A1 = {-4, -1, 0, 3, 10};
    std::vector<int> A2 = {-7, -3, 2, 3, 11};

    auto result1 = sut_.sortedSquares(A1);
    auto result2 = sut_.sortedSquares(A2);

    EXPECT_EQ((std::vector<int>{0,1,9,16,100}), result1);
    EXPECT_EQ((std::vector<int>{4,9,9,49,121}), result2);
}