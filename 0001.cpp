#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> records = std::map<int, int>();
        vector<int> results;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (records.find(target - nums[i]) == records.end()) // no find
            {
                records[nums[i]] = i;
            }
            else
            {
                results.push_back(records[target - nums[i]]);
                results.push_back(i);
                break;
            }
        }
        return results;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = {2, 7, 11, 15};
    auto results = solution.twoSum(nums, 22);
    for (auto &v:results)
    {
        std::cout << v << std::endl;
    }
    return 0;
}