// 골드 3 - 1248번 : Guess
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// n 행의 개수 : 1~10
// 각 요소 : -10~10 -> 21^10
// -> +-로 판단 -> 10^10

vector<vector<char>> g_data;
vector<int> g_result;

void inputData(const int n)
{
    g_data = vector<vector<char>>(n, vector<char>(n, ' '));
    g_result = vector<int>(n);

    string input;
    cin >> input;

    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            g_data[i][j] = input[idx];
            idx++;
        }
    }
}

bool check(const int idx)
{
    // 행
    for(int i = 0; i < idx; i++)
    { 
        // idx 열만 검사
        int sum = 0;

        for(int cur = i; cur <= idx; cur++)
        {
            sum += g_result[cur];
        }

        // 결과 양수
        if(g_data[i][idx] == '+')
        {
            if(sum <= 0)
                return false;
        }
        // 결과 음수
        else if(g_data[i][idx] == '-')
        {
            if(sum >= 0)
                return false;
        }
        // 결과 0
        else
        {
            if(sum != 0)
                return false;
        }
    }

    return true;
}

bool simulate(const int n, const int idx)
{
    // 끝에 도달 -> 정답을 찾음
    if(n == idx)
        return true;

    // 1. 본인 수를 확인

    // 양수
    if(g_data[idx][idx] == '+')
    {
        for(int i = 1; i <= 10; i++)
        {
            g_result[idx] = i;
            if(check(idx) == false)
                continue;

            if(simulate(n, idx+1))
                return true;
        }
    }
    // 음수
    else if(g_data[idx][idx] == '-')
    {
        for(int i = -10; i <= -1; i++)
        {
            g_result[idx] = i;
            if(check(idx) == false)
                continue;

            if(simulate(n, idx+1))
                return true;
        }
    }
    // 0
    else
    {
        g_result[idx] = 0;
        if(check(idx) == false)
            return false;

        if(simulate(n, idx+1))
            return true;
    }

    return false;
}

void printResult()
{
    for(const int& each : g_result)
        cout << each << " ";
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 행의 개수 n
    int n;
    cin >> n;

    inputData(n);
    simulate(n, 0);
    printResult();
}