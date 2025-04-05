// 플레티넘 5 - 17071번 : 숨바꼭질 5
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// BFS

// 동생이 n초에 도달하는 위치를 미리 기록

// 수빈이가 특정 위치에 몇 초에 도착하는지 기록
// 동생과 도착 시간이 다를 때, [수빈 도착 시간 < 동생 도착 시간] 이라면,
// 동생 도착 시간 - 수빈 도착 시간 = 짝수일 때, 만나는게 가능
// 수빈 +1-1 반복해서 해당 위치에 도달할 수 있음.

// 해당 위치에 짝수 번에 도달할 때와 홀수 번에서 도달하는 경우가 나눠져 있음.

const int MAX_VALUE = numeric_limits<int>::max();

struct Loc
{
    int x;
    int time;
};

vector<int> g_br_locs;
vector<vector<int>> g_me_locs;

// 동생 위치 찾기
void findBrotherLocations(const int K)
{
    // (1000+1)*500 -> 500'500 -> 50만 이상이므로 1001까지만 처리
    g_br_locs.reserve(1001);
    g_br_locs.push_back(K);

    for(int i = 1; i <= 1000; i++)
    {
        int loc = g_br_locs[i-1] + i;

        // 범위 벗어나는 경우는 무시
        if(loc > 500'000)
            break;

        g_br_locs.push_back(loc);
    }
}

// 본인 위치 찾기
void findMeLocation(const int N)
{
    // [0][위치] : 짝수 번째에 도착하는 가장 빠른 경우
    // [1][위치] : 홀수 번째에 도착하는 가장 빠른 경우
    g_me_locs = vector<vector<int>>(2, vector<int>(500'001, 0));

    queue<Loc> q;
    q.push({N, 0});
    g_me_locs[0][N] = 1;

    while(q.empty() == false)
    {
        const Loc loc = q.front();
        q.pop();

        // 이동
        int nextSeq = (loc.time + 1) % 2;
        for(int i = 0; i < 3; i++)
        {
            int nextLoc = loc.x;
            if(i == 0) nextLoc *= 2;
            else if(i == 1) nextLoc++;
            else nextLoc--;

            // 범위를 벗어나는 경우는 무시
            if((nextLoc >= 0 && nextLoc <= 500'000) == false)
                continue;

            // 이전에 방문한 경우는 무시
            if(g_me_locs[nextSeq][nextLoc] != 0)
                continue;

            // 방문하지 않은 경우에는 진행
            g_me_locs[nextSeq][nextLoc] = g_me_locs[loc.time % 2][loc.x] + 1;
            q.push({nextLoc, nextSeq});
        }
    }
}

// 비교하기
int compareLocs()
{
    int result = MAX_VALUE;
    // 동생 위치와 비교
    for(int seq = 0; seq < 2; seq++)
    {
        for(int time = 0; time < g_br_locs.size(); time++)
        {
            int term = time - (g_me_locs[seq][g_br_locs[time]] - 1);
            //cout << "time : " << time << ", br loc : " << g_br_locs[time] << ", me dest time : " << g_me_locs[g_br_locs[time]] - 1 << ", term : " << term << "\n";
            // 수진이가 먼저 또는 동시에 도착해야 함.
            // 그래서, 항상 0 이상의 자연수가 나와야 함.
            if(term >= 0 && term % 2 == 0)
                result = min(result, time);
        }
    }

    // 동생에게 도달하지 못하는 경우
    if(result == MAX_VALUE)
        result = -1;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수빈 위치 N, 동생 위치 K
    int K, N;
    cin >> N >> K;

    findBrotherLocations(K);
    findMeLocation(N);

    int result = compareLocs();
    cout << result << "\n";
}