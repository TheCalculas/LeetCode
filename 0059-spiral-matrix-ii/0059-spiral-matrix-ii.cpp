#define vvi vector<vector<int>> 
#define pb push_back
#define vi vector<int> 

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vvi vv(n, vi(n, 0));
        int cnt = 1;
        int direction = 1;
        int l = 0, r = n-1, t = 0, b = n-1;
        n = n*n;
        while(cnt<=n)
        {
            // vi v;
            if(direction==1)
            {
                for(int i = l; i<=r && cnt<=n; i++) vv[t][i] = cnt++;
                t++;
                // vv.pb(v);
                direction = 2;
            }
            // v.clear();
            if(direction ==2)
            {
                for(int i = t; i<=b && cnt<=n; i++) vv[i][r] = cnt++;
                r--;
                direction = 3;
                // vv.pb(v);
            }
            // v.clear();
            else if(direction == 3)
            {
                for(int i = r; i>=l&& cnt<=n; i--) vv[b][i] = cnt++;
                // vv.pb(v);
                b--;
                direction = 4;
                // v.clear();
            }
            else if(direction ==4)
            {
                for(int i = b; i>=t&& cnt<=n; i--) vv[i][l] = cnt++;
                // vv.pb(v);
                l++;
                direction = 1;
            }
            // cout<<cnt<<endl;
            
        }
        return vv;
    }
};