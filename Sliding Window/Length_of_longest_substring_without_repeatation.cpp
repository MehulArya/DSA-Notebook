class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();                  // Length of the input string
        int left = 0;                      // Left pointer of the sliding window
        unordered_set<char> mpp;           // Set to store unique characters in the current window
        int maxlen = 0;                    // Variable to store the maximum length found so far

        for (int right = 0; right < n; right++) {
            // If the character at 'right' is already in the set, remove characters from the left
            while (mpp.find(s[right]) != mpp.end()) {
                mpp.erase(s[left]);        // Remove the character at 'left' from the set
                left++;                    // Move the left pointer forward to shrink the window
            }

            mpp.insert(s[right]);          // Insert the current character into the set

            // Update maxlen if the current window is larger than previous ones
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;                     // Return the length of the longest unique substring
    }
};
