// 골드 5 - 16888번 : 루트 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 완전제곱수 먼저 구하기

const int MAX_SIZE = 1'000'001;

vector<int> g_doubles;
vector<int> g_cases;

void getDouble()
{
    g_doubles.reserve(1'000);

    for(int i = 1; i * i < MAX_SIZE; i++)
    {
        g_doubles.push_back(i * i);
    }
}

void getCases()
{
    g_cases = vector<int>(MAX_SIZE);
    
    for(int i = 0; i < MAX_SIZE; i++)
        g_cases[i] = i;

    for(int num = 1; num < MAX_SIZE; num++)
    {
        for(const int& check : g_doubles)
        {
            // 범위가 넘어가는 경우면, 다음 num으로 이동
            if(num < check)
                break;

            g_cases[num] = min(g_cases[num], g_cases[num - check] + 1);
        }
    }
}

void printResult(const int N)
{
    int result = g_cases[N];

    // 짝수면, 큐브러버가 승
    if(result % 2 == 0)
        cout << "cubelover\n";
    // 홀수면, 구사과가 승
    else
        cout << "koosaga\n";
    
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getDouble();
    getCases();

    // 테스트 케이스 개수 T
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        // 정수 N
        int N;
        cin >> N;

        printResult(N);
    }
}