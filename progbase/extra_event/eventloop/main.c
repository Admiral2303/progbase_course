#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>



#include <xml_func.h>

/* custom constant event type ids*/
enum {
	KeyInputEventTypeId,
	FileRead,
	Exit,
	FileWrite,
	DefaultRead,
	StructRead,
	ChangeName,
	ChangeSalary,
	ChangeScore
};







typedef struct Configuration Configuration;


/* event handler functions prototypes */
void KeyInputHandler_update(EventHandler * self, Event * event);
void KeyInputListener_update(EventHandler * self, Event * event);
void Change_option(EventHandler * self, Event * event);

void XmlLoader_loadConfiguration(Configuration * self, char * xmlStr);
void file_read(EventHandler * self, Event * event);

void free_char(void * self){
	char * str = self;
	free(str);
	str = NULL;
}

int main(void) {
	
	
	
	// startup event system
	EventSystem_init();
	
	// add event handlers
	EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
	Configuration *config = Conf_new();
	EventSystem_addHandler(EventHandler_new(config,free_config,Change_option));	
	Freelancer * self = Freelancer_new();
	//EventSystem_addHandler(EventHandler_new(config, free, file_read));
	EventSystem_addHandler(EventHandler_new(self,free_freelancer,file_read));
	// start infinite event loop
	EventSystem_loop();
	// cleanup event system
	EventSystem_cleanup();
	return 0;
}

/* event handlers functions implementations */

void KeyInputHandler_update(EventHandler * self, Event * event) {
		conClear();
		puts("1.Ввести шлях до xml файла");
		puts("\nЗмітини поле структури:");
		puts("3.Змінити імя");
		puts("4.Змінити заробітню плату");
		puts("5.Змінити рейтинг");
		if (conIsKeyDown()) {  // non-blocking key input check
			char * keyCode = malloc(sizeof(char));
			*keyCode = getchar();
			if (*keyCode == 27) {  // Escape key code
				free(keyCode);
				EventSystem_exit();	
			}
			else if(*keyCode == 49){
				EventSystem_raiseEvent(Event_new(self, KeyInputEventTypeId, keyCode, free));
			}
			else if(*keyCode == 51){
				EventSystem_raiseEvent(Event_new(self, FileWrite, keyCode, free));
			}
			else if(*keyCode == 52){
				EventSystem_raiseEvent(Event_new(self, FileWrite, keyCode, free));
			}
			else if(*keyCode == 53){
				EventSystem_raiseEvent(Event_new(self, FileWrite, keyCode, free));
			}
		}	
		
}	

void Change_option(EventHandler * self, Event * event) {
	switch (event->type) {
		case KeyInputEventTypeId: {
			char keyCode = *(char *)event->data;
			if(keyCode == '1'){
				puts("VVedit filepath");
				char str[100];
				scanf("%s", str);
				change_filepath(self->data,str);
				char* text = malloc(1000*sizeof(char));
				text[0] = '\0';
				char * filepath = Filepath_get(self->data);
				readAllText(filepath, text);
				free(filepath);
				Save_configuration("configuration.xml", self->data);
				EventSystem_raiseEvent(Event_new(self, FileRead, text, free));
				break;
			}
		}
	}
}


void file_read(EventHandler * self, Event * event){
	switch (event->type) {
		case FileRead: {
			XmlLoader_loadFromString(self->data, event->data); 
			EventSystem_raiseEvent(Event_new(NULL, FileWrite, self->data, NULL));
			break;
		}	
		case FileWrite:{
			char keyCode = *(char *)event->data;
			if(keyCode == '3'){
				XmlLoader_loadConfiguration(self->data, "configuration.xml");
				char * text1= malloc(1000*sizeof(char));
				text1[0] = '\0';
				char * filepath1 = Filepath_get(self->data);
				readAllText(filepath1, text1);
				free(filepath1);
				XmlLoader_loadFromString(self->data, text1);
				free(text1);
				conSetAttr(FG_GREEN);
				puts("\n-----------------");
				conReset();
				puts("Введіть імя");
				conSetAttr(FG_GREEN);
				puts("-----------------");
				conReset();
				char name[100];
				scanf("%s", name);
				set_Name(self->data, name);
			}
			if(keyCode == '4'){
				XmlLoader_loadConfiguration(self->data, "configuration.xml");
				char * text1= malloc(1000*sizeof(char));
				text1[0] = '\0';
				char * filepath1 = Filepath_get(self->data);
				readAllText(filepath1, text1);
				free(filepath1);
				XmlLoader_loadFromString(self->data, text1);
				free(text1);
				conSetAttr(FG_GREEN);
				puts("\n-----------------");
				conReset();
				puts("Введіть зарплату");
				conSetAttr(FG_GREEN);
				puts("-----------------");
				conReset();
				int salary = 0;
				scanf("%i", &salary);
				set_Salary(self->data, salary);
			}
			if(keyCode == '5'){
				XmlLoader_loadConfiguration(self->data, "configuration.xml");
				char * text1= malloc(1000*sizeof(char));
				text1[0] = '\0';
				char * filepath1 = Filepath_get(self->data);
				readAllText(filepath1, text1);
				free(filepath1);
				XmlLoader_loadFromString(self->data, text1);
				free(text1);
				conSetAttr(FG_GREEN);
				puts("\n-----------------");
				conReset();
				puts("Введіть рейтинг");
				conSetAttr(FG_GREEN);
				puts("-----------------");
				conReset();
				float score = 0.0;
				scanf("%f",&score);
				set_Score(self->data, score);
			}
			XmlLoader_saveToFile(self->data,"struct.xml");
			EventSystem_raiseEvent(Event_new(NULL,DefaultRead, NULL, NULL));
			break;
		}
	 }
}





