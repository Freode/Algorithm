// 문제 - 734번 :
// 작성자 : jeonghoe22(최정호)
#include <string>
#include <vector>

using namespace std;

// 2차원 행렬 덧셈 문제
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    
    for(int i = 0; i < arr1.size(); i++)
    {
        for(int j = 0; j < arr1[0].size(); j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
    
}