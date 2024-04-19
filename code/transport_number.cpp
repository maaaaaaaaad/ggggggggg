#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    int DP[1000001] = { 0 };
    for (int i = 1; i < 1000001; i++)
        DP[i] = 1000001;
    DP[y] = 0;
    for(int i = y; i > x; i--)
    {
        if (DP[i] != 1000001)
        {
            if(i % 3 == 0)
                DP[i/3] = min(DP[i/3], DP[i] + 1);
            if(i % 2 == 0)
                DP[i/2] = min(DP[i/2], DP[i] + 1);
            if(i - n > 0)
                DP[i - n] = min(DP[i-n], DP[i] + 1);
        }
    }
    if(DP[x] == 1000001)
        DP[x] = -1;
    answer = DP[x];
    return answer;
}