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
	bool valid = false;
	bool rowFlags[9][9];
	bool colFlags[9][9];
	bool boxFlags[3][3][9];

public:
	void solveSudoku(vector<vector<char>>& board) {
		memset(rowFlags, false, sizeof(rowFlags));
		memset(colFlags, false, sizeof(colFlags));
		memset(boxFlags, false, sizeof(boxFlags));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.')
				{
					rowFlags[i][board[i][j] - '1'] = true;
					colFlags[j][board[i][j] - '1'] = true;
					boxFlags[i / 3][j / 3][board[i][j] - '1'] = true;
				}
		solver(board, 0);
	}
	void solver(vector<vector<char>>& board, int index)
	{
		if (index == 81)
		{
			valid = true;
			return;
		}
		else
		{
			int rowIndex = index / 9;
			int colIndex = index % 9;
			int boxRowIndex = rowIndex / 3;
			int boxColIndex = colIndex / 3;
			if (board[rowIndex][colIndex] != '.')
			{
				solver(board, index + 1);
				return;
			}
			for (size_t i = 0; i < 9; i++)
			{
				if (!rowFlags[rowIndex][i] && !colFlags[colIndex][i] && !boxFlags[boxRowIndex][boxColIndex][i])
				{
					rowFlags[rowIndex][i] = colFlags[colIndex][i] = boxFlags[boxRowIndex][boxColIndex][i] = true;
					if (!valid)
					{
						board[rowIndex][colIndex] = '1' + i;
					}
					solver(board, index + 1);
					if (!valid)
					{
						board[rowIndex][colIndex] = '.';
					}
					rowFlags[rowIndex][i] = colFlags[colIndex][i] = boxFlags[boxRowIndex][boxColIndex][i] = false;
				}
			}
			return;
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<char> row1{ '5','3','.','.','7','.','.','.','.' };
	vector<char> row2{ '6','.','.','1','9','5','.','.','.' };
	vector<char> row3{ '.','9','8','.','.','.','.','6','.' };
	vector<char> row4{ '8','.','.','.','6','.','.','.','3' };
	vector<char> row5{ '4','.','.','8','.','3','.','.','1' };
	vector<char> row6{ '7','.','.','.','2','.','.','.','6' };
	vector<char> row7{ '.','6','.','.','.','.','2','8','.' };
	vector<char> row8{ '.','.','.','4','1','9','.','.','5' };
	vector<char> row9{ '.','.','.','.','8','.','.','7','9' };
	vector<vector<char>> nums{ row1, row2, row3, row4, row5, row6, row7, row8, row9 };
	solution.solveSudoku(nums);
	for (auto vec: nums)
	{
		for (auto ch:vec)
		{
			std::cout << ch;
		}
		std::cout <<  std::endl;
	}
	return 0;
}