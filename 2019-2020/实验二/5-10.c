#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade, grade1;
    scanf("%d", &grade);
    grade1 = grade / 10;
    switch (grade1) {
    case 9, case 10:  //:: expected '  //:: expected expression
        printf("Letter grade: A");
        break;
    case 8:
        printf("Letter grade: B");
        break;
    case 7:
        printf("Letter grade: c");
        break;
    case 6:
        printf("Letter grade: D");
        break;
    case 5, case 4, case 3, case 2, case 1, case 0:  //:: expected '  //:: expected expression
        printf("Letter grade: F");
        if (grade > 100 || grade < 0)
            printf("Error, grade must be between 0 and 100.")  //:: 忘记加分号 ; 了
    }
    return 0;
}
