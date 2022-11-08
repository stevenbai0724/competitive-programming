class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        map<int, int>mp;
        
        for(auto x: nums){
            mp[x] ++;
        }
        
        for(int i=0;i<n-1;i++){
            if(i > 0 && nums[i-1] == nums[i])continue;
            
            int a = nums[i];
            
            for(int j=i+1;j<n;j++){
                int b = nums[j];
                if(j > 1){
                    if(a != b){
                        if(nums[j-1] == b)continue;
                    }
                    else{
                        if(nums[j-2] == b)continue;
                    }
                }
                
                int c = -a - b;
                if(c>= b){
                    int cnt = mp[c];
                    if(a == c)cnt--;
                    if(b == c)cnt--;
                    
                    if(cnt > 0){
                        ans.push_back({a, b, c});
                    }
                }
                
            }
        }
        return ans;
    }
};