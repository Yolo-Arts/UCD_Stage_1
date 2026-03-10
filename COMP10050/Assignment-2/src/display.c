/*
 * display.c
 *
 *  Created on: 5 Mar 2026
 *      Author: annie
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "testGantt.h"
#include "edit.h"
#include "recursive.h"
#include "display.h"


void displayGant(Task tasksArray[], int taskAmount){

    // this displays the months
	   for(int i = 0 ; i <= december; i++){

	                switch(i){
	                case(0) :
	                        printf("\n\t\t\t|");
	                        break;
	                case(january):
	                        printf("  January   |");
	                        break;
	                case(february):
	                        printf("  February  |");
	                        break;
	                case(march):
	                        printf("   March    |");
	                        break;
	                case(april):
	                        printf("   April    |");
	                        break;
	                case(may):
	                        printf("    May     |");
	                        break;
	                case(june):
	                        printf("    June    |");
	                        break;
	                case(july):
	                        printf("    July    |");
	                        break;
	                case(august):
	                        printf("   August   |");
	                        break;
	                case(september):
	                        printf(" September  |");
	                        break;
	                case(october):
	                        printf("  October   |");
	                        break;
	                case(november):
	                        printf(" November   |");
	                        break;
	                case(december):
	                        printf(" December   |");
	                        break;


	                default:
	                    break;

	                }

	            }

	            printf(" Dependencies   |\n");
	            printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	            // prints out the customised Gantt:

	            for (int i = 0; i < taskAmount; i++) {
	                printf("%-24s|", tasksArray[i].taskName);
	                for (int j = january; j <= december; j++) {

	                    if ((tasksArray[i].startMonth <= j) && (tasksArray[i].endMonth >= j)) {
	                        printf("    xxx     |");
	                    } else {
	                        printf("            |");
	                    }
	                }



	                for(int d = 0; d < tasksArray[i].dependencyAmount; d++){
	                    printf(" %d", tasksArray[i].dependentTasks[d]);
	                }

	                printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	            }




}
