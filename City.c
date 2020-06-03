/*
 * Graph.c
 * Created by Anh Tu on 27/05/2020 - 8:20 PM.
 * Project AStarAlgorithm
 */

#include <stdio.h>
#include <string.h>
#include "City.h"

void insertNeighborToCity(Neighbor **neighbor, char *name, int distance) {
    Neighbor *temp,*current;
    temp=malloc(sizeof(Neighbor));
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
	City *city;
	city=malloc(sizeof(City));
    char *cityName = malloc(sizeof(strlen(name) + 1));
    strcpy(cityName, name);
	city->name=cityName;
	city->latitude=latitude;
	city->longitude=longitude;
	city->distFromStart=0;
	city->distToGoal=0;
	city->neighbors=NULL;

	return city;
}

Neighbor* newNeighbor(char *name, int distance) {
    Neighbor *neighbor;
    neighbor=malloc(sizeof(Neighbor));
    char *neighborName = malloc(sizeof(strlen(name) + 1));
    strcpy(neighborName, name);
    neighbor->name=neighborName;
    neighbor->distance=distance;
    neighbor->next=NULL;
}