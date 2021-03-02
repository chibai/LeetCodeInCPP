#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace std;

//Definition for singly linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class NumMatrix {
private:
	vector<vector<int>> originalMatrix;
	vector<vector<int>> accumulateMatrix;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		originalMatrix = matrix;
		if (originalMatrix.size() == 0 || originalMatrix[0].size() == 0)
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int rowIndex = 0; rowIndex < matrix.size(); rowIndex++)
		{
			vector<int> vec;
			vec.push_back(matrix[rowIndex][0]);
			for (int colIndex = 1; colIndex < matrix[0].size(); colIndex++)
				vec.push_back(vec[colIndex - 1] + matrix[rowIndex][colIndex]);
			accumulateMatrix.push_back(vec);
		}
		for (int colIndex = 0; colIndex < matrix[0].size(); colIndex++)
			for (int rowIndex = 1; rowIndex < matrix.size(); rowIndex++)
				accumulateMatrix[rowIndex][colIndex] += accumulateMatrix[rowIndex - 1][colIndex];
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (originalMatrix.size() == 0 || originalMatrix[0].size() == 0)
			return 0;
		int rightTop = row1 > 0? accumulateMatrix[row1 - 1][col2] : 0;
		int leftBottom = col1 > 0 ? accumulateMatrix[row2][col1 - 1] : 0;
		int leftTop = row1 > 0 && col1 > 0 ? accumulateMatrix[row1 - 1][col1 - 1] : 0;
		return accumulateMatrix[row2][col2] - rightTop - leftBottom + leftTop;
	}
};

int main()
{
	vector<vector<int>> matrix{ {} };
	NumMatrix* obj = new NumMatrix(matrix);
	std::cout << obj->sumRegion(2, 1, 4, 3) << std::endl;
	std::cout << obj->sumRegion(1, 1, 2, 2) << std::endl;
	std::cout << obj->sumRegion(1, 2, 2, 4) << std::endl;
	return 0;
}