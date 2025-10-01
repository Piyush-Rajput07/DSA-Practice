class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        
        while(st < end) {
            if(!isalnum(s[st])) {
                st++;
                continue; //to check if next ch is alphanum or not
            }
            if(!isalnum(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};