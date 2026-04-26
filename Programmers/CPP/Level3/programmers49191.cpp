// Lv.3 - 49191번 : 순위
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

// 순위 확정 짓기
// 연결된 경우가 n-1개면, 순위를 확정적으로 알 수 있음.
// 100 * 100 * 100 = 1'000'000

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    
    // 기존 선 연결하기
    vector<vector<bool>> relations = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    for(const vector<int>& result : results)
    {
        relations[result[0]][result[1]] = true;
    }
    
    // 모든 관계 검사하고, 연결하기
    for(int mid = 1; mid <= n; mid++)
    {
        for(int start = 1; start <= n; start++)
        {
            for(int end = 1; end <= n; end++)
            {
                // 중간 단계가 서로 연결되어있음을 확인
                if(relations[start][mid] && relations[mid][end])
                    relations[start][end] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        int count = 0;
        for(int j = 1; j <= n; j++)
        {
            // 이기는 경우 || 지는 경우 둘 다 포함
            if(relations[i][j] || relations[j][i])
                count++;
        }
        
        if(count == n-1)
            answer++;
    }
    
    return answer;
}