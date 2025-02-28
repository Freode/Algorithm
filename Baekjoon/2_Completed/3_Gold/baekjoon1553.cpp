// 골드 5 - 1553번 : 도미노 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 도미노 번호 저장소
unordered_map<string, int> num_db;

// 이동 방향
int dy[] = {1, 0};
int dx[] = {0, 1};
 
// 배열 길이
const int len_y = 8;
const int len_x = 7;

// 입력 숫자를 문자열로 만들어서 반환
string NumToString(int i, int j)
{
    return to_string(i) + to_string(j);
}

// 배열에서 사용할 숫자 정보를 미리 저장 
int SaveNumbers()
{
    int count = 0;
    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            string num = NumToString(i,j);
            num_db[num] = count;
            count++;
        }
    }
    return count;
}

// 맵 입력
void InputMap(vector<vector<int>> &in_maps)
{
    string input;
    for(int i = 0; i < len_y; i++)
    {
        cin >> input;
        for(int j = 0; j < len_x; j++)
        {
            in_maps[i][j] = input[j] - '0';
        }
    }
}

int FindDomino(string &in_nums)
{
    return num_db[in_nums];
}

// 현재 도미노를 사용할 수 있는지 확인
bool CanUse(string &in_nums, vector<bool> &in_use)
{
    return static_cast<bool>(in_use[FindDomino(in_nums)]) == false;
}

// 방문했는지 확인
bool IsVisit(vector<vector<bool>> &in_visits, const int &y, int const &x)
{
    return in_visits[y][x];
}

// 범위 안에 존재하는지 확인
bool IsInBoard(const int &y, const int &x)
{
    return y >= 0 && x >= 0 && y < len_y && x < len_x;
}

// 탐색
int Search(vector<vector<int>>& in_maps, vector<vector<bool>>& in_visits, vector<bool>& in_use, int y, int x)
{
    int result = 0;
    int next_y = y, next_x = x;

    // y가 8이라면, 모든 목표에 달성했다고 가정
    if(y == len_y) return 1;

    // 오른쪽 끝에 도달하는 경우, 다음 줄의 첫 번째로 이동
    if(x == len_x)
    {
        return Search(in_maps, in_visits, in_use, next_y + 1, 0);
    }

    // 현재 점을 방문 했는지 확인
    if(IsVisit(in_visits, next_y, next_x))
    {
        // 방문했으면, 옆으로 이동
        return Search(in_maps, in_visits, in_use, next_y, next_x + 1);
    }

    // 현재 점을 방문하지 않았을 때는 도미노 놓기 시도
    for(int i = 0; i < 2; i++)
    {
        int check_y = next_y + dy[i];
        int check_x = next_x + dx[i];

        // 범위 안일 때만 진행
        if(IsInBoard(check_y, check_x) == false) continue;
        // 이미 방문한 곳이면, 무시
        if(IsVisit(in_visits, check_y, check_x)) continue;

        // 사용한 도미노인지 확인
        int domino_s = min(in_maps[next_y][next_x], in_maps[check_y][check_x]);
        int domino_l = max(in_maps[next_y][next_x], in_maps[check_y][check_x]);
        
        string domino = NumToString(domino_s, domino_l);
        if(CanUse(domino, in_use))
        {
            // 해당 도미노 사용
            in_use[FindDomino(domino)] = true;
            in_visits[check_y][check_x] = true;
            in_visits[next_y][next_x] = true;

            // 옆으로 이동
            result += Search(in_maps, in_visits, in_use, y, x+1);

            // 다시 초기화
            in_use[FindDomino(domino)] = false;
            in_visits[check_y][check_x] = false;
            in_visits[next_y][next_x] = false;
        }
    }

    return result;
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 숫자 정보 미리 저장
    int len_domino = SaveNumbers();

    // 맵 입력
    vector<vector<int>> maps(len_y, vector<int>(len_x, 0));
    InputMap(maps);

    vector<vector<bool>> visits(len_y, vector<bool>(len_x, false));
    vector<bool> uses(len_domino, false);
    int result = Search(maps, visits, uses, 0, 0);

    cout << result << "\n";
}