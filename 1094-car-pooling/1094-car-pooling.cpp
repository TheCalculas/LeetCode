class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001);
        for(auto& trip: trips) {
            road[trip[1]] += trip[0];
            road[trip[2]] -= trip[0];
        }
        
        for(int i = 0; i <= 1000; i++) {
            capacity -= road[i];
            if(capacity < 0) {
                return false;
            }
        }
        
        return true;
    }
};