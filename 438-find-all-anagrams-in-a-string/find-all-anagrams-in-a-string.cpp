class Solution {
public:
    bool allZero(vector<int>& freq) {
        for(int i=0; i<freq.size(); i++) {
            if(freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> freq(26, 0);

        for(int i=0; i<m; i++) {
            freq[p[i]-'a']++;
        }

        int i = 0, j = 0;
        vector<int> res;

        while(j < n) {
            freq[s[j]-'a']--;

            if((j - i + 1) == m) {
                if(allZero(freq)) {
                    res.push_back(i);
                }

                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};