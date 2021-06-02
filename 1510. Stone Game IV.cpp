class Solution {
public:
    int dp[100001];
    bool solve(int n){
        // base condn
        // for a player if there is nothing to choose or he/she cannot make a move\
        // for that case he will lose the game hence we return false;
        if(n<=0){
            return false;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        // at first we just think we are going to loose this game
        bool ans = false;
        for(int i=1;i*i<=n;i++){
            // here we had to think that
            // we will only win this game if the opponent will lose it
            // we will check for every square number from (1 to n) wether our opponent                  will lose or not
            // if our opponent will lose then only we are assure of our win
            
            // thats why we check for every i*i , if our opponent will lose then ,
            // !solve(...) = !(false) = true
            // this states that we will win
            ans = ans || !solve(n-i*i);
        }
        return dp[n] = ans;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        bool value = solve(n);
        return value;
    }
    
};
