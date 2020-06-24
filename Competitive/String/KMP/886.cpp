/**
* taken from http://mypaper.pchome.com.tw/zerojudge/post/1325177872
*/
#include <stdio.h>
#include <string.h>
char firstName[1024][100], lastName[1024][100];
char dialing[1024][100];
char trans[1024][200];
char phone[] = "22233344455566677778889999";
char tolower(char c) {
    if(c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}
int main() {
    char s[1024];
    int n = 0;
    int i, j, k;
    while(gets(s)) {
        if(s[0] >= '0' && s[0] <= '9')
            break;
        sscanf(s, "%s %s %s", firstName[n], lastName[n], dialing[n]);
        for(i = 0; firstName[n][i]; i++)
            firstName[n][i] = tolower(firstName[n][i]);
        for(i = 0; lastName[n][i]; i++)
            lastName[n][i] = tolower(lastName[n][i]);
        trans[n][0] = phone[firstName[n][0]-'a'];
        for(i = 0; lastName[n][i]; i++)
            trans[n][i+1] = phone[lastName[n][i]-'a'];
        n++;
    }
    do {
        int flag = 0;
        for(i = 0; i < n; i++) {
            if(!strcmp(s, dialing[i])) {
                flag = 1;
                puts(s);
                break;
            }
        }
        if(flag)    continue;
        for(i = 0; i < n; i++) {
            int ok = 1;
            for(j = 0; s[j] && ok; j++) {
                if(trans[i][j] != s[j])
                    ok = 0;
            }
            if(ok == 1) {
                if(flag)    putchar(' ');
                printf("%s", dialing[i]);
                flag++;
            }
        }
        if(flag == 0)
            puts("0");
        else
            puts("");
    } while(gets(s));
    return 0;
}
