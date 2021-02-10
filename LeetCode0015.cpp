#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		if (nums.size() < 3)
			return results;
		int left, right, sum3, target;
		std::sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] > 0)
				break;
			left = i + 1;
			right = nums.size() - 1;
			while (left < right)
			{
				if (left > i + 1 && nums[left] == nums[left - 1])
				{
					left++;
					continue;
				}
				if (right < nums.size() - 1 && nums[right] == nums[right + 1])
				{
					right--;
					continue;
				}
				sum3 = nums[i] + nums[left] + nums[right];
				if (sum3 == 0)
				{
					results.push_back({ nums[i], nums[left], nums[right] });
					left++;
					right--;
				}
				else if (sum3 > 0)
					right--;
				else
					left++;
			}
			
		}
		return results;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { -1,0,1,2,-1,-4 };
	auto result = solution.threeSum(nums);
	for (auto &vec : result)
	{
		for (auto &num : vec)
		{
			std::cout << num << ' ';
		}
		cout << endl;
	}
	return 0;
}