/*
 * aStar.h
 * Created by Anh Tu on 01/06/2020 - 1:22 AM.
 * Project AStarAlgorithm
 */

#ifndef __ASTAR_H
#define __ASTAR_H

#include "List.h"
#include "City.h"

int findShortestPath(List* cityList, List* openList, List* closeList, City* startCity, City* goalCity, List* res);

void forEachNeighbor(List* cityList, List* openList, List* closeList, City* city);

#endif //__ASTAR_H
