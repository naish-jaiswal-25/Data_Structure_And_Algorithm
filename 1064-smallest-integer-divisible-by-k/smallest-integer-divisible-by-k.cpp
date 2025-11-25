class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;  
        int answer=0;
        for(int i=1;i<=1000000;i++){
            answer=(answer*10+1)%k;
            if(answer==0) return i;
        }     
        return -1;
    }
};