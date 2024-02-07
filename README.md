# Object-Oriented Library Management System

This repository contains an object-oriented library management system designed to streamline library operations, including tracking books, authors, genres, patrons, and interactions within the library. Developed in C++, this system exemplifies advanced object-oriented programming principles and effective system architecture planning.

## Features

- **Book Tracking**: Manage a comprehensive list of books, including details such as title, author(s), genre, and availability.
- **Author Management**: Keep records of authors, including biographical information and their works.
- **Genre Classification**: Allows for the categorization of books into various genres for easier discovery and management.
- **Patron Interactions**: Track patron activities, including book checkouts, returns, and reservation histories.
- **Central Library Entity**: A unified interface to interact with the system, facilitating operations such as searches, transactions, and reports.

## System Architecture

The system is designed around core classes that represent the various entities involved in a library system:

- `Author`: Manages author-specific information.
- `Book`: Represents books, including metadata like title, author(s), and genre.
- `Genre`: Categorizes books into genres.
- `Patron`: Represents a library patron, including their interaction history.
- `Library`: Acts as the central hub for managing the interactions between books, authors, genres, and patrons.

Each class is designed to encapsulate its respective data and behaviors, demonstrating the principles of encapsulation, inheritance, and polymorphism where appropriate.

## Getting Started

### Prerequisites

Ensure you have a C++ compiler installed on your system. This project was developed using GCC, but any standard-compliant C++ compiler should work.

### Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/oop-library-management-system.git
   ```
2. Navigate to the cloned repository's directory.
3. Compile the source code:
   ```bash
   make
   ```
4. Run the compiled program:
   ```bash
   ./libraryManagementSystem
   ```

## Usage

After running the program, you will be presented with a menu to interact with the library system. Options include adding new books, registering authors, checking out books for patrons, and more. Navigate through the menu options to manage and interact with the library system.
