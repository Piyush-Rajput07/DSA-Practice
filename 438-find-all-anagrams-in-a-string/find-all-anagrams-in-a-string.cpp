class Solution {
public:
    bool allZeroes(vector<int> counter) {
        for(int &i : counter) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> counter(26, 0);

        //store the freq of each character
        for(int i=0; i<p.length(); i++) {
            counter[p[i]-'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;

        while(j < n) {
            counter[s[j]-'a']--;

            if(j - i + 1 == p.length()) {
                if(allZeroes(counter)) {
                    result.push_back(i);
                }

                counter[s[i]-'a']++;
                i++;
            }

            j++;
        }
        return result;
    }
};