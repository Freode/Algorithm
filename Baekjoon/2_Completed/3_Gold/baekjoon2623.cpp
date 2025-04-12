// 골드 3 - 2623번 : 음악프로그램
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 가능한 순서대로 출력
// N은 1000이하

struct Num
{
    int idx = 0;
    int count = 0;
    vector<int> connects;

    Num()
    {
        connects.reserve(1'001);
    }
};

vector<Num> g_nums;
vector<int> g_results;

// 연결 정보 입력
void inputInfo(const int N, const int M)
{
    g_nums = vector<Num>(N+1);

    int num, cur, prev;
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        cin >> prev;

        for(int j = 0; j < num-1; j++)
        {
            cin >> cur;

            g_nums[prev].connects.push_back(cur);
            g_nums[cur].count++;

            prev = cur;
        }
    }
}

bool simulate(const int N, const int M)
{
    g_results.reserve(N);
    queue<int> q;

    // 참조하지 않는 번호부터 입력
    for(int i = 1; i <= N; i++)
    {
        if(g_nums[i].count == 0)
        {
            q.push(i);
            g_results.push_back(i);
        }
    }

    // 큐 검사
    while(q.empty() == false)
    {
        int idx = q.front();
        q.pop();

        for(const int& each : g_nums[idx].connects)
        {
            // 방문 횟수 1개 감소
            g_nums[each].count--;

            // 방문 횟수가 0일 때, 추가
            if(g_nums[each].count == 0)
            {
                q.push(each);
                g_results.push_back(each);
            }
        }
    }

    // 마지막까지 순서가 정해지면, 순서 정하기 성공
    return g_results.size() != N;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 가수 수 N, 보조 PD 수 M
    int N, M;
    cin >> N >> M;

    inputInfo(N, M);
    if(simulate(N, M))
        cout << "0\n";
    else
    {
        for(const int& each : g_results)
            cout << each << "\n";
    }
}