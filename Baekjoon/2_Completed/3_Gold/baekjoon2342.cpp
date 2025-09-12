// 골드 3 - 2342번 : Dance Dance Revolution
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

// 1 : 같은 지점 누르기
// 2 : 중앙에서 인접한 지점으로 움직일 때
// 3 : 다른 지점에서 인접한 지점으로 움직일 때
// 4 : 반대편으로 움직일 때

// [순서][왼발 위치][오른발 위치]

const int MAX_VALUE = numeric_limits<int>::max() >> 2;

vector<int> g_datas;
vector<vector<vector<int>>> g_dps;

void initAndInputData()
{
    g_datas.reserve(100'002);
    g_datas.push_back(0);

    int input;
    while(true)
    {
        cin >> input;
        if(input == 0)
            break;

        g_datas.push_back(input);
    }

    g_dps = vector<vector<vector<int>>>(g_datas.size(), vector<vector<int>>(5, vector<int>(5, MAX_VALUE)));
}

// 각 발의 이동 비용을 반환
int moveCost(const int start, const int end)
{
    // 1 : 같은 지점 누르기
    if(start == end)
        return 1;
    // 2 : 중앙에서 인접한 지점으로 움직일 때
    if(start == 0)
        return 2;
    // 3 : 다른 지점에서 인접한 지점으로 움직일 때
    if(abs(start - end) != 2)
        return 3;
    // 4 : 반대편으로 움직일 때
    return 4;
}

void simulate()
{
    int size = g_datas.size();
    // 양발이 정중앙에 존재
    g_dps[0][0][0] = 0;
    
    for(int seq = 1; seq < size; seq++)
    {
        // 각 발의 위치를 확인하기

        // 현재 순서에서 각 발을 옮기기

        // 이동 거리 확인
        for(int left = 0; left < 5; left++)
        {
            for(int right = 0; right < 5; right++)
            {
                // 이전 경우가 없는 경우는 무시
                if(g_dps[seq-1][left][right] == MAX_VALUE)
                    continue;
                
                int next = g_datas[seq];

                // 왼발 옮기기
                int cost = moveCost(left, g_datas[seq]);
                g_dps[seq][next][right] = min(g_dps[seq][next][right], g_dps[seq-1][left][right] + cost);

                // 오른발 옮기기
                cost = moveCost(right, g_datas[seq]);
                g_dps[seq][left][next] = min(g_dps[seq][left][next], g_dps[seq-1][left][right] + cost);
            }
        }
    }
}

int getResult()
{
    int lastIdx = g_datas.size() - 1;

    int result = MAX_VALUE;
    for(int left = 0; left < 5; left++)
    {
        for(int right = 0; right < 5; right++)
        {
            result = min(result, g_dps[lastIdx][left][right]);
        }
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initAndInputData();
    simulate();
    cout << getResult() << "\n";
}