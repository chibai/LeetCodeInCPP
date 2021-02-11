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
	bool isValid(string s) {
		stack<char> stackRecord;
		for (auto &ch : s)
		{
			if (ch == '(' || ch == '{' || ch == '[')
			{
				stackRecord.push(ch);
			}
			else if (ch == ')')
			{
				if (!stackRecord.empty() && stackRecord.top() == '(')
					stackRecord.pop();
				else
					return false;
			}
			else if (ch == ']')
			{
				if (!stackRecord.empty() && stackRecord.top() == '[')
					stackRecord.pop();
				else
					return false;
			}
			else if (ch == '}')
			{
				if (!stackRecord.empty() && stackRecord.top() == '{')
					stackRecord.pop();
				else
					return false;
			}
		}
		return stackRecord.empty();
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.isValid("()[]{}");
	std::cout << result << std::endl;
	return 0;
}