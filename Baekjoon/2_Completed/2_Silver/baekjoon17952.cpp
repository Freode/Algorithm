// 실버 3 - 17952번 : 과제는 끝나지 않아!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 과제 정보 구조체
struct Work
{
    int score = 0;
    int remain = 0;

    Work() = default;
    Work(int score, int remain) : score(score), remain(remain){}
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시간 N
    int N;
    cin >> N;

    int result = 0;
    Work prev_work, new_work;
    stack<Work> stack_work;
    int oper;
    for(int i = 0; i < N; i++)
    {
        // 과제 입력 명령어
        cin >> oper;
        // 과제가 새롭게 들어옴
        if(oper == 1)
        {
            cin >> new_work.score >> new_work.remain;

            // 이전에 진행하던 과제가 있으면, 다시 넣기
            if(prev_work.remain != 0){ stack_work.push(prev_work); }
            // 새로운 과제를 현재 수행해야 할 과제로 등록
            prev_work = new_work;
        }
        // 과제 수행
        prev_work.remain--;

        // 만약에 과제 수행한 경우
        if(prev_work.remain == 0)
        {
            result += prev_work.score;

            // 수행할 과제가 남은 경우
            if(stack_work.empty() == false)
            {
                prev_work = stack_work.top();
                stack_work.pop();
            }
        }
    }
    cout << result << "\n";
}