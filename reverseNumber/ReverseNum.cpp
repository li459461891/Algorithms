#ifndef ReverseNum_h
#define ReverseNum_h
#include <cstdint>

class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;
        while (x!=0)
        {
            int remainder = x % 10;
            x = x / 10;
            if ((reverseNum > (INT_MAX / 10)) || ((reverseNum == (INT_MAX / 10)) && (remainder > INT_MAX % 10))){return 0;}
            if ((reverseNum < (INT_MIN / 10)) || ((reverseNum == (INT_MIN / 10)) && (remainder < INT_MIN % 10))){return 0;}
            reverseNum = reverseNum*10 + remainder;
        }
        return reverseNum;
    }
};

int main(int argc, const char * argv[])
{
    int num = 1234567;
    int negativeNum = -1234567;
    Solution solution;
    num = solution.reverse(num);
    negativeNum = solution.reverse(negativeNum);
    std::cout << "After reverse, num=" << num << ", negativeNum=" << negativeNum << std::endl;
    return 0;
}
#endif /* ReverseNum_h */
