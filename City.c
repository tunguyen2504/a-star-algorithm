/**
 * Graph.c
 * Created by Anh Tu on 27/05/2020 - 8:20 PM.
 * Project AStarAlgorithm
 */

#include <stdio.h>
#include <string.h>
#include "City.h"

/** add neighbor to neighborList of city */
status insertNeighborToCity(City *city, char *name, int distance) {
    Neighbor *temp,*current;
    temp=malloc(sizeof(Neighbor));
    if (!temp) return ERRALLOC;
    temp->name=name;
    temp->distance=distance;
    temp->next=NULL;

    if(city->neighbors==NULL){
        city->neighbors=temp;
        city->neighborCount++;
        return OK;
    }
    else{
        current=city->neighbors;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
        city->neighborCount++;
        return OK;
    }
}

/** create a new city by name, latitude, and longitude */
City* newCity(char *name, int latitude, int longitude) {
	City *city;
	city=malloc(sizeof(City));
	if (!city) return NULL;
    char *cityName = malloc(sizeof(strlen(name) + 1));
    strcpy(cityName, name);
	city->name=cityName;
	city->latitude=latitude;
	city->longitude=longitude;
	city->distFromStart=0;
	city->distToGoal=0;
	city->neighborCount=0;
	city->neighbors=NULL;
	city->preCity=NULL;

	return city;
}

/** create a new neighbor by name and distance from city to neighbor */
Neighbor* newNeighbor(char *name, int distance) {
    Neighbor *neighbor;
    neighbor=malloc(sizeof(Neighbor));
    if (!neighbor) return NULL;
    char *neighborName = malloc(sizeof(strlen(name) + 1));
    strcpy(neighborName, name);
    neighbor->name=neighborName;
    neighbor->distance=distance;
    neighbor->next=NULL;

    return neighbor;
}

/** destroy the city by deallocating used memory */
void delCity(City *city) {
    city->name = NULL;
    city->latitude = NULL;
    city->longitude = NULL;
    city->distFromStart = NULL;
    city->distToGoal = NULL;
    city->neighborCount = NULL;
    city->neighbors = NULL;
    city->preCity = NULL;
    free(city);
}

/** destroy the neighbor by deallocating used memory */
void delNeighbor(Neighbor *neighbor) {
    Neighbor *tmp = neighbor->next;
    while (tmp) {
        neighbor->next = tmp->next;
        tmp->next = NULL;
        tmp = neighbor->next;
    }
    neighbor->name = NULL;
    neighbor->distance = NULL;
    free(neighbor);
}