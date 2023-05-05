#include <iostream>

using namespace std;
const int n =15;
int count;
bool isSafe(int board[][n], int row, int col, int n) {
    for (int i = 0; i < row; i++) {  // Check if there is a queen in the same column
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {  // Check if there is a queen in the left diagonal
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {  // Check if there is a queen in the right diagonal
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(int board[][n], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void printTable(int board[][n], int n){

    count++;
}

void nQueen(int board[][n], int row, int n) {

    if (row == n) {  // Base case: All queens have been placed

        printTable(board, n);

        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {  // Check if it's safe to place a queen in this cell
            board[row][col] = 1;  // Place the queen in this cell
            nQueen(board, row + 1, n);  // Recur for the next row
            board[row][col] = 0;  // Backtrack: Remove the queen from this cell
        }
    }
}

int main() {
    count= 0;

  //  cout <<"Enter Number of Queen :";
 //   cin >> n;
    int board[n][n] = {0};
    cout <<"N       "<<"No. of solutions"<<endl;
    for(int i=1; i<=n;i++){
        count =0;
        nQueen(board, 0, i);
        cout <<i<<"       "<<count<<endl;
    }
    return 0;
}
