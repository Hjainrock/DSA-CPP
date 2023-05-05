// Another way in testing folder

#include<iostream>
using namespace std;

int main(){
    string str = "abcdefabe";
    string str1 = "abc";
    bool index;
    int lt = str.length();
    int lp = str1.length();
    int m = lt-lp+1;

    for(int i = 0; i<m; i++){
        int count = 0;
        while(count <=lp && str[i+count] == str1[count]){
            count += 1;
        }
        if(count >= lp){
                index = true;
                break;
        }
        else{
            index = false;
        }
    }

      if(index == true){
        cout <<"Matched";
    }
    else
        cout <<"Not matched";
return 0;
}
