class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prev(n, 0);
        vector<int> surf(n, 0);
        prev[0] = cardPoints[0];
        for(int i=0; i<n-1; i++)
        {
            prev[i+1] = prev[i]+cardPoints[i+1];
        }
        reverse(cardPoints.begin(), cardPoints.end());
        surf[0] = cardPoints[0];
        for(int i=0; i<n-1; i++)
        {
            surf[i+1] = surf[i]+cardPoints[i+1];
        }
        //
        for(auto x: surf)
            cout<<x<<" ";
        cout<<endl;
        for(auto x: prev)
            cout<<x<<" ";
        cout<<endl;
            
        int i = 0;
        int j = k-2;
        int sum = 0;
        sum = max(prev[k-1], sum);
        sum = max(surf[k-1], sum);
        while(j>=0&&i<=k-2)
        {
            sum = max(prev[i]+surf[j], sum);
            i++;
            j--;
        }
        return sum;
        
    }
};