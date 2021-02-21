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
public:
	int jump(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen < 2)
			return 0;
		else if (nLen == 2)
			return 1;

		vector<int> dp(nLen, nLen);
		dp[0] = 0;
		for (int i = 0; i < nLen; i++)
		{
			int startJ;
			if (i == 0)
				startJ = i + 1;
			else
				startJ = nums[i - 1] + i;
			for (int j = startJ; j <= min(i + nums[i], nLen - 1); j++)
			{
				dp[j] = min(dp[i] + 1, dp[j]);
				
			}
		}
		return dp[nLen - 1];
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 2,3,1,1,4 };
	auto result = solution.jump(nums);
	std::cout << result << std::endl;
	return 0;
}