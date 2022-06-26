typedef long long ll;
class Solution {
public:
    ll mod = 1e9+7;
    int countHousePlacements(int n) {
        ll house=1, space=1, total = 2;
        for(int i=2;i<=n;i++){
	        house = space;
	        space = total;
	        total = (house+space)%mod;
	    }
	    return (total*total)%mod;
    }
};