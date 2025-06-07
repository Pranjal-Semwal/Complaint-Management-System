void register_complaint(){
    FILE *fptr=fopen("complaintfile.dat","ab");
    struct complaint c;
    if(fptr==NULL){
        printf("error...\n");
        return;
    }
    FILE *readptr = fopen("complaintfile.dat", "rb");
    int count = 0;
    struct complaint temp;
    while (fread(&temp, sizeof(struct complaint), 1, readptr)) {
        count++;
    }
    fclose(readptr);
    c.complaintid = 2025099 + count + 1;
    getchar();
    printf("enter your name: ");
    fgets(c.name,20,stdin);
    remove_newline(c.name);

    printf("enter your student id: ");
    fgets(c.studentid,20,stdin);
    remove_newline(c.studentid);

    printf("About what your complaint is: ");
    fgets(c.topic,100,stdin);
    remove_newline(c.topic);

    printf("Describe your complaint: ");
    fgets(c.describe,200,stdin);
    remove_newline(c.describe);
    
    printf("Urgency of your complaint low, medium, high: ");
    fgets(c.urgency,200,stdin);
    remove_newline(c.urgency);

    strcpy(c.status,"pending");

    fwrite(&c,sizeof(struct complaint),1,fptr);
    fclose(fptr);
    
    printf("your complaint id is %d",c.complaintid);
    printf("Your complaint is successfully registered.\n");
}