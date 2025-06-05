// 골드 3 - 1613번 : 역사
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<bool>> g_records;
vector<vector<int>> g_connects; 

void inputData(const int n, const int k)
{
    g_records = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    g_connects = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    int prev, cur;
    for(int i = 0; i < k; i++)
    {
        cin >> prev >> cur;
        g_records[prev][cur] = true;
    }
}

void simulate(const int n)
{
    for(int mid = 1; mid <= n; mid++)
    {
        for(int start = 1; start <= n; start++)
        {
            for(int end = 1; end <= n; end++)
            {
                // 시작과 끝이 같은 경우는 무시
                if(start == end || start == mid || mid == end)
                    continue;

                // 이미 연결되어 있는 경우는 무시
                if(g_records[start][end] == true)
                    continue;

                // 연결되는 중간 지점이 있는 경우 확인
                if(g_records[start][mid] == true && g_records[mid][end] == true)
                {
                    g_records[start][end] = true;
                    g_connects[start][end] = mid;
                }
            }
        }
    }
}

int find(const int first, const int second)
{
    // first가 second보다 앞선 사건인 경우
    if(g_records[first][second] == true)
        return -1;

    // second가 first보다 앞선 사건인 경우
    if(g_records[second][first] == true)
        return 1;

    // 둘 다 직접적으로 연결되어 있지 않는 경우
    if(g_connects[first][second] != 0)
    {
        int result1 = find(first, g_connects[first][second]);
        int result2 = find(g_connects[first][second], second);

        // 둘 중 하나 연결되어 있으면, or 연산으로 반환
        return (result1 | result2);
    }
    // 연결도 되어있지 않는 경우
    else
    {
        return 0;
    }
}

void allfinds(const int s)
{
    int first, second;
    for(int i = 0; i < s; i++)
    {
        cin >> first >> second;
        cout << find(first, second) << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 사건의 개수 n, 전후 관계의 개수 k
    int n, k;
    cin >> n >> k;
    inputData(n, k);
    simulate(n);

    // 사건의 수 s
    int s;
    cin >> s;
    allfinds(s);
}