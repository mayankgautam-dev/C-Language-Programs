#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(const char* password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    int score = hasUpper + hasLower + hasDigit + hasSpecial;

    if (length >= 8) score++;
    return score;
}

void giveFeedback(int score) {
    switch (score) {
        case 5:
            printf("✅ Strong password!\n");
            break;
        case 4:
            printf("🟡 Good password, but could be stronger.\n");
            break;
        case 3:
            printf("🟠 Weak password! Add more variety (digits, symbols).\n");
            break;
        default:
            printf("🔴 Very weak password. Use at least 8 characters, mix cases, numbers, and symbols.\n");
    }
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int score = checkPasswordStrength(password);
    giveFeedback(score);

    return 0;
}
