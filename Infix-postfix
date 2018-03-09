#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int prec(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

void infix_postfix(STACK *head, char *str) {
    int i=0, oc=0;
    char output[30];
    
    
    for (i=0; str[i] != '\0' ; i++) {
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ){
             output[oc++] = str[i];
        } else if(str[i] == '('){
            head = push(head, str[i]);
        } else if(str[i] == ')') {
           while (head->data != '(') {
                output[oc++] = head->data;
                head = pop(head);
            }
            // Remove the paranthesis
            head = pop(head); 
        } else {
            while (head != NULL && prec(str[i]) <= prec(head->data)) {
                    output[oc++] = head->data;
                    head = pop(head);
            }
                head = push(head, str[i]);
             
        }
    }
    while (head != NULL) {
        output[oc++] = head->data;
        head = pop(head);
    }
    output[oc]='\0';    
    printf("%s\n", output);
    
}

int main() {
    STACK *head = NULL;
    int i, num;
    char *str;
    
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        str = malloc(sizeof(char) * (30));
        scanf("%s", str);
        infix_postfix(head, str);
        free(str);
        str = NULL;
    }
    
    return 0;
}
