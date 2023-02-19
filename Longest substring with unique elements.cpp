// Online C++ compiler to run C++ program online
// FING LENGTH OF LONGEST SUBSTRING OF A STRING THAT CONTAINS UNIQUE ELEMENTS 
//INPUT : repeat //output : 4

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force :
int longestsubstr(string s,int n){
    int max = 0;
    for(int i = 0; i < n ; i++){
        int count = 0 ;
        int H[26]{0};
        int j= i;
        while(s[j]!= '\0' and H[s[j]-'a'] == 0){
            count++;
            H[s[j]-97]++;
            j++;
        }
        if(max < count){
            max = count;
        }
    }
    return max;
}

//optimised approach
int abc() {
    string s;
    cin >> s;

    int ans = 0;
    int cnt = 0;
    int n = s.length();
    int freq[26];
    memset(freq, 0, sizeof(freq));
    int head = -1, tail = 0;
    while (tail < n) {
        while ( (head + 1 < n) && (freq[s[head + 1] - 'a'] == 0) ) {
            head++;
            freq[s[head] - 'a']++;
        }
        cnt += head - tail + 1;

        if (head < tail) {
            tail++;
            head = tail - 1;
        }
        else {
            ans = max(ans, cnt);
            tail++;
            freq[s[tail - 1] - 'a']--;
            cnt = 0;
        }
    }
    cout << ans;

    cout << "\n";
    return 0;
}

int main() {
    cout << "enter string\n";
    string s;
    cin>>s;
    cout<<longestsubstr(s,s.length());
    return 0;
}
