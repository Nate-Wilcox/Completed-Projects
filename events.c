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

void make_events(int eventnum, event_t *ptr, FILE *in_file, event_t *myEvent);
void print_event(int eventnum, event_t *ptr, event_t *myEvent);
void print_selected_events(int eventnum, event_t *ptr, event_t *myEvent, FILE *in_file);
int count_events(char *events, int eventnum, char *line, FILE *in_file, event_t *ptr);


int main(int argc, char* argv[]){
	int eventnum;
	char line[100];
	char filename[100];
	char events[100];
                                                                                            //prompt user for input file name and number of events
    printf("Enter an input filename: ");
	scanf("%s", filename);
	
	printf("How many events are in the input file? ");
	scanf("%d", &eventnum);
	event_t myEvent[eventnum];
																							//intput filename and number of events
																							//open input file
    FILE *in_file = fopen(filename,"r");
																							//if opened incorrectly, show error message and terminate
	if(in_file == NULL){
		printf("Unable to open file");
		exit(EXIT_FAILURE);
	}

	printf("Schedule of Events:\n");
	for(int j = 0; j < eventnum; j++){																						/*call make_events() to read from input file
																							* create array from events
																							* return array back to main
																							*/
	    make_events(eventnum, &myEvent[j], in_file, *&myEvent);
	    print_event( eventnum, &myEvent[j], myEvent);
	}
	
	fseek(in_file, 0, SEEK_SET);
	print_selected_events(eventnum, *&myEvent, *&myEvent, in_file);
       																						/*for each event in the array
																							* call print_event() to display event in format shown below
																							* call for all events between 01/01/2018 - 12/21/2019
																							*/
																							//call count_events() to find and print how many times they appear in array
    count_events(events, eventnum, line, in_file, &myEvent[eventnum]);
    fclose(in_file);
	return 0;
}


void make_events(int eventnum, event_t *ptr, FILE *in_file, event_t *myEvent){
																							//loop through array, for each event
																								/*
																								* read event title and store in event struct at current index
																								* create an event_time_t strut instance and read hour and minute into it
																								* create and event_date_tstruct instance and read month, day, and year int it
																								*/
    fscanf(in_file, "%s %d %d %d %d %d", ptr->title, &ptr->myTime.hour, &ptr->myTime.min, &ptr->myDate.mon, &ptr->myDate.day, &ptr->myDate.year);
																							//Close input file and return array of events to main()
return;
}  

void print_event(int eventnum, event_t *ptr, event_t *myEvent){
																							/*
																							input parameters: array of events
																							print the event information for the event passed through
																							*/
	printf("\t%s at:", ptr->title);
	if(ptr->myTime.hour < 10){
	    printf("\t\t0%d:", ptr->myTime.hour);
	}else{
	    printf("\t\t%d:", ptr->myTime.hour);
	}
	if(ptr->myTime.min < 10){
	    printf("0%d on:", ptr->myTime.min);
	}else{
	    printf("%d on:", ptr->myTime.min);
	}
	printf("\t%d/", ptr->myDate.mon);
	printf("%d/", ptr->myDate.day);
	printf("%d\n", ptr->myDate.year);
	
	return;
}

void print_selected_events(int eventnum, event_t *ptr, event_t *myEvent, FILE *in_file){
																							/*
																							input parameters:
																							* array of events
																							* start date
																							* end date
																							*/
	int minmon, minday, minyear;
	int maxmon, maxday, maxyear;
	printf("Date:(mm/dd/yyyy  mm/dd/yyyy)\t");
	scanf("%d/%d/%d", &minmon, &minday, &minyear);
	printf("\t");
	scanf("%d/%d/%d", &maxmon, &maxday, &maxyear);
	int days_min;
	int days_max;
	if(minmon == 1 || minmon == 3 || minmon == 5 || minmon == 7 || minmon == 8 || minmon == 10 || minmon == 12){
	    days_min = (minyear * 365) + (minmon * 31) + minday;
	}else if(minmon == 2){
	    days_min = (minyear * 365) + (minmon * 28) + minday;
	}else{
	    days_min = (minyear * 365) + (minmon * 30) + minday;
	}
	if(maxmon == 1 || maxmon == 3 || maxmon == 5 || maxmon == 7 || maxmon == 8 || maxmon == 10 || maxmon == 12){
	    days_max = (maxyear * 365) + (maxmon * 31) + maxday;
	}else if(maxmon == 2){
	    days_max = (maxyear * 365) + (maxmon * 28) + maxday;
	}else{
	    days_max = (maxyear * 365) + (maxmon * 30) + maxday;
	}
	
	printf("Events:\n");
	for(int i = 0; i < eventnum; i++){
	    int days_test = 0;
	    if(myEvent[i].myDate.mon == 1 || myEvent[i].myDate.mon == 3 || myEvent[i].myDate.mon == 5 
		|| myEvent[i].myDate.mon == 7 || myEvent[i].myDate.mon == 8 || myEvent[i].myDate.mon == 10 
		|| myEvent[i].myDate.mon == 12){
    	    days_test = (myEvent[i].myDate.year * 365) + (myEvent[i].myDate.mon * 31) + myEvent[i].myDate.day;	//turns a date into a single number for comparrison
    	}
    	else if(myEvent[i].myDate.mon == 2){
    	    days_test = (myEvent[i].myDate.year * 365) + (myEvent[i].myDate.mon * 28) + myEvent[i].myDate.day;
    	}
    	else{
    	    days_test = (myEvent[i].myDate.year * 365) + (myEvent[i].myDate.mon * 30) + myEvent[i].myDate.day;
    	}
    	if((days_test >= days_min) && (days_test <= days_max)){
    	    printf("\t%s at:", myEvent[i].title);
        	if(myEvent[i].myTime.hour < 10){
        	    printf("\t\t0%d:", myEvent[i].myTime.hour);
        	}else{
        	    printf("\t\t%d:", myEvent[i].myTime.hour);
        	}
        	if(myEvent[i].myTime.min < 10){
        	    printf("0%d on:", myEvent[i].myTime.min);
        	}else{
        	    printf("%d on:", myEvent[i].myTime.min);
        	}
        	printf("\t%d/", myEvent[i].myDate.mon);
        	printf("%d/", myEvent[i].myDate.day);
        	printf("%d\n", myEvent[i].myDate.year);
    	}
	    
	}
//print all events information for event passed through
return;
}

int count_events(char *events, int eventnum, char *line, FILE *in_file, event_t *ptr){
	int event1 = 0;
	int event2 = 0;
	int event3 = 0;
	int event4 = 0;
	char word[20];
																							//input parameters: array of events
																							//create enum list for some of the event titles
    enum events{BIRTHDAY = 1 ,WEDDING = 2 ,ANNIVERSARY = 3 };
																							//use enum list to count how many times each event appears on the array
    enum events event_name;
    
    fseek(in_file, 0, SEEK_SET);
	while(!feof(in_file)){
	    fscanf(in_file, "%s", ptr->title);
		if (strcmp("Birthday", ptr->title) == 0){
		    event1++;
		}else if (strcmp("Wedding", ptr->title) == 0){
			event2++;
		}else if(strcmp("Anniversary", ptr->title) == 0){
			event3++;
		}else if(strcmp("Seminar", ptr->title) == 0){
		    event4++;
		}
	}
																							//print the above events information
	printf("Events:\n");
	printf("\tBirthday: %d\n", event1);
	printf("\tWedding: %d\n", event2);
	printf("\tAnniversary: %d\n", event3);
	printf("\tSeminar: %d", event4);
	return 0;
    
}