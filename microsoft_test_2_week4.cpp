//求解数组中和为0的连续子数组的数目
//比如 [3, -2, 2, -3, -2, 0, 1]，返回3
//因为[3, -2, 2, -3], [-2, 2], [0] 数组和均为0
// reference: https://blog.csdn.net/oppo62258801/article/details/103327746
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
int subarray_sum_equal_0(std::vector<int>& A, int k){
	unordered_map<int, int> record; 
	record[0]=1;
	int count = 0;
	int sum = 0;
	for(int i=0; i<A.size(); i++){
		sum += A[i];
		//search sum - k
		if(record.find(sum-k)!=record.end()){
			count += record[sum-k];
		}
		
		record[sum]++;
	}
	return count;
}
int main(void){
	std::vector<int> v{3, -2, 2, -3, -2, 0, 1};
	cout<<subarray_sum_equal_0(v,0)<<endl;
	return 0;
}