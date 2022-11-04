class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int j = n-1;
        
        
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                       
               while(j>0 && (!isVowel(s[j]))){
                   j--;
               }
                
                char temp = s[i];
                s[i] = s[j];    
                s[j] = temp;

                j--;
                
                
            }
            if(i >= j)break;
        }
        return s;
    }
};