// 문제 - 2538번
// 작성자 : jeonghoe22(최정호)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // commands의 한 줄마다 3개 요소
    // array를 자르는 시작점과 끝점, 정렬 후 몇 번째 요소를 answer에 넣을 것인지 표시
    vector<int> cutting_array;
    for(int i = 0; i < commands.size(); i++)
    {
        cutting_array.clear();
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            cutting_array.push_back(array[j]);
        }
        
        
        sort(cutting_array.begin(), cutting_array.end());
        
        answer.push_back(cutting_array[commands[i][2] - 1]);
    }

    return answer;
}