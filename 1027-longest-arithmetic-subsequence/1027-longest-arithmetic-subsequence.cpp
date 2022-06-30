class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int lastindex[501], seqs[1000][501]; // seqs[i] goes from -250 to 250 
        fill_n(lastindex, 501, -1);
        int res = 2;
        for(int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            for(int j = 0; j <= 500; j++)
            {
                seqs[i][j] = 1;
                int n2 = n + (j - 250);
                if(n2 >= 0 && n2 <= 500)
                {
                    if(lastindex[n2] != -1)
                    {
                        seqs[i][j] = seqs[lastindex[n2]][j] + 1;
                        res = max(res, seqs[i][j]);
                    }
                }
            }
            lastindex[n] = i;
        }
        return res;
    }
};