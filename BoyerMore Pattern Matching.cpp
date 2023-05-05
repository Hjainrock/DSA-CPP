#include<iostream>
using namespace std;
#define NO_OF_CHARS 256

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]){
    int i=0;
    for(i=0; i<NO_OF_CHARS; i++)
        badchar[i] = -1;

    for(i=0; i< size; i++)
        badchar[str[i]] = i;
}

void search(string txt, string pat){
    bool flag = 0;
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0; // S for shift
    while(s<= (n-m)){
        int j = m-1;
        while(j>=0 && pat[j] == txt[s+j])
            j--;

        if(j<0){
            flag = 1;
            cout <<"Pattern Found At : "<< s << endl;
            //break; (to find only first occurence)
            s += (s+m < n) ? m-badchar[txt[s+m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s+j]]);
    }
    if(flag ==0)
        cout <<"Pattern Not Found "<<endl;
}
int main(){
    string txt = "ABCDEF@#$%gfgfd";
    string pat = "$%gf";
    search(txt , pat);
return 0;
}
