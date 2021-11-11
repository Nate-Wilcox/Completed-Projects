/*
Name:     Nathaniel Wilcox
Date:     4/8/2020
Subject:  CSE1002
File:     list.case
Algorithm:
* Open file
* Place events into linked list alphabetically
* Print list to shell
* Ask user for date to filter by
* Print event title and time for selected dates
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

																							/*Event time struct that contains
																							a integer for the hour(0-23)
																							a integer for the minute(0-59)*/
typedef struct etime{
    int hour;
    int min;
}event_time_t;
																							/*Event Date struct that contains
																							integer for the month(1-12)
																							the day(1-31)
																							the year(4-digit years)*/
typedef struct date{
    int mon;
    int day;
    int year;
}event_date_t;
																							/*Event struct that contains
																							a char array[20] for event title
																							event_time_t to hold event time
																							event_date_t to hold event date*/
typedef struct event{
    char title[20];
    event_time_t myTime;
    event_date_t myDate;
}event_t;

typedef struct node{
	event_t event;
	struct node *next;
}event_node_t;

void make_events(int eventnum, event_t *ptr, FILE *in_file, event_t *myEvent);
void print_event();
void print_selected_events(event_node_t *head_node, event_t event);
void add_events(event_t event, event_t *myEvent);
void print_node();

event_node_t *head_node = NULL;

int main(int argc, char* argv[]){
	int eventnum;
	char line[100];
	char filename[100];
	event_t event;

    strcpy(filename, "events.txt");
    eventnum = 5;
    event_t myEvent[eventnum];

																							//intput filename and number of events
  FILE *in_file = fopen(filename,"r");
																							//if opened incorrectly, show error message and terminate
	if(in_file == NULL){
		printf("Unable to open file");
		exit(EXIT_FAILURE);
	}

	printf("Schedule of Events:\n");
	for(int j = 0; j < eventnum; j++){														/*call make_events() to read from input file
																							* create array from events
																							* return array back to main
																							*/
	    make_events(eventnum, &myEvent[j], in_file, *&myEvent);
	}
    print_event();
	fseek(in_file, 0, SEEK_SET);
	print_selected_events(head_node, event);
       																						/*for each event in the array
																							* call print_event() to display event in format shown below
																							* call for all events between 01/01/2018 - 12/21/2019
																							*/
																							//call count_events() to find and print how many times they appear in array
  fclose(in_file);
	return 0;
}


void make_events(int eventnum, event_t *ptr, FILE *in_file, event_t *myEvent){
																							//loop through array, for each event
																								/*
																								* read event title and store in event struct at current index
																								* create an event_time_t strut instance and read hour and minute into it
																								* create and event_date_tstruct instance and read month, day, and year in it
																								*/
    fscanf(in_file, "%s %d %d %d %d %d", ptr->title, &ptr->myTime.hour, &ptr->myTime.min, &ptr->myDate.mon, &ptr->myDate.day, &ptr->myDate.year);
																							//Close input file and return nodes of events to main()
	add_events(*ptr, myEvent);
    return;
}

void print_event(void){
	print_node();
	return;
}

void print_selected_events(event_node_t *head_node, event_t event){
																							/*
																							input parameters:
																							* array of events
																							* start date
																							* end date
																							*/
	int mon, day, year;
	event_node_t *temp_node;
	printf("Date:(mm/dd/yyyy)\t");
	scanf("%d/%d/%d", &mon, &day, &year);

	printf("Events:\n");
	temp_node = head_node;

	while(temp_node != NULL){
	    if(mon == temp_node->event.myDate.mon && day == temp_node->event.myDate.day && year == temp_node->event.myDate.year){
	        printf("\t%s at:", temp_node->event.title);
        	if(temp_node->event.myTime.hour < 10){
        	    printf("\t\t0%d:", temp_node->event.myTime.hour);
        	}else{
        	    printf("\t\t%d:", temp_node->event.myTime.hour);
        	}
        	if(temp_node->event.myTime.min < 10){
        	    printf("0%d\n", temp_node->event.myTime.min);
        	}else{
        	    printf("%d\n", temp_node->event.myTime.min);
        	}
	    }
	    temp_node = temp_node->next;
	}
//print all events information for date passed through
return;
}

void add_events(event_t new_data, event_t *myEvent){
	event_node_t *new_node, *temp_node;
	new_node = (event_node_t *) malloc(sizeof(event_node_t));
	new_node->event = new_data;
	new_node->next = NULL;
    int result = 0;

	if(head_node == NULL){
		head_node = new_node;
	}else{
    	temp_node = head_node;
    	while(temp_node->next != NULL){
    	    result = strcmp(temp_node->next->event.title, new_node->event.title);

    	    if(result <= 0){
    		   temp_node = temp_node->next;
    	    }else{
    	        break;
    	    }
    	}

    	if(temp_node == head_node){
	        result = strcmp(temp_node->event.title, new_node->event.title);
	        if(result > 0){
	            new_node->next = temp_node;
	            head_node = new_node;
	        }else{
	          new_node->next = temp_node->next;
	          head_node->next = new_node;
	        }
	    }else{
	        new_node->next = temp_node->next;
	        temp_node->next = new_node;
	    }
	}
    return;
}

void print_node(void){
    event_node_t *temp_node;
    temp_node = head_node;

    while(temp_node != NULL){
        printf("\t%s at:", temp_node->event.title);
	if(temp_node->event.myTime.hour < 10){
	    printf("\t\t0%d:", temp_node->event.myTime.hour);
	}else{
	    printf("\t\t%d:", temp_node->event.myTime.hour);
	}
	if(temp_node->event.myTime.min < 10){
	    printf("0%d on:", temp_node->event.myTime.min);
	}else{
	    printf("%d on:", temp_node->event.myTime.min);
	}
	printf("\t%d/", temp_node->event.myDate.mon);
	printf("%d/", temp_node->event.myDate.day);
	printf("%d\n", temp_node->event.myDate.year);
        temp_node = temp_node->next;
    }
    printf("\n");

    return;
}
