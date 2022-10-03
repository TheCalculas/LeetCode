class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime) {
            int cost = 0;
            for(int i=0; i<colors.size()-1; i++)
            {
                priority_queue<int, vector<int>, greater<int>> pq;
                int count = 0;
                while(colors[i]==colors[i+1]&&i<colors.size())
                {
                    pq.push(neededTime[i]);
                    i++;
                    count++;
                }
                pq.push(neededTime[i]);
                while(count--)
                {
                    cost += pq.top();
                    pq.pop();
                }
            }
            return cost;
        }
};