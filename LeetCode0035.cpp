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
	int searchInsert(vector<int>& nums, int target) {
		int nLen = nums.size();
		if (nLen == 0)
			return 0;
		else if (nLen == 1)
			return target <= nums[0] ? 0 : 1;
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (l == r)
			{
				if (nums[mid] > target)
				{
					return mid;
				}
				else if (nums[mid] < target)
				{
					return  mid + 1;
				}
			}
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid;
			}
		}
		return 0;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 5,7,7,8,8,10 };
	auto result = solution.searchInsert(nums,6);
	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;
	return 0;
}