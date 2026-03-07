// 골드 3 - 2179번 : 비슷한 단어
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

// N개의 영단어 -> 가장 비슷한 두 단어
// 비슷한 정도 = 두 단어의 접두사 길이

// 최대가 여러 개 : 우선 S가 입력되는 순서대로 제일 앞쪽에 있는 단어 출력
// 그런 경우도 여러 개 : T가 입력되는 순서대로 제일 앞쪽에 있는 단어

// 2 <= N <= 20'000
// 각 줄마다 100자 이하의 서로 다른 영단어 주어짐

// 같은 단어는 제외

// 20'000 * 100 = 2'000'000

vector<string> g_words;
vector<string> g_sort_words;

void initData(const int N)
{
    g_words = vector<string>(N);
    g_sort_words = vector<string>(N);

    for(int i = 0; i < N; i++)
    {
        cin >> g_words[i];
        g_sort_words[i] = g_words[i];
    }
}

int getSameCount(const string& a, const string& b)
{
    int len = min(a.size(), b.size());
    int cnt = 0;

    for(int i = 0; i < len; i++)
    {
        if(a[i] != b[i]) 
            break;
        cnt++;
    }

    return cnt;
}

void simulate(const int N)
{
    sort(g_sort_words.begin(), g_sort_words.end());

    int cnt = 0;
    for(int i = 0; i < N - 1; i++)
        cnt = max(cnt, getSameCount(g_sort_words[i], g_sort_words[i + 1]));

    string S, T;
    bool is_found = false;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(getSameCount(g_words[i], g_words[j]) != cnt)
                continue;

            S = g_words[i];
            T = g_words[j];
            is_found = true;
            break;
        }

        if(is_found)
            break;
    }

    cout << S << "\n" << T << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 단어 개수 N
    int N;
    cin >> N;

    initData(N);
    simulate(N);

}