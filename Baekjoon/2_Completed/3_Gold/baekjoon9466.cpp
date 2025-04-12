// 골드 3 - 9466번 : 텀 프로젝트
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 프로젝트 팀원 수 제한 x
// 한 팀만 존재 가능
// 모든 학생 -> 프로젝트 함꼐하고 싶은 학생 선택 (한 명만 선택 가능)
// 혼자하고 싶은 학생 -> 자기 자신

// s1->s2, s2->s3, s3->..s(r-1)->sr, sr->s1 한 팀 가능

// ex)
// 1 2 3 4 5 6 7
// 3 1 3 7 3 4 6

// 1->3 : 팀x
// 2->1 : 팀x
// 3->3 : 한 팀
// 4->7->6->4 (4,7,6) 순환 : 한 팀
// 5->3 : 팀x

// start : idx
// start로 다시 돌아오지 않는다면, 팀x
// 중간에 다른 곳 순회에 빠진다는 것을 어떻게 판단??
// visited로 판단? -> 방문 기록을 vector로 stack처럼 관리

enum Search : int
{
    NOT_SEARCH = 0,
    TEAM,
    NOT_TEAM, 
};

vector<int> g_wants;
vector<int> g_visited;
vector<int> g_seq;
vector<int> g_teams;

void init()
{
    g_wants = vector<int>(100'001);
    g_visited = vector<int>(100'001);
    g_seq = vector<int>(100'001);
    g_teams = vector<int>(100'001, NOT_SEARCH);
}

// 팀 정보 초기화
void resetTeams(const int n)
{
    for(int i = 1; i <= n; i++)
        g_teams[i] = false;
}

// 학생 정보 입력
void inputInfo(const int n)
{
    resetTeams(n);
    for(int i = 1; i <= n; i++)
        cin >> g_wants[i];
}

void simulate(const int start)
{
    int count = 1;
    g_visited[start] = 1;
    g_seq[0] = start;

    int idx = g_wants[start];
    bool b_state = false;
    while(true)
    {
        // 이미 판단된 곳이 나오면, 무조건 팀이 아님
        if(g_teams[idx] != NOT_SEARCH)
        {
            b_state = true;
            break;
        }
        // 방문했다고 설정
        g_visited[idx]++;
        g_seq[count] = idx;
        count++;
        // 이미 중복 방문한 경우면, 빠져나오기
        if(g_visited[idx] == 2)
            break;
        
        // 다음으로 이동
        idx = g_wants[idx];
    }

    // 방문 기록 초기화
    for(int i = count-1; i >= 0; i--)
    {
        // 이미 판단된 곳이 나왔으므로 스택에 있는 모든 방문지는 팀을 구성할 수 없음
        if(b_state)
        {
            g_teams[g_seq[i]] = NOT_TEAM;
            g_visited[g_seq[i]]--;
            continue;
        }

        // 이미 방문한 곳이 start와 같으면, 팀을 이룸
        if(idx == start)
            g_teams[g_seq[i]] = TEAM;

        // 팀이 아닐 경우
        // 중복 방문한 idx를 x라고 하면,
        // 1. x의 방문횟수가 1이 될 때까지, TEAM으로 판단
        // 2. 그 이후부터는 NOT_TEAM으로 판단 가능
        else
        {
            if(g_visited[idx] >= 1)
                g_teams[g_seq[i]] = TEAM;

            else
                g_teams[g_seq[i]] = NOT_TEAM;
        }
        g_visited[g_seq[i]]--;
    }
}

// 모든 번호에 대해서 서칭
void allSearch(const int n)
{
    for(int i = 1; i <= n; i++)
    {
        // 이미 팀의 유무가 판정난 경우는 무시
        if(g_teams[i] == TEAM || g_teams[i] == NOT_TEAM)
            continue;

        simulate(i);
    }
}

// 팀을 이루지 못한 인원 찾기
int notTeam(const int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        count = (g_teams[i] == NOT_TEAM) ? count + 1 : count;
    }
    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    init();

    for(int i = 0; i < T; i++)
    {
        // 학생 수 n
        int n;
        cin >> n;

        inputInfo(n);

        allSearch(n);

        int result = notTeam(n);
        cout << result << "\n";
    }
}