// Lv.2 - 1829번 : 카카오프렌즈 컬러링북
// 작성자 : jeonghoe22(최정호)

#include <vector>

using namespace std;

int search(int y, int x, vector<vector<int>> &picture, vector<vector<bool>> &b_visited)
{
    // 현재 위치 방문했다고 설정
    int area = 1;
    b_visited[y][x] = true;

    int next_y, next_x;
    // 상하좌우 검사
    for(int i = 0; i < 4; i++)
    {
        next_y = y;
        next_x = x;

        // 방향 설정
        if(i == 0){ next_y--; }
        else if(i == 1){next_x++;}
        else if(i == 2){next_y++;}
        else{ next_x--; }

        // 범위 내인지 확인
        if(!(next_y >= 0 && next_x >= 0 && next_y < picture.size() && next_x < picture[0].size()))
        {
            continue;
        }

        // 같은 색상이고 방문하지 않았을 때만 이동
        if(picture[y][x] == picture[next_y][next_x] && !b_visited[next_y][next_x])
        {
            area += search(next_y, next_x, picture, b_visited);
        }
    }

    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> b_visited(m, vector<bool>(n, false));

    int cur_size_of_one_area;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 색칠 영역이면서 방문하지 않은 경우
            if(picture[i][j] != 0 && !b_visited[i][j])
            {
                // 영역 개수 증가 및 영역 범위 검사
                number_of_area++;
                cur_size_of_one_area = search(i, j, picture, b_visited);

                // 현재 영역의 범위가 더 넓은 경우, 초기화
                if(max_size_of_one_area < cur_size_of_one_area)
                {
                    max_size_of_one_area = cur_size_of_one_area;
                }
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}