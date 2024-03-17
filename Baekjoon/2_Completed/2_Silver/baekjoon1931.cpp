// 실버 1 - 1931번 : 회의실 배정
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 종료 시간을 기준으로 오름차순 정렬
// 현재 시작할 수 있는 회의를 기준으로 빨리 끝나는 순서대로 실행

// 회의 구조체
struct Conference
{
    int start_time = 0;
    int end_time = 0;

    // 생성자
    Conference(){}
    Conference(int _start_time, int _end_time){ start_time = _start_time; end_time = _end_time; }
};

int main()
{
    // 입력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<Conference> cons(N);
    
    // 회의 시간 입력
    int st, et;
    for(Conference& each : cons)
    {
        cin >> st >> et;
        each.start_time = st;
        each.end_time = et;
    }

    // 회의 종료 시간 오름차순 정렬
    // 회의 종료 시간이 같으면, 시작 시간 오름차순 정렬
    sort(cons.begin(), cons.end(), [](Conference& a, Conference& b)
    {
        if(a.end_time != b.end_time) { return a.end_time < b.end_time; }
        else { return a.start_time < b.start_time; }
    });

    // 최대 회의 개수
    int count = 1;
    Conference& cur_con = cons.front();
    for(int i = 1; i < N; i++)
    {
        if(cur_con.end_time <= cons[i].start_time)
        {
            cur_con = cons[i];
            count++;
        }
    }

    // 출력
    cout << count << "\n";
}