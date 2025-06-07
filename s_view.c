void s_view_complaint(){
    FILE *fptr=fopen("complaintfile.dat","rb");
    struct complaint c;
    if (fptr==NULL){
        printf("Complaint not found.\n");
        return;
    }
    printf("\n=====Your Complaint=====\n");
    int view_id;
    int found = 0;
    printf("Enter your Complaint ID: ");
    scanf("%d", &view_id);
    getchar();

        while (fread(&c, sizeof(struct complaint), 1, fptr)) {
            if (c.complaintid == view_id) {
                found = 1;
                print_complaint(c);
                printf("----------------------------------\n");
                break;
            }
        }
        
        if (!found) {
            printf("No complaint found with ID %d\n", view_id);
        }
    
    fclose(fptr);
    printf("\n");
}