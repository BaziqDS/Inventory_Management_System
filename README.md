# Inventory Management System

## Description

This is a console-based Inventory Management System developed in C as part of a course project at NED University. The application allows users to manage product inventory through a simple command-line interface, including features for user authentication, adding, removing, displaying, searching, and modifying products.

## Features

- **User Authentication**: Create accounts and login to access the system.
- **Add Products**: Enter product details including name, price, quantity, category, and description.
- **Remove Products**: Delete products by ID or name.
- **Display Products**: View all products in a tabular format.
- **Search Products**: Find products by ID or name.
- **Modify Products**: Update existing product information.
- **Data Persistence**: Products and credentials are stored in text files (Product.txt and credentials.txt).

## Technologies Used

- C Programming Language
- File I/O for data storage
- Windows Console API for UI (gotoxy, etc.)

## Installation and Usage

1. Ensure you have a C compiler installed (e.g., GCC).
2. Clone or download the repository.
3. Compile the program:
   ```
   gcc IMS.c -o IMS.exe
   ```
4. Run the executable:
   ```
   ./IMS.exe
   ```

## Screenshots

Screenshots of the application are available in the `ScreenShots/` folder.

## Project Structure

- `IMS.c`: Main source code file.
- `credentials.txt`: Stores user credentials.
- `Product.txt`: Stores product data.
- `ScreenShots/`: Contains application screenshots.
- `IMS Project Report.docx`: Project report document.
- `Project Proposal.pdf`: Project proposal document.

## Contributing

This is a course project. Feel free to fork and modify for educational purposes.