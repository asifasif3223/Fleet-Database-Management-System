#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_AIRCRAFT 50
#define MAX_CITY_LENGTH 50
#define DATA_FILE "aircraft_data.dat"
typedef struct {
    int id;
    char model[50];
    char registration[20];
    float latitude;
    float longitude;
    float fuel_level;
    float speed;
    int maintenance_due;
    char departing_city[MAX_CITY_LENGTH];
    char destination[MAX_CITY_LENGTH];
    float travel_time;
} Aircraft;
Aircraft fleet[MAX_AIRCRAFT];
int aircraft_count = 0;
void loadData() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        printf("Error opening %s. Starting new.\n", DATA_FILE);
        return;
    }
    aircraft_count = fread(fleet, sizeof(Aircraft), MAX_AIRCRAFT, fp);
    fclose(fp);
    printf("Loaded %d aircraft from %s.\n", aircraft_count, DATA_FILE);
}
void saveData() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) {
        printf("Error opening %s for writing.\n", DATA_FILE);
        return;
    }
    fwrite(fleet, sizeof(Aircraft), aircraft_count, fp);
    fclose(fp);
    printf("Saved %d aircraft to %s.\n", aircraft_count, DATA_FILE);
}
void add() {
    if (aircraft_count >= MAX_AIRCRAFT) {
        printf("Fleet full.\n");
        return;
    }
    Aircraft *newAircraft = &fleet[aircraft_count];
    printf("Enter ID: ");
    if (scanf("%d", &newAircraft->id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Model of Aircraft: ");
    scanf("%s", newAircraft->model);
    printf("Enter International Registration: ");
    scanf("%s", newAircraft->registration);
    printf("Enter Latitude(m): ");
    if (scanf("%f", &newAircraft->latitude) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Longitude: ");
    if (scanf("%f", &newAircraft->longitude) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Fuel (minimum 20%% - 100%%): ");
    if (scanf("%f", &newAircraft->fuel_level) != 1 || newAircraft->fuel_level < 20 || newAircraft->fuel_level > 100) {
        printf("Invalid fuel level. Please enter a value between 20 and 100.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Speed(km/h)(maximum spreed 800km/h): ");
    if (scanf("%f", &newAircraft->speed) != 1 || newAircraft->speed < 0 || newAircraft->speed > 800) {
        printf("Invalid speed. Please enter a value between 0 and 800.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Maintenance Due (minimum 2 days): ");
    if (scanf("%d", &newAircraft->maintenance_due) != 1 || newAircraft->maintenance_due < 2) {
        printf("Invalid maintenance due. Please enter a value of 2 or more.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Enter Departing City: ");
    scanf("%s", newAircraft->departing_city);
    printf("Enter Destination: ");
    scanf("%s", newAircraft->destination);
    printf("Enter Travel Time(hours): ");
    if (scanf("%f", &newAircraft->travel_time) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    aircraft_count++;
    saveData();
    printf("Aircraft added.\n");
}
void update() {
    int id, choice, i, found = 0;
    printf("Enter ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    for (i = 0; i < aircraft_count; i++) {
        if (fleet[i].id == id) {
            found = 1;
            printf("\nUpdate Options:\n");
            printf("1. Location\n2. Fuel\n3. Speed\n4. Maintenance Due\n5. Destination\n");
            printf("Enter choice: ");
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                return;
            }
            switch (choice) {
                case 1:
                    printf("Enter new Latitude: ");
                    if (scanf("%f", &fleet[i].latitude) != 1) {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    printf("Enter new Longitude: ");
                    if (scanf("%f", &fleet[i].longitude) != 1) {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    break;
                case 2:
                    printf("Enter new Fuel (minimum 20%% - 100%%): ");
                    if (scanf("%f", &fleet[i].fuel_level) != 1 || fleet[i].fuel_level < 20 || fleet[i].fuel_level > 100) {
                        printf("Invalid fuel level. Please enter a value between 20 and 100.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    break;
                case 3:
                    printf("Enter new Speed(km/h): ");
                    if (scanf("%f", &fleet[i].speed) != 1 || fleet[i].speed < 0 || fleet[i].speed > 1000) {
                        printf("Invalid speed. Please enter a value between 0 and 1000.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    break;
                case 4:
                    printf("Enter new Maintenance Due (minimum 5 days): ");
                    if (scanf("%d", &fleet[i].maintenance_due) != 1 || fleet[i].maintenance_due < 5) {
                        printf("Invalid maintenance due. Please enter a value of 5 or more.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    break;
                case 5:
                    printf("Enter new Departing City: ");
                    scanf("%s", fleet[i].departing_city);
                    printf("Enter new Destination: ");
                    scanf("%s", fleet[i].destination);
                    printf("Enter new Travel Time: ");
                    if (scanf("%f", &fleet[i].travel_time) != 1) {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        return;
                    }
                    break;
                default:
                    printf("Invalid update option.\n");
                    return;
            }
            saveData();
            printf("Aircraft %d updated.\n", id);
            return;
        }
    }
    if (!found) printf("Aircraft %d not found.\n", id);
}
void search() {
    int id, i, found = 0;
    printf("Enter ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    for (i = 0; i < aircraft_count; i++) {
        if (fleet[i].id == id) {
            printf("No.%d, ID: %d, Model: %s, Registration: %s, Location: (%.2f, %.2f), Fuel: %.2f%%, Speed: %.2f km/h, Maintenance Due: %d days, Departing City: %s, Destination: %s, Travel Time: %.2f hours\n",
                   i + 1, fleet[i].id, fleet[i].model, fleet[i].registration, fleet[i].latitude, fleet[i].longitude,
                   fleet[i].fuel_level, fleet[i].speed, fleet[i].maintenance_due, fleet[i].departing_city, fleet[i].destination, fleet[i].travel_time);
            found = 1;
            return;
        }
    }
    if (!found) printf("Aircraft %d not found.\n", id);
}
void delete() {
    int id, i, j, found = 0;
    printf("Enter ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    for (i = 0; i < aircraft_count; i++) {
        if (fleet[i].id == id) {
            found = 1;
            for (j = i; j < aircraft_count - 1; j++) {
                fleet[j] = fleet[j + 1];
            }
            aircraft_count--;
            saveData();
            printf("Aircraft %d deleted.\n", id);
            return;
        }
    }
    if (!found) printf("Aircraft %d not found.\n", id);
}
void display() {
    if (aircraft_count == 0) {
        printf("No aircraft in fleet.\n");
        return;
    }
    printf("\nFleet Details:\n");
    printf("No.\tID\tModel\t\tRegistration\tLatitude\tLongitude\tFuel(%%)\tSpeed(km/h)\tMaintenance Due(days)\tDeparting City\tDestination\tTravel Time(hrs)\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < aircraft_count; i++) {
        printf("%d\t%d\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\t\t%s\t\t%s\t\t%.2f\n",
               i + 1, fleet[i].id, fleet[i].model, fleet[i].registration, fleet[i].latitude, fleet[i].longitude,
               fleet[i].fuel_level, fleet[i].speed, fleet[i].maintenance_due, fleet[i].departing_city, fleet[i].destination, fleet[i].travel_time);
    }
}
void report() {
    if (aircraft_count == 0) {
        printf("No aircraft in fleet.\n");
        return;
    }
    printf("\nCompliance Report:\n");
    printf("ID\tModel\t\tFuel(%%)\tSpeed(km/h)\tMaintenance Due(days)\tDeparting City\tDestination\tTravel Time(hrs)\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < aircraft_count; i++) {
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%d\t\t%s\t\t%s\t\t%.2f\n",
               fleet[i].id, fleet[i].model, fleet[i].fuel_level, fleet[i].speed, fleet[i].maintenance_due,
               fleet[i].departing_city, fleet[i].destination, fleet[i].travel_time);
        if (fleet[i].fuel_level < 20) printf("  >> ALERT: Low Fuel!\n");
        if (fleet[i].speed > 700) printf("  >> ALERT: Approaching Speed Limit!\n");
        if (fleet[i].speed >= 800) printf("  >> ALERT: Exceeding Speed Limit!\n");
        if (fleet[i].maintenance_due < 2) printf("  >> ALERT: Maintenance Due Soon!\n");
    }
}
int main() {
    srand(time(0));
    loadData();
    int choice;
    printf("\n===================================================\n");
    printf("    Evergreen Airways Fleet Management Database        \n");
    printf("===================================================\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Aircraft\n");
        printf("2. Update Aircraft(All types of information update)\n");
        printf("3. Search Aircraft\n");
        printf("4. Delete Aircraft\n");
        printf("5. Compliance Report\n");
        printf("6. Display Fleet\n");
        printf("7. Save and Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1: add(); break;
            case 2: update(); break;
            case 3: search(); break;
            case 4: delete(); break;
            case 5: report(); break;
            case 6: display(); break;
            case 7: saveData(); printf("Exiting.\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
