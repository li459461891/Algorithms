"""
python code much more readable and clean than that in C++ !
use python3 in leetcode, run time double of the c++.

python recursive function
Runtime: 248 ms, faster than 50.22% of Python3 online submissions for Sort an Array.
Memory Usage: 19.6 MB, less than 80.57% of Python3 online submissions for Sort an Array.

non recursive function
Runtime: 288 ms, faster than 38.44% of Python3 online submissions for Sort an Array.
Memory Usage: 19.6 MB, less than 77.26% of Python3 online submissions for Sort an Array.
"""
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        self._qsort(nums, 0, len(nums)-1)

    def _partition(self, arr, left, right):
        pos = left
        for j in range(left + 1, right + 1):
            # loop from the left side, different from my cpp vesion. 
            # In cpp version, it's start from right side.
            if arr[j] <= arr[left]:
                pos = pos + 1
                if j != pos:
                    arr[j], arr[pos] = arr[pos], arr[j]
        arr[pos], arr[left] = arr[left], arr[pos]
        return pos
    
    # recursive funciton,
    def _qsort(self, arr, left, right):
        if left >= right or left < 0:
            return
        middle_pos = self._partition(arr, left, right)
        self._qsort(arr, left, middle_pos - 1)
        self._qsort(arr, middle_pos + 1, right)
        return arr

    def _push_back_if_valid(self, range_stack, left, right):
        if left < right and left >= 0:
            print([left, right])
            range_stack.append([left, right])
    
    # non recursive function
    def _qsort_non_recursive(self, arr):
        range_stack = []
        self._push_back_if_valid(range_stack, 0, len(arr) - 1)
        while 0 != len(range_stack):
            popout_range = range_stack.pop()
            left = popout_range[0]
            right = popout_range[1]
            pivot = self._partition(arr, left, right)
            self._push_back_if_valid(range_stack, left, pivot - 1)
            self._push_back_if_valid(range_stack, pivot + 1, right)

# The following code need supported by pytest framework
def test_qsort():
    input1 = [5,2,3,1]
    output1 = [1,2,3,5]
    Solution().sortArray(input1)
    assert output1 == input1

    input2 = [5,1,1,2,0,0]
    output2 = [0,0,1,1,2,5]
    Solution().sortArray(input2)
    assert output2 == input2
