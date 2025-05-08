void update_complaint(){
    FILE *fptr=fopen("complaintfile.dat","rb+");
    struct complaint c;
    int update_id,found=0;
    if (fptr==NULL){
        printf("Complaint not found.\n");
        return;
    }
    printf("Enter Complaint ID to Update:");
    scanf("%d",&update_id);
    while (fread(&c, sizeof(struct complaint), 1, fptr)) {
        if (c.complaintid == update_id) {
            found = 1;

            printf("\nComplaint Found:\n");
            printf("Complaint ID : %d\n", c.complaintid);
            printf("Student Name : %s\n", c.name);
            printf("Student ID   : %s\n", c.studentid);
            printf("Topic        : %s\n", c.topic);
            printf("Description  : %s\n", c.describe);
            printf("Status       : %s\n", c.status);
            
            int choice;
            printf("\nWhat do you want to update?\n");
            printf("1. Topic\n2. Description\n3. Status\n");
            printf("enter your choice:");
            scanf("%d", &choice);
            getchar(); // clear newline

            switch (choice) {
                case 1:
                    printf("Enter new topic: ");
                    fgets(c.topic, sizeof(c.topic), stdin);
                    remove_newline(c.topic);
                    break;
                case 2:
                    printf("Enter new description: ");
                    fgets(c.describe, sizeof(c.describe), stdin);
                    remove_newline(c.describe);
                    break;
                case 3:
                    printf("Enter new status: ");
                    fgets(c.status, sizeof(c.status), stdin);
                    remove_newline(c.status);
                    break;
                default:
                    printf("Invalid choice.\n");
                    fclose(fptr);
                    return;
            }

            // Move file pointer back to the correct position
            fseek(fptr, -sizeof(struct complaint), SEEK_CUR);
            fwrite(&c, sizeof(struct complaint), 1, fptr);
            printf("Complaint updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("No complaint found with ID %d\n", update_id);
    }

    fclose(fptr);
}