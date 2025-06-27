// 실버 5 - 10814번 : 나이순 정렬
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Info
{
    int age = 0;
    string name = "";
    int seq = 0;
};

vector<Info> g_infoes;

void inputData(const int N)
{
    g_infoes = vector<Info>(N);

    for(int i = 0; i < N; i++)
    {
        cin >> g_infoes[i].age >> g_infoes[i].name;
        g_infoes[i].seq = i + 1;
    }
}

void sortData()
{
    sort(g_infoes.begin(), g_infoes.end(), [](const Info& A, const Info& B)
    {
        // 나이가 다른 경우, 나이 오름차순으로 정렬
        if(A.age != B.age)
            return A.age < B.age;
        
        // 나이가 같은 경우, 등록 순으로 정렬
        return A.seq < B.seq;
    });
}

void printData()
{
    for(const Info& info : g_infoes)
    {
        cout << info.age << " " << info.name << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 회원 수 N
    int N;
    cin >> N;

    inputData(N);
    sortData();
    printData();
}