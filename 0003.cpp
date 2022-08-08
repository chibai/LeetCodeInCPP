#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

 //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> records = vector<int>(256);
        for (size_t i = 0; i < 256; i++)
            records[i] = -1;
        int maxLen = s.length() > 0 ? 1:0;
        int lastIndex = -1;
        for (size_t i = 0; i < s.length(); i++)
        {
            int index = int(s[i]);
            lastIndex = std::max(lastIndex, records[index]);
            maxLen = std::max(maxLen, int(i - lastIndex));
            records[index] = i;
        }
        return maxLen;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.lengthOfLongestSubstring("bbbbbbbbb");
    std::cout << results << std::endl;
    return 0;
}