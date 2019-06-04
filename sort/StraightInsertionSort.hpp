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

#ifndef SORT_AN_ARRAY_HPP_
#define SORT_AN_ARRAY_HPP_

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>

using std::vector;
namespace SortAnArray {

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return straightInsertArray(nums);
    }
private:
    vector<int> straightInsertArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
        {
            int tmp = nums[i];
            int j = i - 1;
            for (; j >= 0; --j)
            {
                if (nums[j] > tmp)
                    nums[j + 1] = nums[j];
                else
                    break;
            }
            nums[j + 1] = tmp;
        }
        return nums;
    }
};
}  // namespace SortAnArray
/*
int main(int argc, const char * argv[])
{
    // insert code here...
    
    std::vector<int> testVec = {5,1,1,2,0,0};
    std::for_each(testVec.begin(), testVec.end(), [](int &n){ std::cout << n << " "; });
    std::cout << std::endl;
    SortAnArray::Solution().sortArray(testVec);
    std::for_each(testVec.begin(), testVec.end(), [](int &n){ std::cout << n << " "; });
    std::cout << std::endl;
    return 0;
}
*/


#endif  // SORT_AN_ARRAY_HPP_

