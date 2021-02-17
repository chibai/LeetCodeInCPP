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
	int search(vector<int>& nums, int target) {
		int nLen = nums.size();
		if (nLen == 0)
			return -1;
		else if (nLen == 1)
			return nums[0] == target ? 0 : -1;
		// find pivot
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[left] <= nums[mid])
			{// left is sorted
				if (nums[left] <= target && target <= nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{// right is sorted
				if (nums[mid] <= target && target <= nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 1, 3 };
	auto result = solution.search(nums,3);
	std::cout << result;
	return 0;
}