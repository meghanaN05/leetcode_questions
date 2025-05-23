  
 class Solution 
{
public:
    long long maximumValueSum(vector<int>& a, int x, vector<vector<int>>& e) 
    {
        long long total = 0;
        vector<int> delta;

        for (int v : a) 
        {
            int y = v ^ x;
            int d = y - v;
            total += v;
            delta.push_back(d);
        }

        sort(delta.rbegin(), delta.rend());

        long long best = 0, sum = 0;
        int c = 0;

        for (int d : delta) 
        {
            sum += d;
            c++;
            if (c % 2 == 0) 
            {
                best = max(best, sum);
            }
        }

        return total + best;
    }
};
