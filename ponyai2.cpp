#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//10%pass
//深度搜索
int dfs(vector<string>& record, 
        vector<vector<int>>& numBlock, 
        vector<vector<int>>& visited, 
        int row, 
        int col){
    //超出范围，返回0
    
    //cout<<row<<" "<<col<<endl;
    if(row>=record.size() || row <0 || col>=record[0].size() || col<0) return 0;
    
    //已经得到了结果，返回对应的数量
    if(visited[row][col]==1) return numBlock[row][col];
    //visited 更新
    visited[row][col]=1;
    if(record[row][col]=='^') numBlock[row][col] += dfs(record, numBlock, visited, row-1, col);
    else if(record[row][col]=='v') numBlock[row][col] += dfs(record, numBlock, visited, row+1, col);
    else if(record[row][col]=='>') numBlock[row][col] += dfs(record, numBlock, visited, row, col+1);
    else  numBlock[row][col] += dfs(record, numBlock, visited, row, col-1);
    
    //cout<<numBlock[row][col]<<endl;
    return numBlock[row][col];
}
int getMaxNumber(vector<string> record, int row, int col){
    if(row==0 || col==0) return 0;
    int maxBlock=0;
    vector<vector<int>> numBlock(row, vector<int>(col, 1));
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            //cout<<"i: "<<i<<" j: "<<j<<endl;
            int curblock = dfs(record, numBlock, visited, i,j);
            //cout<<curblock<<endl;
            maxBlock = max(maxBlock, curblock);
        }
    }
    return maxBlock;
}

int main(void){
    int row=4;
    int col=1;
    //cin>>row>>col;
    vector<string> record={"v","v","v","v"};
    //for(int i=0; i<row; i++){
    //    cin>>record[i];
    //}
    int result=getMaxNumber(record, row, col);
    cout<<result<<endl;
    return 0;
}