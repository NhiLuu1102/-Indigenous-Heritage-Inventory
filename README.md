# Indigenous Heritage Inventory System

## Overview
The Indigenous Heritage Inventory System is a project designed to manage and preserve heritage sites, including cultural and natural sites. This system provides functionality for adding, viewing, and managing heritage sites, categories, and preservation efforts. It aims to facilitate the systematic tracking and documentation of heritage information.

## Features

### Heritage Site Management
- **Add Heritage Sites**: Register cultural or natural sites with relevant details such as name, location, and significance.
- **View Heritage Sites**: Display details of all registered heritage sites.

### Category Management
- **Add Categories**: Create categories to group heritage sites by shared characteristics.
- **View Categories**: Display all categories and their associated sites.

### Preservation Efforts
- **Record Preservation Efforts**: Log preservation activities for specific heritage sites, including effort ID, description, and date.
- **View Preservation History**: Review recorded preservation efforts.

## Project Structure

The project contains the following classes:

### 1. `HeritageSite`
- Manages information about individual heritage sites.
- Supports attributes like site ID, name, location, and category ID.
- Includes methods for viewing and updating site details.

### 2. `CulturalSite` (Derived from `HeritageSite`)
- Adds cultural significance details for cultural heritage sites.
- Overrides the `getDescription` method.

### 3. `NaturalSite` (Derived from `HeritageSite`)
- Adds ecosystem details for natural heritage sites.
- Overrides the `getDescription` method.

### 4. `Category`
- Groups heritage sites into categories.
- Supports adding and displaying sites under a specific category.

### 5. `PreservationEffort`
- Logs preservation activities for heritage sites.
- Stores effort ID, site ID, description, and date.

### 6. `HeritageInventorySystem`
- Combines functionality from the other classes to manage the entire heritage inventory.
- Supports operations like adding sites, managing categories, and recording/viewing preservation efforts.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC, Clang).
- Basic knowledge of C++ programming.

### How to Run
1. Clone this repository to your local machine.
2. Compile the source code using a C++ compiler:
   g++ -o heritage_inventory final_project.cpp
3. Run the compiled program:
   ./heritage_inventory

## Contributing
Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.

### Contact
For questions or feedback, please contact the project maintainer at emma.luu112@gmail.com.

