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
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		string current;
		DFS(0, 0, n, current, results);
		return results;
	}
	void DFS(int left, int right, int n, string& current, vector<string>& results)
	{
		if (left == n && right == n)
		{
			results.push_back(current);
		}
		else
		{
			if (left < n)
			{
				current.push_back('(');
				DFS(left + 1, right, n, current, results);
				current.pop_back();
			}
			if (right < left)
			{
				current.push_back(')');
				DFS(left, right + 1, n, current, results);
				current.pop_back();
			}

		}
	}
};

int main()
{
	Solution solution = Solution();
	auto results = solution.generateParenthesis(1);
	for (auto str:results)
	{
		for (auto ch:str)
		{
			std::cout << ch;
		}
		std::cout << endl;
	}
	return 0;
}