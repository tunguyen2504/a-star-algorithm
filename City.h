/* City.h */

#ifndef __City_H
#define __City_H

#include <stdlib.h>
//#include "List.h"

struct Neighbor {
	char *name;
	int distance;
	struct Neighbor *next;
} Neighbor;

typedef struct City {
	char *name;
	int latitude, longitude;
	struct Neighbor *neighbors;
//	struct City *nextCity;
} City;

void insertNeighbor(struct Neighbor **neighbor, char name[], int distance);

//void insertCity(struct City **city, struct )

City* newCity(char name[], int latitude, int longitude);

void setNeighborsOfCity(struct City *city, struct Neighbor *neighbor);

void displayCity(struct City *city);

#endif
