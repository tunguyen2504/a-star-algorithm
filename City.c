/*
 * City.c
 * Created by Anh Tu on 27/05/2020 - 8:20 PM.
 * Project AStarAlgorithm
 */

#include <stdio.h>
#include <string.h>
#include "City.h"

/*
 *
 */
void insertNeighborToCity(struct Neighbor **neighbor, char *name, int distance) {
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


void insertCityToGraph(struct Graph **graph, struct City *head) {
    struct Graph *temp,*current;
    temp=malloc(sizeof(struct Graph));
    temp->headCity=head;
    temp->next=NULL;
    if((*graph)==NULL){
        (*graph)=temp;
    }
    else{
        current=(*graph);
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
}

City* newCity(char *name, int latitude, int longitude) {
	struct City *city;
	city=malloc(sizeof(struct City));
    char *cityName = malloc(sizeof(strlen(name) + 1));
    strcpy(cityName, name);
	city->name=cityName;
	city->latitude=latitude;
	city->longitude=longitude;
	city->neighbors=NULL;

	return city;
}

Neighbor* newNeighbor(char *name, int distance) {
    struct Neighbor *neighbor;
    neighbor=malloc(sizeof(struct Neighbor));
    char *neighborName = malloc(sizeof(strlen(name) + 1));
    strcpy(neighborName, name);
    neighbor->name=neighborName;
    neighbor->distance=distance;
    neighbor->next=NULL;
}

void displayGraph(struct Graph *graph) {
    int i=1;
    struct Graph *currentGraph;
    struct City *currentCity;
    struct Neighbor *currentNeighbor;
    currentGraph=graph;
    while(currentGraph!=NULL){
        currentCity=currentGraph->headCity;
        printf("City %d: %s\n", i, currentCity->name);
        printf("L1: %d, L2: %d\n", currentCity->latitude, currentCity->longitude);
        currentNeighbor=currentCity->neighbors;
        printf("Neighbors: \n");
        while(currentNeighbor!=NULL){
            printf("Name: %s\tDistance: %d\n", currentNeighbor->name, currentNeighbor->distance);
            currentNeighbor=currentNeighbor->next;
        }
        i++;
        printf("\n");
        currentGraph=currentGraph->next;
    }
}