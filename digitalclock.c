#include <stdio.h>
#include <windows.h>

int main() {
    int h = 0, m = 0, s = 0;  // hour, minute, second

    printf("Set Time (HH MM SS): ");
    scanf("%d %d %d", &h, &m, &s);

    if (h >= 24 || m >= 60 || s >= 60) {
        printf("Invalid time format!\n");
        return 0;
    }

    while (1) {
        system("cls");  // clear screen

        printf("\n\n\t\t==============================\n");
        printf("\t\t        DIGITAL CLOCK\n");
        printf("\t\t==============================\n\n");
        printf("\t\t     %02d : %02d : %02d\n", h, m, s);
        printf("\n\t\t==============================\n");

        Sleep(1000);  // delay 1 second
        s++;

        if (s == 60) {
            s = 0;
            m++;
        }
        if (m == 60) {
            m = 0;
            h++;
        }
        if (h == 24) {
            h = 0;
        }
    }

    return 0;
}
