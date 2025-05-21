class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq; // We define a map to find the frequency of values in the nums array.
        for(int i : nums){
            freq[i]++; // Loop through each element in the nums array and count its frequency.
        }

        vector<vector<int>> bucket(n + 1); // Define a vector of vectors to group elements by their frequency.
        for(auto high = freq.begin(); high != freq.end(); high++){
            bucket[high->second].push_back(high->first); // Push elements into their respective bucket based on frequency.
        }

        vector<int> topK; // Define a vector to store the top k frequent elements.
        for(int i = n; i > 0 && topK.size() < k; i--){ // Loop backward through the bucket to get most frequent elements first.
            for(int num : bucket[i]){
                topK.push_back(num); // Push elements into topK until we have k elements.
            }
        }

        return topK; // Return the top k frequent elements.
    }
};
