class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        vector<char> str(n);

        for(int i=0; i<indices.size(); i++) {
            str[indices[i]] = s[i];
        }
        
        string ans = "";
        for(int i=0; i<s.length(); i++) {
            ans += str[i];
        }

        return ans;
    }
};