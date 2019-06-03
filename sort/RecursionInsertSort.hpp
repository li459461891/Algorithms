/*
 Given an array of integers nums, sort the array in ascending order.
 
 Example 1:
 
 Input: [5,2,3,1]
 Output: [1,2,3,5]
 Example 2:
 
 Input: [5,1,1,2,0,0]
 Output: [0,0,1,1,2,5]
 
 
 Note:
 
 1 <= A.length <= 10000
 -50000 <= A[i] <= 50000
 

LeetCode Time Limit Exceeded. Runtime more than expected.
 */
#ifndef RecursionInsertSort_hpp
#define RecursionInsertSort_hpp
#include <vector>

using std::vector;

namespace RecursionInsertSort {
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        recursionInsertSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void recursionInsertSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return ;
        recursionInsertSort(nums, left, right - 1);
        int targetNum = nums[right];
        int i = right - 1;

        for (; i >= left; i--)
        {
            if (nums[i] > targetNum)
                nums[i+1] = nums[i];
            else
                break;
        }
        nums[i+1] = targetNum;
    }
};
}  // namespace RecursionInsertSort

#endif /* RecursionInsertSort_hpp */

