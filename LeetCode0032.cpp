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
	int longestValidParenthesesDP(string s) {
		int sLen = s.length();
		if (sLen < 2)
			return 0;
		int maxResult = 0;
		vector<int> dp(sLen, 0);
		dp[0] = 0;
		for (int i = 1; i < sLen; i++)
		{
			if (s[i] == ')')
			{
				if (dp[i - 1] == 0)
				{
					if (s[i - 1] == '(')
					{
						dp[i] = i > 1 ? 2 + dp[i - 2] : 2;
					}
				}
				else
				{
					if (i - dp[i - 1] - 1 >= 0)
					{
						if (s[i - dp[i - 1] - 1] == '(')
						{
							dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
						}
					}
				}
			}
			maxResult = max(dp[i], maxResult);
		}
		return maxResult;
	}
	
	int longestValidParenthesesStack(string s) {
		int sLen = s.length();
		if (sLen < 2)
			return 0;
		stack<int> sStack;
		sStack.push(-1);
		int currentLen = 0;
		int maxLen = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				sStack.push(i);
			}
			else if (s[i] == ')')
			{
				sStack.pop();
				if (sStack.empty())
				{
					sStack.push(i);
				}
				else
				{
					maxLen = max(maxLen, i - sStack.top());
				}
			}
		}
		return maxLen;
	}

	int longestValidParentheses(string s) {
		int sLen = s.length();
		if (sLen < 2)
			return 0;
		int maxLen_left2right = 0, maxLen_right2left = 0;
		//scan left 2 right
		int leftParentheses = 0, rightParentheses = 0;
		for (int i = 0; i < sLen; i++)
		{
			if (s[i] == '(')
				leftParentheses++;
			else
				rightParentheses++;
			if (leftParentheses == rightParentheses)
			{
				maxLen_left2right = max(maxLen_left2right, 2 * rightParentheses);
			}
			else if (leftParentheses < rightParentheses)
			{
				leftParentheses = 0;
				rightParentheses = 0;
			}
		}
		// scan right 2 left
		leftParentheses = 0;
		rightParentheses = 0;
		for (int i = sLen - 1; i >= 0; i--)
		{
			if (s[i] == '(')
				leftParentheses++;
			else
				rightParentheses++;
			if (leftParentheses == rightParentheses)
			{
				maxLen_right2left = max(maxLen_right2left, 2 * leftParentheses);
			}
			else if (leftParentheses > rightParentheses)
			{
				leftParentheses = 0;
				rightParentheses = 0;
			}
		}
		return max(maxLen_left2right, maxLen_right2left);
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.longestValidParentheses("()");
	std::cout << result;
	return 0;
}