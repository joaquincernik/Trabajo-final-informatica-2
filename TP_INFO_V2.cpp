#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

struct timestamp
{
	int day;
	int month;
	int hh;
	int mm;
};

struct measurement
{
	float temp;
	float hum;
	struct timestamp time;
};

struct city
{
	struct city *next;
	struct measurement m;
	int cityld;
	char city_name[50];
};

struct cordoba
{
	int cba_id;
	struct city c;
	struct cordoba *next;
};

struct santa_fe
{
	int sf_id;
	struct city c;
	struct santa_fe *next;
};

struct mendoza
{
	int men_id;
	struct city c;
	struct mendoza *next;
};
int menu();
void cant_muestras(struct cordoba**, struct santa_fe**, struct mendoza**);
void temp_prom(struct cordoba**, struct santa_fe**, struct mendoza**);
void temp_prom_city(struct cordoba**, struct santa_fe**, struct mendoza**);
int main(int argc, char *argv[]) {
	
	struct cordoba* head_c=NULL;
	struct cordoba* temp_c=NULL;			//Punteros Cba
	struct cordoba* new_node_c=NULL;
	
	struct santa_fe* head_sf=NULL;
	struct santa_fe* temp_sf=NULL;      	//Punteros Santa Fe
	struct santa_fe* new_node_sf=NULL;
	
	struct mendoza* head_m=NULL;
	struct mendoza* temp_m=NULL;			//Punteros Mendoza
	struct mendoza* new_node_m=NULL;
	
	FILE *fp=NULL; /*Puntero Abrir Archivo*/
	
	fp=fopen("./data_set.txt", "r");  /*Funcion abrir data_set.txt*/
	
	if(fp==NULL)											
	{
		printf("Es imposible abrir el archivo. \n\n");  /* Check Funcion Abrir */
		exit(1);
	}

	int d,f,g,h,j,k;
	char cadena1[50];
	float f1,f2;
	while(!feof(fp)){
		fscanf(fp,"%d %d %s %f %f %d %d %d %d",&d,&f,&cadena1,&f1,&f2,&g,&h,&j,&k);
		
		if(f==1){
			
			new_node_m=(struct mendoza*)malloc(sizeof(struct mendoza));
			
			if(new_node_m==NULL)
			{
				printf("No hay memoria suficiente para cordoba. \n");
				exit(0);
			}
			new_node_m->c.cityld= d;
			new_node_m->men_id= f;
			strcpy(new_node_m->c.city_name, cadena1);
			new_node_m->c.m.temp= f1;
			new_node_m->c.m.hum= f2;
			new_node_m->c.m.time.hh= g;
			new_node_m->c.m.time.mm= h;
			new_node_m->c.m.time.day= j;
			new_node_m->c.m.time.month= k;
			
			new_node_m->next=NULL;
			
			if(head_m==NULL)
			{
				head_m=new_node_m;
			}
			else
			{
				temp_m=head_m;
				while (temp_m->next != NULL)
				{
					temp_m=temp_m->next;
				}
				temp_m->next=new_node_m;
			}
		}
		if(f==2){
			
			new_node_sf=(struct santa_fe*)malloc(sizeof(struct santa_fe));
			
			if(new_node_sf==NULL)
			{
				printf("No hay memoria suficiente para cordoba. \n");
				exit(0);
			}
			new_node_sf->c.cityld= d;
			new_node_sf->sf_id= f;
			strcpy(new_node_sf->c.city_name, cadena1);
			new_node_sf->c.m.temp= f1;
			new_node_sf->c.m.hum= f2;
			new_node_sf->c.m.time.hh= g;
			new_node_sf->c.m.time.mm= h;
			new_node_sf->c.m.time.day= j;
			new_node_sf->c.m.time.month= k;
			
			new_node_sf->next=NULL;
			
			if(head_sf==NULL)
			{
				head_sf=new_node_sf;
			}
			else
			{
				temp_sf=head_sf;
				while (temp_sf->next != NULL)
				{
					temp_sf=temp_sf->next;
				}
				temp_sf->next=new_node_sf;
			}
		}
		if(f==3){
			
			new_node_c=(struct cordoba*)malloc(sizeof(struct cordoba));
			
			if(new_node_c==NULL)
			{
				printf("No hay memoria suficiente para cordoba. \n");
				exit(0);
			}
			new_node_c->c.cityld= d;
			new_node_c->cba_id= f;
			strcpy(new_node_c->c.city_name, cadena1);
			new_node_c->c.m.temp= f1;
			new_node_c->c.m.hum= f2;
			new_node_c->c.m.time.hh= g;
			new_node_c->c.m.time.mm= h;
			new_node_c->c.m.time.day= j;
			new_node_c->c.m.time.month= k;
			
			new_node_c->next=NULL;
			
			if(head_c==NULL)
			{
				head_c=new_node_c;
			}
			else
			{
				temp_c=head_c;
				while (temp_c->next != NULL)
				{
					temp_c=temp_c->next;
				}
				temp_c->next=new_node_c;
			}
		}
	}
	int opcion=0;
	do {
		opcion= menu();
		switch (opcion)
		{
		case 0:
			printf ("Adios ¡Gracias!");
			break;
		case 1:
			temp_m=head_m;
			temp_sf=head_sf;
			temp_c=head_c;
			cant_muestras(&temp_c,&temp_sf,&temp_m);
			break;
		case 2:
			temp_m=head_m;
			temp_sf=head_sf;
			temp_c=head_c;
			temp_prom(&temp_c,&temp_sf,&temp_m);
			break;
		case 3:
			temp_m=head_m;
			temp_sf=head_sf;
			temp_c=head_c;
			temp_prom_city(&temp_c,&temp_sf,&temp_m);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}while (opcion !=0);
	printf("Ciudad Id | Provincia Id | Ciudad | Temperatura | Humedad | Hora | Min | Dia | Mes \n\n");
	temp_c=head_c;
	while(temp_c!=NULL)
	{
		cout<<temp_c->c.cityld<<"\t"<<temp_c->cba_id<<"\t"<<temp_c->c.city_name<<"\t"<<temp_c->c.m.temp<<"\t"<<temp_c->c.m.hum<<"\t"<<temp_c->c.m.time.hh<<"\t"<<temp_c->c.m.time.mm<<"\t"<<temp_c->c.m.time.day<<"\t"<<temp_c->c.m.time.month<<endl;
		temp_c=temp_c->next;
	}
	/*printf("Ciudad Id | Provincia Id | Ciudad | Temperatura | Humedad | Hora | Min | Dia | Mes \n\n");
	temp_sf=head_sf;
	while(temp_sf!=NULL)
	{
		printf("    %d           %d          %s      %f           %f         %d    %d     %d    %d\n",new_node_sf->c.cityld,new_node_sf->sf_id,new_node_sf->c.city_name,new_node_sf->c.m.temp,new_node_sf->c.m.hum,new_node_sf->c.m.time.hh,new_node_sf->c.m.time.mm,new_node_sf->c.m.time.day,new_node_sf->c.m.time.month);
		temp_sf=temp_sf->next;
	}
	printf("hola");*/
	
	return 0;
}
int menu()
{
	int opcion=0;
	printf ("1: Total de las muestras almacenadas en las listas pertenecientes a cada provincia.\n");
	printf ("2: Temperatura promedio de cada provincia.\n3: Temperatura promedio de cada ciudad.\n");
	printf ("4: Ciudad mas calida de cada provincia.\n5: Ciudad mas fria de cada provincia\n6: Dia mas frio de cada provincia.\n");
	printf ("7: Dia mas calido de cada ciudad.\n8: Mejor provincia para el cultivo de pimientos.\nElija la opcion que desee ver: ");
	scanf("%d",&opcion);
	return (opcion);
}
void cant_muestras(struct cordoba** temp_c, struct santa_fe** temp_sf, struct mendoza** temp_m){
	int acum= 0;
	printf("--------------------------------------------\n");
	//OPCION 1 DEL MENU (MENDOZA)
	while(*temp_m!=NULL)
	{
		acum++;						
		*temp_m=(*temp_m)->next;
	}
	printf("Hay %d muestras de Mendoza\n", acum*2); 
	acum= 0;
	//OPCION 1 DEL MENU (SANTA FE)
	while(*temp_sf!=NULL)
	{
		acum++;						
		*temp_sf=(*temp_sf)->next;
	}
	printf("Hay %d muestras de Santa Fe\n", acum*2); 
	acum= 0;
	//OPCION 1 DEL MENU (CORDOBA)
	while(*temp_c!=NULL)
	{
		acum++;						
		*temp_c=(*temp_c)->next;
	}
	printf("Hay %d muestras de Cordoba\n", acum*2); 
	printf("--------------------------------------------\n");
}
void temp_prom(struct cordoba** temp_c, struct santa_fe** temp_sf, struct mendoza** temp_m){
	
	int acum= 0;
	double suma= 0;
	printf("--------------------------------------------\n");
	//OPCION 1 DEL MENU (MENDOZA)
	while(*temp_m!=NULL)
	{
		acum++;	
		suma+= (*temp_m)->c.m.temp;
		*temp_m=(*temp_m)->next;
	}
	printf("Temperatura promedio de Mendoza: %f\n", ((float)suma/acum)); 
	acum= 0;
	suma= 0;
	while(*temp_sf!=NULL)
	{
		acum++;	
		suma+= (*temp_sf)->c.m.temp;
		*temp_sf=(*temp_sf)->next;
	}
	printf("Temperatura promedio de Santa Fe: %f\n", ((float)suma/acum)); 
	acum= 0;
	suma= 0;
	while(*temp_c!=NULL)
	{
		acum++;	
		suma+= (*temp_c)->c.m.temp;
		*temp_c=(*temp_c)->next;
	}
	printf("Temperatura promedio de Cordoba: %f\n", ((float)suma/acum)); 
	printf("--------------------------------------------\n");
}
void temp_prom_city(struct cordoba** temp_c, struct santa_fe** temp_sf, struct mendoza** temp_m){
	int acum= 0, ii= 0;
	double suma= 0;
	FILE *fp=fopen("./data_set.txt", "r");
	while((*temp_c)!=NULL){
		while((*temp_c)->c.cityld == ii){
			acum++;
			suma+= (*temp_c)->c.m.temp;
			(*temp_c)= (*temp_c)->next; 
		}
		cout<<"Temperatura prom de "<<(*temp_c)->c.city_name<<" es: "<<((float)suma/acum)<<endl;
		ii++;
		
	}
	/*
		if((*temp_sf)->c.cityld == ii){
			acum++;
			suma+= (*temp_sf)->c.m.temp;
			cout<<"Temperatura prom de "<<(*temp_sf)->c.city_name<<" es: "<<((float)suma/acum)<<endl;
		}
		if((*temp_m)->c.cityld == ii){
			acum++;
			suma+= (*temp_m)->c.m.temp;
			cout<<"Temperatura prom de "<<(*temp_m)->c.city_name<<" es: "<<((float)suma/acum)<<endl;
		}
		ii++;
	}*/
	
}//HAGANLO XD A MI NO ME SALE
