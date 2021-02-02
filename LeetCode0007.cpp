#include <iostream>
#include <vector>
#include <string>


class Solution{
    public:
    int reverse(int x) {
        // 2^31 - 1 = 2147483647
        // -2^31 = -2147483647
        if (x > -10 && x < 10)
            return x;
        bool positiveFlag = x > 0 ? true:false;
        int result = 0, quotient, remainder;
        while(x != 0)
        {
            remainder = x % 10;
            x = x / 10;
            if (result > INT32_MAX / 10 || (result == INT32_MAX && remainder > 7))
                return 0;
            if (result < INT32_MIN / 10 || (result == INT32_MIN && remainder < -8))
                return 0;
            result = 10 * result + remainder;
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    auto result = solution.reverse(120);
    std::cout << result << std::endl;
    return 0;
}

