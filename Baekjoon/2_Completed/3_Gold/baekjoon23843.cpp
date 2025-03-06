// 골드 5 - 23843번 : 콘센트
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 전자기기 N개, 콘센트 M개
    int N, M;
    cin >> N >> M;

    // 전자기기 정보
    vector<int> elects(N);
    for(int& elect : elects)
    {
        cin >> elect;
    }

    // 내림차순 정렬 -> 가장 오래 걸리는 것부터 충전
    sort(elects.begin(), elects.end(), greater<int>());

    // 가장 빨리 끝나는 것에 추가로 채워넣기
    priority_queue<int, vector<int>, greater<int>> que;

    // 콘센트에 처음으로 추가
    for(int i = 0; i < M; i++)
    {
        // 콘센트보다 전자기기 수가 적을 때, 무시
        if(i == N) break;
        que.push(elects[i]);
    }
    // 1024 2048 4096 8192 16 32000 * 10000 
    // 완료될 때마다 하나씩 추가 - 콘센트 M개 유지
    int count = M;
    int time = 0;
    while(que.empty() == false)
    {
        time = que.top();
        que.pop();
        // 추가로 충전할게 있음
        if(count < N)
        {
            que.push(time + elects[count]);
            count++;
        }
    }

    cout << time << "\n";
}