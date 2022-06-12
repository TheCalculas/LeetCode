class Solution
{
    public:
        int maxProduct(vector<int> &v)
        {
            if(v.size()==1) return v[0];
            int mn = 1;
            int mx = 1;
            int gmax = 0;
            for (int i = 0; i < v.size(); i++)
            {
                auto maxi = mx;
                auto mini = mn;
                if (v[i] == 0)
                {
                    mx = 0;
                    mn = 0;
                }
                else
                {
                    mx = max(maxi *v[i], mini *v[i]);
                    mx = max(mx, v[i]);
                    mn = min(maxi *v[i], mini *v[i]);
                    mn = min(mn, v[i]);
                }
                gmax = max(gmax, mx);
            }
            return gmax;
        }
};