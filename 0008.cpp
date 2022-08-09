#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int myAtoi(string s) {
        int index = 0, result = 0;
        // read whitespaces
        while (s[index] == ' ')
        {
            index++;
        }
        // read + and -
        bool positiveFlag = true;
        if (s[index] == '+')
        {
            index++;
        }
        else if (s[index] == '-')
        {
            index++;
            positiveFlag = false;
        }
        // read digits
        int current = 0;
        while (s[index] <= '9' && s[index] >= '0')
        {
            current = s[index] - '0';
            index++;
            if (positiveFlag)
            {
                if (result > (INT32_MAX - current) / 10)
                {
                    return INT32_MAX;
                }
                result = 10 * result + current;
                
            }
            else //negative
            {
                if (result < (INT32_MIN + current) / 10)
                {
                    return INT32_MIN;
                }
                result = 10 * result - current;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.myAtoi("1.1248");
    std::cout << results << std::endl;
    return 0;
}