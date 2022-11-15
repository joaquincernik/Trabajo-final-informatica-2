#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>

class clase{
private:
	FILE *fp= NULL;
public:
	clase();
	void setFilePointer();
	FILE* getFilePointer();
	
};
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
void cant_muestras(struct cordoba*, struct santa_fe*, struct mendoza*);
void temp_prom(struct cordoba*, struct santa_fe*, struct mendoza*);
void temp_prom_city(struct cordoba*, struct santa_fe*, struct mendoza*);
void ciudad_mas_calida(struct cordoba*,struct santa_fe*,struct mendoza*);
void ciudad_mas_fria(struct cordoba*,struct santa_fe*,struct mendoza*);
void dia_mas_frio(struct cordoba*,struct santa_fe*,struct mendoza*);
void dia_mas_calido_city(struct cordoba*,struct santa_fe*,struct mendoza*);
void provincia_para_pimientos(struct cordoba*,struct santa_fe*,struct mendoza*);

clase::clase(){
	
}
void clase::setFilePointer(){
	fp= fopen("./data_set.txt", "r");
}
FILE* clase::getFilePointer(){
	return(fp);
}
int menu(){
	int opcion=0;
	printf ("1: Total de las muestras almacenadas en las listas pertenecientes a cada provincia.\n");
	printf ("2: Temperatura promedio de cada provincia.\n3: Temperatura promedio de cada ciudad.\n");
	printf ("4: Ciudad mas calida de cada provincia.\n5: Ciudad mas fria de cada provincia\n6: Dia mas frio de cada provincia.\n");
	printf ("7: Dia mas calido de cada ciudad.\n8: Mejor provincia para el cultivo de pimientos.\nElija la opcion que desee ver: ");
	scanf("%d",&opcion);
	return (opcion);
}
void cant_muestras(struct cordoba* temp_c, struct santa_fe* temp_sf, struct mendoza* temp_m){
	int acum= 0;
	printf("--------------------------------------------\n");
	//OPCION 1 DEL MENU (MENDOZA)
	while(temp_m!=NULL)
	{
		acum++;						
		temp_m=(temp_m)->next;
	}
	printf("Hay %d muestras de Mendoza\n", acum*2); 
	acum= 0;
	//OPCION 1 DEL MENU (SANTA FE)
	while(temp_sf!=NULL)
	{
		acum++;						
		temp_sf=(temp_sf)->next;
	}
	printf("Hay %d muestras de Santa Fe\n", acum*2); 
	acum= 0;
	//OPCION 1 DEL MENU (CORDOBA)
	while(temp_c!=NULL)
	{
		acum++;						
		temp_c=(temp_c)->next;
	}
	printf("Hay %d muestras de Cordoba\n", acum*2); 
	printf("--------------------------------------------\n");
}
void temp_prom(struct cordoba* temp_c, struct santa_fe* temp_sf, struct mendoza* temp_m){		
	int acum= 0;
	double suma= 0;
	
	printf("--------------------------------------------\n");
	while(temp_m!=NULL)
	{
		acum++;	
		suma+= (temp_m)->c.m.temp;
		temp_m=(temp_m)->next;
	}
	printf("Temperatura promedio de Mendoza: %f\n", ((float)suma/acum)); 
	acum= 0;
	suma= 0;
	while(temp_sf!=NULL)
	{
		acum++;	
		suma+= (temp_sf)->c.m.temp;
		temp_sf=(temp_sf)->next;
	}
	printf("Temperatura promedio de Santa Fe: %f\n", ((float)suma/acum)); 
	acum= 0;
	suma= 0;
	while(temp_c!=NULL)
	{
		acum++;	
		suma+= (temp_c)->c.m.temp;
		temp_c=(temp_c)->next;
	}
	printf("Temperatura promedio de Cordoba: %f\n", ((float)suma/acum)); 
	printf("--------------------------------------------\n");
}
void temp_prom_city(struct cordoba* temp_c, struct santa_fe* temp_sf, struct mendoza* temp_m){
	int acum= 0, ii= 0;
	double suma= 0;
	char aux[50];
	
	ii=(temp_m)->c.cityld;
	printf("-----MENDOZA-----\n");
	while(temp_m!=NULL){
		if(ii==((temp_m)->c.cityld)){
			acum++;	
			suma+= (temp_m)->c.m.temp;
			strcpy(aux, ((temp_m)->c.city_name));
			temp_m=(temp_m)->next;
		}
		else{
			printf("%s:\t%f\n", aux, (float)suma/acum);
			ii=(temp_m)->c.cityld;
			suma=0;
			acum=0;
			
		}
	}
	printf("%s:\t%f\n", aux, (float)suma/acum);//DEBIDO A QUR AL SER LA ULTIMA MUESTRA NO ENTRA AL ELSE LO IMPRIMIMOS DE LA SIGUIENTE MANERA
	acum= 0;
	suma= 0;
	ii=(temp_c)->c.cityld;
	printf("-----CORDOBA-----\n");
	while(temp_c!=NULL){
		if(ii==((temp_c)->c.cityld)){
			acum++;	
			suma+= (temp_c)->c.m.temp;
			strcpy(aux, ((temp_c)->c.city_name));
			temp_c=(temp_c)->next;
		
		}
		else{
			printf("%s:\t%f\n", aux, (float)suma/acum);
			ii=(temp_c)->c.cityld;
			suma=0;
			acum=0;
		}
	}
	printf("%s:\t%f\n", aux, (float)suma/acum);
	acum= 0;
	suma= 0;
	ii=(temp_sf)->c.cityld;
	printf("-----SANTA FE-----\n");
	while(temp_sf!=NULL){
		if(ii==((temp_sf)->c.cityld)){
			acum++;	
			suma+= (temp_sf)->c.m.temp;
			strcpy(aux, ((temp_sf)->c.city_name));
			temp_sf=(temp_sf)->next;
			
		}
		else{
			printf("%s:\t%f\n", aux, (float)suma/acum);
			ii=(temp_sf)->c.cityld;
			suma=0;
			acum=0;
		}
	}
	printf("%s:\t%f\n", aux, (float)suma/acum);
	printf("\n");
}
void ciudad_mas_calida(struct cordoba* temp_c,struct santa_fe* temp_sf,struct mendoza* temp_m){
	float max_temp_m=0;
	char ciudad_mas_calida_m[50];
	float max_temp_c=0;
	char ciudad_mas_calida_c[50];
	float max_temp_sf=0;
	char ciudad_mas_calida_sf[50];
	//ciudad mas calida de mendoza
	while(temp_m!=NULL){
		if(max_temp_m==0){
			max_temp_m=temp_m->c.m.temp;
			strcpy(ciudad_mas_calida_m,temp_m->c.city_name);
		}
		else{
			if(max_temp_m<temp_m->c.m.temp){
				max_temp_m=temp_m->c.m.temp;
				strcpy(ciudad_mas_calida_m,temp_m->c.city_name);
			}
		}
		temp_m=temp_m->next;
	}
	printf("La maxima temperatura de mendoza es %0.2f grados, correspondiente a la ciudad de %s\n",max_temp_m,ciudad_mas_calida_m);
	
	//ciudad mas calida de cordoba
	while(temp_c!=NULL){
		if(max_temp_c==0){
			max_temp_c=temp_c->c.m.temp;
			strcpy(ciudad_mas_calida_c,temp_c->c.city_name);
		}
		else{
			if(max_temp_c<temp_c->c.m.temp){
				max_temp_c=temp_c->c.m.temp;
				strcpy(ciudad_mas_calida_c,temp_c->c.city_name);
			}
		}
		temp_c=temp_c->next;
	}
	printf("La maxima temperatura de Cordoba es %0.2f grados, correspondiente a la ciudad de %s\n",max_temp_c,ciudad_mas_calida_c);
	
	//ciudad mas calida de Santa Fe
	while(temp_sf!=NULL){
		if(max_temp_sf==0){
			max_temp_sf=temp_sf->c.m.temp;
			strcpy(ciudad_mas_calida_sf,temp_sf->c.city_name);
		}
		else{
				if(max_temp_sf<temp_sf->c.m.temp){
				max_temp_sf=temp_sf->c.m.temp;
				strcpy(ciudad_mas_calida_sf,temp_sf->c.city_name);
			}
		}
		temp_sf=temp_sf->next;
	}
	printf("La maxima temperatura de Santa Fe es %0.2f grados, correspondiente a la ciudad de %s\n",max_temp_sf,ciudad_mas_calida_sf);
}
void ciudad_mas_fria(struct cordoba* temp_c,struct santa_fe* temp_sf,struct mendoza* temp_m){
	float min_temp_m=0;
	char ciudad_mas_fria_m[50];
	float min_temp_c=0;
	char ciudad_mas_fria_c[50];
	float min_temp_sf=0;
	char ciudad_mas_fria_sf[50];
	
	//ciudad mas fria de mendoza
	while(temp_m!=NULL){
		if(min_temp_m==0){
			min_temp_m=temp_m->c.m.temp;
			strcpy(ciudad_mas_fria_m,temp_m->c.city_name);
		}
		else{
			if(min_temp_m>temp_m->c.m.temp){
				min_temp_m=temp_m->c.m.temp;
				strcpy(ciudad_mas_fria_m,temp_m->c.city_name);
			}
		}
		temp_m=temp_m->next;
	}
	printf("La minima temperatura de mendoza es %0.2f grados, correspondiente a la ciudad de %s\n",min_temp_m,ciudad_mas_fria_m);
	
	//ciudad mas fria de cordoba
	while(temp_c!=NULL){
		if(min_temp_c==0){
			min_temp_c=temp_c->c.m.temp;
			strcpy(ciudad_mas_fria_c,temp_c->c.city_name);
		}
		else{
			if(min_temp_c>temp_c->c.m.temp){
				min_temp_c=temp_c->c.m.temp;
				strcpy(ciudad_mas_fria_c,temp_c->c.city_name);
			}
		}
		temp_c=temp_c->next;
	}
	printf("La minima temperatura de Cordoba es %0.2f grados, correspondiente a la ciudad de %s\n",min_temp_c,ciudad_mas_fria_c);
	
	//ciudad mas fria de Santa Fe
	while(temp_sf!=NULL){
		if(min_temp_sf==0){
			min_temp_sf=temp_sf->c.m.temp;
			strcpy(ciudad_mas_fria_sf,temp_sf->c.city_name);
		}
		else{
			if(min_temp_sf>temp_sf->c.m.temp){
				min_temp_sf=temp_sf->c.m.temp;
				strcpy(ciudad_mas_fria_sf,temp_sf->c.city_name);
			}
		}
		temp_sf=temp_sf->next;
	}
	printf("La minima temperatura de Santa Fe es %0.2f grados, correspondiente a la ciudad de %s\n",min_temp_sf,ciudad_mas_fria_sf);
}
void dia_mas_frio(struct cordoba* temp_c,struct santa_fe* temp_sf,struct mendoza* temp_m){
	int hora_m=0,mes_m=0,dia_m=0,hora_c=0,mes_c=0,dia_c=0,hora_sf=0,mes_sf=0,dia_sf=0;
	float min_temp_m=0;
	char ciudad_mas_fria_m[50];
	float min_temp_c=0;
	char ciudad_mas_fria_c[50];
	float min_temp_sf=0;
	char ciudad_mas_fria_sf[50];

	//dia mas frio de mendoza
	while(temp_m!=NULL){
		if(min_temp_m==0){
			min_temp_m=temp_m->c.m.temp;
			hora_m=temp_m->c.m.time.hh;
			dia_m=temp_m->c.m.time.day;
			mes_m=temp_m->c.m.time.month;
			strcpy(ciudad_mas_fria_m,temp_m->c.city_name);
		}
		else{
			if(min_temp_m>temp_m->c.m.temp){
				min_temp_m=temp_m->c.m.temp;
				hora_m=temp_m->c.m.time.hh;
				dia_m=temp_m->c.m.time.day;
				mes_m=temp_m->c.m.time.month;
				strcpy(ciudad_mas_fria_m,temp_m->c.city_name);
			}
		}
		temp_m=temp_m->next;
	}
	printf("El dia en el cual se alcanzo la temperatura mas fria en la provincia de Mendoza fue el %d/%d, al rededor de las %d hs en la ciudad de %s, alcanzando los %0.2f grados\n",dia_m,mes_m,hora_m,ciudad_mas_fria_m,min_temp_m);

	//dia mas frio de cordoba
	while(temp_c!=NULL){
		if(min_temp_c==0){
			min_temp_c=temp_c->c.m.temp;
			hora_c=temp_c->c.m.time.hh;
			dia_c=temp_c->c.m.time.day;
			mes_c=temp_c->c.m.time.month;
			strcpy(ciudad_mas_fria_c,temp_c->c.city_name);
		}
		else{
			if(min_temp_c>temp_c->c.m.temp){
				min_temp_c=temp_c->c.m.temp;
				hora_c=temp_c->c.m.time.hh;
				dia_c=temp_c->c.m.time.day;
				mes_c=temp_c->c.m.time.month;
				strcpy(ciudad_mas_fria_c,temp_c->c.city_name);
			}
		}
		temp_c=temp_c->next;
	}
	printf("El dia en el cual se alcanzo la temperatura mas fria en la provincia de Mendoza fue el %d/%d, al rededor de las %d hs en la ciudad de %s, alcanzando los %0.2f grados\n",dia_c,mes_c,hora_c,ciudad_mas_fria_c,min_temp_c);

	//dia mas fria de Santa Fe
	while(temp_sf!=NULL){
		if(min_temp_sf==0){
			min_temp_sf=temp_sf->c.m.temp;
			hora_sf=temp_sf->c.m.time.hh;
			dia_sf=temp_sf->c.m.time.day;
			mes_sf=temp_sf->c.m.time.month;
			strcpy(ciudad_mas_fria_sf,temp_sf->c.city_name);
		}
		else{
			if(min_temp_sf>temp_sf->c.m.temp){
				min_temp_sf=temp_sf->c.m.temp;
				hora_sf=temp_sf->c.m.time.hh;
				dia_sf=temp_sf->c.m.time.day;
				mes_sf=temp_sf->c.m.time.month;
				strcpy(ciudad_mas_fria_sf,temp_sf->c.city_name);
			}
		}
		temp_sf=temp_sf->next;
	}
	printf("El dia en el cual se alcanzo la temperatura mas fria en la provincia de Mendoza fue el %d/%d, al rededor de las %d hs en la ciudad de %s, alcanzando los %0.2f grados\n",dia_sf,mes_sf,hora_sf,ciudad_mas_fria_sf,min_temp_sf);
}
void dia_mas_calido_city(struct cordoba* temp_c,struct santa_fe* temp_sf,struct mendoza* temp_m)
{
	float max_temp=0;
	char dia_mas_calido_city[50];
	int ii=0,dia=0,hora=0,minuto=0;
	//DIA MAS CALIDO EN CADA CIUDAD DE MENDOZA
	printf("----MENDOZA-----\n");
	ii=(temp_m)->c.cityld;
	max_temp=temp_m->c.m.temp;
	while(temp_m!=NULL){	
		if(ii==(temp_m)->c.cityld){
			if(max_temp<(temp_m)->c.m.temp){
				max_temp=(temp_m)->c.m.temp;
				strcpy(dia_mas_calido_city,temp_m->c.city_name);
				dia=temp_m->c.m.time.day;
				hora=temp_m->c.m.time.hh;
				minuto=temp_m->c.m.time.mm;
			}
			temp_m=(temp_m)->next;
		}
		else{
			printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
			ii=(temp_m)->c.cityld;//EN LA ULTIMA VUELTA DE WHILE ENTRA AL IF PERO AL ELSE NO, POR ESO NO LA MUESTRA
			max_temp=(temp_m)->c.m.temp;
		}
	}
	printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
	printf("----SANTA FE-----\n");
	ii=(temp_sf)->c.cityld;
	max_temp=temp_sf->c.m.temp;
	while(temp_sf!=NULL){	
		if(ii==(temp_sf)->c.cityld){
			if(max_temp<(temp_sf)->c.m.temp){
				max_temp=(temp_sf)->c.m.temp;
				strcpy(dia_mas_calido_city,temp_sf->c.city_name);
				dia=temp_sf->c.m.time.day;
				hora=temp_sf->c.m.time.hh;
				minuto=temp_sf->c.m.time.mm;
			}
			temp_sf=(temp_sf)->next;
		}
		else{
			printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
			ii=(temp_sf)->c.cityld;//EN LA ULTIMA VUELTA DE WHILE ENTRA AL IF PERO AL ELSE NO, POR ESO NO LA MUESTRA
			max_temp=(temp_sf)->c.m.temp;
		}
	}
	printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
	printf("----CORDOBA-----\n");
	ii=(temp_c)->c.cityld;
	max_temp=temp_c->c.m.temp;
	while(temp_c!=NULL){	
		if(ii==(temp_c)->c.cityld){
			if(max_temp<(temp_c)->c.m.temp){
				max_temp=(temp_c)->c.m.temp;
				strcpy(dia_mas_calido_city,temp_c->c.city_name);
				dia=temp_c->c.m.time.day;
				hora=temp_c->c.m.time.hh;
				minuto=temp_c->c.m.time.mm;
			}
			temp_c=(temp_c)->next;
		}
		else{
			printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
			ii=(temp_c)->c.cityld;//EN LA ULTIMA VUELTA DE WHILE ENTRA AL IF PERO AL ELSE NO, POR ESO NO LA MUESTRA
			max_temp=(temp_c)->c.m.temp;
		}
	}
	printf("El dia mas calido en %s con %0.2f grados, el dia: %d a las %d:%d\n",dia_mas_calido_city, max_temp, dia, hora, minuto);
}
void provincia_para_pimientos(struct cordoba* temp_c,struct santa_fe* temp_sf,struct mendoza* temp_m){
	int acum= 0;
	double suma= 0;
	float prom_m=0,prom_c=0,prom_sf=0,proxim_m=0,proxim_c=0,proxim_sf=0;
	printf("--------------------------------------------\n");
	//OPCION 1 DEL MENU (MENDOZA)
	while(temp_m!=NULL)
	{
		acum++;	
		suma+= temp_m->c.m.temp;
		temp_m=temp_m->next;
	}
	prom_m=(float)suma/acum;
	acum= 0;
	suma= 0;
	while(temp_sf!=NULL)
	{
		acum++;	
		suma+= temp_sf->c.m.temp;
		temp_sf=temp_sf->next;
	}
	prom_sf=(float)suma/acum;
	acum= 0;
	suma= 0;
	while(temp_c!=NULL)
	{
		acum++;	
		suma+= temp_c->c.m.temp;
		temp_c=temp_c->next;
	}
	prom_c=(float)suma/acum;
	//comparacion de temperautrs
	proxim_sf=fabs(prom_sf-25);
	proxim_m=fabs(prom_m-25);
	proxim_c=fabs(prom_c-25);
	//comparamos valores absoluto debido a que expresa proximidad
	if(proxim_c<proxim_m &&proxim_c<proxim_sf){
		printf("La provincia mas adecuada para el cultivo de pimientos es Cordoba debido a su temperatura media de %0.2f grados\n",prom_c);
	}
	else{
		if(proxim_m<proxim_c&&proxim_m<proxim_sf){
		printf("La provincia mas adecuada para el cultivo de pimientos es Mendoza debido a su temperatura media de %0.2f\n",prom_m);
		}
		else{
		printf("La provincia mas adecuada para el cultivo de pimientos es Santa Fe debido a su temperatura media de %0.2f\n",prom_sf);
		}
	}
}
