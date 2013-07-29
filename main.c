#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "queue.h"

void read_queue_LTF(q_queue *input_queue){ //czyta kolejke od ostatniego do pierwszego
    q_joint *temp_joint;
    temp_joint =(input_queue->last);
    //Petla wypisuje dane i adres i przenosi dane
    while (temp_joint->prev!=NULL){
        printf("%d,",(temp_joint->data));
        printf("\t%p,\n",temp_joint->prev);
        temp_joint=temp_joint->prev;
    }

    printf("%d,",(temp_joint->data));
    printf("\t%p,\n",temp_joint->prev);
}
void read_queue_FTL(q_queue *input_queue){
    q_joint *temp_joint;
    temp_joint =(input_queue->first);
    while (temp_joint->next!=NULL){
        printf("%d,",(temp_joint->data));
        printf("\t%p,\n",temp_joint->next);
        temp_joint=temp_joint->next;
    }
    printf("%d,",(temp_joint->data));
    printf("\t%p,\n",temp_joint->next);
}
int main()
{
    srand(time(NULL));

    q_queue *q=malloc(sizeof(q_queue));
    *q=q_create_queue();
    if(q==NULL) //but if you cant allocate one q_queue you have bigger problems than this.
    {
        fprintf(stderr,"could not allocate q_queue\n");
        exit(1);
    }
    printf("Queue app,\n");
    q_add_joint(q,235);
    q_add_joint(q,25);
    q_add_joint(q,2);
    for (int i=1; i<=100; i++){
    //while (true){
        q_add_joint(q,rand()%10000);
    }
    printf("Queue length: %d\n",q_queue_length(q));
    printf("Queue from last to first joint:\n");
    printf("Value\tAdress\n");
    read_queue_LTF(q);
    printf("Queue from first to last joint:\n");
    printf("Value\tAdress\n");
    read_queue_FTL(q);
    getchar();
    return 0;
}
