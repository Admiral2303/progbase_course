#ifndef LAB_3
#define LAB_3


struct profecional{
	char profname[100];
	int salary;
	float score;
	struct  {
		char name[100];
		char surname[100];
		int year;
	} information;
};

void cat();																																				//// cat



void stringtostruct( struct profecional * profs[]);																/////
int enterstuct(void);
void texttostruct(struct profecional * profs[]);
void structtostring( struct profecional * profs[]);
void structtotext(struct profecional * profs[]);
//void deletestruct(struct profecional * profs[]);
void copystruct (struct profecional * profs[]);
void rewritefiealdinstruct(struct profecional * profs[]);
int fileread(const char * readFileName, struct profecional *profs[]);							/////	main functions
int filewrite(struct profecional *profs[]);
void highestsalary(struct profecional *profs[]);
char filename(char str[100]);
//void deleteallstruct(struct profecional *profs[]);
void printstructs(struct profecional * profs[] ,int i, char *str);								/////
int filecheck(const char * readFileName);
int validtestfloat(char *str);
int validtest( char *str);
int checksalary(struct profecional *profs[],int i, int midsalary);								/////


int deltstruct1(struct profecional * profs[],int i);
void deletestruct(struct profecional * profs[]);

int scanint(char * str);
int checkstruct(struct profecional * profs[],int i);
struct profecional * copstr(struct profecional * profs[],int i ,int k);

#endif //LAB_3



/*void line();																										//////
void printfirstmenu();
void clearmainmenu();
void printsecondmenu();
void clearstringtostruct();																			///// MENU
void clear();
void rewhelp(int i, int j);
void clearfield();
void printthirdmenu();
void cleanall();
void cleanstr(int i, int j);																		/////*/







/*void validtesting();
void validtestfloatin();
void check (struct profecional * profs[]);
void filetest();	*/
