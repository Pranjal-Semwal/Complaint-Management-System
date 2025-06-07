void s_update_complaint(){
    FILE *fptr = fopen("complaintfile.dat", "rb+");
    struct complaint c;
    int update_id, found = 0;

    if (fptr == NULL){
        printf("Complaint file not found.\n");
        return;
    }

    printf("Enter your Complaint ID: ");
    scanf("%d", &update_id);

    while (fread(&c, sizeof(struct complaint), 1, fptr)) {
        if (c.complaintid == update_id) {
            found = 1;
            print_complaint(c);

            while (1) {
                int ch;
                printf("\nWhat do you want to update?\n");
                printf("1. Topic\n2. Description\n3. Urgency\n4. Back to previous page\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                getchar(); // Clear newline character

                if (ch == 4) {
                    printf("Returning to student menu...\n");
                    break;
                }

                switch (ch) {
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
                        printf("Enter new urgency: ");
                        fgets(c.urgency, sizeof(c.urgency), stdin);
                        remove_newline(c.urgency);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        continue;
                }
                printf("Field updated.\n");
            }

            // Move pointer back and write updated data
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
