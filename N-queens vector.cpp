#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int diff = abs(queens[i] - col);
        if (diff == 0 || diff == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& queens, int row, vector<vector<int>>& solutions) {
    int n = queens.size();
    if (row == n) {
        solutions.push_back(queens);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, row + 1, solutions);
        }
    }
}

void printSolution(vector<vector<int>>& solutions) {
    cout << "There are " << solutions.size() << " solutions to the 4 Queens problem." << endl;
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ": \n" << endl;
        for (int j = 0; j < solutions[i].size(); ++j) {
            for (int k = 0; k < solutions[i].size(); ++k) {
                if (solutions[i][j] == k) {
                    cout << "1  ";
                } else {
                    cout << "0  ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main(){
    vector<vector<int>> solutions;
    vector<int> queens(4);
    solveNQueens(queens, 0, solutions);
    printSolution(solutions);
    return 0;

}
