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
    string longestPalindrome(string s)
    {
        if (s.length() < 2 || (s.length() == 2 && s[0] == s[1]))
        {
            return s;
        }
        std::string result;
        result.push_back(s[0]);
        std::vector<bool> odd_records;
        std::vector<bool> even_records;
        for (size_t i = 0; i < s.length(); i++)
        {
            odd_records.push_back(true);
            even_records.push_back(true);
        }
        //
        std::vector<bool> records;
        for (size_t subStrLen = 2; subStrLen <= s.length(); subStrLen++)
        {
            records = (subStrLen % 2 == 0) ? even_records : odd_records;
            for (size_t i = 0; i <= s.length() - subStrLen; i++)
            {
                if (records[i+1] && s[i] == s[i + subStrLen - 1])
                {
                    result = s.substr(i, subStrLen);
                    records[i] = true;
                }
                else
                {
                    records[i] = false;
                }
            }
            if (subStrLen % 2 == 0)
            {
                even_records = records;
            }
            else
            {
                odd_records = records;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.longestPalindrome("aacabdkacaa");
    std::cout << results << std::endl;
    return 0;
}