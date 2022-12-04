class Solution {
public:
    bool isCircularSentence(string s) {
         int i=0 ;
        while( s[i] != ' ' && i<s.size() ){
            i++ ;
        }
        
        // if sentence does'nt have whitespaces 
        // then simply check the first and last character 
        if( s[0] != s[s.size()-1] ) return false ;
        
        // if sentence have whitespaces 
        // now check for the last and first word 
        else if( s[i] == ' ' && s[i-1] != s[i+1] ) return false ;
        
        return true ;
    }
};