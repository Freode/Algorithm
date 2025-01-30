// 골드 5 - 1351번 : 무한 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

// 2^10 = 10^3
// 2^40 = 10^12
// 최대로 계산하는 경우의 max -> 약 40번

// 해당 수열에 대한 정보
struct Info
{
    long long first = -1;
    long long second = -1;
    long long value = -1;
    bool b_is_visit = false;

    Info() = default;
    Info(long long first, long long second) : first(first), second(second){}
};

// 수열 연결 정보 입력
void connect(unordered_map<long long, Info> &c_map, set<long long> &c_cases, long long n, long long p, long long q)
{
    // 초기화
    queue<long long> que_seq;
    que_seq.push(n);
    c_map[n].b_is_visit = true;
    c_cases.insert(n);

    // 연결 정보 검사
    while(que_seq.empty() == false)
    {
        long long cur = que_seq.front();

        long long first = cur / p;
        long long second = cur / q;

        // 연결 정보 추가
        c_map[cur].first = first;
        c_map[cur].second = second;

        // 방문하지 않았을 때만 추가
        if(c_map[first].b_is_visit == false)
        {
            c_map[first].b_is_visit = true;
            que_seq.push(first);
            c_cases.insert(first);
        }

        // 이하 동문
        if(c_map[second].b_is_visit == false)
        {
            c_map[second].b_is_visit = true;
            que_seq.push(second);
            c_cases.insert(second);
        }

        que_seq.pop();
    }
}

// 수열 계산
void calcuate(unordered_map<long long, Info> &c_map, set<long long> &c_cases)
{
    // 오름차순으로 검사
    for(const long long& c_case : c_cases)
    {
        // 0인 경우 제외
        if(c_case == 0)
        {
            c_map[0].value = 1;
            continue;
        }

        // 계산
        long long first = c_map[c_case].first;
        long long second = c_map[c_case].second;
        c_map[c_case].value = c_map[first].value + c_map[second].value;
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    long long n, p, q;
    cin >> n >> p >> q;

    unordered_map<long long, Info> c_map;
    set<long long> c_cases;

    // 수열 연결 정보 입력
    connect(c_map, c_cases, n, p, q);

    // 수열 계산
    calcuate(c_map, c_cases);

    // 출력
    cout << c_map[n].value << "\n";
}