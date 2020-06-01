/* main.c - read file
 * Author: Anh Tu NGUYEN - anh-tu.nguyen@epita.fr
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
    char *cityName[40];
    char *neighborName[100];
    int x, y;
    int res;
    List* l = newList(compString,prString);
//    struct Neighbor** neighbors = NULL;
    struct City cities[20];
    struct City* city = NULL;
    int i=-1, j=-1;
    while ((res = fscanf(file, "%s%d%d", name, &x, &y))) {

        if (res == 3) {
//			printf("\nCity: %s\t\tL1: %d\tL2: %d\n", name, x, y);
//            if (city != NULL) {
//                addList(l, &cities[i]);
//            }
            city = newCity(name, x, y);
            if (city != NULL) {
//				addList(l, city);
                i++;
                cityName[i] = malloc(sizeof(strlen(city->name) + 1));
                strcpy(cityName[i], city->name);
                cities[i].name = cityName[i];
                cities[i].latitude = city->latitude;
                cities[i].longitude = city->longitude;
                cities[i].neighbors = city->neighbors;
            }
//            neighbors = NULL;
        } else if (res == 2) {
//			printf("Neighbor: %s\t\tCost: %d\n", name, x);
            j++;
            neighborName[j] = malloc(sizeof(strlen(name) + 1));
            strcpy(neighborName[j], city->name);
            insertNeighbor(&cities[i].neighbors, neighborName[j], x);
//            setNeighborsOfCity(city, *neighbors);
        } else if (res == EOF) {
            for (int i=0; i<sizeof(cities)/sizeof(struct City); i++) {
                if (!cities[i].name) {
                    break;
                }
                displayCity(&cities[i]);
            }
            break;
        }
    }
//	displayList(l);
//

    free(cityName);
    free(neighborName);
    fclose(file);


    return 0;
}
