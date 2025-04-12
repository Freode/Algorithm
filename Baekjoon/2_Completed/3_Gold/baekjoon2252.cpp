// 골드 3 - 2252번 : 줄 세우기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Student
{
    int count = 0;
    vector<int> seqs;

    Student()
    {
        seqs.reserve(100);
    }
};

vector<Student> g_students;
vector<int> g_results;

// 학생 키 순서 정보 입력
void inputInfo(const int N, const int M)
{
    g_students = vector<Student>(N+1);

    int prev, next;
    for(int i = 0; i < M; i++)
    {
        cin >> prev >> next;

        g_students[prev].seqs.push_back(next);
        g_students[next].count++;
    }
}

void simulate(const int N)
{
    g_results.reserve(N);
    queue<int> q;

    // 순서 상관 없는 학생부터 입력
    for(int i = 1; i <= N; i++)
    {
        if(g_students[i].count == 0)
        {
            g_results.push_back(i);
            q.push(i);
        }
    }

    while(q.empty() == false)
    {
        int idx = q.front();
        q.pop();

        // 다음 순서로 오는 학생들 검사
        for(const int& each : g_students[idx].seqs)
        {
            g_students[each].count--;

            // 추가
            if(g_students[each].count == 0)
            {
                q.push(each);
                g_results.push_back(each);
            }
        }
    }
}

void printResult(const int N)
{
    for(const int& each : g_results)
        cout << each << " ";
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 학생 수 N (1~32'000)
    // 키 순서 M (1~100'000)
    int N, M;
    cin >> N >> M;

    inputInfo(N, M);
    simulate(N);
    printResult(N);
}