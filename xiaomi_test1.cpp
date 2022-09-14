/*计算将x减小到0的最小操作数*/
/* 依次减去最左侧或者最右侧的数字，知道x=0，返回最小操作次数，如果无法等于0，返回-1*/
#include<vector>
#include<iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
vector<long> getInput(string input){
  vector<long> result;
  if(input.size()==0) return result;
  char *tok;
  tok = strtok((char *)input.c_str(), " ,[]");
  while (tok != NULL) {
    result.push_back(stoi(tok));
    tok = strtok(NULL, " ,[]");
  }
  return result;
}
bool minOperation(vector<long> record, long left, long right, long x, long& operation_num){
  //选择两边最少的数字，使得其和为x
  if(x==0){operation_num=0; return true;}
  if(record.size()==0) {operation_num=-1; return false;}
  if(left>=record.size() || right<0) {operation_num=-1; return false;}
  if(left>right){ operation_num=-1; return false;}
  if(left==right && record[left]==x){operation_num=1; return true;}
  if(left==right && record[left]!=x){operation_num=-1; return false;}
  //判断左边的是否成立
  long left_num=0;
  minOperation(record, left+1, right, x-record[left], left_num);
  //判断右边的是否成立
  long right_num = 0;
  minOperation(record, left, right-1, x-record[right], right_num);
  if(left_num==-1 && right_num==-1){ operation_num=-1; return false;}
  if(left_num!=-1 && right_num==-1){operation_num=left_num+1; return true;}
  if(left_num==-1 && right_num!=-1){operation_num=right_num+1; return true;}
  if(left_num!=-1 && right_num!=-1){operation_num=min(right_num+1, left_num+1); return true;}
}
int main(void){
  vector<long> record;
  string input;
  getline(cin, input);
  record = getInput(input);
  long length = 0;
  cin>>length;
  long x=0;
  cin>>x;
  long operation_num=0;
  minOperation(record, 0, length-1, x, operation_num);
  cout<<operation_num<<endl;
  return 0;
}