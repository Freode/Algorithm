// 골드 3 - 2109번 : 순회강연
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 강연 정보 구조체
struct Course
{
    int value = 0;
    int in_day = 0;
    Course(){}
    Course(int _value, int _in_day){ value = _value; in_day = _in_day; }
};

// d일이 많은 것부터 내림차순
// 기한이 가장 많은 강연일부터 시작해서 1일차 강연까지 뒤로 내려가기.
// 현재 검사하는 강연일에 강연할 수 있는 강의가 존재할 경우
// 강연 가능 목록 중에서 가장 강의료가 비싼 것을 선택

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    // 0 입력 시, 0을 출력하고 바로 끝냄.
    if(n == 0){ cout << "0\n"; return 0; }

    // 강연 정보 입력
    vector<Course> courses(n);
    for(Course& course : courses){ cin >> course.value >> course.in_day; }

    // 강연 일을 기준으로 내림차순
    sort(courses.begin(), courses.end(), [](Course a, Course b)
    {
        return a.in_day > b.in_day;
    });

    //
    priority_queue<int> cour_value;
    int start_idx = 0;
    int sum_value = 0;
    // 1일씩 차감
    for(int i = courses[0].in_day; i >= 1; i--)
    {
        // 강의에 대한 기한과 검사하는 기한이 같을 때
        if(start_idx < n && courses[start_idx].in_day == i)
        {
            // 강의에 대한 기한이 같은 강의료를 모두 추가
            while(start_idx < n && courses[start_idx].in_day == i)
            {
                cour_value.push(courses[start_idx].value);
                start_idx++;
            }
        }

        // 현재 진행할 수 있는 강의가 있으면, 강의 목록 중에 가장 값이 높은 것을 진행
        if(cour_value.empty() == false)
        {
            sum_value += cour_value.top();
            cour_value.pop();
        }
    }
    // 출력
    cout << sum_value << "\n";
}