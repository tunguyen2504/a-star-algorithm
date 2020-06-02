/*
 * main.c
 * Created by Anh Tu on 26/05/2020 - 2:11 AM.
 * Project AStarAlgorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Graph.h"
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

/*************************************************************
 * Function to display an element of the list
 * @param s the string to display
 *************************************************************
 */
static void prString(void * s) {
    printf("%s",(char*)s);
}

/*************************************************************
 * another display function, just to test "forEach"
 * @param s the string to display
 *************************************************************/
static void prString2 (void * s) {
    printf("%s\n",(char*)s);
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
    struct Graph* graph = NULL;
    struct City* city = NULL;
    struct Neighbor* neighbor = NULL;
    while ((res = fscanf(file, "%s%d%d", name, &x, &y))) {

        if (res == 3) {
            if (city) {
                insertCityToGraph(&graph, city);
            }
            city = newCity(name, x, y);
        } else if (res == 2) {
            neighbor = newNeighbor(name, x);
            if (neighbor) {
                insertNeighborToCity(&city->neighbors, neighbor->name, neighbor->distance);
            }
        } else if (res == EOF) {
            insertCityToGraph(&graph, city);
            break;
        }
    }
//	displayList(l);
//
    fclose(file);
    displayGraph(graph);

    return 0;
}
