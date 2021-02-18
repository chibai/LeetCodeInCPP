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
private:
	vector<vector<int>> results;

public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n == 0 || k == 0)
			return results;
		vector<int> current;
		dfs( current, 0, 0, n, k);
		return results;
	}

	void dfs(vector<int> current, int sum, int index, int target, int k)
	{
		if (index >= k)
		{
			if (sum == target)
			{
				results.push_back(current);
			}
		}
		else
		{
			int startIndex = current.size() > 0 ? current[current.size() - 1] : 0;
			for (size_t i = startIndex + 1; i < 10; i++)
			{
				if (sum + i <= target)
				{
					sum += i;
					current.push_back(i);
					dfs(current, sum, index + 1, target, k);
					current.pop_back();
					sum -= i;
				}
			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> candidate{ 10,1,2,7,6,1,5 };
	auto results = solution.combinationSum3(9, 45);
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