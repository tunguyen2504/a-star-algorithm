/* City.c */

#include <stdio.h>
#include "City.h"

void insertNeighbor(struct Neighbor **neighbor, char *name, int distance) {
    struct Neighbor *temp,*current;
    temp=malloc(sizeof(struct Neighbor));
    temp->name=name;
    temp->distance=distance;
    temp->next=NULL;

    if((*neighbor)==NULL){
        (*neighbor)=temp;
    }
    else{
        current=(*neighbor);
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
}

City* newCity(char *name, int latitude, int longitude) {
	struct City *city;
	city=malloc(sizeof(struct City));
	city->name=name;
	city->latitude=latitude;
	city->longitude=longitude;
	city->neighbors=NULL;
	
	return city;
}

void setNeighborsOfCity(struct City *city, struct Neighbor *neighbors) {
	city->neighbors = neighbors;
}

void displayCity(struct City *city) {
    struct City *current;
    struct Neighbor *currentlist;
    current=city;
//    while(current!=NULL){
//        currentlist=current->start;
        printf("City: %s\n", current->name);
        printf("X: %d, Y: %d\n", current->latitude, current->longitude);
        currentlist = current->neighbors;
        printf("Neighbors: \n");
        while(currentlist!=NULL) {
            printf("Name: %s\tDistance: %d\n", currentlist->name, currentlist->distance);
            currentlist=currentlist->next;
        }
//        while(currentlist!=NULL){
//            printf("%d ",currentlist->Data);
//            currentlist=currentlist->next;
//        }
//        i++;
        printf("\n");
//        current=current->listnext;
//    }
}
