// Lv.2 - 12913번 : 땅따먹기
// 작성자 : jeonghoe22(최정호)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    // DP
    vector<vector<int>> results = land;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    // 위에서 아래로 진행
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // 마지막 행일 경우, 가장 큰 결과값 찾기
            if(i == land.size() - 1)
            {
                if(answer < results[i][j])
                {
                    answer = results[i][j];
                }
            }
            // 마지막 행이 아닌 경우에는 아래 행의 다른 열 값과 더했을 때, 최대 비교
            else
            {
                for(int k = 0; k < 4; k++)
                {
                    if(j != k)
                    {
                        results[i+1][k] = max(results[i+1][k], land[i+1][k] + results[i][j]);
                    }
                }
            }
        }
    }

    return answer;
}