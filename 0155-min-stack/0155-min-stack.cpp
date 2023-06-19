class MinStack {
    vector<int> s, minIdx;
public:
    void push(int val) {
        if(minIdx.empty() || val < s[minIdx.back()]) minIdx.push_back(s.size());
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        if(minIdx.back() == s.size()) minIdx.pop_back();
    }

    int top() { return s.back(); }
    int getMin() { return s[minIdx.back()]; }
};