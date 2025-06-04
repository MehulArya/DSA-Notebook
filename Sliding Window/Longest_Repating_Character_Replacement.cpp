class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); // Get the length of the string
        int maxlen = 0; // Variable to store the maximum length of valid substring

        // Try replacing each character from 'A' to 'Z'
        for(char ch = 'A'; ch <= 'Z'; ch++){
            int left = 0, right = 0, count = 0; // Initialize sliding window and count of replacements

            // Expand the window using the right pointer
            while(right < n){
                if(s[right] != ch){
                    count++; // Increment count if current char is not the target char
                }

                // Shrink the window from the left if replacements exceed k
                while(count > k){
                    if(s[left] != ch){
                        count--; // Decrease count when removing a non-target char
                    }
                    left++; // Move left pointer to maintain valid window
                }

                // Update the maximum length of valid window
                maxlen = max(maxlen, right - left + 1);
                right++; // Move right pointer to expand the window
            }
        }

        return maxlen; // Return the maximum length found
    }
};
