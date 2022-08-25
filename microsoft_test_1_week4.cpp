// you can use includes, for example:
 #include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    vector<int> record;
    vector<int> five_pos; // record 5 position
    int flag = N>=0 ? 1:-1;
    int Num = N>=0 ? N:-N;
    int count = 0;
    int index = 0;
    //record digits
    while(Num>0){
        if (Num%10==5){
            count++;
            five_pos.push_back(index); // record 5 position, 0-index
        } 
        record.push_back(Num%10);
        Num = Num/10;
        index++;
    }
    // judge digit '5' num, if==1
    int result = 0;
    if(count==1){
        if(record[record.size()-1]==5)//'5' is at 1st position
        {
            int i=record.size()-2;
            while(i>=0){
                result = result*10 + record[i];
                i--;
            }
            return flag*result;
        }
        else{ // digit '5' is not at 1st position
            int i = record.size()-1;
            while(i>=0){
                if(record[i]==5){i--; continue;}  // skip if == 5
                result = result*10 + record[i];
                i--;
            }
            return flag*result;
        }
    }
    else{// num of digit '5' >= 2
        //search different result
        vector<int> diff_five_result(count);
        for(int j=0; j<five_pos.size(); j++){
            int cur_five_pos = five_pos[j];
            int i=record.size()-1;
            while(i>=0){
                if(i==cur_five_pos) {i--; continue;} // skip if does't use that 5
                diff_five_result[j] = diff_five_result[j]*10 + record[i]; // get result 
                // doesn't use cur five
                i--; 
            }
            if(flag==1) result = max(result, diff_five_result[j]);
            else{
                if(j==0) result = min(1000000, diff_five_result[j]);
                else result = min(result, diff_five_result[j]);
            } 
            
        }
        return flag*result;
    }  
}
