
/*
* testGantt.c
*
*  Created on: 19 Feb 2026
*      Author: annie
*/

/*
* testGantt.c
*
*  Created on: 10 March 2026
*      Author: Weng Teong
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

int loadTestExample(Task project[]) {
	int totalTasks = 10;

	strcpy(project[0].taskName, "Brainstorming");
	project[0].startMonth = 1; project[0].endMonth = 1;
	project[0].dependencyAmount = 0;

	strcpy(project[1].taskName, "Concept_Design");
	project[1].startMonth = 2; project[1].endMonth = 2;
	project[1].dependencyAmount = 1;
	project[1].dependentTasks[0] = 1;

	strcpy(project[2].taskName, "Prototyping");
	project[2].startMonth = 3; project[2].endMonth = 3;
	project[2].dependencyAmount = 2;
	project[2].dependentTasks[0] = 1;
	project[2].dependentTasks[1] = 2;

	strcpy(project[3].taskName, "Creating_Art_Assets");
	project[3].startMonth = 4; project[3].endMonth = 5;
	project[3].dependencyAmount = 1;
	project[3].dependentTasks[0] = 3;

	strcpy(project[4].taskName, "Development");
	project[4].startMonth = 5; project[4].endMonth = 6;
	project[4].dependencyAmount = 0;

	strcpy(project[5].taskName, "Sound_Design");
	project[5].startMonth = 6; project[5].endMonth = 7;
	project[5].dependencyAmount = 2;
	project[5].dependentTasks[0] = 4;
	project[5].dependentTasks[1] = 5;

	strcpy(project[6].taskName, "Steam_Store_Page");
	project[6].startMonth = 7; project[6].endMonth = 8;
	project[6].dependencyAmount = 1;
	project[6].dependentTasks[0] = 6;

	strcpy(project[7].taskName, "Marketing");
	project[7].startMonth = 7; project[7].endMonth = 8;
	project[7].dependencyAmount = 1;
	project[7].dependentTasks[0] = 7;

	strcpy(project[8].taskName, "Distributing_Game_Keys");
	project[8].startMonth = 9; project[8].endMonth = 9;
	project[8].dependencyAmount = 1;
	project[8].dependentTasks[0] = 5;

	strcpy(project[9].taskName, "Analysing_Revenue");
	project[9].startMonth = 10; project[9].endMonth = 12;
	project[9].dependencyAmount = 2;
	project[9].dependentTasks[0] = 8;
	project[9].dependentTasks[1] = 9;

	return totalTasks;
}

// deprecated due to assignment 2 requirements
void showGantTemplate(){

	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for(int i = 0 ; i <= december + 1; i++){

		switch(i){
		case(0) :
				printf("\t\t\t|");
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
		case(december + 1):
				printf(" Dependencies   \n");
        		break;

		default:
	        break;

		}

	}

		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Module Registration\t|    xxx     |            |            |            |            |            |            |            |            |            |            |            |    \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Internship Applications\t|            |    xxx     |    xxx     |    xxx     |            |            |            |            |            |            |            |            | 1   \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Midterm Exam Prep\t|            |    xxx     |    xxx     |            |            |            |            |            |            |            |            |            | 1   \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Book Review\t\t|            |            |    xxx     |    xxx     |            |            |            |            |            |            |            |            | 1   \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Final Exams\t\t|            |            |            |            |    xxx     |            |            |            |            |            |            |            | 3, 4   \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Summer Internship\t|            |            |            |            |            |    xxx     |    xxx     |    xxx     |            |            |            |            | 2, 5  \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Peer Mentor Meeting\t|            |            |            |            |            |            |            |            |    xxx     |            |            |            |    \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Group Project\t\t|            |            |            |            |            |            |            |            |    xxx     |    xxx     |            |            |    \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Creative Project\t|            |            |            |            |            |            |            |            |            |    xxx     |    xxx     |            |    \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("Major Presentationn\t|            |            |            |            |            |            |            |            |            |            |            |    xxx     | 8, 9   \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

