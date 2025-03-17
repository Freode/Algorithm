// 실버 1 - 20923번 : 숫자 할리갈리 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// 턴 : 도도(게임1회) -> 수연(게임1회) -> 반복..

// 종치기
// 1. 도도 : 가장 위에 위치한 숫자 5가 나오는 순간(도도 차례에서도 가능)
// 2. 수연 : 카드 합이 5가 되는 순간(단, 어느 쪽의 그라운드도 비면 안됨)
// 종치기는 진행 순서에 영향 x
// 카드 뒤집어서 넣기 -> 제일 밑에 있는거를 제일 위로해서 자신의 덱 밑에 합치기

// 승리 조건
// 1. 카드 개수 0개 -> 상대방 승리 -> 종치기 조건 만족해도, 카드 개수 0개면 끝
// 2. M 번 진행 후, 덱에 카드가 더 많은 사람
// 3. M 번 진행 후, 덱에 카드 개수 동일 : 무승부

enum State
{
    NONE,
    DODO,
    SU,
    DRAW
};

// 그라운드를 덱에 넣기
void clearGround(deque<int> &deq, deque<int> &ground)
{
    while(ground.empty() == false)
    {
        deq.push_front(ground.front());
        ground.pop_front();
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 카드 개수 N, 진행 횟수 M;
    int N, M;
    cin >> N >> M;

    // 카드 입력
    deque<int> deq_do;
    deque<int> deq_su;
    int input_do, input_su;
    for(int i = 0; i < N; i++)
    {
        cin >> input_do >> input_su;
        deq_do.push_back(input_do);
        deq_su.push_back(input_su);
    }

    // 게임 진행
    bool b_do_turn = true;
    deque<int> ground_do;
    deque<int> ground_su;

    State state = State::NONE;
    for(int i = 0; i < M; i++)
    {
        // 도도 차례
        if(b_do_turn)
        {
            int top = deq_do.back();
            deq_do.pop_back();
            ground_do.push_back(top);
            b_do_turn = false;
        }
        // 수연 차례
        else
        {
            int top = deq_su.back();
            deq_su.pop_back();
            ground_su.push_back(top);
            b_do_turn = true;
        }

        // 1. 덱이 없는지 확인
        if(deq_do.size() == 0) 
        {
            state = State::SU;
            break;
        }
        else if(deq_su.size() == 0) 
        {
            state = State::DODO;
            break;
        }

        // 가장 높은 수 확인
        int top_do = 0, top_su = 0;
        if(ground_do.size() != 0) top_do = ground_do.back();
        if(ground_su.size() != 0) top_su = ground_su.back();

        // 2. 도도 - 종치기 가능한지 확인
        if(top_do == 5 || top_su == 5)
        {
            // 상대방 그라운드 넣기
            clearGround(deq_do, ground_su);
            // 본인 그라운드 넣기
            clearGround(deq_do, ground_do);
        }

        // 3. 수연 - 종치기 가능한지 확인
        if(top_do != 0 && top_su != 0 && top_do + top_su == 5)
        {
            // 상대방 그라운드 넣기
            clearGround(deq_su, ground_do);
            // 본인 그라운드 넣기
            clearGround(deq_su, ground_su);
        }
    }

    // 게임 진행 완료 후, 판단
    if(state == State::NONE)
    {
        if(deq_do.size() == deq_su.size()) state = State::DRAW;
        else if(deq_do.size() > deq_su.size()) state = State::DODO;
        else state = State::SU;
    }

    // 게임 결과 출력
    switch (state)
    {
    case State::DODO:
        cout << "do\n";
        break;
    case State::SU:
        cout << "su\n";
        break;
    case State::DRAW:
        cout << "dosu\n";
        break;
    }
}