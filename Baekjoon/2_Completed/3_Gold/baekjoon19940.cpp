// 골드 5 - 19940번 : 피자 오븐
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 60, 10, 1로 나누는 수로 비교해서 하는 방법도 있긴할 듯?

const int MAX = 61;

struct Num
{
    vector<int> kinds = vector<int>(5, 1'000);

    int getTotal()
    {
        int result = 0;
        for(const int& kind :kinds)
            result += kind;

        return result;
    }

    bool operator<(const Num& other) const
    {
        for(int i = 0; i < 5; i++)
        {
            if(kinds[i] != other.kinds[i])
            {
                // 기존이 더 작은 경우
                return kinds[i] < other.kinds[i];
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, const Num& num)
    {
        for(const int& each : num.kinds)
        {
            os << each << " ";
        }

        return os;
    }
};

vector<Num> g_cases(MAX);

int di[] = {60, 10, -10, 1, -1};

// 모든 수에 대해서 미리 탐색하기
void search(const int start)
{
    queue<int> q;
    q.push(start);
    g_cases[start].kinds[0] = (start / 60);
    for(int i = 1; i < 5; i++)
        g_cases[start].kinds[i] = 0;

    while(q.empty() == false)
    {
        int idx = q.front();
        Num cur;
        q.pop();
        for(int i = 0; i < 5; i++)
        {
            int nextI = idx + di[i];
            cur = g_cases[idx];
            cur.kinds[i]++;

            // 범위 벗어난 경우, 무시
            if((nextI >= 0 && nextI < MAX) == false)
                continue;

            // 더 클 경우는 무시
            if(cur.getTotal() > g_cases[nextI].getTotal())
                continue;

            // 같은 경우
            else if(cur.getTotal() == g_cases[nextI].getTotal())
            {
                // 우선 순위 비교 -> 새로운 방법이 더 작은 경우
                if(cur < g_cases[nextI])
                    g_cases[nextI] = cur;

                else
                    continue;
            }

            // 더 작은 경우
            else
                g_cases[nextI] = cur;

            q.push(nextI);
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    search(0);
    for(int i = 0; i < T; i++)
    {
        // 시간 입력 N
        int N;
        cin >> N;

        Num cur = g_cases[N % 60];
        cur.kinds[0] += (N / 60);

        cout << cur << "\n";
    }
}