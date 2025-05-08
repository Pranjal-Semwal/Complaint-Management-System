void login() {
    char username[20], password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, "Pranjal") == 0 && strcmp(password, "pass") == 0) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password. Exiting...\n");
        exit(0);
    }
}