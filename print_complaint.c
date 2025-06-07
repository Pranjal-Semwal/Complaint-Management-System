void print_complaint(struct complaint c) {
    printf("\nComplaint Found:\n");
    printf("Complaint ID : %d\n", c.complaintid);
    printf("Student Name : %s\n", c.name);
    printf("Student ID   : %s\n", c.studentid);
    printf("Topic        : %s\n", c.topic);
    printf("Description  : %s\n", c.describe);
    printf("Status       : %s\n", c.status);
    printf("Urgency      : %s\n", c.urgency);
}
