#include<iostream>

#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int new_size = numbers.size();
		vector<int> array(new_size, 0);
		return true;
	}
};

void TestFunc(){
	vector<int> array = { 1, 2, 3, 0, 0, 6, 7 };
	Solution s;
	s.IsContinuous(array);
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}