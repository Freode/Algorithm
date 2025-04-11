// 골드 3 - 1954번 : 화학실험
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 현재 상태 기준으로 가장 총량이 작은 용액에 1ml씩 추가
// 주어진 모든 용액을 사용해야 함.

// 제일 처음 용액에 모든 시액을 다 붓기
// 가장 큰 것에서 가장 작은 것으로 하나씩 옮기기

// 현재 용액 상태
struct Liquid
{
    int idx;
    int total;

    // 총량 기준 우선순위 큐에서 오름차순
    bool operator<(const Liquid& other) const
    {
        return total > other.total;
    }
};

// 용액의 성질
struct Property
{
    int x;
    int b;
    int total = 0;
};

vector<Property> g_infoes;
priority_queue<Liquid> g_pq;

// 시약 종류 입력 및 설정
void input(const int n)
{
    g_infoes = vector<Property>(n);

    for(int i = 0; i < n; i++)
    {
        cin >> g_infoes[i].x >> g_infoes[i].b;
        g_infoes[i].total = g_infoes[i].b;

        g_pq.push({i, g_infoes[i].b});
    }
}

// 용액의 양이 모두 같은지 확인
bool allLiquidsEqual()
{
    bool b_equal = true;
    int base = g_infoes[0].total;
    cout << "base : " << base << "\n";
    for(int idx = 1; idx < g_infoes.size(); idx++)
    {
        cout << "idx : " << idx << ", total : " << g_infoes[idx].total << "\n";
        // 다른 경우는 바로 다르다고 출력
        if(base != g_infoes[idx].total)
        {
            b_equal = false;
            // break;
        }
    }

    return b_equal;
}

// 용액량이 모두 같은지 확인
int simulate(const int m)
{
    int use = 0;

    // 용액 사용
    while(use < m)
    {   
        Liquid liquid = g_pq.top();
        g_pq.pop();

        // 용액 추가 대입
        liquid.total += g_infoes[liquid.idx].x;
        g_infoes[liquid.idx].total = liquid.total;
        g_pq.push(liquid);

        cout << "==========\nuse : " << use + 1 << "\n";
        for(int i = 0; i < g_infoes.size(); i++)
        {
            cout << "i : " << i << ", total : " << g_infoes[i].total << "\n";
        }

        use++;
    }

    return allLiquidsEqual() ? g_infoes[0].total : 0;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시약 종류 n
    int n;
    cin >> n;

    // 시약 종류 입력
    input(n);

    // 용액 총량
    int m;
    cin >> m;

    // 시뮬레이션 시작
    int result = simulate(m);
    cout << result << "\n";
}