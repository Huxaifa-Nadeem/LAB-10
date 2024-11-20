#include <stdio.h>
#include <string.h>

#define MAX_PKG 5
#define MAX_LEN 100

typedef struct {
    char pkgName[MAX_LEN];
    char location[MAX_LEN];
    int days;
    float price;
    int seatsLeft;
} Package;

void showPackages(Package pkgs[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s to %s - %d days - $%.2f - Seats: %d\n", 
               i + 1, pkgs[i].pkgName, pkgs[i].location, pkgs[i].days, pkgs[i].price, pkgs[i].seatsLeft);
    }
}

void reservePackage(Package pkgs[], int count) {
    int option, seats;
    printf("Choose package number: ");
    scanf("%d", &option);
    option--;

    if (option < 0 || option >= count) {
        printf("Invalid selection.\n");
        return;
    }

    if (pkgs[option].seatsLeft > 0) {
        printf("Seats to book: ");
        scanf("%d", &seats);

        if (seats <= 0 || seats > pkgs[option].seatsLeft) {
            printf("Invalid or too many seats.\n");
        } else {
            pkgs[option].seatsLeft -= seats;
            printf("Booking confirmed for %d seats.\n", seats);
        }
    } else {
        printf("No seats available.\n");
    }
}

int main() {
    Package pkgs[MAX_PKG] = {
        {"Beach Escape", "Hawaii", 7, 1500.00, 10},
        {"Mountain Expedition", "Himalayas", 14, 2000.00, 5},
        {"City Break", "Paris", 5, 1200.00, 8},
        {"Desert Safari", "Dubai", 6, 1800.00, 3},
        {"Ocean Cruise", "Caribbean", 10, 2500.00, 12}
    };

    int choice;
    while (1) {
        printf("\n1. View Packages\n2. Book Package\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showPackages(pkgs, MAX_PKG);
        } else if (choice == 2) {
            reservePackage(pkgs, MAX_PKG);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
