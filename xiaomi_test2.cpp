#include<vector>
#include<iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
vector<long> getData(string input){
  vector<long> result;
  if(input.size()==0) return result;
  char *tok;
  tok = strtok((char *)input.c_str(), " ,[]");
  while (tok != NULL) {
    result.push_back(stoi(tok));
    tok = strtok(NULL, " ,[]");
  }
  /*for(auto num: result){
    cout<<num<<endl;
  }*/
  return result;
}
vector<long> LinearConv(vector<long> data1, vector<long> data2){
  
}
vector<long> SelfRlation(vector<long> data1, vector<long> data2){
  
}
int main(void){
  string data1_str;
  string data2_str;
  getline(cin, data1_str);
  getline(cin, data2_str);
  vector<long> data_1 = getData(data1_str);
  vector<long> data_2 = getData(data2_str);
  vector<long> result_cov = LinearConv(data_1, data_2);
  vector<long> result_rel = SelfRlation(data_1, data_2);
  cout<<result_cov.size()<<",";
  for(int i=0; i<result_cov.size(); i++){
    if(i!=result_cov.size()-1) cout<<result_cov[i]<<" ";
    else cout<<result_cov[i]<<endl;
  }
  cout<<result_rel.size()<<",";
  for(int i=0; i<result_rel.size(); i++){
    if(i!=result_rel.size()-1) cout<<result_rel[i]<<" ";
    else cout<<result_rel[i]<<endl;
  }
  return 0;
}