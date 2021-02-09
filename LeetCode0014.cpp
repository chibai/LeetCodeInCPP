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
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return strs[0];

		char ch;
		int minLen = 200;
		int i;
		for (i = 0; i < strs.size(); i++)
			minLen = min(minLen, int(strs[i].size()));
		for (i = 0; i < minLen; i++)
		{
			ch = strs[0][i];
			bool sameFlag = true;
			for (size_t j = 1; j < strs.size(); j++)
			{
				if (strs[j][i] != ch)
				{
					sameFlag = false;
					break;
				}
			}
			if (!sameFlag)
				return strs[0].substr(0, i);
		}
		return strs[0].substr(0, i);
	}
};

int main()
{
	Solution solution = Solution();
	vector<string> strs = { "flower","flow","flight" };
	auto result = solution.longestCommonPrefix(strs);
	for (auto &ch : result)
	{
		std::cout << ch;
	}
	return 0;
}