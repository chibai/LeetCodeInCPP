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
        int rest = 0;
        int current = 0;
        while (x > rest)
        {
            current = x % 10;
            x = x / 10;
            if (rest == x)
                return true;
            rest = 10 * rest + current;
            if (rest == x)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.isPalindrome(1221);
    std::cout << results << std::endl;
    return 0;
}