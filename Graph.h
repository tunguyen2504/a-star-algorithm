/*
 * Graph.h
 * Created by Anh Tu on 27/05/2020 - 8:20 PM.
 * Project AStarAlgorithm
 */

#ifndef __GRAPH_H
#define __GRAPH_H

#include <stdlib.h>

/**
 *
 */
typedef struct Neighbor {
    char *name;
    int distance;
    struct Neighbor *next;
} Neighbor;

/**
 *
 */
typedef struct City {
    char *name;
    int latitude, longitude;
    struct Neighbor *neighbors;
} City;

/**
 *
 */
typedef struct Graph {
    struct City *headCity;
    struct Graph *next;
} Graph;

/**
 *
 * @param neighbor
 * @param name
 * @param distance
 */
void insertNeighborToCity(struct Neighbor **neighbor, char *name, int distance);

/**
 *
 * @param city
 * @param head
 */
void insertCityToGraph(struct Graph **city, struct Graph *head);

/**
 *
 * @param name
 * @param latitude
 * @param longitude
 * @return
 */
City* newCity(char *name, int latitude, int longitude);

/**
 *
 * @param name
 * @param distance
 * @return
 */
Neighbor* newNeighbor(char name[], int distance);

/**
 *
 * @param graph
 */
void displayGraph(struct Graph *graph);

#endif //__GRAPH_H
