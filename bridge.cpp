#include <string>
#include <vector>
using namespace std; 

int temp;
bool check(vector<int> stones, int friends,int k) {
	int prevZero=0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] < friends) {
			prevZero++;
			if (prevZero == k) {
				return false;
			}
		}
		else
			prevZero = 0;
	}

	return true;
}

void binarySearch(vector<int> stones,int start, int end,int k){
	if (start > end)
		return;
	int mid = (start + end) / 2;
	if (check(stones, mid,k)) {
		if (temp < mid)
			temp = mid;
		binarySearch(stones, mid+1,end, k);
	}
	else {
		binarySearch(stones, start,mid - 1, k);
	
	}
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	binarySearch(stones,1,200000000,k);
	answer= temp;
	return answer;
}
