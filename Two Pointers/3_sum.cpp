class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Array of pairs
        map<int, int> mpp; // map for storing the values and index
        sort(nums.begin(), nums.end()); // Sorting the values in order
        int n = nums.size(); // size of Array
        for(int i = 0; i < n; i++){ // looping through the vector nums
            mpp.clear(); // We clear the map after every time using it removing the old values
            if(i > 0 && nums[i] == nums[i - 1]) continue; // We do it remove redundnacy of ith value
            int x = nums[i]; // Storing the value of ith index
            int target = 0 - x;  // Finding the target to be achieved 
            for(int j = i + 1; j < n; j++){ // Looping through the remaining vector
                int num = nums[j]; // Performing Two Sum 
                int more = target - num;
                if(mpp.find(more) != mpp.end()){
                    ans.push_back({nums[i], nums[j], nums[mpp[more]]}); // pushing the index in ans vector
                    while(j + 1 < n && nums[j] == nums[j + 1]) j++; // removing redundancy for same element
                }
                mpp[num] = j; 
            }
        }
        return ans; // vector of answer in returned
    }
};