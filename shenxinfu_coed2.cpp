#include <iostream>
#include <vector>
using namespace std;
//给出每个员工方便的时间段，求最多能让多少个员工觉得方便
//50%通过率
int main() {
    int test_number = 0;
    cin>>test_number;
    for(int i=0; i<test_number; i++){
        int cur_data_num = 0;
        cin>>cur_data_num;
        vector<vector<int>> record(cur_data_num, vector<int>(2));
        int max_num = 0;
        for(int j=0; j<cur_data_num; j++){
            cin>>record[j][0]>>record[j][1];
            max_num = max(max_num, max(record[j][0], record[j][1]));
        }
        vector<int> cur_appear_num(max_num);
        for(int j=0; j<cur_data_num; j++){
            int left = record[j][0];
            int right = record[j][1];
            for(int k=left-1; k<=right-1; k++){
                cur_appear_num[k]++;
            }
        }
        int result=0;
        for(int p=0; p<cur_appear_num.size(); p++){
            result = max(result, cur_appear_num[p]);
        }
        cout<<result<<endl;
    }
}
// 64 位输出请用 printf("%lld")