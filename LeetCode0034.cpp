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
	int bs_left(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (l == r)
			{
				if (nums[l] == target)
					return mid;
				else
					return -1;
			}
			if (nums[mid] >= target)
			{
				r = mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
		}
		return -1;
	}
	int bs_right(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (l + r + 1) / 2;
			if (l == r)
			{
				if (nums[l] == target)
					return mid;
				else
					return -1;
			}
			if (nums[mid] <= target)
			{
				l = mid;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
		}
		return -1;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return vector<int>{-1, -1};
		}
		return vector<int>{bs_left(nums, target), bs_right(nums, target)};
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 5,7,7,8,8,10 };
	auto result = solution.searchRange(nums,6);
	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;
	return 0;
}