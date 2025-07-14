// 골드 1 - 1275번 : 커피숍2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

vector<ll> g_datas;
vector<ll> g_sums;

// 입력 데이터 전처리
void inputData(const int N)
{
    for(int i = 1; i <= N; i++)
        cin >> g_datas[i];
}

// 세그먼트 트리 제작
ll buildTree(const int idx, const int left, const int right)
{
    // 시작 부분만 있을 때는 해당 데이터 값을 바로 저장
    if(left == right)
    {
        g_sums[idx] = g_datas[left];
        return g_sums[idx];
    }

    // 그렇지 않을 경우에는 나눠서 처리
    int mid = (left + right) >> 1;
    g_sums[idx] = buildTree(2 * idx, left, mid) + buildTree(2 * idx + 1, mid + 1, right);
    return g_sums[idx];
}

// 구간에 대한 합을 구하기
ll queryTree(const int idx, const int start, const int end, const int left, const int right)
{
    // 범위에서 벗어난 경우
    if(start > right || end < left)
        return 0;

    // 범위에 완전히 포함된 경우, 해당 구간의 합을 바로 반환
    if(start <= left && right <= end)
        return g_sums[idx];

    // 범위에 일부분만 포함된 경우, 현재 범위의 가운데를 기준으로 나눠서 구간에 대한 합을 가져오기
    int mid = (left + right) >> 1;
    return queryTree(2 * idx, start, end, left, mid) + queryTree(2 * idx + 1, start, end, mid + 1, right);
}

void updateTree(const int idx, const int updateIdx, const ll diff, const int left, const int right)
{
    // 범위에서 벗어난 경우, 해당 구간은 무시
    if(updateIdx < left || updateIdx > right)
        return;

    // 변경된 노드가 현재 범위에 속한 경우, 변경된 간격만큼 더하기
    g_sums[idx] += diff;

    // 해당 노드에 도착하지 않은 경우, 리프 노드를 찾으러 재귀 함수 호출
    if(left == right)
        return;

    int mid = (left + right) >> 1;
    updateTree(2 * idx, updateIdx, diff, left, mid);
    updateTree(2 * idx + 1, updateIdx, diff, mid + 1, right);
}

void simulate(const int N, const int Q)
{
    buildTree(1, 1, N);

    int start, end, updateIdx, queryStart, queryEnd;
    ll updateVal;
    for(int i = 0; i < Q; i++)
    {
        cin >> start >> end >> updateIdx >> updateVal;

        queryStart = min(start, end);
        queryEnd = max(start, end);

        cout << queryTree(1, queryStart, queryEnd, 1, N) << "\n";
        
        ll diff = updateVal - g_datas[updateIdx];
        g_datas[updateIdx] = updateVal;
        updateTree(1, updateIdx, diff, 1, N);
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수의 개수 N, 턴의 개수 Q
    int N, Q;
    cin >> N >> Q;

    g_datas = vector<ll>(N+1, 0);
    g_sums = vector<ll>(4 * (N+1), 0);
    inputData(N);
    simulate(N, Q);
}