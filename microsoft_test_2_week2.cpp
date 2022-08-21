#include<iostream>
#include<vector>
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
using namespace std;
bool compare(int a, int b){
    if(a>=b) return true;
    else return false;
}
bool compare_double(double a, double b){
    if(a>=b) return true;
    else return false;
}
int solution(vector<int> &A) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    // for  factories, return 0
    if(A.size()==0) return 0;
    if(A.size()==1) return 1;
    //copy
    //sort(A.begin(), A.end());
    //for(auto i:A) cout<<i<<" ";
    cout<<endl;
    vector<double> B(A.size());
    B.assign(A.begin(), A.end());
    for(auto i:B) cout<<i<<" ";
    cout<<endl;
    //sort
    sort(B.begin(), B.end(), compare_double);
    //reverse(B.begin(), B.end());
    //sum and aim
    double sum = 0;
    for(int i=0; i<int(B.size()); i++)
        sum += B[i];
    double aim_reduce = sum/2;
    cout<<aim_reduce<<endl;
    double real_reduce = 0;
    int count = 0;
    //continue when real_reduce < aim_reduce
    while(real_reduce<aim_reduce){
        if(B[0]>=B[1]){
        	real_reduce += B[0]/2;
            B[0] = B[0]/2;
            count++;
            
            //continue;
        }
        
        cout<<real_reduce<<endl;
        sort(B.begin(), B.end(), compare_double);
        for(auto i:B) cout<<i<<" "; 
        	cout<<endl;
        //reverse(B.begin(), B.end());
    }
    return count;
}

int main(void){
	std::vector<int> A={10,10,10};
	int count = solution(A);
	cout<<count<<endl;
	return 0;
}