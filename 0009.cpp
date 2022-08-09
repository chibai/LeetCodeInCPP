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
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10) return true;
        if (x % 10 == 0)    return false;
        int rest = 0;
        while (x > rest)
        {
            rest = 10 * rest + x % 10;
            x = x / 10;
        }
        return (x == rest) || (x == rest / 10);
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.isPalindrome(10);
    std::cout << results << std::endl;
    return 0;
}