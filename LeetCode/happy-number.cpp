class Solution {
    int sum(int x){
        int ans = 0;
        while(x > 0){
            ans += (x%10) * (x%10);
            x /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {

        int t = 20;
        while(t--){
            if(n == 1)return true;
            n = sum(n); 
        }
        return false;
    }
};