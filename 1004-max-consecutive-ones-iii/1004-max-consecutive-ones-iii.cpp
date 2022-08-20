class Solution {
public:
    int longestOnes(vector<int>& v, int no) {
        int start = 0;
        int end = 0;
        int count = 0;
        int ans = 0;
        int zer = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]==0){
                zer++;

            }
            while(zer>no){
                if(v[start]==0) zer--;
                start++;
            }
            end++;
            if(end-start+1>ans) ans = end-start;

        }
        return ans;
    }
};