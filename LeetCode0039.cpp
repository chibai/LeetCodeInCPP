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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		if (candidates.size() == 0)
			return results;
		vector<int> current;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, results, current, 0, 0, target);
		return results;
	}

	void dfs(vector<int>& candidates, vector<vector<int>> & results, vector<int> current, int sum, int index, int target)
	{
		if (sum == target)
		{
			results.push_back(current);
		}
		else
		{
			for (size_t i = index; i < candidates.size(); i++)
			{
				if (candidates[i] + sum > target)
				{
					break;
				}
				else
				{
					sum += candidates[i];
					current.push_back(candidates[i]);
					dfs(candidates, results, current, sum, i, target);
					sum -= candidates[i];
					current.pop_back();
				}
			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> candidate{ 1};
	auto results = solution.combinationSum(candidate, 2);
	for (auto vec: results)
	{
		for (auto num: vec)
		{
			std::cout << num;
		}
		std::cout << std::endl;
	}
	return 0;
}