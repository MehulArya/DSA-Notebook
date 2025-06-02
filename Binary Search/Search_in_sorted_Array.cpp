class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;  // Find the middle index

            if(nums[mid] == target) return mid;  // Target found

            // Left half is sorted
            if(nums[low] <= nums[mid]){
                // Target lies within the sorted left half
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else{
                // Target lies within the sorted right half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;  // Target not found
    }
};
