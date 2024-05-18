// Lv.2 - 1844번 : 게임 맵 최단거리 
// 작성자 : jeonghoe22(최정호)

#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    // 공간 정보 2차원 벡터
    vector<vector<pair<bool, int>>> area_info((int)maps.size(), vector<pair<bool, int>>((int)maps[0].size(), make_pair(false, -1)));
    
    // y와 x 위치를 담은 queue
    queue<pair<int, int>> que_loc;
    que_loc.push(make_pair(0,0));
    // 시작 지점 방문 설정
    area_info[0][0].first = true;
    area_info[0][0].second = 1;
    
    // BFS
    pair<int, int> cur_loc;
    int y, x;
    while(que_loc.empty() == false)
    {
        // 현재 위치에서 동서남북으로 검사
        cur_loc = que_loc.front();
        for(int i = 0; i < 4; i++)
        {
            x = cur_loc.second;
            y = cur_loc.first;
            // 동
            if(i == 0){ x++; }
            // 남
            else if(i == 1){ y++; }
            // 서
            else if(i == 2){ x--; }
            // 북
            else{ y--; }
            
            // 해당 지점이 맵 안에 있으며, 벽이 아니고, 방문하지 않았을 때만 진행
            if(x>=0 && y>= 0 && x < (int)maps[0].size() && y < (int)maps.size() && maps[y][x] == 1 && area_info[y][x].first == false)
            {
                // queue에 추가
                area_info[y][x].first = true;
                area_info[y][x].second = area_info[cur_loc.first][cur_loc.second].second + 1;
                que_loc.push(make_pair(y, x));
            }
        }
        
        que_loc.pop();
    }
    
    // 도착 지점 출력
    answer = area_info[(int)maps.size() - 1][(int)maps[0].size() - 1].second;
    
    return answer;
}