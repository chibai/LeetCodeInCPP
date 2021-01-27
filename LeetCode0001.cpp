#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> records = map<int, int>();
		vector<int> results;
		for (int i = 0; i < nums.size(); i++)
		{
			if (records.find(target - nums[i]) != records.end())
			{
				results.push_back(records[target - nums[i]]);
				results.push_back(i);
			}
			else
			{
				records[nums[i]] = i;
			}
		}
		return results;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 2,7,11,15};
	int target = 9;
	auto results = solution.twoSum(nums, target);
	for (auto &v:results)
	{
		std::cout << v << std::endl;
	}
	return 0;
}