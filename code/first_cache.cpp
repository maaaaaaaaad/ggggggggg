#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    for (auto& city : cities) {
        for (auto& c : city) {
            c = tolower(c);
        }
    }
    
    for (const auto& city : cities) {
        vector<string>::iterator cache_i = find(cache.begin(), cache.end(), city);
        if (cache_i != cache.end()) {
            cache.erase(cache_i);
            cache.push_back(city);
            answer += 1;
        }
        else {
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
            answer += 5;
        }
    }
    
    return answer;
}