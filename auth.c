void admin_login() {
    FILE *fptr = fopen("admin_record.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char username[20], password[20];
    char file_username[20], file_password[20], file_name[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    while (fscanf(fptr, "%s %s %s", file_name, file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            printf("Login successful. Welcome, %s!\n", file_name);
            found = 1;
            break;
        }
    }

    int ch;
    while(1){
        printf("=====COMPLAINT MANAGEMENT SYSTEM=====\n");
        printf("1.View all Complaints\n");
        printf("2.Search Complaint\n");
        printf("3.Update Complaint\n");
        printf("4.Delete Complaint\n");
        printf("5.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: a_view_complaint(); break;
            case 2: search_complaint(); break;
            case 3: a_update_complaint(); break;
            case 4: delete_complaint(); break;
            case 5: printf("exiting......\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }

    if (!found)
        printf("Invalid credentials.\n");

    fclose(fptr);
}
void std_login() {
    FILE *fptr = fopen("std_record.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char username[20], password[20];
    char file_username[20], file_password[20], file_name[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    while (fscanf(fptr, "%s %s %s", file_name, file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            printf("Login successful. Welcome, %s!\n", file_name);
            found = 1;
            break;
        }
    }

    int ch;
    while(1){
        printf("=====COMPLAINT MANAGEMENT SYSTEM=====\n");
        printf("1.Register your Complaint\n");
        printf("2.View your Complaint\n");
        printf("3.Update your Complaint\n");
        printf("4.Delete your Complaint\n");
        printf("5.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch (ch){
        case 1: register_complaint(); break;
        case 2: s_view_complaint(); break;
        case 3: s_update_complaint(); break;
        case 4: delete_complaint(); break;
        case 5: printf("exiting......\n"); exit(0);
        default: printf("Invalid choice\n");
        }
    }

    if (!found)
        printf("Invalid credentials.\n");

    fclose(fptr);
} 
void admin_signup(){
    FILE *fptr=fopen("admin_record.txt","a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char a_name[20],u_name[20],pass[20];
    getchar();
    printf("enter your name:");
    scanf("%[^\n]",a_name);
    getchar();
    
    printf("enter a username:");
    scanf("%[^\n]",u_name);
    getchar();
    
    printf("enter a password:");
    scanf("%[^\n]",pass);
    getchar();
    
    fprintf(fptr, "%s %s %s\n", a_name, u_name, pass);

    printf("you are successfully signed up!\n");
    fclose(fptr);
}
void std_signup(){
    FILE *fptr=fopen("std_record.txt","a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char s_name[20],u_name[20],pass[20];
    getchar();
    printf("enter your name:");
    scanf("%[^\n]",s_name);
    getchar();
    
    printf("enter a username:");
    scanf("%[^\n]",u_name);
    getchar();
    
    printf("enter a password:");
    scanf("%[^\n]",pass);
    getchar();

    fprintf(fptr, "%s %s %s\n", s_name, u_name, pass);

    printf("you are successfully signed up!\n");
    fclose(fptr);
}
void signup(){
    int ch;
    printf("Want to sign up as a student or as a admin\n1.sign up as student\n2.sign up as admin\n");
    printf("enter your choice:");
    scanf("%d",&ch);    
    switch (ch){
        case 1: std_signup(); break;
        case 2: admin_signup(); break;
    }    
}
void login(){
    int ch;
    printf("Want to login as a student or as a admin\n1.login as student\n2.login as admin\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch (ch){
        case 1: std_login(); break;
        case 2: admin_login(); break;
    }    
}
void auth(){
    int ch;
    printf("Want to login or signup\n1.login\n2.signup\n3.exit\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch (ch){
        case 1: login(); break;
        case 2: signup(); break;
        case 3: exit(0);
    }            
}
