class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet; // We define an unordered set for storing the numbers so that we don't have to go back in the array to find the element for its duplicate, in order to make the solution optimal.

        int n = nums.size();
        for(int i = 0; i < n; i++) {  
            // We loop through each element of the array and check whether or not it is present in the unordered set. 
            // Simultaneously, we also store the value in the set if it is not found.
            if(numSet.find(nums[i]) != numSet.end()) {
                return true;  // Returns true when we find a duplicate of the element.
            }
            numSet.insert(nums[i]);
        }
        return false; // Returns false when we don't find any duplicates.
    }
};
