class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        bool updated = true;
        int n = target.size();
        int m = stamp.size();
        vector<int> ret;
        while(updated) {
            updated = false;
            for(int i = 0; i < n-m+1; ++i) {
                bool changed = false;
                bool fits = true;
                for(int j = 0; j < m; ++j) {
                    if(target[i+j] == '*') {
                        continue;
                    } else if (target[i+j] == stamp[j]) {
                        changed = true;
                    } else {
                        fits = false;
                        break;
                    }
                }
                
                if(fits && changed) {
                    for(int j = 0; j < m; ++j) {
                        target[i+j] = '*';
                    }
                    ret.push_back(i);
                    updated = true;
                }
            }
        }
        
        for(char c : target) {
            if(c != '*') {
                return {};
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};