#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK {
    char data;
    struct STACK *next;
} STACK;

STACK* push(STACK* head,char data)
{
    STACK* tmp = (STACK*)malloc(sizeof(STACK));
    tmp->data = data;
    if(head == NULL)
        tmp->next = NULL;
    else
        tmp->next = head;
    head = tmp;
   
    return head;
}
STACK* pop(STACK *head)
{
   if(head == NULL)
      return NULL;
    else{
      STACK* tmp = head;
      head = tmp->next;
      free(tmp);
   }
    
    return head;
}

void check_balanced(STACK *head, char *str) {
    int i=0, check = 0;
    int len = strlen(str);
    if (len % 2 != 0) {
        printf("not balanced\n");
        return;
    }
    for (i=0; i < len; i++) {
        check = 0;
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
                head = push(head, str[i]);
                check =1;
                
        } 
        
        if (head != NULL) {
            if (str[i] == '}' && head->data == '{') {
                head = pop(head);
                check = 1;
            }
        
            if (str[i] == ')' && head->data == '(') {
                head = pop(head);
                check = 1;
            }
        
            if(str[i] == ']' && head->data == '[') {
                head = pop(head); 
                check = 1;
            }
        } 
        
        if (check == 0) {
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
    //char str[10];
    char *str;
    
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        str = malloc(sizeof(char) * (100));
        scanf("%s", str);
        check_balanced(head, str);
        free(str);
        str = NULL;
    }
    
    return 0;
}
