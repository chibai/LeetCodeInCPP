#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
    int myAtoi(string s) {
        int index = 0, result = 0;
        // read whitespaces
        while (true)
            if (s[index] == ' ')
                index++;
            else
                break;
        // read + and -
        bool positiveFlag = true;
        if (s[index] == '+')
            index++;
        else if (s[index] == '-')
        {
            positiveFlag = false;
            index++;
        }
        // read digits
        int current = 0;
        while (true)
        {
            if (s[index] <= '9' && s[index] >= '0')
                current = s[index] - '0';
            else
                break;
            if (positiveFlag)
            {
                if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && current > 7))
                    return INT32_MAX;
                result = 10 * result + current;
            }
            else // negative
            {
                if (result < INT32_MIN / 10 ||(result == INT32_MIN / 10 && current > 8))
                    return INT32_MIN;
                result = 10 * result - current;
            }
            index++;
        }
        return result;
        
    }
};

int main()
{
    Solution solution = Solution();
    auto result = solution.myAtoi("-91283472332");
    std::cout << result << std::endl;
    return 0;
}

