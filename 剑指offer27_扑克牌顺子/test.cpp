#include<iostream>

#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		vector<int> array;
		int i = 0;
		int num_zero = 0;
		int index = -1;
		while (numbers[i] == 0){
			++num_zero;
		}
		i = num_zero;
		while (i < numbers.size()){
			if (array.empty()){
				array.push_back(numbers[i]);
				index++;
			}
			else if (numbers[i] - 1 == array[index]){
				array.push_back(numbers[i]);
				index++;
			}
			else{
				int cur = numbers[i] - array[index] - 1;
				if (cur > num_zero){
					return false;
				}
				else{
					while (cur){
						array.push_back(0);
						index++;
						cur--;
					}
				}
			}
			++i;
		}
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