#ifndef BubbleSort_h
#define BubbleSort_h
#include <vector>
using std::vector;
using Status = bool;

namespace BubbleSort
{
class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        return bubbleSort(nums);
    }
    
private:
    vector<int> bubbleSort(vector<int>& nums)
    {
        Status flg = true;  // Used for optimization, pure bubble sort algorithm if remove flg.
        for (int i = 0 ; i < nums.size() - 1 && flg; ++i)
        {
            flg = false;
            for ( int j = nums.size() - 2; j >= i ; j--)
            {
                if (nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    flg = true;
                }
            }
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
}  // namespace BubbleSort

#endif /* BubbleSort_h */
