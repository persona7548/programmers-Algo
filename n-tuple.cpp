#include <iostream>
#include <string>
#include <vector>
using namespace std; 

vector<int> solution(string s) {
	vector<int> answer, tmp,reverse;

	int num = 0,size=-1;
	for (int i = 1; i < s.size(); i++){
		if (s[i] == ',') {
			tmp.push_back(num);
			num = 0;
		}
		else if (s[i] >= 48 && s[i] < 58)
			num = (num * 10) + (s[i] - 48);
		else if (s[i] == '}')
			size++;
	}
	tmp.push_back(num);
	reverse.assign(size, 0);

	
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != 0) {
			int count = 0;
			for (int j = i+1; j < tmp.size(); j++)
			{
				if (tmp[j] == tmp[i]) {
					count++;
					tmp[j] = 0;
				}
			}
			reverse[count] = tmp[i];
		}
	}
	num = reverse.size();
	for (int i = 0; i < num; i++) {
		answer.push_back(reverse.back());
		reverse.pop_back();
	}

	return answer;
}
