#include <string>
#include <vector>

using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> temp = {0};
    int answer = 0;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (board[j][moves[i] - 1] == temp.back()) {
                    temp.pop_back();
                    answer+=2;
                }
                else {          
                    temp.push_back(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}
