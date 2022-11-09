class StockSpanner {
public:
// AUTHOR : DHARMESH SHARMA 
    stack<pair<int,int>>st;
    int i; // so this will tell the index to be taken care of (smaller nikaalne ke kaam mei aayega) 
    
    // this is the constructor which will init the value 
    StockSpanner() {
        i=0;
    }

    int next(int price) {
        // ans store karega asli maal ki kitne chhote hai 
        int res;
        
        // stack ko tabhtak pop karo jabtak voh condition satify nhi karta
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }
        // agar empty ho jaaye toh saare elements (veise iski zaroorat nhi hai but shi h)
        if(st.empty()){
         res= i+1;
        }
        else {
             res=i-st.top().first; // ye apan indexes mei deal kar rhe hai
        }
        // last mei push kardo asli maal 
        st.push({i,price});
        i++; // for next element 
        // returning the answerrrrr 
        // jaao aur mauj karo
        
        return res;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */