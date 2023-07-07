class Solution {
public:
    int arr[27];
    int find(int a)
    {
        if(arr[a]==a) return a;
        return arr[a] = find(arr[a]); 
    }
  
    bool equationsPossible(vector<string>& v) {
        for(int i = 0; i<27; i++)
        {
            arr[i] = i;
        }
        
        for(auto x: v)
        {
            if(x[1]=='=')
            {
                int b = x[3]-'a';
                int a = x[0]-'a';
                arr[find(a)] = find(b);
            }
        }
      
        for(auto x: v)
        {
            if(x[1]=='!')
            {
                int b = x[3]-'a';
                int a = x[0]-'a';
                cout<<"Find a: "<<find(a)<<" findB: "<<find(b)<<endl;
                if(find(a) == find(b)) return false;
            }
        }
        return true;
    }
};