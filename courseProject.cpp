#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

FILE *master;
FILE *database;

struct Master{
	int id;
	char name[20];
};
	
	struct inputDatabase{
	int number;
	char lastName[30];
	char Name[50];
	char phoneNumber[20];
	char model[15];
	char brand[15];
	char imei[20];
	char work[300];
	int workValue;
	int detailsValue;
	int deliveryValue;
	int value;
	int day;
	int month;
	int year;
	char master[20];
};

void databaseOutput();
void databaseInput();
int workValue(char** work);
int details();
int delivery();
char *imei ();
char *lastname();
char *Name();
int Date ();
int Month ();
int Year ();
void phone (char * phoneNumber);
char *Brand();
char *Model();
void Master(char* mastersName);
void setup();
void MastersInput();
struct inputDatabase* synchronization(int *number);

main(){
	
	int choise, choise1;
	while(1){
		printf("Input code below:\n");
		printf("1-Input mode\n");
		printf("2-Output mode\n");
		printf("3-Setup mode\n");
		printf("4-Clean console\n");
		printf("5-Exit\n");
		scanf("%i",&choise);
	
		if(choise==1){
		while(1){
			system("cls");
			getchar();
			databaseInput();
			printf("Do you want to continue database work in input mode?\n");
			scanf("%i",&choise1);
			if(choise1==1){
				continue;
			}
			else{
				system("cls");
				getchar();
				break;
			} 
		}
		}
	
		if(choise==2){
			while(1){
				system("cls");
				getchar();
				databaseOutput();
				printf("Do you want to continue database work in output mode?\n");
				scanf("%i", &choise1);
				if(choise1==1){
					continue;
				}
				else{
					system("cls");
					fclose(database);
					break;
				}
			}
		}
	
	
		if(choise==3){
			while(1){
				system("cls");
				getchar();
				setup();
				printf("Do you want to continue database work in setup mode?\n");
				scanf("%i",&choise1);
				if(choise1==1){
					continue;
				}
				else{
				system("cls");
				getchar();
				break;
				}
				}
		}
		
		if(choise==4){
			system("cls");
			getchar();
		}
		
		if(choise==5){
			break;
		}
		else{
			fflush(stdin);
			continue;
		}
	}
	
}



void databaseOutput(){
	struct inputDatabase* base;
	int month, year;
	database=fopen("database.txt", "r");
	int parameter;
	int i, number;
	int count=0;
	int baseNumber;
	char* masterName = (char*) malloc(30);
	char* klientName = (char*) malloc(30);
	char* klientPhoneNumber = (char*) malloc(30);
	char* imeiNumber = (char*) malloc(30);
	base = synchronization(&number);
	while(1){
		printf("select the option to display the information:\n");
		printf("1-base number\n");
		printf("2-customer's last name\n");
		printf("3-customer's phone number\n");
		printf("4-imei\n");
		printf("5-master's name\n");
		printf("6-all\n");
		scanf("%i",&parameter);
		system("cls");
		getchar();

		if(parameter==1){
			printf("Input base number:\n");
			scanf("%i",&baseNumber);
			break;
		}				
		if(parameter==2){
			printf("Input customer's last name:\n");
			scanf("%s",klientName);
			break;
		}
		if(parameter==3){
			printf("Input customer's phone number:\n");
			scanf("%s",klientPhoneNumber);
			break;
		}
		if(parameter==4){
			printf("Input imei:\n");
			scanf("%s",imeiNumber);
			break;
		}				
		if(parameter==6 || parameter==5){
			printf("Search for:\n");
			while(1){
				printf("month:");
				scanf("%i",&month);
				getchar();
				if(month<=12){
					break;
				}
			}
			printf("year:");
			scanf("%i",&year);
			getchar();
			
			if(parameter==5){
				printf("Input master's name\n");
				scanf("%s",masterName);
				system("cls");
				getchar();
			}
		break;
		}
		else {
			printf("code is not correct!!!\n");
			continue;
		}
	}
		
	for(i=0;i<number;i++){	
		if(parameter==1){
			if(baseNumber==base[i].number){
				count=i;			
			}
		}
			
		if(parameter==2){
			if(0==strcmp(base[i].lastName, klientName)){
				base[count]=base[i];
				count++;
			}
		}
			
		if(parameter==3){
			if(0==strcmp(base[i].phoneNumber, klientPhoneNumber)){
				base[count]=base[i];
				count++;	
			}
		}
			
		if(parameter==4){
			if(0==strcmp(base[i].imei, imeiNumber)){
				base[count]=base[i];
				count++;	
			}
		}
						
		if(parameter==6 || parameter==5){
			if(base[i].year==year&&base[i].month==month){
				base[count]=base[i];
				count++;
			}
			if(parameter==5){
				if(0!=strcmp(base[i].master, masterName)){
					count--;
				}
			}		
		}			
	}
		
					
	if(parameter==1){
		printf("base number - %i\n", base[count].number);
		printf("phone brand - %s\n", base[count].brand);
		printf("phone model - %s\n", base[count].model);
		printf("imei - %s\n", base[count].imei);
		printf("customer's last name - %s ", base[count].lastName);
		printf("customer's name - %s\n", base[count].Name);
		printf("customer's phone number - %s\n", base[count].phoneNumber);
		printf("date - %i.", base[count].day);
		printf("%i.", base[count].month);
		printf("%i\n", base[count].year);
		printf("master - %s\n", base[count].master);
		printf("done work - %s\n", base[count].work);
		printf("work value - %i\n", base[count].workValue);
		printf("details value - %i\n", base[count].detailsValue);
		printf("delivery value - %i\n", base[count].deliveryValue);
		printf("value - %i\n", base[count].value);	
	}
	if(parameter==6 || parameter==5 || parameter==4 || parameter==3 || parameter==2){
		for(i=0;i<count;i++){	
			printf("\nbase number - %i\n", base[i].number);
			printf("phone brand - %s\n", base[i].brand);
			printf("phone model - %s\n", base[i].model);
			printf("imei - %s\n", base[i].imei);
			printf("customer's last name - %s ", base[i].lastName);
			printf("customer's name%s\n", base[i].Name);
			printf("nomer telefonu - %s\n", base[i].phoneNumber);
			printf("date - %i.", base[i].day);
			printf("%i.", base[i].month);
			printf("%i\n", base[i].year);
			printf("master - %s\n", base[i].master);
			printf("Done work - %s\n", base[i].work);
			printf("work value - %i\n", base[i].workValue);
			printf("details value - %i\n", base[i].detailsValue);
			printf("delivery value - %i\n", base[i].deliveryValue);
			printf("value - %i\n\n\n", base[i].value);	
		}
	}
}

void setup(){
		int count;
		
		printf("1-add master\n");
		scanf("%i",&count);
		while(1){
			if(count==1){
				MastersInput();
				break;
			}
			else {
				printf("Code is not correct!!!\n");
				continue;
			}
		}
	}

void MastersInput(){
	struct Master fileInput;
	int setup = 0;
	master=fopen("master.txt", "r");

	while(fscanf (master, "%i%s", &fileInput.id, fileInput.name)!=EOF)
		setup++;
	fclose(master);
	fileInput.id = setup + 1;
	printf("Input master's name\n");
	scanf("%s",fileInput.name);
	printf("Master %s number %i\n",fileInput.name, fileInput.id);
	system("cls");
	getchar();
	master=fopen("master.txt", "a");
	fprintf(master, "%i %s\n",fileInput.id, fileInput.name);
	fclose(master);
}
	
struct inputDatabase* synchronization(int* number){	
	int i=0, count;
	struct inputDatabase base;
	database=fopen("database.txt", "r");
	while(fscanf (database,"%i %s %s %s %s %s %s %i %i %i %s %s %i %i %i %i", &base.number, base.brand, base.model, base.imei, base.lastName, base.Name, base.phoneNumber, &base.day, &base.month, &base.year, base.master, base.work, &base.workValue, &base.detailsValue, &base.deliveryValue, &base.value)!=EOF){
	}
	fclose (database);
	*number = base.number;
	struct inputDatabase* array;
	array = (struct inputDatabase*)malloc(*number * sizeof(struct inputDatabase));
	
	database=fopen("database.txt", "r");
		
	for(i=0;i<*number;i++){	
		fscanf (database,"%i %s %s %s %s %s %s %i %i %i %s %s %i %i %i %i", &array[i].number, array[i].brand, array[i].model, array[i].imei, array[i].lastName, array[i].Name, array[i].phoneNumber, &array[i].day, &array[i].month, &array[i].year, array[i].master, array[i].work, &array[i].workValue, &array[i].detailsValue, &array[i].deliveryValue, &array[i].value);
	}
	fclose(database);
	return array;	
}
	

void databaseInput(){
	int summa,workPrice,detailsPrice,deliveryPrice,i;
	int date, month, year;
	char* Imei, *work;
	char* name, *lastName;
	char* marka, *model;
	char phoneNumber[20];
	char mastersName[20];
	int automaticly = 0;
	struct inputDatabase base;
		
		database=fopen("database.txt", "r");
		while(fscanf (database, "%i %s %s %s %s %s %s %i %i %i %s %s %i %i %i %i", &base.number, base.brand, base.model, base.imei, base.lastName, base.Name, base.phoneNumber, &base.day, &base.month, &base.year, base.master, base.work, &base.workValue, &base.detailsValue, &base.deliveryValue, &base.value)!=EOF)
			automaticly++;
		fclose(database);
		base.number = automaticly + 1;
		printf("Input date:\n");
		while(1){
			date = Date();
			month = Month ();
			year = Year ();
			printf("Data entered right?");
			scanf("%i",&i);		
			if(i==1){
				system("cls");
				getchar();
				break;
			}
			else{
				continue;
			} 
		}	
		while(1){
			marka = Brand();
			model = Model();
			Imei = imei();
			printf ("Data entered right?");
			scanf ("%i",&i);
			if(i==1){
				system("cls");
				getchar();
				break;
			}
			else{
				continue;
			}
		}
		while(1){
			lastName=lastname();
			name = Name();
		 	phone (phoneNumber);
			printf ("Data entered right?");
			scanf ("%i",&i);
			if(i==1){
				system("cls");
				getchar();
				break;
			}
			else{
				continue;
			}
		}
		workPrice = workValue(&work);
		system("cls");
		getchar();
		detailsPrice = details();
		system("cls");
		getchar();
		deliveryPrice = delivery();
		system("cls");
		getchar();
		summa=workPrice+detailsPrice+deliveryPrice;
		Master(mastersName);	
		system("cls");
		getchar();
		
		database=fopen("database.txt", "a");
		strcpy(base.brand, marka);
		strcpy(base.model, model);
		strcpy(base.imei, Imei);
		strcpy(base.lastName, lastName);
		strcpy(base.Name, name);
		strcpy(base.phoneNumber, phoneNumber);
		base.day = date;
		base.month = month;
		base.year = year;
		strcpy(base.master, mastersName);
		strcpy(base.work, work);
		base.workValue = workPrice;
		base.detailsValue = detailsPrice;
		base.deliveryValue = deliveryPrice;
		base.value = summa;
		
		fprintf(database, "%i ", base.number);
		fprintf(database, "%s ", base.brand);
		fprintf(database, "%s ", base.model);
		fprintf(database, "%s ", base.imei);
		fprintf(database, "%s ", base.lastName);
		fprintf(database, "%s ", base.Name);
		fprintf(database, "%s ", base.phoneNumber);
		fprintf(database, "%i ", base.day);
		fprintf(database, "%i ", base.month);
		fprintf(database, "%i ", base.year);
		fprintf(database, "%s ", base.master);
		fprintf(database, "%s ", base.work);
		fprintf(database, "%i ", base.workValue);
		fprintf(database, "%i ", base.detailsValue);
		fprintf(database, "%i ", base.deliveryValue);
		fprintf(database, "%i\n", base.value);
		fclose(database);
}


int workValue(char* *work){
	int workName, workPrice=0, a = 0, b=0;
	*work = (char*) malloc(300);
	**work=0;
	printf("Input work code:\n");
	while(1){
		printf("1-Change MicroUsb Connector\n");
		printf("2-Change touchscreen\n");
		printf("3-Change display\n");
		printf("4-Change module\n");
		printf("5-Clean after water\n");
		printf("6-Change battery\n");
		printf("7-Another\n");
		scanf("%i",&workName);
		workPrice+=workPrice;
	    if(a==1){
			strcat(*work, ",");	
		}
		switch (workName){
			case 1: workPrice=160;
				strcat (*work,"Change_MicroUsb");
				break;
			case 2: workPrice=270;
				strcat (*work,"Change_touchscreen");
				break;
			case 3: workPrice=300;
				strcat (*work, "Change_display" );
				break;
			case 4: workPrice=250; 
				strcat (*work, "Change_module");
				break;
			case 5: workPrice=120; 
				strcat (*work, "Clean_after_water");
				break;
			case 6: workPrice=50; 
				strcat (*work, "Change_battery" );
				break;
			case 7: 
				printf("Input name of repair:\n");
				scanf("%s",*work);
				printf ("Input value:\n");
				scanf ("%i", &workPrice);break;
			default: workPrice=0;
				printf("Code is uncorrect\n"); break;
		}
		b+=workPrice;
		printf("work value is: %i\n", b);
		printf("done work is: %s\n", *work);
		printf("Was some work done yet?\n");
		scanf("%i",&a);
		if (a==1){
			printf("Input code below:\n");
			continue;
		}
		else if (a==0){
			printf("Work value is: %i\n", b);
			break;
		}
	}
	return b;
}

int details(){
	int a, b=0, c=0;
	printf ("Was the money spent on the details?\n1-yes\n0-no\n");
	scanf("%i",&a);
		if (a==0){
			c=0;
		}
		if (a==1){
			while (1){
				printf("Input detail value:");
				scanf("%i",&b);
				c+=b;
				printf("were there any more details??");
				scanf("%i",&a);
			if (a==1){
				continue;
			}
			if (a==0){
				break;
			}
		}
	}
	if (a!=1&&a!=0){ 
		printf("Code is uncorrect!!!\n");
	}
	printf("You spent %i grn for details\n", c);
	return c;
}


int delivery(){
	int summa=0,b=0,a;
	printf("Was the money spent on the delivery?\n");
	while(1){
		scanf("%i",&a);
		if (a==1){
			printf("Input delivery value:");
			scanf("%i",&summa);
			break;
		}
		if (a==0){
			summa=0;
			break;
		}
		else {
			printf("Code is uncorrect!!!\n");
			continue;
		}
	}
	b+=summa;
	printf("Was there any extra money spent?\n");
	while(1){
		scanf("%i",&a);
		if (a==1){
			printf("Input value:\n");
			scanf("%i",&summa);
			break;
		}
		if (a==0){
			summa=0;
			break;
		}
		else {
			printf("Code is uncorrect!!!\n");
			continue;
		}
	
	}
	b+=summa;
	printf("You spent %i grn for delivery\n",b);
	return b;
}

int Date (){
	int date;
	while(1){
		printf("Input day:\n");
		scanf("%i",&date);
		if(date<=31) break;
	}
	return date;
}
int Month (){
	int Month;
	while(1){
		printf("Input month:\n");
		scanf("%i",&Month);
		if(Month<=12) break;
	}
	return Month;
}
int Year (){
	int Year;
	printf("Input year:\n");
	scanf("%i",&Year);
	return Year;
}

void phone (char * phoneNumber){
	printf("Input phone number\n");
	scanf("%s",phoneNumber);
}


char *imei(){
	char *kod=(char *)malloc(30);
	printf("Input imei\n");
	scanf("%s",kod);
	return kod;
}


char *lastname (){

	char *lastName = (char*)malloc(30);
	printf("Input last name:\n");
	scanf("%s",lastName);
	return lastName;
}

char *Name (){
	char *Name = (char*)malloc(50);
	printf("Input name:\n");
	scanf("%s",Name);
	return Name;
}

char *Brand(){
	char *Brand = (char*)malloc(30);
	printf("Input brand\n");
	scanf("%s",Brand);
	return Brand;
}


char *Model(){
	char *Model = (char*)malloc(30);
	printf("Input model:\n");
	scanf("%s",Model);
	return Model;
}

void Master(char* mastersName){
	int i, count;
	master=fopen("master.txt", "r");
	struct Master base;
	printf("Choose master:\n");
	while(fscanf (master, "%i%s", &base.id, base.name)!=EOF){
		printf("%i - %s\n", base.id, base.name);
	}
	scanf("%i", &count);
	fclose(master);
	master=fopen("master.txt", "r");
	for(i=0;i<count;i++){
		fscanf (master, "%i%s", &base.id, base.name);
	}
	printf("%s\n", base.name);
	strcpy(mastersName,base.name);
	fclose(master);
}
