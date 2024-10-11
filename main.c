#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

void list_services(sqlite3 *db) {
    const char *sql = "SELECT * FROM service;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("ID | Serviced Miles | Type of Service | Item Description | Notes | Cost | Date\n");
    printf("------------------------------------------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d | %d | %s | %s | %s | %.2f | %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_int(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_text(stmt, 3),
               sqlite3_column_text(stmt, 4),
               sqlite3_column_double(stmt, 5),
               sqlite3_column_text(stmt, 6));
    }

    sqlite3_finalize(stmt);
}

void add_service(sqlite3 *db) {
    int serviced_miles;
    char type_of_service[100], item_description[100], notes[100];
    double cost;

    printf("Enter serviced miles: ");
    scanf("%d", &serviced_miles);
    printf("Enter type of service: ");
    scanf("%s", type_of_service);
    printf("Enter item description: ");
    scanf("%s", item_description);
    printf("Enter notes: ");
    scanf("%s", notes);
    printf("Enter cost: ");
    scanf("%lf", &cost);

    const char *sql = "INSERT INTO service (serviced_miles, type_of_service, item_description, notes, cost) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_int(stmt, 1, serviced_miles);
    sqlite3_bind_text(stmt, 2, type_of_service, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, item_description, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, notes, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 5, cost);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Service added successfully!\n");
    }

    sqlite3_finalize(stmt);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    sqlite3 *db;
    if (sqlite3_open("service.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (strcmp(argv[1], "ls") == 0) {
        list_services(db);
    } else if (strcmp(argv[1], "add") == 0) {
        add_service(db);
    } else {
        fprintf(stderr, "Invalid command. Use 'ls' to list services or 'add' to add a service.\n");
    }

    sqlite3_close(db);
    return 0;
}

