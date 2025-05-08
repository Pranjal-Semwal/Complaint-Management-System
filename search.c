
void search_complaint(){
    FILE *fptr=fopen("complaintfile.dat","rb");
    struct complaint c;
    int search_id, found = 0;
    char search_t[20],search_s[10];
    if (fptr == NULL) {
        printf("Complaint file not found.\n");
        return;
    }
    int ch;
    printf("By what you want to find the complaint:\n");
    printf("1. Complaint ID\n2. Topic\n3. Status\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    getchar();
    if(ch==1){
        printf("Enter Complaint ID to search: ");
        scanf("%d", &search_id);    
        while (fread(&c, sizeof(struct complaint), 1, fptr)) {
            if (c.complaintid == search_id) {
                found = 1;
                printf("\nComplaint Found:\n");
                printf("Complaint ID : %d\n", c.complaintid);
                printf("Student Name : %s\n", c.name);
                printf("Student ID   : %s\n", c.studentid);
                printf("Topic        : %s\n", c.topic);
                printf("Description  : %s\n", c.describe);
                printf("Status       : %s\n", c.status);
                break;
            }
        }
        
        if (!found) {
            printf("No complaint found with ID %d\n", search_id);
        }
        
        }
    else if(ch==2){
        printf("Enter topic to search: ");
        fgets(search_t,100,stdin);
        remove_newline(search_t);
                
        while (fread(&c, sizeof(struct complaint), 1, fptr)) {
            if (strcmp(c.topic,search_t)==0) {
                found = 1;
                printf("\nComplaint Found:\n");
                printf("Complaint ID : %d\n", c.complaintid);
                printf("Student Name : %s\n", c.name);
                printf("Student ID   : %s\n", c.studentid);
                printf("Topic        : %s\n", c.topic);
                printf("Description  : %s\n", c.describe);
                printf("Status       : %s\n", c.status);
                break;    
            }
        }
        
        if (!found) {
            printf("No complaint found with topic %s\n", search_t);
        }
        
    }
    else if(ch==3){
        printf("Enter Complaint status to search: ");
        fgets(search_s,10,stdin);
        remove_newline(search_s);

        while (fread(&c, sizeof(struct complaint), 1, fptr)) {
            if (strcmp(c.status,search_s)==0) {
                found = 1;
                printf("\nComplaint Found:\n");
                printf("Complaint ID : %d\n", c.complaintid);
                printf("Student Name : %s\n", c.name);
                printf("Student ID   : %s\n", c.studentid);
                printf("Topic        : %s\n", c.topic);
                printf("Description  : %s\n", c.describe);
                printf("Status       : %s\n", c.status);
                break;
            }
        }
    
        if (!found) {
            printf("No complaint found with status %s\n", search_s);
        }        
    }
    else printf("Invalid Choice.\n");
    fclose(fptr);
}