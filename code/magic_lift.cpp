#include <string>
#include <vector>
#include <cmath>
 
using namespace std;
 
int solution(int storey) {
    int answer = 0;
    
    while(storey != 0) {
        int n = storey % 10;
        if(n > 5) {
            answer += 10 -n;
            storey = storey / 10;
            storey = storey + 1;
        }
        else if(n == 5) {
            int tmp = (storey/10) % 10;                                                                            
            if(tmp >= 5) {
                storey = storey / 10;
                storey = storey + 1;
            }
            else {
                storey = storey / 10;
            }
            answer = answer + 5;
        }
        else {
            answer = answer + n;
            storey = storey / 10;
        }
    }
    
    return answer;
}
