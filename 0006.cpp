#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> rows(numRows);
        // top bottom flag
        int flag = 1;
        int idxRows = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            rows[idxRows].push_back(s[i]);
            idxRows += flag;
            if (idxRows == numRows - 1 || idxRows == 0)
            {//for most bottom case and most top case
                flag = -flag;
            }
        }
        string res;
        for (auto row:rows)
        {
            res += row;
        }
        return res;
    }
};

int main()
{
    Solution solution = Solution();
    auto results = solution.convert("PAYPALISHIRING", 3);
    std::cout << results << std::endl;
    return 0;
}