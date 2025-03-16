// 실버 1 - 11286번 : 절댓값 힙
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Num
{
    int num;
    Num() : num(0){}
    Num(int num) : num(num) {}

    bool operator<(const Num& other) const
    {
        // 절댓값이 더 작은 순으로 정렬
        if(abs(num) != abs(other.num))
        {
            return abs(num) > abs(other.num);
        }

        // 절댓값이 같으면, 음수부터 정렬
        return num > other.num;
    }
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 연산 개수 N
    int N;
    cin >> N;

    // 연산 입력
    priority_queue<Num> pq;
    int oper;
    for(int i = 0; i < N; i++)
    {
        cin >> oper;

        // 0일 경우, 기준에 따라 절댓값이 가장 작거나, 같으면 음수부터 제거해서 출력
        if(oper == 0)
        {
            // 비어 있는 경우
            if(pq.empty())
            {
                cout << "0\n";
            }
            // 비어 있지 않음.
            else
            {
                cout << pq.top().num << "\n";
                pq.pop();
            }
        }
        // 0이 아니면, 추가
        else { pq.push(Num(oper)); }
    }
}