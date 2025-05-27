class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); // Determining the size of the array height
        int i = 0;     // defining the pointer location for i and j
        int j = n - 1; // to implement two pointer
        int maxWater = INT_MIN; // lets say maxWater stored in the vessel can be INT_MIN
        while(i < j){
            int mini = min(height[i], height[j]); // we find the minimum height between two indexes
            int distance = j - i; // identify the distance between two indexes
            int water = distance * mini; // for calculating the water stored in this vessel
            maxWater = max(water, maxWater); // We assign the maximum water stored in one of the vessel
            if(height[i] < height[j]){ // if the j's height is more than we move i++ to ensure more water is stored
                i++;
            }
            else{ // if i's height is more than we move j-- to ensure more water is stored
                j--;
            }
        }
        return maxWater; // We return the maxWater that can be stored in one of the vessels in the array height
    }
};