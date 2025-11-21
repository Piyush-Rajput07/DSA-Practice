class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        vector<int> store(26, 0);

        for(int i=0; i<n; i++) {
            store[sentence[i]-'a']++;
        }

        for(int i=0; i<store.size(); i++) {
            if(store[i] == 0) {
                return false;
            }
        }
        return true;
    }
};