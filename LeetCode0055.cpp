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
	bool canJump(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0)
			return false;
		else if (nLen == 1)
			return true;
		else if (nLen == 2)
			return nums[0] == 0 ? false : true;
		int maxIndex = 0;
		for (int i = 0; i < nLen && i <= maxIndex; i++)
			maxIndex = max(maxIndex, nums[i] + i);
		return maxIndex >= nLen - 1 ? true : false;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 3,2,1,0,4 };
	auto result = solution.canJump(nums);
	std::cout << result << std::endl;
	return 0;
}