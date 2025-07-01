// 실버 4 - 11558번 : The Game of Death
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_targets;

void inputData(const int N)
{
    int num;
    for(int i = 1; i <= N; i++)
    {
        cin >> num;
        g_targets[i] = num;
    }
}

int simulate(const int N)
{
    int num = 1;
    int count = 0;
    
    while(num != N)
    {
        // 이미 방문한 경우, 목적지에 도달 불가능
        if(g_targets[num] == -1)
            return -1;

        int next = g_targets[num];
        g_targets[num] = -1;
        num = next;

        count++;
    }
    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    g_targets = vector<int>(10'001, 0);
    int N;

    for(int i = 0; i < T; i++)
    {
        // 사람 수 N
        cin >> N;
        inputData(N);
        cout << simulate(N) << "\n";
    }
}