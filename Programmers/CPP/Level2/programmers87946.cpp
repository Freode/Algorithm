// Lv.2 - 87946번 : 피로도
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int search(vector<vector<int>> &dungeons, vector<bool> b_visits, int amount, int count)
{
    int result = count;
    // 던전 모두 검사
    for(int i = 0; i < dungeons.size(); i++)
    {
        // 방문하지 않았고, 최소 피로도 이상일 때
        if(b_visits[i] == false && dungeons[i][0] <= amount)
        {
            b_visits[i] = true;
            int after_count = search(dungeons, b_visits, amount - dungeons[i][1], count + 1);
            result = max(result, after_count);

            // 다른 던전에서는 방문하지 않았다고 해야하므로 초기화
            b_visits[i]= false;
        }
    }
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    // 방문 기록 배열
    vector<bool> b_visits(dungeons.size(), false);
    
    answer = search(dungeons, b_visits, k, 0);

    return answer;
}