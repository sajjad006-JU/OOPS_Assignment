#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include <string.h>

int main () {
    char* str="()(([]))";
    int n=strlen(str);
    int flag=1;

    Stack* st=createStack();    

    for (int i=0; i<n; i++) {
        char ch=str[i];

        if (ch=='(' || ch=='{' || ch=='[') {
            push(ch, st);
        } else if(ch == ')' || ch==']' || ch=='}') {
            char c=(char)top(st);
            pop(st);

            if ((ch==')' && c!='(') || (ch==']' && c!='[') || (ch=='}' && c!='{')) {
                printf("Invalid perenthesis");
                flag=0;
                break;
            }
        }
    } 
    if (flag)
        printf("valid prenetheses");
}