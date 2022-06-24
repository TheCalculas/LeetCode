class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sum=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        while(pq.top()!=1){
            long max=pq.top();
            sum-=max;
            if(sum<=0 || sum>=max)
                return 0;
            max=max%sum;
            sum+=max;
            pq.push(max>0 ? max:sum);
            pq.pop();
        }
        return 1;
    }
};