class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while(target != 1) {
            if(target%2 == 0){
                if(maxDoubles){
                    --maxDoubles;
                    ++cnt;
                    target /= 2;
                }
                else{
                    return cnt+target-1;
                }
            } else{
                ++cnt;
                --target;
            }
        }
        return cnt;
    }
};