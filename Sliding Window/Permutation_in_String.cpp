class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        // If s1 is longer than s2, s1 can't be a permutation of any substring of s2
        if(n1 > n2) return false;

        unordered_map<char, int> freq1, freq2;

        // Count character frequencies of s1
        for(char c : s1){
            freq1[c]++;
        }

        // Build initial window of size n1 in s2
        for(int i = 0; i < n1; i++){
            freq2[s2[i]]++;
        }

        // Check if first window matches the frequency of s1
        if(freq1 == freq2) return true;

        // Slide the window one character at a time
        for(int i = n1; i < n2; i++){
            // Add the new character to the window
            freq2[s2[i]]++;

            // Remove the character that is no longer in the window
            freq2[s2[i - n1]]--;

            // If the count becomes zero, erase it from the map to keep map sizes equal
            if(freq2[s2[i - n1]] == 0){
                freq2.erase(s2[i - n1]);
            }

            // Check if current window matches the frequency of s1
            if(freq1 == freq2) return true;
        }

        // No matching permutation found in any window
        return false;
    }
};
