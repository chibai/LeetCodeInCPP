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
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int i = nums.size() - 1;
		while (i > 0 && nums[i] <= nums[i - 1])
		{
			i--;
		}
		i--;
		if (i >= 0)
		{
			int j = nums.size() - 1;
			while (j > 0 && nums[j] <= nums[i])
			{
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + 1 + i, nums.end());
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 5,1, 1 };
	solution.nextPermutation(nums);
	for (auto num: nums)
	{
		std::cout << num << std::endl;
	}
	return 0;
}