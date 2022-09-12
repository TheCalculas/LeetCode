class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(), token.end());
        int score = 0;
        int mx = 0;
        int h = token.size()-1;
        int l = 0;
        while(h>=l)
        {
            if(power>=token[l])
            {
                power-=token[l++];
                score++;
            }
            else if(power<token[l]&&score){
                score--;
                power+=token[h--];
            }
            else{
                break;
            }
            mx = max(mx, score);
        }
        // if(score<0) return 0;
        return mx;
    }
};