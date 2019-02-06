#include<iostream>

#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() < 5){
			return false;
		}
		sort(numbers.begin(), numbers.end());
		vector<int> array;
		int i = 0;
		int num_zero = 0;
		int index = -1;
		while (numbers[i] == 0){
			++num_zero;
			++i;
		}
		while (i < numbers.size()){
			if (array.empty()){
				array.push_back(numbers[i]);
				index++;
			}
			else if ((numbers[i] - 1 == array[index])){
				array.push_back(numbers[i]);
				index++;
			}
			else{
				int cur = numbers[i] - array[index] - 1;
				if (cur > num_zero&&index < 5){
					return false;
				}
				else if (index >= 5){
					return true;
				}
				else{
					while (cur){
						int temp = array[index];
						array.push_back(++temp);
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
	vector<int> array = { 0};
	Solution s;
	cout<<s.IsContinuous(array)<<endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}