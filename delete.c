void delete_complaint(){
    FILE *fptr = fopen("complaintfile.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct complaint c;
    int delete_id, found = 0;

    if (fptr == NULL) {
        printf("Complaint file not found.\n");
        return;
    }

    if (temp == NULL) {
        printf("Temporary file could not be created.\n");
        fclose(fptr);
        return;
    }

    printf("Enter Complaint ID to delete: ");
    scanf("%d", &delete_id);

    while (fread(&c, sizeof(struct complaint), 1, fptr)) {
        if (c.complaintid == delete_id) {
            found = 1;
            printf("\nComplaint with ID %d deleted successfully.\n", delete_id);
            continue;  // skip writing this record to temp
        }
        fwrite(&c, sizeof(struct complaint), 1, temp);
    }

    fclose(fptr);
    fclose(temp);

    if (found) {
        remove("complaintfile.dat");
        rename("temp.dat", "complaintfile.dat");
    } else {
        printf("No complaint found with ID %d\n", delete_id);
        remove("temp.dat");  // cleanup
    }
}