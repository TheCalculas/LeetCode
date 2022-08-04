class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        string result = "";
        int key = 2 * numRows - 2;
        
        for (int i=0; i<numRows; i++){
            int idx = i;
            int offset = i * 2;
            int val;
            while (idx < s.size()){
                if ((idx-i) % key == 0 && i != numRows-1)
                    val = key - offset;
                else
                    val = offset;
                result.append(s,idx,1);
                idx += val;
            }
        }
        
        return result;
        
    }
};