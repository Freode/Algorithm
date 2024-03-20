// 실버 2 - 2630번 : 색종이 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 예제 입력
    int A, B;
    cin >> A >> B;

    // 초기화
    map<int, int> visit;
    visit[A] = 0;

    queue<int> int_queue;
    int_queue.push(A);

    int current_check = 0;
    while(int_queue.empty() == false)
    {
        for(int i = 0; i < 2; i++)
        {
            current_check = int_queue.front();

            // * 2
            if(i == 0) { current_check *= 2; }
            // * 10 + 1
            else if(i == 1 && current_check < 100000000){ current_check = current_check * 10 + 1; }

            else { continue; }

            if(visit.find(current_check) == visit.end()) { visit[current_check] = 10000000; }
            if(current_check <= B && visit[int_queue.front()] + 1 < visit[current_check])
            {
                visit[current_check] = visit[int_queue.front()] + 1;
                // B보다 작을 때는 큐에 추가
                if(current_check < B) { int_queue.push(current_check); }
            }
        }

        int_queue.pop();
    }

    // 출력
    if(visit.find(B) == visit.end()){ cout << "-1\n"; }
    else { cout << visit[B] + 1 << "\n"; }
}