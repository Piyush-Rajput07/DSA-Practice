class Solution {
public:
    bool allZeroes(vector<int> &counter) {
        for(int &i : counter) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> counter(26, 0);

        if(n != m) {
            return false;
        }

        for(int i=0; i<m; i++) {
            counter[s[i]-'a']++;
        }

        int i = 0, j = 0;
        while(j < n) {
            counter[t[j]-'a']--;

            if(j - i + 1 == m) {
                if(allZeroes(counter)) {
                    return true;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};