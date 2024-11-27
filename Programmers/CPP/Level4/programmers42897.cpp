// Lv.4 - 42897번 : 도둑질
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();

    vector<vector<int>> cases(2, vector<int>(size, 0));

    // 1번을 담는 경우
    cases[0][0] = money[0];
    cases[0][1] = money[1];
    cases[1][1] = money[1];

    // 3번부터 경우 검색

    // 1번부터 담은 경우를 고려
    for(int i = 2; i < size; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            // 1번부터 담은 경우 / 2번부터 담는 경우
            cases[j][i] = max(cases[j][i - 1], cases[j][i - 2] + money[i]);
            
            // 두 칸 띄어서 담는 경우
            if(i > 2)
            {
                cases[j][i] = max(cases[j][i], cases[j][i - 3] + money[i]);
            }
        }
    }

    // 1번부터 담는 경우 vs 1번을 담지 않은 경우
    answer = max(cases[0][size - 2], cases[1][size - 1]);

    return answer;
}