#include <string>
using namespace std;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool Visit[15][15][4];
 
int Reverse(int Dir)
{
    if (Dir == 0) return 1;
    else if (Dir == 1) return 0;
    else if (Dir == 2) return 3;
    else if (Dir == 3) return 2;
}
 
int solution(string dirs) 
{
    int answer = 0;
    int x = 5;
    int y = 5;
 
    for (int i = 0; i < dirs.length(); i++)
    {
        char C = dirs[i];
        int nx;
        int ny;
        int Dir;
        if (C == 'U')
        {
            Dir = 3;
            nx = x + dx[3];
            ny = y + dy[3];
        }
        else if (C == 'D')
        {
            Dir = 2;
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else if (C == 'R')
        {
            Dir = 0;
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else
        {
            Dir = 1;
            nx = x + dx[1];
            ny = y + dy[1];
        }
 
        if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        if (Visit[x][y][Dir] == false && Visit[nx][ny][Reverse(Dir)] == false)
        {
            answer++;
            Visit[x][y][Dir] = true;
        }
 
        x = nx;
        y = ny;
    }
    return answer;
}