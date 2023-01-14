#include <iostream> 
using namespace std; 
 
const int q = 1e9 + 7; 
const int d = 26; 
int main(){ 
    string s; 
    cin >> s; 
    int a[s.size()]; 
    for(int i = 0; i < s.size(); i++){ 
        a[i] = 0;  
    } 
    int n; 
    cin >> n; 
    string pattern; 
    for(int x = 0; x < n; x++){ 
        cin >> pattern; 
        long long t = 0, p = 0, h = 1, i, j; 
        for(i = 0; i < pattern.size() - 1; i++){ 
            h = (h * d) % q; 
        } 
 
        for(i = 0; i < pattern.size(); i++){ 
            p = (p * d + pattern[i]) % q; 
            t = (t * d + s[i]) % q; 
        } 
 
        for(i = 0; i <= s.size() - pattern.size(); i++){ 
            if(p == t){ 
                for(j = 0; j < pattern.size(); j++){ 
                    if(s[i+j] != pattern[j]){ 
                        break; 
                    } 
                } 
                if(j == pattern.size()){ 
                    for(j = 0; j < pattern.size(); j++){ 
                        a[i+j] += 1; 
                    } 
                } 
            } 
 
            if(i < s.size() - pattern.size()){ 
                t = (((t - s[i] * h) * d) + s[i + pattern.size()]) % q; 
                if(t < 0){ 
                    t += q; 
                } 
            } 
        } 
    } 
    for(int i = 0; i < s.size(); i++){ 
        // cout << a[i] << ' '; 
        if(a[i] == 0){ 
            cout << "NO"; 
            return 0;             
        } 
    } 
    cout << "YES"; 
    return 0; 
 
}