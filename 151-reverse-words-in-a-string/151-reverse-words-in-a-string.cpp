class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        stringstream ss(s);
        string a;
        while(ss>>a)
        {
            word = a +" "+ word;
        }
        word.pop_back();
        return word;
    }
};