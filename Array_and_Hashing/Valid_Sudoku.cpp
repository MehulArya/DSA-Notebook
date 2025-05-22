class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ✅ Check each column for duplicates
        for (int i = 0; i < 9; i++) {
            unordered_set<char> check; // Set to store seen digits in the column
            for (int j = 0; j < 9; j++) {
                char num = board[j][i]; // Accessing element in column 'i' and row 'j'
                if (num != '.' && check.find(num) != check.end()) {
                    return false; // Duplicate found in column
                }
                check.insert(num);
            }
        }

        // ✅ Check each row for duplicates
        for (int i = 0; i < 9; i++) {
            unordered_set<char> check; // Set to store seen digits in the row
            for (int j = 0; j < 9; j++) {
                char num = board[i][j]; // Accessing element in row 'i' and column 'j'
                if (num != '.' && check.find(num) != check.end()) {
                    return false; // Duplicate found in row
                }
                check.insert(num);
            }
        }

        // ✅ Check each 3x3 subgrid for duplicates
        for (int rows = 0; rows < 9; rows += 3) {         // rows = 0, 3, 6 → starting point of each subgrid
            for (int col = 0; col < 9; col += 3) {        // col = 0, 3, 6 → starting point of each subgrid
                unordered_set<char> check;               // Set to store digits in the current subgrid
                for (int i = 0; i < 3; i++) {             // Traverse 3 rows inside the subgrid
                    for (int j = 0; j < 3; j++) {         // Traverse 3 columns inside the subgrid
                        char num = board[i + rows][j + col];
                        if (num != '.' && check.find(num) != check.end()) {
                            return false; // Duplicate found in subgrid
                        }
                        check.insert(num);
                    }
                }
            }
        }

        // If no duplicates found in any row, column, or subgrid, the board is valid
        return true;
    }
};
