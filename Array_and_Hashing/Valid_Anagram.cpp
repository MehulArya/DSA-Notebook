class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; // Edge case: Cause if the strings are anagrams they must be of same length
        unordered_map<char,int> mpp; // Map defined for char and int pair, char showing the character of string and int the count of those characters
        for(char c : s){  // Traversing through string and putting all the characters in the map.
            mpp[c]++;
        }

        for(char c : t){ // Traversing through the t string
            if(mpp.find(c) == mpp.end() || mpp[c] == 0){ // Checking if the characters are in the map or not; if not, then false is returned. If an element occurs more times than in the map then also we return false.
                return false;
            }
            mpp[c]--; // We keep on decreasing the elements in order to not count the elements we have taken into account.
        }
        return true;
    }
};