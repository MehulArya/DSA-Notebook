class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns
        
        for(int i = 0; i < n; i++) {
            int low = 0;
            int high = m - 1;

            // Skip this row if its largest element is smaller than target
            if(matrix[i][high] < target){
                continue;
            }

            // Binary search on the current row
            while(low <= high){
                int mid = (low + high) / 2;

                if(matrix[i][mid] == target){
                    return true;    // Target found
                }
                else if(matrix[i][mid] < target){
                    low = mid + 1;  // Search right half
                }
                else{
                    high = mid - 1; // Search left half
                }
            }
        }

        return false; // Target not found in any row
    }
};
