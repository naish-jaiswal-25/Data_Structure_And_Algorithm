class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int reverse = 0;
        while(x>0){
            reverse = reverse*10 + x%10;
            x = x/10;
        }
        return abs(n-reverse);
       
       
        
    }

};