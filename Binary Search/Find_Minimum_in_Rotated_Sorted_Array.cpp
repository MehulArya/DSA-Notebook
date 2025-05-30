class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX; // Store the minimum element found

        // Binary search in the rotated sorted array
        while(low <= high){
            int mid = (low + high) / 2;

            // If left half is sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]); // The leftmost value could be the minimum
                low = mid + 1;             // Discard the sorted left part
            }
            else{
                ans = min(ans, nums[mid]); // The mid value could be the minimum
                high = mid - 1;            // Discard the right half
            }
        }
        return ans; // Return the minimum value found
    }
};
