class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupAnagram; // We define a map with a string and a vector of strings, holding one string and its anagrams
        
        for (string s : strs) { // We then traverse through the strs to check every string
            string sortedStr = s; // Each string is equated with the string sortedStr
            sort(sortedStr.begin(), sortedStr.end()); // The sortedStr is then sorted and is used as the first part of the map
            groupAnagram[sortedStr].push_back(s); // Now all the s's are pushed back to the map with the same characters
        }

        vector<vector<string>> result; // Now to provide the result, we create a vector of vector of strings
        for (auto enter : groupAnagram) { // Traversing through the hash map 
            result.push_back(enter.second); // We then push the vector of strings to the result
        }   
        return result; // Return the vector of strings 
    }
};
