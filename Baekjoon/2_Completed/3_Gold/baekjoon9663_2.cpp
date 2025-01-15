// 골드 4 - 9663번 : N-Queen
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 퀸 배치 불가능 지역 설정/되돌리기
void change(vector<vector<int>> &_area, int _start_y, int _start_x, int _dir, bool _add)
{
    int size = _area.size();

    int temp_y = _start_y;
    int temp_x = _start_x;

    // 범위 안
    while(1)
    {
        switch(_dir)
        {
        // 위
        case 0:
            temp_y--;
            break;
        // 오른쪽 위
        case 1:
            temp_y--;
            temp_x++;
            break;
        // 오른쪽
        case 2:
            temp_x++;
            break;
        // 오른쪽 아래
        case 3:
            temp_y++;
            temp_x++;
            break;
        // 아래
        case 4:
            temp_y++;
            break;
        // 왼쪽 아래
        case 5:
            temp_y++;
            temp_x--;
            break;
        // 왼쪽
        case 6:
            temp_x--;
            break;
        // 왼쪽 위
        case 7:
            temp_x--;
            temp_y--;
            break;
        }

        // 범위 밖
        if(!(temp_y >= 0 && temp_x >= 0 && temp_y < size && temp_x < size))
        {
            break;
        }

        // 배치 불가능 지역 설정/되돌리기
        _area[temp_y][temp_x] = _add ? _area[temp_y][temp_x] + 1 : _area[temp_y][temp_x] - 1;
    }
}

// 퀸 배치 시뮬레이션
int search(vector<vector<int>> &_area, int _queen_num)
{
    // 모두 다 배치
    if(_queen_num == -1)
    {
        return 1;
    }
    
    int result = 0;
    int size = _area.size();

    // 배치 가능한 곳에 모두 배치해보기
    for(int i = 0; i < size; i++)
    {
        // 배치 가능
        if(_area[_queen_num][i] == 0)
        {
            _area[_queen_num][i] = 1;

            // 8방향으로 배치 불가능 지역 설정
            for(int dir = 0; dir < 8; dir++)
            {
                change(_area, _queen_num, i, dir, true);
            }

            // 결과 더하기
            result += search(_area, _queen_num - 1);

            // 8방향으로 배치 불가능 지역 되돌리기
            for(int dir = 0; dir < 8; dir++)
            {
                change(_area, _queen_num, i, dir, false);
            }
            _area[_queen_num][i]--;
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 사이즈 입력
    int n;
    cin >> n;

    // 크기 할당
    vector<vector<int>> area(n, vector<int>(n, 0));

    // 시뮬레이션 실행
    int result = search(area, n - 1);

    cout << result << "\n";
}