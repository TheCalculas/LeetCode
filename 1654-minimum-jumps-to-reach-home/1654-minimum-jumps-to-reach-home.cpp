class Solution
{
    public:
        int forbidden[8000];
    int seen[8000][2];

    int minimumJumps(vector<int> &forb, int a, int b, int x)
    {
        for (auto x: forb) forbidden[x] = 1;

        queue<pair<int, bool>> q;
        q.push({ 0,
            false });
        seen[0][0] = 1;

        int jumps = 0;
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                auto[pos, isBackward] = q.front();
                q.pop();

                if (pos == x)
                {
                    return jumps;
                }

               	// Go forward
                if (!seen[pos + a][0] && pos < 4000 && !forbidden[pos + a])
                {
                    seen[pos + a][0] = 1;
                    q.push({ pos + a,
                        false });
                }

               	// Go backward
                if (!isBackward && pos - b > 0 && !seen[pos - b][1] && !forbidden[pos - b])
                {
                    seen[pos - b][1] = 1;
                    q.push({ pos - b,
                        true });
                }
            }
            ++jumps;
        }

        return -1;
    }
};