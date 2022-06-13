class Solution
{
    public:
        int maxProduct(vector<int> &v)
        {
            // base case when size of the vector is 1 
            if(v.size()==1) return v[0];
            // temp variables to store the minimum and maximum
            int mn = 1;
            int mx = 1;
            int gmax = 0;
            for (int i = 0; i < v.size(); i++)
            {
                // as the values would change so I'm storing the prev values in these variables
                auto maxi = mx;
                auto mini = mn;
                // Here I'm solving the edge case when 0 would be there
                if (v[i] == 0)
                {
                    // if zero is there then taking both as zero as it disrupts
                    mx = 0;
                    mn = 0;
                }
                else
                {
                    // Here I'm computing the max and min for sake
                    mx = max(maxi *v[i], mini *v[i]);
                    mx = max(mx, v[i]);
                    mn = min(maxi *v[i], mini *v[i]);
                    mn = min(mn, v[i]);
                }
                // storing the global maximum in the variable
                gmax = max(gmax, mx);
            }
            return gmax;
        }
};