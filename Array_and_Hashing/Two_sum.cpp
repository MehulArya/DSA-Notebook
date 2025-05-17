class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp; // A map is defined for the numerical value in int and its index in int
        for (int i = 0; i < nums.size(); i++) { // We traverse through the array fixing a number and checking if we had some value in the map that makes up the target
            int more = target - nums[i]; // The required value to add up to the target
            if (mpp.find(more) != mpp.end()) { // Searching for the element
                return {mpp[more], i}; // Return the index of the elements
            }
            mpp[nums[i]] = i; // Adding the element if the 'more' value is not found
        }
        return {}; // If there are no pairs adding up to the target we return the empty element
    }
};