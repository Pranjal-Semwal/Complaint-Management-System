void search_complaint(){
    FILE *fptr = fopen("complaintfile.dat", "rb");
    struct complaint c;
    int search_id, found = 0;
    char search_t[200], search_s[10], search_u[10];

    if (fptr == NULL) {
        printf("Complaint file not found.\n");
        return;
    }

    int ch;
    printf("Search complaint by:\n");
    printf("1. Complaint ID\n2. Topic\n3. Status\n4. Urgency\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    getchar(); // To consume newline after number input

    switch (ch) {
        case 1:
            printf("Enter Complaint ID to search: ");
            scanf("%d", &search_id);
            while (fread(&c, sizeof(struct complaint), 1, fptr)) {
                if (c.complaintid == search_id) {
                    print_complaint(c);
                    found = 1;
                    break;  // Only one ID expected
                }
            }
            if (!found)
                printf("No complaint found with ID %d\n", search_id);
            break;

        case 2:
            printf("Enter topic to search: ");
            fgets(search_t, sizeof(search_t), stdin);
            remove_newline(search_t);
            while (fread(&c, sizeof(struct complaint), 1, fptr)) {
                if (strcmp(c.topic, search_t) == 0) {
                    print_complaint(c);
                    found = 1;
                }
            }
            if (!found)
                printf("No complaint found with topic %s\n", search_t);
            break;

        case 3:
            printf("Enter complaint status to search: ");
            fgets(search_s, sizeof(search_s), stdin);
            remove_newline(search_s);
            while (fread(&c, sizeof(struct complaint), 1, fptr)) {
                if (strcmp(c.status, search_s) == 0) {
                    print_complaint(c);
                    found = 1;
                }
            }
            if (!found)
                printf("No complaint found with status %s\n", search_s);
            break;

        case 4:
            printf("Enter complaint urgency to search: ");
            fgets(search_u, sizeof(search_u), stdin);
            remove_newline(search_u);
            while (fread(&c, sizeof(struct complaint), 1, fptr)) {
                if (strcmp(c.urgency, search_u) == 0) {
                    print_complaint(c);
                    found = 1;
                }
            }
            if (!found)
                printf("No complaint found with urgency %s\n", search_u);
            break;

        default:
            printf("Invalid choice.\n");
    }

    fclose(fptr);
}
