#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct complaint {
    int complaintid;
    char name[20];
    char studentid[20];
    char topic[20];
    char describe[100];
    char status[10]; 
};

FILE *fptr;
struct complaint c;

#include "auth.c"
#include "remove_newline.c"
#include "register.c"
#include "view.c"
#include "search.c"
#include "update.c"
#include "delete.c"
int main(){
    login();
    int ch;
    while(1){
        printf("=====COMPLAINT MANAGEMENT SYSTEM=====\n");
        printf("1.Register Complaint\n");
        printf("2.View Complaint\n");
        printf("3.Search Complaint\n");
        printf("4.Update Complaint\n");
        printf("5.Delete Complaint\n");
        printf("6.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch (ch){
        case 1: register_complaint(); break;
        case 2: view_complaint(); break;
        case 3: search_complaint(); break;
        case 4: update_complaint(); break;
        case 5: delete_complaint(); break;
        case 6: printf("exiting......"); exit(0);
        default: printf("Invalid choice");
        }
    }
    return 0;
}
