class Solution {
public:
    bool isPalindrome(string s) {
        string news = ""; // We Create two new empty string for checking the palindrome
        string revs = "";
        for(int i = 0; i < s.size(); i++){ // Loop through the original string
            if(isalnum(s[i])){  // and push back the values in new string if the element is alpha numeric value
                news.push_back(tolower(s[i])); // also convert the value in lower case
            }
        }

        for(int i = news.size() - 1; i>=0; i--){ // now loop in reverse for the new string fromed
            revs.push_back(news[i]); // and push back the values in reverse
        }
        return news == revs; // if the values are equal then return true otherwise false
    }
};