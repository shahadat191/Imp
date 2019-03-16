
    int findMaximumXOR(vector<int>& nums) {
            int mask = 0, mx = 0;
            for(int i = 30; i>=0; i--){
            mask |= (1 << i);

            set<int> S;
            for(int c: nums){
                S.insert(c & mask);
            }

            int nxt = mx | (1 << i);
            for(int c: S){
                if(S.find(c ^ nxt) != S.end()){
                    mx = nxt;
                    break;
                }
            }
        }
        return mx;
        
    }
