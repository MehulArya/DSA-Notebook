class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // This set stores unique identifiers for each number's position in rows, columns, and boxes
        unordered_set<string> seen;

        // Traverse each cell of the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];

                // Skip empty cells (represented by '.')
                if (num != '.') {

                    // Create a unique key for the number in its row
                    string rowkey = string(1, num) + "in row" + to_string(i);

                    // Create a unique key for the number in its column
                    string colkey = string(1, num) + "in col" + to_string(j);

                    // Create a unique key for the number in its 3x3 sub-box
                    // Each 3x3 box is identified by its top-left corner index (i/3, j/3)
                    string boxkey = string(1, num) + "in box" + to_string(i / 3) + "-" + to_string(j / 3);

                    // If any of these keys already exist in the set, the Sudoku is invalid
                    if (seen.count(rowkey) || seen.count(colkey) || seen.count(boxkey)) {
                        return false; // Duplicate found
                    }

                    // Insert the keys into the set to mark the number's presence
                    seen.insert(rowkey);
                    seen.insert(colkey);
                    seen.insert(boxkey);
                }
            }
        }

        // If no duplicates were found, the Sudoku board is valid
        return true;
    }
};
