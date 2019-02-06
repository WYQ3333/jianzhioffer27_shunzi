#include<iostream>

#include<vector>
#include<algorithm>


using namespace std;

//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers) {
//		if (numbers.size() < 5){
//			return false;
//		}
//		sort(numbers.begin(), numbers.end());
//		vector<int> array;
//		int i = 0;
//		int num_zero = 0;
//		int index = -1;
//		while (numbers[i] == 0){
//			++num_zero;
//			++i;
//		}
//		while (i < numbers.size()){
//			if (array.empty()){
//				array.push_back(numbers[i]);
//				index++;
//			}
//			else if ((numbers[i] - 1 == array[index])){
//				array.push_back(numbers[i]);
//				index++;
//			}
//			else{
//				int cur = numbers[i] - array[index] - 1;
//				if (cur > num_zero&&index < 5){
//					return false;
//				}
//				else if (index >= 5){
//					return true;
//				}
//				else{
//					while (cur){
//						int temp = array[index];
//						array.push_back(++temp);
//						index++;
//						cur--;
//					}
//				}
//			}
//			++i;
//		}
//		return true;
//	}
//};

class Solution {
public:
	/*˳�������������max-min<5;
	��0�����������ֶ������ظ�
	����������5��Ԫ��*/
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) return 0;
		int count[14] = { 0 };//��¼ÿ��Ԫ�س��ֵĴ���;��numbers�е�Ԫ����Ϊ�±�(���K,��Ӧ13)
		int len = numbers.size();
		int max = -1;
		int min = 14;

		for (int i = 0; i<len; ++i)
		{
			count[numbers[i]]++;
			if (numbers[i] == 0) continue;

			if (count[numbers[i]]>1) return 0;//����ظ��򲻻ṹ��˳��,0����

			if (numbers[i]>max) max = numbers[i];

			if (numbers[i]<min) min = numbers[i];

		}//end for

		if (max - min<5) return 1;

		return 0;

	}//end IsContinuous()
};

void TestFunc(){
	vector<int> array = { 0,0,2,1,4 };
	Solution s;
	cout<<s.IsContinuous(array)<<endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}