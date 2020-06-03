/*
 * main.c
 * Created by Anh Tu on 26/05/2020 - 2:11 AM.
 * Project AStarAlgorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "City.h"
#include "status.h"

/*************************************************************
 * Function to compare two elements (strings) : based on strcmp
 * @param s1 the first string to compare
 * @param s2 the second string to compare
 * @return <0 if s1 is less than s2
 * @return 0 if s1 equals s2
 * @return >0 otherwise
 *************************************************************/
static int compString (void * s1, void * s2) {
    return strcmp((char*)s1, (char*)s2);
}

/**
 *
 * @param s1
 * @param s2
 * @return
 */
static int compCityByName (void * s1, void * s2) {
    City* c1 = s1;
    City* c2 = s2;
    return strcmp(c1->name, c2->name);
}

static int compCityByF (void * s1, void * s2) {
    City* c1 = s1;
    City* c2 = s2;
    return ((c1->distFromStart + c1->distToGoal) < (c2->distFromStart + c2->distToGoal)) ? -1 : ((c1->distFromStart + c1->distToGoal) > (c2->distFromStart + c2->distToGoal));
}

/*************************************************************
 * Function to display an element of the list
 * @param s the string to display
 *************************************************************
 */
static void prString(void * s) {
    printf("%s",(char*)s);
}

/**
 *
 * @param s
 */
static void prCity(void * s) {
    City* city = s;
    printf("\nCity: %s", city->name);
    printf("\nL1: %d, L2: %d", city->latitude, city->longitude);
    printf("\nG: %d, H: %d", city->distFromStart, city->distToGoal);
    Neighbor* neighbor = city->neighbors;
    printf("\nNeighbors:");
    while(neighbor!=NULL){
        printf("\nName: %s\tDistance: %d", neighbor->name, neighbor->distance);
        neighbor=neighbor->next;
    }
    printf("\n");
}

static char* startName = "Rennes";
static char* goalName = "Lyon";
static City* startCity = NULL;
static City* goalCity = NULL;

/**
 *
 * @param city
 */
static void findStartAndGoalCity (City * city) {
    if (strcmp(city->name, startName) == 0) {
        startCity = city;
    } else if (strcmp(city->name, goalName) == 0) {
        goalCity = city;
    }
}

/**
 *
 * @param s
 */
static void calculateGAndH(void * s) {
    City* currentCity = s;
    if (currentCity == startCity) {
        currentCity->distFromStart = 0;
        currentCity->distToGoal = (abs(currentCity->latitude - goalCity->latitude) + abs(currentCity->longitude - goalCity->longitude))/4;
    } else if (currentCity == goalCity) {
        currentCity->distFromStart = 100000;
        currentCity->distToGoal = 0;
    } else {
        currentCity->distFromStart = 100000;
        currentCity->distToGoal = (abs(currentCity->latitude - goalCity->latitude) + abs(currentCity->longitude - goalCity->longitude))/4;
    }

}

int main(int argc, char *argv[]) {
    FILE *file;
//	if (argc < 2) {
//    	printf("Missing Filename\n");
//        return(1);
//   	}
//    char *filename = argv[1];
    char *filename = "FRANCE.MAP";
    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    char name[50];
    int x, y;
    int res;
    City* city = NULL;
    Neighbor* neighbor = NULL;
    List* cityList = newList(compCityByName, prCity);
    List* openList = newList(compCityByF, prCity);
    List* closeList = newList(compCityByName, prCity);
    while ((res = fscanf(file, "%s%d%d", name, &x, &y))) {

        if (res == 3) {
            if (city) {
                findStartAndGoalCity(city);
                addList(cityList, city);
            }
            city = newCity(name, x, y);
        } else if (res == 2) {
            neighbor = newNeighbor(name, x);
            if (neighbor) {
                insertNeighborToCity(&city->neighbors, neighbor->name, neighbor->distance);
            }
        } else if (res == EOF) {
            findStartAndGoalCity(city);
            addList(cityList, city);
            break;
        }
    }

//
    fclose(file);
    forEach(cityList, calculateGAndH);
//    for (int i=1; i<=lengthList(cityList); i++) {
//        City* c = NULL;
//        nthInList(cityList, i, &c);
//        addList(openList, c);
//    }
//    prCity(startCity);
//    prCity(goalCity);
    displayList(cityList);
//    displayList(openList);
    return 0;
}
