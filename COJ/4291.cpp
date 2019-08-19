#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string to;
    while(cin >> to){
        int to1;
        cin >>to1;
        string na;
        cin >> na;
        int na1;
        cin >>na1;
        if(to[0] == na[0]){
            if(to1 > na1)
                printf("Tobby\n");
            else if(to1 < na1)
                printf("Naebbirac\n");
            else
                printf("Draw\n");                
            continue;
        }
        if(to[0] == 'C'){
            if(na[0] == 'B'){
                if(na1 < 2 * to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
            else{
                if(na1 * 2 <= to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
        }

        if(to[0] == 'D'){
            if(na[0] == 'B'){
                if(na1 * 2 <= to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
            else{
                if(na1 < 2 * to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
        }

        if(to[0] == 'B'){
            if(na[0] == 'C'){
                if(na1 * 2 <= to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
            else{
                if(na1 < 2 * to1)
                    printf("Tobby\n");
                else
                    printf("Naebbirac\n");
                continue;
            }
        }
    }
    return 0;
}