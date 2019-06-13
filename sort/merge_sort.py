def merge( left_arr, right_arr):
    res = []
    while left_arr and right_arr:
        if left_arr[0] < right_arr[0]:
            res.append(left_arr.pop(0))
        else:
            res.append(right_arr.pop(0))
    # Add the remaining nums in left_arr or right_arr
    res = res + left_arr + right_arr
    return res
    
def merge_sort(nums):
    if len(nums) <= 1:
        return nums
    mid = len(nums) // 2
    left_nums = merge_sort(nums[:mid])
    right_nums = merge_sort(nums[mid:])
    return merge(left_nums, right_nums)

# The following code need pytest freamwork.
def test_merge_sort():
    input1 = [5,2,3,1]
    output1 = [1,2,3,5]
    assert output1 == merge_sort(input1)

    input2 = [5,1,1,2,0,0]
    output2 = [0,0,1,1,2,5]
    assert output2 == merge_sort(input2)
