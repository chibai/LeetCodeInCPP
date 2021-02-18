#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
	string countAndSay(int n) {
		if (1 == n)
			return "1";
		if (2 == n)
			return "11";
		string str = "11";
		for (size_t i = 2; i < n; i++)
		{
			string nextStr = "";
			int count = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				if (i == 0 || str[i] == str[i-1])
				{
					count++;
				}
				else
				{
					nextStr.push_back(count + '0');
					nextStr.push_back(str[i - 1]);
					count = 1;
				}
			}
			if (count > 0)
				nextStr.push_back(count + '0');
			else
				nextStr.push_back('1');
			nextStr.push_back(str[str.size() - 1]);
			str = nextStr;
		}
		return str;
	}
};

int main()
{
	Solution solution = Solution();
	auto results = solution.countAndSay(8);
	for (auto ch: results)
	{
		std::cout << ch;
	}
	return 0;
}