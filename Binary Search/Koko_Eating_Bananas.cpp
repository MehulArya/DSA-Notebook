class Solution {
public:
    // Helper function to check if Koko can eat all bananas at speed 'k' within 'h' hours
    bool canEatAll(vector<int>& piles, int h, int k){
        long long totalHours = 0;
        for(int pile : piles){
            // Each pile takes ceil(pile / k) hours to eat
            totalHours += (long long)(pile + k - 1) / k;
        }
        // Return true if total hours is within the allowed time
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; // Minimum possible eating speed
        int high = *max_element(piles.begin(), piles.end()); // Maximum pile size = max speed needed
        int answer = high;

        // Binary search to find the minimum valid speed
        while(low <= high){
            int mid = (low + high) / 2;
            if(canEatAll(piles, h, mid)){
                answer = mid;      // Try to find a smaller valid speed
                high = mid - 1;
            }
            else{
                low = mid + 1;     // Increase speed to eat faster
            }
        }
        return answer; // Minimum speed to finish in h hours
    }
};
