class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();  // Get the number of elements in the array
        if(n == 0) return 0;  // If array is empty, return 0

        sort(nums.begin(), nums.end());  // Sort the array

        int lastSmaller = INT_MIN;  // To store the last distinct number seen
        int count = 0;              // Current length of consecutive sequence
        int longest = 1;            // Maximum length found

        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 == lastSmaller) {
                // Current number continues the consecutive sequence
                count++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                // Start a new sequence if it's not a duplicate
                count = 1;
                lastSmaller = nums[i];
            }
            // Update the longest sequence length
            longest = max(count, longest);
        }

        return longest;  // Return the maximum consecutive sequence length
    }
};
