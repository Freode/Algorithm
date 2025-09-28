// 실버 2 - 2644번 : 촌수계산
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 주어진 두 사람의 촌수 계산
// n : 1~100

// 1
// 2 3
// 4 5 6 7

// 사람 구조체
struct Person
{
    bool is_visit = false;
    vector<int> connects;

    Person()
    {
        connects.reserve(20);
    }
};

// 촌수 구조체
struct Info
{
    int idx = 0;
    int cost = 0;
};

vector<Person> g_people;

// 데이터 입력 및 할당
void inputAndInitData(const int n, const int m)
{
    g_people = vector<Person>(n+1);

    int first, second;
    for(int i = 0; i < m; ++i)
    {
        cin >> first >> second;
        g_people[first].connects.push_back(second);
        g_people[second].connects.push_back(first);
    }
}

// 촌수 계산
int simulate(const int start, const int end)
{
    queue<Info> q;
    q.push({start, 0});
    g_people[start].is_visit = true;

    int result = -1;
    while(q.empty() == false)
    {
        Info cur = q.front();
        q.pop();

        int cost = cur.cost + 1;
        // 다음 것 검사
        for(const int& connect : g_people[cur.idx].connects)
        {
            // 목표에 도달할 시
            if(end == connect)
                return cur.cost + 1;

            // 목표 도달 x시, 다음 것에 이미 도달한 경우가 존재
            if(g_people[connect].is_visit)
                continue;

            g_people[connect].is_visit = true;
            q.push({connect, cost});
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 사람 수 n
    int n;
    cin >> n;

    // 서로 다른 두 사람
    int x, y;
    cin >> x >> y;

    // 관계 개수
    int m;
    cin >> m;

    inputAndInitData(n, m);
    int result = simulate(x, y);
    cout << result << "\n";
}