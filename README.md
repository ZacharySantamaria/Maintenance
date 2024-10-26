# Documentation for `Maintance`

## Overview

This CLI program interacts with a SQLite database (`service.db`) to manage service entries. Users can list existing entries or add new service records.

---

## Functions

### `void list_services(sqlite3 *db);`
- **Description**: Retrieves and displays all service entries from the `service` table in the database.
- **Parameters**:
  - `sqlite3 *db`: Pointer to the SQLite database connection.
- **Returns**: None.
- **Usage**: Call this function after opening a connection to the database to list all service records.

### `void add_service(sqlite3 *db);`
- **Description**: Prompts the user for details about a new service entry and inserts it into the `service` table.
- **Parameters**:
  - `sqlite3 *db`: Pointer to the SQLite database connection.
- **Returns**: None.
- **Usage**: Call this function to add a new service record after verifying that the user wants to add one.
- **Input Prompts**:
  - Serviced miles (integer).
  - Type of service (string).
  - Item description (string).
  - Notes (string).
  - Cost (double).
- **Error Handling**: Checks the return value of `scanf` to ensure valid input and displays error messages if needed.

### `int main(int argc, char **argv);`
- **Description**: Entry point of the program. Processes command-line arguments to either list services or add a new service.
- **Parameters**:
  - `int argc`: Argument count.
  - `char **argv`: Array of argument strings.
- **Returns**: Exit status code (0 for success, 1 for failure).
- **Usage**: This function checks for valid commands (`ls` or `add`) and invokes the appropriate function based on user input.
- **Database Connection**: Opens a connection to `service.db` and ensures it closes before the program exits.

---

## Data Structure

- **Database Table**: `service`
  - **Columns**:
    - `id`: Integer, primary key (auto-increment).
    - `serviced_miles`: Integer, miles at the time of service.
    - `type_of_service`: Text, description of the type of service.
    - `item_description`: Text, details of the service items.
    - `notes`: Text, any additional notes regarding the service.
    - `cost`: Real, cost of the service.
    - `date`: Text, date of service (auto-generated).

---

## Compilation

To compile the program, use the following command:

```bash
make
```

## Cleaning up
To clean up the program executable, use the following command:
```bash
make clean
```
