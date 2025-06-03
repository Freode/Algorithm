// 실버 3 - 26215번 : 눈 치우기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 내림차순 정렬
// 가장 많은 눈이 쌓인 두 집을 청소

vector<int> g_snows;

void inputData(const int N)
{
    g_snows = vector<int>(N);

    for(int& snow : g_snows)
        cin >> snow;
}

int simulate(const int N)
{ 
    int result = 0;

    sort(g_snows.begin(), g_snows.end(), greater<int>());

    while(g_snows[0] != 0)
    {
        // 두 집의 눈을 치울 수 있는 경우
        if(N != 1 && g_snows[1] != 0)
            g_snows[1]--;

        g_snows[0]--;
        result++;

        // 계산 후, 가장 눈이 많이 쌓인 집 순서로 정렬
        sort(g_snows.begin(), g_snows.end(), greater<int>());

        // 24시간을 초과한 경우, -1을 출력
        if(result > 1440)
        {
            result = -1;
            break;
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 집의 수 N
    int N;
    cin >> N;

    inputData(N);
    cout << simulate(N) << "\n";
}