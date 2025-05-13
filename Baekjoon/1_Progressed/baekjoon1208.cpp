// 골드 1 - 1208번 : 부분수열의 합 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// N 1~40
// S -1'000'000 ~ 1'000'000

// 수 정렬 + 개수 누적

// -5 -4 -3 -2 -1 0 1 2 3 4 5

// -1

// 0 < -1
// 0 -1(-1) == -1
// 

// -5 -3 3 5
// 0

struct Num
{
    int num = 0;
    int count = 0;
};

vector<Num> g_nums;
map<int, int> g_front;
map<int, int> g_back;

void combine(const int N, const int idx, const int num)
{
    
}

void inputData(const int N)
{
    // 같은 값 개수로 누적 + 수 정렬
    map<int, int> save;
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        save[num]++;
    }

    for(auto each : save)
    {
        g_nums.push_back({each.first, each.second});
    }
}

int find(const int S)
{
    int left = 0, right = g_nums.size();
    int mid;

    while(left + 1 < right)
    {
        mid = (left + right) >> 1;

        if(g_nums[mid].num == S)
            return mid;

        else if(g_nums[mid].num < S)
            left = mid;

        else
            right = mid;
    }

    return right;
}

int simulate(const int S)
{
    int result = 0;

    // 시작할 지점 찾기
    int start = find(S);
    int end = start;

    int each = g_nums[start].count;
    int sum = g_nums[start].num;
    while(start >= 0 && end < g_nums.size())
    {
        if(sum == S)
        {
            result += each;

        }
        else if(sum < S)
        {

        }
        else
        {

        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 개수 N, 목표 S
    int N, S;
    cin >> N >> S;

    inputData(N);
    int result = simulate(S);

    cout << result << "\n";
}