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
	int strStr(string haystack, string needle) {
		if (haystack.size() == 0 && needle.size() == 0)
			return 0;
		if (haystack.size() < needle.size())
			return -1;
		for (size_t i = 0; i < haystack.size() - needle.size() + 1; i++)
		{
			int j;
			for (j = 0; j < needle.size(); j++)
			{
				if (needle[j] != haystack[i + j])
				{
					break;
				}
			}
			if (j == needle.size())
				return i;
		}
		return -1;
	}
	int KMP(string haystack, string needle)
	{
		if (needle.size() == 0)
			return 0;
		if (haystack.size() < needle.size())
			return -1;
		//create FSM
		vector<vector<int>> FSM;
		for (size_t i = 0; i < needle.length(); i++)
		{
			vector<int> tmp = vector<int>(256, 0);
			FSM.push_back(tmp);
		}
		FSM[0][needle[0]] = 1;
		int X = 0;
		for (size_t i = 1; i < needle.length(); i++)
		{
			for (size_t c = 0; c < 256; c++)
				FSM[i][c] = FSM[X][c];

			FSM[i][needle[i]] = i + 1;
			X = FSM[X][needle[i]];
		}
		// search
		int j = 0;
		for (size_t i = 0; i < haystack.size(); i++)
		{
			j = FSM[j][haystack[i]];
			if (j == needle.size())
				return i - needle.size() + 1;
		}
		return -1;
	}
	
};

int main()
{
	Solution solution = Solution();
	auto result = solution.KMP("mississippi", "issip");
	std::cout << result;
	return 0;
}