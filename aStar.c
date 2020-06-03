/*
 * aStar.c
 * Created by Anh Tu on 01/06/2020 - 1:22 AM.
 * Project AStarAlgorithm
 */

#include "aStar.h"
#include <string.h>

static Neighbor *currentNeighbor = NULL;

int isNamed(void * c) {
    City *city = c;
    return strcmp(city->name, currentNeighbor->name) == 0;
}

void forEachNeighbor(List* cityList, List* openList, List* closeList, City* city) {
    currentNeighbor = city->neighbors;
    while (currentNeighbor) {
        City* c = firstThat(cityList, isNamed);
        if (c!=0) {
            int g = city->distFromStart + currentNeighbor->distance;
            if ((isInList(openList, c) || isInList(closeList, c)) && g>c->distFromStart) {
                currentNeighbor = currentNeighbor->next;
                continue;
            }
            if (isInList(openList, c)) remFromList(openList, c);
            if (isInList(closeList, c)) remFromList(closeList, c);
            c->distFromStart = g;
            c->preCity = city;
            addList(openList, c);
        }
        currentNeighbor = currentNeighbor->next;
    }
}

int findShortestPath(List* cityList, List* openList, List* closeList, City* startCity, City* goalCity, List* res) {
    addList(openList, startCity);
    City* currentCity = startCity;
    while (currentCity != goalCity) {
        if (lengthList(openList) == 0) {
            return 1;
        }

        remFromListAt(openList, 1, &currentCity);
        addList(closeList, currentCity);
        if (currentCity == goalCity) {
            while (currentCity->preCity) {
                addListAt(res, 1, currentCity);
                currentCity = currentCity->preCity;
            }
            addListAt(res, 1, currentCity);
            return 0;
        }
        forEachNeighbor(cityList, openList, closeList, currentCity);
    }
}

