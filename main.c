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
    char urgency[10]; 
};

FILE *fptr;
struct complaint c;

#include "remove_newline.c"
#include "register.c"
#include "print_complaint.c"
#include "s_view.c"
#include "a_view.c"
#include "search.c"
#include "s_update.c"
#include "a_update.c"
#include "delete.c"
#include "auth.c"

int main(){
    auth();
    return 0;
}
/*void std_menu(){
    std_login();

}
void admin_menu(){
    admin_login();
}
*/