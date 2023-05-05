#include<iostream>
#include<string.h>
using namespace std;

void computeLPSArray(char pat[], int M, int lps[])
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    cout<<" Pattern is : "<<endl;
    for(int i =0; i<M; i++){
        cout<<pat[i] << "  ";
    }
    cout<<"\n Pie Table is : "<<endl;
    for(int i =0; i<M; i++){
        cout<<lps[i] << "  ";
    }
}

void KMPSearch(char* pat,char* txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    bool flag = 0;
    computeLPSArray(pat, M, lps);
    int i=0,j=0;
    while((N-i) >= (M-j)){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }
        if(j == M){
            flag = 1;
            cout << "\nPattern Found at index:" << i-j;
            j = lps[j-1];
        }
        else if( i < N && pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    if(flag == 0){
        cout << "\nPattern Not Found";
    }
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABA";

    KMPSearch(pat, txt);
return 0;
}
