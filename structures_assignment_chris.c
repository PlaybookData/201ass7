#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *f;

struct contact{
    char name[100];
    char phonenum[10];
};

struct contact getdetails (char *string);
char displaymenu (void);
void search (struct contact *p, int num);
void displayall (struct contact *p, int num);

int main(){
    struct contact phonelist[100];
    struct contact *pl;
    pl=phonelist;
    int i, count;
    char choice;
    char line[200];
    f=fopen("contactlist.txt", "r");
    if (f == NULL){
        printf("Error - cannot open file");
        exit(13);
    }
    i = 0;
    while (fgets(line, 200, f) != NULL) {
        phonelist[i] = getdetails(line);
        i++;
    }
    count=i;
    fclose(f);
    choice = displaymenu();
    if (choice=='A'){
        search(pl, count);
    }
    if (choice=='B'){
        displayall(pl, count);
    }
    if (choice=='Q'){
        exit(34);
    }
}

struct contact getdetails (char *string){
    int len, i, j;
    struct contact p;
    i=0;
    j=0;
    len = strlen(string);
    if (string[len-1]=='\n'){
        string[len-1]='\0';
    }
    while (string[i]!=';'){
        p.name[j] = string[i];
        i++;
        j++;
    }
    p.name[j] ='\0';
    i++;
    j=0;
    while (string[i]!='\0'){
        p.phonenum[j] = string[i];
        i++;
        j++;
    }
    p.phonenum[j] = '\0';
    return p;
}

char displaymenu (void){
    char letter;
    printf("A. Search for a name\nB. Display all names\nQ Quit.");
    letter=getchar();
    if ((letter=='a') || (letter=='b') || (letter=='q')){
        letter=letter-32;
    }
    while ((letter!='A') && (letter!='B') && (letter!='Q')){
        getchar();
        printf("You have entered an invalid selection. Please try again.");
        letter=getchar();
        if ((letter=='a') || (letter=='b') || (letter=='q')){
        letter=letter-32;
        }
    }
    getchar();
    return letter;
}

void search (struct contact *p, int num){
    char query[100];
    bool found = false;
    int i;
    printf("Enter the name for which you wish to search: (Note: names are stored in the form Bloggs Jo ");
    gets (query);
    for (i=0; i<num; i++){
        if ((strcmp(p[i].name, query)==0)){
            found=true;
            printf("The number for %s is %s", query, p[i].name);
        }
    }
    if (!found){
        printf("That name does not appear in your contact list");
        exit (56);
    }
}
