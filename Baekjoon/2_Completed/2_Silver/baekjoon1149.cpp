// 실버 1 - 1149번 : RGB거리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// n-1, n, n+1 줄의 집들 사이에서 연관만 있고
// 나머지 줄은 연관 없음.
// 이전 선택 라인을 기준으로 연속된 라인을 선택할 수 없게 하고
// 현재 줄의 해당 라인을 기준으로 이전 줄의 다른 라인과 더해서 최솟값을 저장

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<vector<int>> houses(N, vector<int>(3, 0));
    for(vector<int>& house : houses)
    {
        cin >> house[0] >> house[1] >> house[2];
    }

    int result = 10000000;

    // 계산
    for(int i = 1; i < N; i++)
    {
        houses[i][0] = houses[i][0] + houses[i-1][1] > houses[i][0] + houses[i-1][2] ? houses[i][0] + houses[i-1][2] : houses[i][0] + houses[i-1][1];
        houses[i][1] = houses[i][1] + houses[i-1][0] > houses[i][1] + houses[i-1][2] ? houses[i][1] + houses[i-1][2] : houses[i][1] + houses[i-1][0];
        houses[i][2] = houses[i][2] + houses[i-1][0] > houses[i][2] + houses[i-1][1] ? houses[i][2] + houses[i-1][1] : houses[i][2] + houses[i-1][0];
    }

    // 3개의 라인 중 최솟값으로 결정
    for(int i = 0; i < 3; i++)
    {
        if(result > houses[N-1][i]){ result = houses[N-1][i]; }
    }

    // 결과 출력
    cout << result << "\n";
}