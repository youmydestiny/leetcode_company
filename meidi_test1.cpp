//种树，保证1的位置不相邻，能否再种进去n个树
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param woodland int整型vector 
     * @param n int整型 
     * @return bool布尔型
     */
    bool canPlaceTrees(vector<int>& woodland, int n) {
        if(n==0) return true;
        //查找wooland允许种的最多的树
        vector<int> tree(woodland.size());//tree[i]第i个位置种树时可以种的最多的树
        if(woodland[0]==0 && woodland[1]==0) tree[0] = 1;
        for(int i=1; i<woodland.size(); i++){
            
            if(woodland[i]==1 || woodland[i-1]==1 || (i<woodland.size()-1 && woodland[i+1]==1)) 
                {tree[i]=tree[i-1]; continue;}
            //当前位置可以种
            if(i>=2 && i<woodland.size()-1 && woodland[i]==0 && woodland[i+1]==0)
                tree[i]=max(tree[i-1], tree[i-2]+1);
        }
        int maxNum=0;
        for(int i=0; i<woodland.size(); i++){
            maxNum = max(maxNum, tree[i]);
        }
        return maxNum>=n?true:false;
    }
};