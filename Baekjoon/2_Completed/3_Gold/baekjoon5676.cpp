// 골드 1 - 5676번 : 음주 코딩
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// C : 배열의 값을 하나만 바꾸기
// P : 배열의 곱을 출력 -> 0 or + or -
// 음수와 0의 개수로만 출력 가능할 듯?

// 수열의 크기 N, 게임의 라운드 수 K (1~10^5)

const int MAX_SIZE = 100'001;

enum EState
{
    MINUS = 0,
    ZERO,
    PLUS,
};

vector<int> g_datas;
vector<vector<int>> g_tree;

// 입력 데이터 전처리
void inputData(const int N, const int K)
{
    for(int i = 1; i <= N; i++)
    {
        cin >> g_datas[i];
    }
}

// 현재 숫자의 상태를 반환
int getState(const int num)
{
    if(num < 0)
        return MINUS;

    if(num == 0)
        return ZERO;

    return PLUS;
}

void buildTree(const int node, const int start, const int end)
{
    // 리프 노드일 경우, 데이터를 바로 대입 후, 반환
    if(start == end)
    {
        int state = getState(g_datas[start]);
        for(int i = 0; i < 3; i++)
        {
            g_tree[node][i] = (i == state);
        }
        return;
    }

    // 그렇지 않을 경우에는 중간을 기준으로 반반 나눠서 탐색
    int mid = (start + end) >> 1;
    int left_child = node << 1;
    int right_child = node << 1 | 1;
    buildTree(left_child, start, mid);
    buildTree(right_child, mid + 1, end);

    // 양쪽 구간을 더하기
    for(int i = 0; i < 3; i++)
    {
        g_tree[node][i] = g_tree[left_child][i] + g_tree[right_child][i];
    }
}

void queryTree(const int node, const int start, const int end, const int query_left, const int query_right, vector<int>& result)
{
    // 구간에서 완전히 벗어난 경우
    if(query_right < start || query_left > end)
        return;

    // 구간이 완전히 포함된 경우
    if(query_left <= start && end <= query_right)
    {
        for(int i = 0; i < 3; i++)
        {
            result[i] += g_tree[node][i];
        }
        return;
    }

    // 구간의 일부만 포함된 경우
    int mid = (start + end) >> 1;
    int left_child = node << 1;
    int right_child = left_child | 1;
    queryTree(left_child, start, mid, query_left, query_right, result);
    queryTree(right_child, mid + 1, end, query_left, query_right, result);
}

void updateTree(const int node, const int change_idx, 
    const int remove_state, const int add_state,
    const int start, const int end)
{
    // 구간 안에 포함되지 않을 경우, 무시
    if(start > change_idx || end < change_idx)
        return;

    // 구간 안에 포함된 경우
    g_tree[node][remove_state]--;
    g_tree[node][add_state]++;

    // 리프 노드가 아닐 경우에는, 구간을 또 반으로 나눠서 탐색
    if(start == end)
        return;

    int mid = (start + end) >> 1;
    int left_child = node << 1;
    int right_child = left_child | 1;
    updateTree(left_child, change_idx, remove_state, add_state, start, mid);
    updateTree(right_child, change_idx, remove_state, add_state, mid + 1, end);
}

// 결과에 대한 상태 반환
char getResult(const vector<int>& result)
{
    if(result[ZERO] > 0)
        return '0';

    if(result[MINUS] % 2 == 1)
        return '-';

    return '+';
}

void simulate(const int N, const int K)
{
    char c;
    int start, end;

    buildTree(1, 1, N);
    for(int i = 0; i < K; i++)
    {
        cin >> c >> start >> end;
        // 변경 모드
        if(c == 'C')
        {
            // 기존과 같은 상태면, 변경 x
            int prev = getState(g_datas[start]);
            int next = getState(end);
            g_datas[start] = end;

            if(prev == next)
                continue;

            updateTree(1, start, prev, next, 1, N);
        }
        // 곱셉 모드
        else
        {
            vector<int> result = vector<int>(3, 0);

            queryTree(1, 1, N, start, end, result);
            cout << getResult(result);
        }
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    g_datas = vector<int>(MAX_SIZE, 0);
    g_tree = vector<vector<int>>(MAX_SIZE * 4 + 1, vector<int>(3, 0));

    // 수열의 크기 N, 게임의 라운드 수 K
    int N, K;
    while(cin >> N >> K)
    {
        inputData(N, K);
        simulate(N, K);
    }
}