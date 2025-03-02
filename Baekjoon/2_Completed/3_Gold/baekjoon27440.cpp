// 골드 4 - 27440번 : 1로 만들기 3
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    // 맵과 큐 사용
    unordered_map<ll, int> u_map;
    queue<ll> que;
    que.push(N);
    u_map[N] = 0;

    // 1에 도달할 때까지 반복
    while(que.empty() == false)
    {
        ll cur = que.front();
        que.pop();

        // 목표에 도달한 경우, 바로 바져나옴
        if(cur == 1) break;

        // 1. 3으로 나누기
        if(cur % 3 == 0 && u_map[cur/3] == 0 && cur/3 > 0)
        {
            u_map[cur/3] = u_map[cur] + 1;
            que.push(cur/3);
        }

        // 2. 2로 나누기
        if(cur % 2 == 0 && u_map[cur/2] == 0 && cur/2 > 0)
        {
            u_map[cur/2] = u_map[cur] + 1;
            que.push(cur/2);
        }

        // 3. 1 빼기
        if(cur - 1 > 0 && u_map[cur-1] == 0)
        {
            u_map[cur-1] = u_map[cur] + 1;
            que.push(cur-1);
        }
    }

    cout << u_map[1] << "\n";
}