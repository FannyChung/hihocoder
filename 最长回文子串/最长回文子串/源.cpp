#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i<N; i++){//读入N个字符串
		string str;
		cin >> str;
		int result = 0;

		string str1 = "#";//把字符串每一个都加标记#
		for (int j = 0; j<str.size(); j++){
			str1.append(1, str[j]);
			str1.append(1, '#');
		}
		int len = str1.size();

		int *P=new int[len];//动态？？
		int id=0;
		int mx = 0;
		//P[0] = 1;
		for (int j = 0; j < len; ++j)
		{
			P[j] = 0;
			if (mx>j){
				int a = P[2 * id - j];
				int b = mx - j;
				P[j] = (a>b)?b:a;//min
			}
			else{
				P[j] = 1;
			}
			while (j - P[j] >= 0 && (j + P[j]<len) && str1[j + P[j]] == str1[j - P[j]]){//
				P[j]++;
			}
			if (P[j] + j>mx){
				mx = P[j] + j;
				id = j;
			}
			if (result < P[j]-1){
				result = P[j]-1;
			}
		}

		cout << result << endl;
	}
	return 0;
}