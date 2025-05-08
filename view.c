void view_complaint(){
    FILE *fptr=fopen("complaintfile.dat","rb");
    struct complaint c;
    if (fptr==NULL){
        printf("Complaint not found.\n");
        return;
    }
    printf("\n=====List of Complaints=====\n");
    
    int found = 0;
    while (fread(&c, sizeof(struct complaint), 1, fptr)) {
        found = 1;
        printf("\nComplaint ID : %d\n", c.complaintid);
        printf("Student Name   : %s\n", c.name);
        printf("Student ID     : %s\n", c.studentid);
        printf("Topic          : %s\n", c.topic);
        printf("Description    : %s\n", c.describe);
        printf("Status         : %s\n", c.status);
        printf("----------------------------------\n");
    }

    if (!found) {
        printf("No complaints to display.\n");
    }

    fclose(fptr);
    printf("\n");
}