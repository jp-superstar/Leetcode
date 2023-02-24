class Solution {
    public int coinChange(int[] coins, int amount) {
        Integer dp[][] = new Integer[coins.length+1][amount+1];
        int ret = dfs(coins, amount, 0, dp);
        return ret == 100000 ? -1 : ret;
    }

    int dfs(int coins[], int amount, int i, Integer dp[][]) {
        if(amount==0) return 0;
        if(i>coins.length-1 || amount<0) return 100000;
        if(dp[i][amount]!=null) return dp[i][amount];
        int pick = 0;
        int dontPick = 0;


        int val = coins[i];
        pick = 1 + dfs(coins, amount-val, i,dp);

        dontPick = dfs(coins, amount, i+1,dp);

        dp[i][amount] = Math.min(pick, dontPick);
        return dp[i][amount];

    }
}
