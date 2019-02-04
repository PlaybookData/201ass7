#include <stdio.h>

int i;
float sfdays, totaldays, target, ratio;

int main (){
    printf("Enter number of sugar free days so far: ");
    scanf ("%f", &sfdays);
    printf ("Enter number of total days so far: ");
    scanf("%f", &totaldays);
    target = 300.0/365.0;
    i=0;
    ratio = ((sfdays+i)/(totaldays+i));
    printf("target = %1.2f\n", target);
    while (target>ratio){
        i++;
        ratio = ((sfdays+i)/(totaldays+i));
    }
    printf("you need to go %d days sugar free to get on track\n", i);
    printf("%1.0f/%1.0f = %1.2f\n", sfdays+i, totaldays+i, (sfdays+i)/(totaldays+i));
}
