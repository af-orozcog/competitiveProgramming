#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    int i = 1;
    while(cin >> re && re[0] != '#'){
        printf("Case %d: ",i++);
        if(re.compare("HELLO") == 0) puts("ENGLISH");
        else if(re.compare("HOLA") == 0) puts("SPANISH");
        else if(re.compare("HALLO") == 0) puts("GERMAN");
        else if(re.compare("BONJOUR") == 0) puts("FRENCH");
        else if(re.compare("CIAO") == 0) puts("ITALIAN");
        else if(re.compare("ZDRAVSTVUJTE") == 0) puts("RUSSIAN");
        else puts("UNKNOWN");
    }
    return 0;
}
