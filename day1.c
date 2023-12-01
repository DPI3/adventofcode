#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
//adventofcode day1 little bit overcomplicated and not finished

int stonum(char *s){
    if(strcmp(s, "one") == 0)
        return 1;
    if(strcmp(s, "two") == 0)
        return 2;
    if(strcmp(s, "three") == 0)
        return 3;
    if(strcmp(s, "four") == 0)
        return 4;
    if(strcmp(s, "five") == 0)
        return 5;
    if(strcmp(s, "six") == 0)
        return 6;
    if(strcmp(s, "seven") == 0)
        return 7;
    if(strcmp(s, "eight") == 0)
        return 8;
    if(strcmp(s, "nine") == 0)
        return 9;
    return 0;        
}

int first_num(char *s) {
    char* num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < sizeof(num) / sizeof(num[0]); ++i) {
        char *t = strstr(s, num[i]);
        if (t != NULL) {
            return stonum(t);
        }
    }

    return 0;
}

int last_num(char *s) {
    char* num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = 0;
    for (int i = 0; i < sizeof(num) / sizeof(num[0]); ++i) {
        char *t = strstr(s, num[i]);
        if (t != NULL) {
            n = stonum(t);
        }
    }

    return n;
}

int main(){
    FILE *f;
    f = fopen("file.txt", "r");
    if (f == NULL) {
        perror("ERROR");
        return 0;   
    }

    char c;
    int sum = 0;
    bool first = true;
    int temp = 0;
    int index = 0;
    char s[500];
    while((c = fgetc(f)) != EOF){
        if(isdigit(c)){
            s[index] = '\0';
            if(first_num(s) != 0){
                sum += first_num(s)*10;
                first = false;
                s[index] = c;
            }else{
                s[index] = c;
            }
            if(first){
                sum += 10*(c - '0');
                temp = c - '0';
                first = false;
            }else
                temp = c - '0';
        }else{
            if(c != '\n'){
                s[index] = c;
                index++;
            }else{
                s[index] = '\0';
                if(last_num(s) != 0){
                    sum += last_num(s);
                    if(first)
                        temp = last_num(s);
                    else
                        temp = 0;
                }
            }
        }
        if(c == '\n'){
            sum += temp;
            printf("%d\n", sum);
            first = true;
            index = 0;
        }
    }
    sum += temp;
    printf("%d\n", sum);

    fclose(f);
    return 0;
}