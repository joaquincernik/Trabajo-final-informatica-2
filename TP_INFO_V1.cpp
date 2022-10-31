#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
	string city_name;
};

//ESTRUCTURA DE PROVINCIAS
struct cordoba
{
	int cba_id;
	struct city c;
	struct cordoba *next;
};

struct santa_fe
{
	int stfe_id;
	struct city c;
	struct santa_fe *next;
};

struct mendoza
{
	int mendoza_id;
	struct city c;
	struct mendoza *next;
};

//ESTRUCTURA DE PROVINCIAS





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

	/*char escritura=' ';
	while(!feof(fp))
	{
		escritura=getc(fp);
		cout<<escritura;
	}
	
	struct provincias *punt;
	struct city *pont;
	
	while(!feof(fp))
	{
		fscanf(fp,"%d",&p.c.cityld);
		temp=temp->next;
	}
	
	while(1!=0)
	{
		printf("%d \n",p.c.cityld);
	}
	
	while(1!=0)
	{
		printf("%d \n",punt->c.cityld);
		
	}*/

	do
	{
		new_node_c=(struct cordoba*)malloc(sizeof(struct cordoba));
		
		if(new_node_c==NULL)
		{
			printf("No hay memoria suficiente para cordoba. \n");
		}
		
		fscanf(fp,"%d %d %s %f %f %d %d %d %d",&new_node_c->c.cityld,&new_node_c->cba_id,&new_node_c->c.city_name,&new_node_c->c.m.temp,&new_node_c->c.m.hum,&new_node_c->c.m.time.hh,&new_node_c->c.m.time.mm,&new_node_c->c.m.time.day,&new_node_c->c.m.time.month);
		new_node_c->next=NULL;
		
		if(new_node_c->cba_id==1)
		{
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
		else
		{
			free(new_node_c);
		}
	}
	while(new_node_c->cba_id==1);

	
	printf("Ciudad Id | Provincia Id | Ciudad | Temperatura | Humedad | Hora | Min | Dia | Mes \n\n");
	temp_c=head_c;
	while(temp_c!=NULL)
	{
		printf("    %d           %d          %s      %f           %f         %d    %d     %d    %d\n",temp_c->c.cityld,temp_c->cba_id,temp_c->c.city_name,temp_c->c.m.temp,temp_c->c.m.hum,temp_c->c.m.time.hh,temp_c->c.m.time.mm,temp_c->c.m.time.day,temp_c->c.m.time.month);
		temp_c=temp_c->next;
	}
	
	
	
	
	printf("hola");

	
	
	return 0;
}

