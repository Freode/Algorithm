// 골드 5 - 1553번 : 도미노 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

// 도미노 번호 저장소
unordered_map<pair<int, int>, int> num_db;

// 배열에서 사용할 숫자 정보를 미리 저장 
void SaveNumbers()
{
    int count = 0;
    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            num_db[make_pair(i, j)] = count;
            count++;
        }
    }
}

// 맵 입력
void InputMap(vector<vector<int>> &in_maps)
{
    for(int i = 0; i < in_maps.size(); i++)
    {
        for(int j = 0; j < in_maps[0].size(); j++)
        {
            cin >> in_maps[i][j];
        }
    }
}

// 현재 도미노를 사용할 수 있는지 확인
bool CanUse(pair<int, int> &in_nums, vector<bool> &in_use)
{
    return static_cast<bool>(in_use[num_db[in_nums]]);
}

// 방문했는지 확인
bool IsVisit(vector<vector<bool>> &in_visits, const int &y1, int const &x1, const int &y2, const int& x2)
{
    return in_visits[y1][x1] || in_visits[y2][x2];
}

// 범위 안에 존재하는지 확인
bool IsInBoard(const int &y1, const int &x1, const int &y2, const int &x2)
{
    return y1 >= 0 && x1 >= 0 && y2 >= 0 && x2 >= 0 && y1 < 8 && x1 < 7 && y2 < 8 && x2 < 7;
}

// 탐색
int Search(vector<vector<int>>& in_maps, vector<vector<bool>> in_visits, vector<bool> in_use, int y, int x, int count)
{
    int result = 0;
    int temp_y = y, temp_x = x;
    // 세로 방향으로 두기
    if(IsInBoard(y, x, y+1, x))
    {
        // 방문하지 않은 경우
        if(IsVisit(in_visits, y, x, y+1, x))
        {
            // 현재 두 수를 사용하지 않았을 때만 두기
            if(CanUse(make_pair(in_maps[y][x], in_maps[y+1][x]), in_use))
            {
                in_visits[y][x] = true;
                in_visits[y+1][x] = true;
                // 옆으로 이동
                result += Search(in_maps, in_visits, in_use, y, x+1, count);

                in_visits[y][x] = false;
                in_visits[y+1][x] = false;
            }
            // 사용했다면, 해당 경우 아예 무시
        }
        // 방문한 경우 그냥 옆 칸으로 밀기
        else
        {
            result += Search(in_maps, in_visits, in_use, y, x+1, count);
        }
    }
    // 범위 밖이여서 못 두는 경우
    else
    {
        // 마지막 줄인 경우는 무시
        if(y+1 != 7)
        {
            //result += 
        }
    }

    // 가로 방향으로 두기

    return result;
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 숫자 정보 미리 저장
    SaveNumbers();

    // 맵 입력
    vector<vector<int>> maps(8, vector<int>(7, 0));
    InputMap(maps);




}