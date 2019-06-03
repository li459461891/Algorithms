#ifndef Qsort_h
#define Qsort_h
#include <iostream>
#include <vector>

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
 
 */

using std::vector;

namespace Qsort {
    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            qsort(nums, 0, nums.size() - 1);
            return nums;
        }
    private:
        void swapIfNotEqual(int& num1 ,int& num2)
        {
            if (num1 != num2)
            {
                int tmp = num1;
                num1 = num2;
                num2 = tmp;
            }
        }
        
        int partition(vector<int>& nums, int left, int right)
        {
            int middleNum = nums[right];
            int j = left - 1;
            
            for (int i = left ; i < right ; ++i)
            {
                if (middleNum > nums[i])
                    swapIfNotEqual(nums[i], nums[++j]);
            }
            swapIfNotEqual(nums[right], nums[++j]);
            return j;
        }
        
        void qsort(vector<int>& nums, int left, int right)
        {
            // In this case no need to sort, only one or none elems. Alos exit of recursion funciton.
            if (left >= right)
                return;
            int middleIndex = partition(nums, left, right);
            qsort(nums, left, middleIndex - 1);
            qsort(nums, middleIndex + 1, right);
        }
        
    };
}  // namespace Qsort

#endif /* Qsort_h */

