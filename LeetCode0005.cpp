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
	string longestPalindrome(string s) {
		if (s.length() < 2)
			return s;
		vector<vector<bool>> records(s.length() + 1);
		for (size_t i = 0; i < s.length() + 1; i++)
			records[i].resize(s.length() + 1, false);
		string longest_str = s.substr(0, 1);
		// for 1 character, must be Palindromic
		for (size_t i = 0; i < s.length(); i++)
			records[i][i] = true;
		// for 2 chracters. must be Palindromic
		for (size_t i = 0; i < s.length() - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				records[i][i + 1] = true;
				if (longest_str.length() < 2)
					longest_str = s.substr(i, 2);
			}
		}
		// for character numbers from 3 to s.length() characters
		for (size_t char_num = 3; char_num < s.length() + 1; char_num++)
		{
			for (size_t left = 0; left < s.length() + 1 - char_num; left++)
			{
				int right = left + char_num - 1;
				if (records[left + 1][right - 1] == true && s[left] == s[right])
				{
					records[left][right] = true;
					if (longest_str.length() < char_num)
						longest_str = s.substr(left, char_num);
				}
			}
		}
		return longest_str;

	}
};

int main()
{
	Solution solution = Solution();
	string s = "acbca";
	auto result = solution.longestPalindrome(s);
	for (auto &ch:result)
	{
		std::cout << ch;
	}
	return 0;
}