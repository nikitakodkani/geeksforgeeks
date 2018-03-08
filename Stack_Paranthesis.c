#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK {
    char data;
    struct STACK *next;
} STACK;

STACK* push(STACK* head,int data)
{
    STACK* tmp = (STACK*)malloc(sizeof(STACK));
    if(tmp == NULL)
    {
        printf("Malloc error \n");
        exit(0);
    }
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    
    return head;
}
STACK* pop(STACK *head)
{
    STACK* tmp;
    tmp = head;
    if (tmp == NULL) {
        printf("\n Error : Trying to pop from empty stack");
        return NULL;
    } else {
        tmp = tmp->next;
    }
    free(head);
    head = tmp;
    return head;
}

void check_balanced(STACK *head, char *str) {
    int i=0;
    int len = strlen(str);
    if (len % 2 != 0) {
        printf("not balanced\n");
        return;
    }
    for (i=0; i < len; i++) {
        
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
                head = push(head, str[i]);
                
        } 
        
        if (head != NULL) {
            if (str[i] == '}' && head->data == '{') {
                head = pop(head);

            }
        
            if (str[i] == ')' && head->data == '(') {
                head = pop(head);
                
            }
        
            if(str[i] == ']' && head->data == '[') {
                head = pop(head); 
                
            }
        } else  {
            printf("not balanced\n");
            return;
        }
            
    }    
    
    if (head == NULL) { 
        printf("balanced\n") ;
    } else {
        printf("not balanced\n");
        free(head);
        head = NULL;
    }
}

int main() {
    STACK *head = NULL;
    int i, num;
    char str[10];
    
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        //str = malloc(sizeof(char) * (10));
        scanf("%s", str);
        check_balanced(head, str);
        //free(str);
        //str = NULL;
    }
    
    return 0;
}

