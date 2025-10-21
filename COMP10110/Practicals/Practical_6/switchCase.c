#include <stdio.h>

int main(void)
{
	/* declare variables */
	int mark;
	char grade;

	/* read the mark */
	printf("Enter the mark:\n");
	scanf("%d", &mark);
		
	
	/** Write your code here **/

	int newMark = mark / 10;
// 	printf("%d", mark);
	
	switch (newMark) { 
	    case 10:
	    case 9:
    	    grade = 'A';
    	    printf("A mark of %d corresponds to grade %c", mark, grade);
    	    break;
    	case 8:
    	    grade = 'B';
    	    printf("A mark of %d corresponds to grade %c", mark, grade);
    	    break;
    	case 7:
    	    grade = 'C';
    	    printf("A mark of %d corresponds to grade %c", mark, grade);
    	    break;
    	case 6:
    	    grade = 'D';
    	    printf("A mark of %d corresponds to grade %c", mark, grade);
    	    break;
    	default:
    	    grade = 'F';
    	    printf("A mark of %d corresponds to grade %c", mark, grade);
    	    break;

	}
	return 0;
}
