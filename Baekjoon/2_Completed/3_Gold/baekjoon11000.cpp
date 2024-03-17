// 골드 5 - 11000번 : 강의실 배정
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 시작 시간으로 오름차순하고 시작 시간이 같다면, 종료 시간 기준으로 오름차순 정렬
// 강의실은 종료 시간을 기준으로 우선 순위를 부여
// 해당 강의실 종료 시간보다 가장 빠른 수업 시작 시간이 이르다면, 모든 강의실를 무시하고 새로운 강의실 추가
// 만약 그렇지 않다면, 해당 강의실에 현재 수업을 새롭게 대입

// 수업 구조체
struct Course
{
    int start_time;
    int end_time;

    // 생성자
    Course(){}
    Course(int _start_time, int _end_time){ start_time = _start_time; end_time = _end_time; }

    // 비교 연산자 
    bool operator<(const Course& other) const
    {
        // 종료 시간이 빠른 것부터 정렬
        return end_time > other.end_time;
    }
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    // 수업 정보 입력
    vector<Course> cour_info(N);
    int st, et;
    for(Course& each : cour_info)
    {
        cin >> st >> et;
        each.start_time = st;
        each.end_time = et;
    }

    // 수업 시간 정렬
    sort(cour_info.begin(), cour_info.end(), [](Course& a, Course& b)
    {
        // 시작 시간이 다르다면, 시작 시간 기준으로 오름차순
        if(a.start_time != b.start_time){ return a.start_time < b.start_time; }
        // 시작 시간이 같으면, 종료 시간 기준으로 오름차순
        else { return a.end_time < b.end_time; }
    });

    // 강의실 정보
    priority_queue<Course> classroom;
    classroom.push(cour_info[0]);
    // 
    for(int i = 1; i < N; i++)
    {
        // 현재 제일 빠르게 끝나는 강의실보다 지금 수업 시작 시간보다 늦을 때
        // 강의실을 하나 추가
        if(cour_info[i].start_time < classroom.top().end_time)
        {
            classroom.push(cour_info[i]);
        }
        // 그렇지 않을 경우
        // 현재 강의실에서 수업 가능하므로, 1개를 빼고 다시 1개 추가
        else
        {
            classroom.pop();
            classroom.push(cour_info[i]);
        }

    }

    // 강의실 개수 출력
    cout << static_cast<int>(classroom.size()) << "\n";
}