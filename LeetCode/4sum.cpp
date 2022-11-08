class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        if(nums.size() <= 3){
            return {};
        }
        int n = nums.size();
        
        vector<vector<int>>ans;
        
        map<int, int>mp;
        
        sort(nums.begin(), nums.end());
        
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<n-3;i++){
            int a = nums[i];
            
            if(i > 0){
                if(a == nums[i-1])continue;
            }
 
            for(int j=i+1;j<n-2;j++){
                int b = nums[j];
                
                if(j-i > 1){
                    if(nums[j-1] == b)continue;
                }

                
                for(int k=j+1;k<n-1;k++){
                    int c = nums[k];
    
                    if(k-j > 1){
                        if(nums[k-1] == c)continue;
                    }
                    
                    long long check = (long long)target - (long long)a - (long long)b - (long long)c;
                    
                    if(abs(check) > 1e9)continue;
                    
                    int d = target - a - b - c;
                    
                    if(d >= c){
                        int cnt = mp[d];
                        if(a == d)cnt--;
                        if(b == d)cnt--;
                        if(c == d)cnt--;
                        
                        if(cnt > 0){
                            ans.push_back({a, b, c, d});
                        }
                    
                    }
                    
                    //{-2,-1,0,0,1,2}
                }
            }
        }
        
        
        return ans;
    }
};