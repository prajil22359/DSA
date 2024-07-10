char arr[m][n];
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
    // printf("Enter your value.\n");
    char value;
    do scanf("%c", &value);
        while ( value == '\n' || value == '\r');
    arr[i][j] = value;
}
}
