#ifndef SelectSort_h
#define SelectSort_h
#include <vector>

namespace SelectSort {
class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        return SelectSort(nums);
    }
    
private:
    vector<int> SelectSort(vector<int>& nums)
    {
        auto vecSize = nums.size();
        for (int i = 0 ; i < vecSize - 1; ++i)
        {
            auto min = i;
            for (int j = i + 1; j < vecSize - 1; ++j) {
                if (nums[min] > nums[j])
                    min = j;
            }
            if (i != min)
                swap(nums[min], nums[i]);
        }
        return nums;
    }

    void swap(int& a, int& b)
    {
        auto tmp = a;
        a = b ;
        b = tmp;
    }
};
}  // namespace SelectSort

#endif /* SelectSort_h */
