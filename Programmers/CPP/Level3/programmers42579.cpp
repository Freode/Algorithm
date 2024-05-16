// Lv.3 - 42579번 : 베스트앨범 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Genre
{
    long long genre_play_times = 0;
    vector<vector<int>> song_lists;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    
    map<string, Genre> lists;
    
    for(int i = 0; i < (int)genres.size(); i++)
    {
        // 장르 총합
        lists[genres[i]].genre_play_times += plays[i];
        // 각 장르에 해당하는 노래를 인덱스와 플레이 타임으로 추가
        lists[genres[i]].song_lists.push_back({i, plays[i]});
    }
    
    vector<Genre> genres_vec;
    // 벡터에 옮기기
    for(const auto& each : lists)
    {
        genres_vec.push_back(each.second);
    }
    
    // 각 장르별로 기준에 부합하게 정렬
    sort(genres_vec.begin(), genres_vec.end(), [](const Genre& a, const Genre& b)
    {
        // 장르의 총 재생 횟수 내림차순 정렬
        return a.genre_play_times > b.genre_play_times;
    });
    
    for(Genre& each : genres_vec)
    {
        sort(each.song_lists.begin(), each.song_lists.end(), [](const vector<int>&a, const vector<int>&b)
        {
            // 재생 횟수가 다른 경우에는, 플레이 타임 기준 내림차순 정렬
            if(a[1] != b[1]) { return a[1] > b[1]; }
            // 재생 횟수가 같은 경우에는 고유 번호 오름차순 정렬
            else { return a[0] < b[0]; }  
        });
        
        // 재생 횟수의 총합이 가장 많은 장르순으로 가장 많은 최대 2곡을 추가
        answer.push_back(each.song_lists[0][0]);
        if((int)each.song_lists.size() > 1)
        {
            answer.push_back(each.song_lists[1][0]);
        }
    }
    
    return answer;
}