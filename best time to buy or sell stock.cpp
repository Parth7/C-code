
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;int ans = 0;
        for(int i=0;i<prices.size();i++)
        {
            buy = min(buy, prices[i]);
            ans = max(ans,prices[i]-buy);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_ik0_pre = 0, T_ik0 = 0, T_ik1 = INT_MIN;

        for (int price : prices) {
            int T_ik0_old = T_ik0;
            T_ik0 = max(T_ik0, T_ik1 + price);
            T_ik1 = max(T_ik1, T_ik0_pre - price);
            T_ik0_pre = T_ik0_old;
        }

        return T_ik0;
    }
};  

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1) return 0;
        int maxs=0;int maxt=INT_MIN;
        for(int i=1;i<prices.size();i++)
        {
            maxs = max(0,maxs+=prices[i]-prices[i-1]);
            maxt = max(maxt,maxs);
        }
        return maxt;
    }
};
*/