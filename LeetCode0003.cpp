#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//Definition for singly linked list
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
		if (s.length() == 0)
			return 0;
		int global_max_len = 1;
		int records[256];
		for (int i = 0; i < 256; i++)
			records[i] = -1;
		int left = -1, current_len;
		for (int i = 0; i < s.length(); i++)
		{
			if (records[s[i]] > left)
			{
				left = records[s[i]];
			}
			global_max_len = max(global_max_len, i - left);
			records[s[i]] = i;
		}
		return global_max_len;
	}
};

int main()
{
	Solution solution = Solution();
	string s = "pwwkew";
	auto results = solution.lengthOfLongestSubstring(s);
	std::cout << results << std::endl;
	return 0;
}