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
    int reverse(int x) {
        if (x == INT32_MIN || x == 0)
            return 0;
        int flag = x < 0 ? -1:1;
        x = abs(x);
        int result = 0;
        int tmp;
        while (x != 0)
        {
            tmp = x % 10;
            x = x / 10;
            if (flag > 0)
            {
                if (result > (INT32_MAX - tmp) / 10)  
                    return 0;
                else
                    result = 10 * result + tmp;
            }
            else // flag < 0
            {
                if (result < (INT32_MIN + tmp) / 10)
                    return 0;
                else
                    result = 10 * result - tmp;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.reverse(-120);
    std::cout << results << std::endl;
    return 0;
}