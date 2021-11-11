
/*
Name:     Nathaniel Wilcox
Date:     4/28/2020
Subject:  CSE1002
File:     lists.c
Algorithm:
* Open file
Part 1
* Place events into 2 linked lists
* Print lists to shell
Part 2
* Place evetns into 2 linked lists, or use previously made lists
* Combine lists using doubly linked list functions
* print lists to shell
*/

//Library Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct constructors
typedef struct{
  int month;
  int day;
} event_date;

struct event{
  char *title;
  event_date date;
  struct event *previous;
  struct event *next;
};


//function declarations
void insert_events_linked_list(struct event LIST);
void insert_events_queue(struct event QUEUE);
void merge_lists(struct event LIST, struct event QUEUE);
void print_linked_list(void);
void print_queue(void);
void add_front(struct event LIST, struct event QUEUE, struct event FINAL);


int main(void){
  //struct declaration
  struct event LIST, QUEUE, FINAL;
  int new_date;
  int eventnum1 = 0;
  int eventnum2 = 0;
  char filename[13] = "input_1.txt";
  //Open file using hard coded file name
  FILE *in_file = fopen(filename, "r");
  //make pointers to head and tail of structs, and create a temp pointer to move through linked list
  struct event *temp, *head, *tail;
  head = NULL;
  tail = NULL;
  temp = NULL;
  //Check to see if file opened properly
  if(in_file == NULL){
		printf("Unable to open file");
		exit(EXIT_FAILURE);
	}
  //scan through file to create nodes
  fscanf(in_file, "%d\n", &eventnum1);
  for(int i = 0; i < eventnum1; i++){
    fscanf(in_file, "%s\n %d %d\n", LIST.title, &LIST.date.month, &LIST.date.day);
    insert_events_linked_list(LIST);
  }
  fscanf(in_file, "%d\n", &eventnum2);
  for(int i = 0; i < eventnum2; i++){
    fscanf(in_file, "%s\n %d %d\n", QUEUE.title, &QUEUE.date.month, &QUEUE.date.day);
    insert_events_queue(QUEUE);
  }
  print_linked_list();
  print_queue();
  add_front(LIST, QUEUE,  FINAL);
  print_linked_list();
  print_queue();

}

//Function definitions
void insert_events_linked_list(struct event LIST){
  struct event *new;
  struct event *temp, *head;
  new = (struct event *)malloc(sizeof(struct event));
  new->title = LIST.title;
  new->date = LIST.date;
  new->next = NULL;

  if(head == NULL){
    head = new;
  }else{
    temp = head;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }

}
void insert_events_queue(struct event QUEUE){
  struct event *new, *temp, *head;
  new = (struct event *)malloc(sizeof(struct event));
  new->title = QUEUE.title;
  new->date = QUEUE.date;
  new->next = NULL;
  if(head == NULL){
    head = new;
  }else{
    temp = head;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
}
void merge_lists(struct event LIST, struct event QUEUE){
  struct event *new, *temp, *head;
  int result = 0;
	if(temp->next == NULL){
    	temp = head;
    	while(temp->next != NULL){
    	    result = strcmp(temp->next->title, temp->title);

    	    if(result <= 0){
    		   temp = temp->next;
    	    }else{
    	        break;
    	    }
    	}

    	if(temp == head){
	        result = strcmp(temp->title, new->title);
	        if(result > 0){
	            new->next = temp;
	            head = new;
	        }else{
	          new->next = temp->next;
	          head->next = new;
	        }
	    }else{
	        new->next = temp->next;
	        temp->next = new;
	    }
	}
    return;
}
void print_linked_list(void){
  struct event *temp, *head, *new;
  temp = head;
  printf("Doubly List:");
  while (temp != NULL){
    printf("%s %d/%d\n", temp->title, temp->date.month, temp->date.day);
  }
  if(temp == NULL){
    printf("End of list.\n\n");
  }
}
void print_queue(void){
  struct event *temp, *head;
  temp = head;
  printf("Doubly List:");
  while (temp != NULL){
    printf("%s %d/%d\n", temp->title, temp->date.month, temp->date.day);
  }
  if(temp == NULL){
    printf("End of list.\n\n");
  }
}
void add_front(struct event LIST, struct event QUEUE, struct event FINAL){
  struct event *new, *temp, *head, *tail;
  new = (struct event *) malloc(sizeof(struct event));
  new->title = LIST.title;
  new->date = LIST.date;
  new->previous = NULL;
  new->next = NULL;

  if(head == NULL){
    head = new;
    tail = new;
  }else{
    head->previous = new;
    new->next = head;
    head = new;
  }
  return;
}
void delete_node(event date){
  struct event *temp, *new, *head, *tail;

  if(head != NULL){
    temp = head;
    if(head->date = event.date){
      head = head->next;
      free(temp);
      if(head == NULL)
        tail = NULL;
      else
        head->previous = NULL;
      } else;
      }
}
