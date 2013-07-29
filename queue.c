//========================================================================
//
//      queue.h - simple two way queue data stuctue implementation
//
//      Copyleft - Bartosz Olender 2013 <bartosz.olender@gmail.com>
//
//      This source code is realesed under the terms of the Simplified
//      BSD License for more licence information check LICENCE file.
//
//========================================================================
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

q_queue q_create_queue(){ // creates null pointers to the first and last joint of the queue
    q_queue generated_queue;
    generated_queue.first=NULL;
    generated_queue.last=NULL;
    return generated_queue;
}

bool q_add_joint(q_queue* input_queue,int added_data){ // adds a joint to the end of the structure, returns true if succesfull
    q_joint *new_joint=malloc(sizeof(q_joint)); //make it a pointer with malloc
    if (new_joint==NULL){
        fprintf(stderr,"could not allocate q_joint");
    }
    new_joint->data=added_data;
    new_joint->next=NULL;
    if (input_queue->first==NULL){
        //printf("The Queue is empty!\n"); //debug thingie.
        input_queue->first=new_joint;
        input_queue->last=new_joint;
        new_joint->prev=NULL;
        return(true);
    }
    else{
        //printf("The Queue exists!\n"); //debug thingie.
        q_joint *prev_joint;
        prev_joint=input_queue->last;
        new_joint->prev=prev_joint;
        prev_joint->next=new_joint;
        input_queue->last=new_joint;
        //printf("%p, %d, %p\n",new_joint->prev,new_joint->data,prev_joint->next); //debug thingie.
        return(true);
    }
}

bool q_remove_joint(q_queue *input_queue){  // removes the last joint, returns true if succesfull
return true;
}


int q_queue_length(q_queue *input_queue){ // calculates and returns the length of the queue
    if (input_queue->first==NULL){
        return 0;
    }
    else{
        q_joint *temp_joint;
        temp_joint=input_queue->first;
        int length=1;
        while (temp_joint->next!=NULL) {
            length++;
            temp_joint=temp_joint->next;
        };
        return length;
    };
}

