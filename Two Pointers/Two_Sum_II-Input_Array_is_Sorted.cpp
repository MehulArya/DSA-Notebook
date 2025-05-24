class Solution { // Sames as Two Sum
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mpp;
        int n = numbers.size();
        for(int i = 1; i <= n; i++){
            int num = numbers[i - 1];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {};
    }
};