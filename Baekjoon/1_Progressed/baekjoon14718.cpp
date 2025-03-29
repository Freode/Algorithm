// 골드 4 - 14718번 : 용감한 용사 진수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// N명 병사

// 이기는 조건
// 1. 적 병사보다 진수의 힘이 크거나 같음.
// 2. 적 병사보다 진수의 민첩이 크거나 같음.
// 3. 적 병사보다 진수의 지능이 크거나 같음.

// 최대한 많은 적을 이기는게 목표
// 스탯 포인트 스스로 분배

// 적어도 K명 병사를 이길 수 있게 하는 최소의 스탯 포인트 구하기

// 병사 능력치의 총합을 오름차순으로 나열
// 해당 병사를 이길려면, 해당 병사의 능력치 총합만큼 스탯을 투자해야하기 때문

// 오름차순된 병사 목록 중에서 능력치 별로 최댓값을 구하기

// 총량이 다르더라도, 편차가 적을수록 좋은 것?

struct Stat
{
    int str = 0;
    int dex = 0;
    int inte = 0;
    int total = 0;
    int average = 0;
    int deviation = 0;

    inline void setTotal()
    { 
        total = str + dex + inte;
        average = total / 3;
        deviation = abs(str - average) + abs(dex - average) + abs(inte - average);
    }
};

vector<Stat> g_enemies;

// 적 병사 정보 입력 및 정렬
void inputEnemy(const int N)
{
    g_enemies = vector<Stat>(N);

    for(Stat& enemy : g_enemies)
    {
        cin >> enemy.str >> enemy.dex >> enemy.inte;
        enemy.setTotal();
    }

    // 총합 기준 오름차순
    sort(g_enemies.begin(), g_enemies.end(), [](const Stat& a, const Stat& b)
    {
        // 총합이 다르면, 오름차순
        if(a.total != b. total)
            return a.total < b.total;

        // 총합이 같으면, 평균에 가까운 순서(편차가 적은 순서)로 오름차순 정렬
        return a.deviation < b.deviation;
    });
}

// 능력치 최소 투자 비용 구하기
int search(const int K)
{
    int max_str = 0, max_dex = 0, max_inte = 0;

    for(int i = 0; i < K; i++)
    {
        max_str = max(max_str, g_enemies[i].str);
        max_dex = max(max_dex, g_enemies[i].dex);
        max_inte = max(max_inte, g_enemies[i].inte);
    }

    return max_str + max_dex + max_inte;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 병사 수 N, 용사 K
    int N, K;
    cin >> N >> K;

    // 적 병사 정보 입력 및 정렬
    inputEnemy(N);

    // 능력치 최소 투자 비용 구하기
    int result = search(K);

    // 출력
    cout << result << "\n";
}