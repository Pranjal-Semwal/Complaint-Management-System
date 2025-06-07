void a_view_complaint(){
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
        print_complaint(c);
        printf("----------------------------------\n");
    }

    if (!found) {
        printf("No complaints to display.\n");
    }

    fclose(fptr);
    printf("\n");
}