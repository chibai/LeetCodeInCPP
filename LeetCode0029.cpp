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
	int myDivide(int dividend, int divisor) {
		if (dividend == 0)
			return 0;
		else if (divisor == 1)
			return dividend;
		else if (divisor == -1)
			return dividend == INT32_MIN ? INT32_MAX : -dividend;
		else if (divisor == INT32_MIN)
			return dividend == divisor ? 1 : 0;
		////////////////////
		bool isDividendPositive = dividend > 0;
		bool isDivisorPositive = divisor > 0;
		int extraOne = 0;
		if (!isDividendPositive)
		{
			if (dividend == INT32_MIN)
			{
				dividend = INT32_MAX;
				extraOne = 1;
			}
			else
			{
				dividend = -dividend;
			}
		}
			divisor = isDivisorPositive ? divisor : -divisor;
		int result = 0;
		while (dividend >= divisor - extraOne)
		{
			int tmp_divisor = divisor;
			int tmp_result = 1;
			while (tmp_divisor < (INT32_MAX>>2) && dividend >= ((tmp_divisor<<2) - extraOne))
			{
				tmp_result = tmp_result << 2;
				tmp_divisor = tmp_divisor << 2;
			}
			if (extraOne == 1)
			{
				dividend = dividend - tmp_divisor + extraOne;
				extraOne = 0;
			}
			else
				dividend -= tmp_divisor;
			result += tmp_result;
		}
		return isDividendPositive ^ isDivisorPositive?-result : result;
	}
	int divide(int dividend, int divisor)
	{

	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.divide(INT32_MIN, 2);
	std::cout << result;
	return 0;
}