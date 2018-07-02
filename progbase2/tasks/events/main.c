#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>




enum {
	KeyInputEventTypeId
};

/* event handler functions prototypes */
void KeyInputHandler_update(EventHandler * self, Event * event);
void KeyInputListener_update(EventHandler * self, Event * event);


struct park{
	int cars[5];
};
typedef struct park park;



void frees(void * self){
	free(self);
}

void addcar( park *self, int position);
void print(park * self);
void delcar(park *self, int position);
int getnumber(park *self, int position);
int checkcar(park *self, int position);

int main(void) {
	// startup event system
	park * park1 = malloc(sizeof(struct park));
	for(int i = 0; i < 5 ;i++){
		park1->cars[i] = 0;
	}

	EventSystem_init();

	// add event handlers
	EventSystem_addHandler(EventHandler_new(NULL,NULL, KeyInputHandler_update));
	EventSystem_addHandler(EventHandler_new(park1, frees, KeyInputListener_update));




	// start infinite event loop
	EventSystem_loop();
	// cleanup event system
	EventSystem_cleanup();


	return 0;
}







/* event handlers functions implementations */

void KeyInputHandler_update(EventHandler * self, Event * event) {
	if (conIsKeyDown()) {  // non-blocking key input check
		char * keyCode = malloc(sizeof(char));
		*keyCode = getchar();
		
		if (*keyCode == 27) {  // Escape key code
			free(keyCode);
			EventSystem_exit();	
		}  	
		else {
			EventSystem_raiseEvent(Event_new(self, KeyInputEventTypeId, keyCode, free));
		}
	}
}

void KeyInputListener_update(EventHandler * self, Event * event) {
	
	switch(event->type) {
		case StartEventTypeId: {
			puts("Press [Esc] to exit");
			break;
		}
		
		case KeyInputEventTypeId: {
			char keyCode = *(char *)event->data;
			if(keyCode == '1'){
				if(checkcar(self->data, 0) == 0){
					addcar(self->data , 0);
					puts("\nМашина 1 вїхала на парковку");
				}
				else{
					delcar(self->data , 0);
					puts("\nМашина 1 виїхала з парковки");
				}
			}
			if(keyCode == '2'){
				if(checkcar(self->data, 1) == 0){
					addcar(self->data , 1);
					puts("\nМашина 2 вїхала на парковку");
				}
				else{
					delcar(self->data , 1);
					puts("\nМашина 2 виїхала з парковки");
				}
			}
			if(keyCode == '3'){
				if(checkcar(self->data, 2) == 0){
					addcar(self->data , 2);
					puts("\nМашина 3 вїхала на парковку");
				}
				else{
					delcar(self->data , 2);
					puts("\nМашина 3 виїхала з парковки");
				}
			}
			if(keyCode == '4'){
				if(checkcar(self->data, 3) == 0){
					addcar(self->data , 3);
					puts("\nМашина 4 вїхала на парковку");		
				}
				else{
					delcar(self->data , 3);
					puts("\nMашина 4 виїхала з парковки");
				}
			}
			if(keyCode == '5'){
				if(checkcar(self->data, 4) == 0){
					addcar(self->data , 4);
					puts("\nМашина 5 вїхала на парковку");
				}
				else{
					delcar(self->data , 4);
					puts("\nМашина 5 виїхала з парковки");					
				}
				
			}	 	
		
			print(self->data);
			break;
		}
	}
}


void addcar(park *self, int position){
	self->cars[position] = 1;
}

void delcar(park *self, int position){
	self->cars[position] = 0;
}
int getnumber(park *self, int position){
	return self->cars[position];
}


int checkcar(park *self, int position){
	if(self->cars[position] == 1){
		return 1;
	}
	else{
		return 0;
	}
}

void print(park * self){
	int count = 0;
	for(int i = 0; i < 5; i++){
		if(self->cars[i] != 0){
			count ++;
		}	
	}
	conSetAttr(FG_RED);
	printf("\nКількість машин на парковкі - %i\n", count);
	conReset();
}







