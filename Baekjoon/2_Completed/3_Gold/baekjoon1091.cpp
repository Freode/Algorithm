// 골드 4 - 1091번 : 카드 섞기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 3명 플레이어 (0,1,2)
// N개 카드 (0~N-1)

// 0번째 카드 -> P0
// 1번째 카드 -> P1
// 2번째 카드 -> P2
// 3번째 카드 -> P3

// 길이 N, 수열 S
// 카드 한번 섞기 : i 번째 위치 카드 -> S[i]번째 위치로 이동
// 각 카드 -> 어떤 플레이어에게 가야 하는지에 대한 정보는 길이가 N인 수열 P

// 맨 처음 i번 째 위치 카드 -> P[i]에게 보내야 함.
// 목적 달성을 위한 카드 섞는 횟수의 최솟값 구하기

// N : 3~48 -> 3의 배수
// P -> 0,1,2 중 하나
// S -> 모두 N-1보다 작거나 같은 자연수 또는 0, 중복 x

// 3
// 2 0 1 P
// 1 2 0 S

// 0번 카드 -> P2
// 1번 카드 -> P0
// 2번 카드 -> P1

// 0 1 2 (시작)
// 2 0 1 (1)
// 1 2 0 (2)

vector<int> g_S;
vector<int> g_P;
vector<int> g_cur;
unordered_map<string, bool> g_visited;

void inputData(const int N)
{
    g_S = vector<int>(N);
    g_P = vector<int>(N);

    for(int& P : g_P)
        cin >> P;

    for(int& S : g_S)
        cin >> S;
}

// 목표에 도달했는지 비교
bool isTarget(const int N)
{
    for(int i = 0; i < N; i++)
    {
        // 현재 i번째에 있는 카드가 목표에 있는 정보와 일치하는지 확인
        if(g_P[g_cur[i]] != (i % 3))
            return false;
    }

    return true;
}

// 계속 반복하고 있는지 확인
// 처음이 아니더라도 이미 검사한 것과 같을 경우
bool isRepeat(const int N)
{
    string check = "";
    for(int i = 0; i < N; i++)
        check += to_string(g_cur[i]);
    
    // 이미 방문
    if(g_visited[check])
        return true;

    g_visited[check] = true;
    return false;
}

int simulate(const int N)
{
    g_cur = vector<int>(N);

    for(int i = 0; i < N; i++)
        g_cur[i] = i;

    int result = 0;
    vector<int> tmp = vector<int>(N);

    while(true)
    {
        // 계속 반복하고 있는지 확인
        if(result != 0 && isRepeat(N))
            return -1;

        // 목표에 도달했는지 확인
        if(isTarget(N))
            break;

        // 카드 섞기
        for(int i = 0; i < N; i++)
            tmp[g_S[i]] = g_cur[i];
        
        g_cur = tmp;
        
        result++;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수열 길이 N
    int N;
    cin >> N;

    inputData(N);
    cout << simulate(N) << "\n";
}