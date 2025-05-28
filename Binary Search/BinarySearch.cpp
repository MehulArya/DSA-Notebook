class Solution {
public:
    // Binary search function to find the target in the sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // Loop until search space is valid
        while(low <= high){
            int mid = (low + high) / 2;

            // If target found, return its index
            if(target == nums[mid]){
                return mid;
            }
            // If target is smaller, search in the left half
            else if(target < nums[mid]){
                high = mid - 1;
            }
            // If target is greater, search in the right half
            else{
                low = mid + 1;
            }
        }

        // Target not found
        return -1;
    }
};
