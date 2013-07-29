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

#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
// q_joint - joint structure
typedef struct {
    struct q_joint *prev;
    int data;
    struct q_joint *next;
} q_joint;
// q_queue - structure that points to the begining and end of the queue
typedef struct {
    struct q_joint *first;
    struct q_joint *last;
} q_queue;

q_queue q_create_queue(); // creates null pointers to the first and last joint of the queue
bool q_add_joint(q_queue* input_queue,int added_data); // adds a joint to the end of the structure, returns true if succesfull
bool q_remove_joint(q_queue* input_queue); // removes the last joint, returns true if succesfull
int q_queue_length(q_queue * input_queue); // calculates and returns the length of the queue

#endif
