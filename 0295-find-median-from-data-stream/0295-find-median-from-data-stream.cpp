class MedianFinder {
public:
    priority_queue<int> firstHalf;
    priority_queue<int,vector<int>,greater<int> > secondHalf;
    double med = 1e9;
    MedianFinder() {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    }
    
    void addNum(int num) {
        if(med == 1e9) med = num;
        if(firstHalf.size()>secondHalf.size()){
            if(num < med){
                secondHalf.push(firstHalf.top());
                firstHalf.pop();
                firstHalf.push(num);
            }else{
                secondHalf.push(num);
            }
            med = (firstHalf.top()+secondHalf.top())/2.0;
        }else if(firstHalf.size() < secondHalf.size()){
            if(num > med){
                firstHalf.push(secondHalf.top());
                secondHalf.pop();
                secondHalf.push(num);
            }else{
                firstHalf.push(num);
            }
            med = (firstHalf.top()+secondHalf.top())/2.0;
        }else{
            if(num > med){
                secondHalf.push(num);
                med = secondHalf.top();
            }else{
                firstHalf.push(num);
                med = firstHalf.top();
            }
        
        }
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */