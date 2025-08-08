// 골드 1 - 1509번 : 팰린드롬 분할
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max() >> 2;

vector<vector<bool>> g_checks;
vector<vector<int>> g_results;
vector<vector<int>> g_mins;

// g_results[idx][dist]

void simulate(const string& input)
{
    int size = input.size();
    g_checks = vector<vector<bool>>(size, vector<bool>(size, false));
    g_results = vector<vector<int>>(size, vector<int>(size, MAX_VALUE));
    g_mins = vector<vector<int>>(size, vector<int>(size, MAX_VALUE));
    g_results[0][0] = 1;
    
    for(int dist = 0; dist < size; dist++)
    {
        for(int start = 0; start + dist < size; start++)
        {
            int end = start + dist;
            // 조건 1. input[start] == input[end]
            if(input[start] != input[end])
                continue;

            // 조건 2. checks[start+1][end-1] == true
            if((start + 1 <= end - 1) == true)
            {
                if(g_checks[start+1][end-1] == false)
                    continue;
            }

            //cout << start << " " << end << "\n";
            g_checks[start][end] = true;
        }
    }
}

int getResult()
{
    int size = g_mins.size();

    // g_mins[i][0] : 안 쓴 경우
    // g_mins[i][1] : 사용한 경우
    for(int i = 0; i < size; i++)
    {
        g_mins[i][0] = i + 1;
        g_mins[i][1] = i + 1;
    }

    for(int end = 0; end < size; end++)
    {
        for(int dist = 1; dist <= end; dist++)
        {
            int start = end - dist;

            // 앞 부분과 합치는 경우가 더 작은지 확인
            if(g_checks[start][end] == true)
                g_mins[end][1] = min(g_mins[end][1], g_mins[start][0]);

            // 바로 앞에서 독립적으로 가는 경우가 더 작은지 확인
            if(end - 1 >= 0)
            {
                g_mins[end][0] = min(g_mins[end][0], g_mins[end - 1][1] + 1);
                g_mins[end][0] = min(g_mins[end][0], g_mins[end - 1][0] + 1);
            }
        }
    }

    // for(const int& each : g_mins)
    //     cout << each << " ";
    // cout << "\n";

    return min(g_mins[size - 1][0], g_mins[size - 1][1]);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 문자열 입력
    string input;
    cin >> input;

    simulate(input);
    cout << getResult() << "\n";
}