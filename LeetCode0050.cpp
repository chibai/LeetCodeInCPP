#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
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
private:
	
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (x == 1)
			return 1;
		vector<double> weights(32, -1);
		vector<bool> flags(32, false);
		int lastTrueIndex = 0;
		if (n != INT32_MIN)
		{
			int nn = n > 0 ? n : -n;
			int k = 1;
			for (int i = 0; i < 32; i++)
			{
				if ((k & nn) == k)
				{
					flags[i] = true;
					lastTrueIndex = i;
				}
				if (i != 31)
					k = k << 1;
			}
		}
		else
		{
			flags[31] = true;
			lastTrueIndex = 31;
		}
		double xx = n > 0 ? x : 1 / x;
		double result = 1;
		for (int i = 0; i <= lastTrueIndex; i++)
		{
			weights[i] = xx;
			if (flags[i])
				result *= weights[i];
			xx = xx * xx;
		}
		return result;
	}

	double quickMul(double x, long long N)
	{
		double xx = x;
		double result = 1;
		while (N != 0)
		{
			if (N % 2 == 1)
				result *= xx;
			xx *= xx;
			N = N / 2;
		}
		return result;
	}

	double myPowOfficial(double x, int n)
	{
		if (n == 0)
			return 1;
		if (x == 1)
			return 1;
		long long N = n;
		return n > 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
		
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.myPowOfficial(2, -2);
	std::cout << result << std::endl;
	return 0;
}