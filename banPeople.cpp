#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> answerList;
bool check[9];
bool listCheck(vector<string> tempList, vector<string> banned_id) {
	int banLen = banned_id.size();
	for (int i = 0; i < banLen; i++) {
		int userLen = tempList[i].length();
		int banUserLen = banned_id[i].length();
		if (userLen != banUserLen)
			return false;
		for (int j = 0; j < userLen; j++) {
			if (banned_id[i][j] != '*'&&tempList[i][j] != banned_id[i][j])
				return false;
		}

	}
	return true;
}
void dfs(int depth, int list[], vector<string> user_id, vector<string> banned_id) {
	int userLen = user_id.size(), banLen = banned_id.size(), answerLen = answerList.size();
	if (depth == banned_id.size())
	{
		vector<string> tempList;
		for (int i = 0; i < banLen; i++) {
			tempList.push_back(user_id[list[i]]);
		}
		if (listCheck(tempList, banned_id)) {
			int tmp = 0;
			for (int i = 0; i < userLen; i++)
				tmp = (tmp * 10) + check[i];

			answerList.insert(tmp);
		}
	}
	else {
		for (int i = 0; i < userLen; i++) {
			if (!check[i]) {
				check[i] = true;
				list[depth] = i;
				dfs(depth + 1, list, user_id, banned_id);
				check[i] = false; 
			}
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0, list[9];

	dfs(0, list, user_id, banned_id);
	answer = answerList.size();
	cout << answer;
	return answer;
}
