// 골드 4 - 10942번 : 팰린드롬?
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// check[start][end] = 0 or 1
// 조건 1. data[start] == data[end]
// 조건 2. check[start+1][end-1] == 1(팰린드롬)

// start == end면, 팰린드롬

vector<int> g_data;
vector<vector<bool>> g_check;

void initAndInputData(const int N)
{
    g_data = vector<int>(N+1, 0);
    g_check = vector<vector<bool>>(N+1, vector<bool>(N+1, false));

    for(int i = 1; i <= N; i++)
    {
        cin >> g_data[i];
    }
}

void simulate(const int N)
{
    // 1개만 있는 경우는 팰린드롬
    for(int i = 1; i <= N; i++)
    {
        g_check[i][i] = true;
    }


    for(int dist = 1; dist < N; dist++)
    {
        for(int start = 1; start + dist <= N; start++)
        {
            int end = start + dist;
            // 조건 1. data[start] == data[end]
            if(g_data[start] != g_data[end])
                continue;

            // 조건 2. check[start+1][end-1] == 1(팰린드롬)
            // 단, start + 1 <= end - 1
            if((start + 1) <= (end - 1) && g_check[start+1][end-1] == false)
                continue;

            g_check[start][end] = true;
        }
    }
}

void query(const int M)
{
    int start, end;
    for(int i = 0; i < M; i++)
    {
        cin >> start >> end;
        int result = g_check[start][end] ? 1 : 0;
        cout << result << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수열의 크기 N
    int N;
    cin >> N;

    initAndInputData(N);
    simulate(N);

    // 질문의 개수 M
    int M;
    cin >> M;

    query(M);
}