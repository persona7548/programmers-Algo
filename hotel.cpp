#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std; 

map<long long, long long> room;
long long findRoom(long long roomNum) {
	if (room[roomNum] == 0) return roomNum;
	room[roomNum] = findRoom(room[roomNum]);
	return room[roomNum];
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	
	for (int i = 0; i < room_number.size(); i++) {
		long long tmp = findRoom(room_number[i]);
		answer.push_back(tmp);
		room[tmp] = tmp+1;
	}

	return answer;
}
