🎨 NFT Marketplace – C++ OOP Project
📌 Project Overview

This project is a console-based NFT Marketplace system developed in C++ using Object-Oriented Programming (OOP) principles.
It simulates how users can register, log in, create NFTs, buy/sell NFTs, and manage wallet balances, while persisting data using file handling.

The project is designed for academic purposes to demonstrate real-world application of:

OOP concepts

File handling

Modular program structure

User interaction via console

🛠️ Technologies Used

Language: C++

IDE: Dev-C++

Compiler: MinGW (GCC)

Paradigm: Object-Oriented Programming

Storage: Text files (.txt) for persistent data

📂 Project Structure Explanation
🔹 Root Directory
DEV C++ project/


This directory contains:

User data files

NFT data files

Compiled executable

Project configuration files

🔹 Main Source Code Folder
DEV C++ project/finals project/


This folder contains the core implementation of the NFT Marketplace.

🧱 Core Classes & Files
1️⃣ User.h / User.cpp

Purpose:
Handles user-related operations.

Responsibilities:

Stores username, password, and wallet balance

Manages owned NFTs

Handles login authentication

Saves and loads user NFTs from files

OOP Concepts Used:

Encapsulation

Constructors & destructors

Dynamic memory management

2️⃣ NFT.h / NFT.cpp

Purpose:
Defines the base NFT structure.

Responsibilities:

NFT ID

Title

Price

Owner information

Acts as a base class for specialized NFT types.

3️⃣ ArtNft.h / ArtNft.cpp

Purpose:
Represents art-based NFTs.

Responsibilities:

Inherits from NFT

Adds art-specific behavior

Demonstrates inheritance & polymorphism

4️⃣ Marketplace.h / Marketplace.cpp

Purpose:
Controls marketplace logic.

Responsibilities:

Display NFTs available for sale

Handle buying and selling

Transfer ownership

Update wallet balances

Acts as the central controller of the system.

5️⃣ main.cpp

Purpose:
Program entry point.

Responsibilities:

Displays menus

Handles user interaction

Calls marketplace and user functions

Controls application flow

📁 Data Handling Files
🔹 User Data Files

users.txt

all_users.txt

blocked_users.txt

Purpose:

Store registered users

Maintain login records

Manage blocked users (if applicable)

🔹 NFT Ownership Files

Examples:

nfts_Rameez.txt

nfts_Abdullah.txt

nfts_IBRAHIM.txt

Purpose:

Each file stores NFTs owned by a specific user

Ensures persistent NFT ownership

⚙️ Configuration & Build Files
Makefile.win

Used by Dev-C++ for compilation

.dev and .layout files

Dev-C++ project configuration

UI layout and compiler settings

▶️ How to Run the Project
Method 1: Using Executable

Open:

DEV C++ project/Project2.exe


Run directly (Windows)

Method 2: Using Dev-C++

Open Project2.dev

Click Compile & Run

Ensure all .cpp files are included

🔐 Features Implemented

User registration & login

Wallet balance system

NFT creation

Buying & selling NFTs

Ownership transfer

File-based data persistence

Modular OOP-based design

🎯 OOP Concepts Demonstrated

Encapsulation – private data members

Inheritance – ArtNFT from NFT

Polymorphism – virtual functions

Abstraction – separation of logic via classes

Dynamic Memory Allocation

File Handling

📚 Academic Relevance

This project is ideal for:

OOP Final Exam Projects

Software Engineering Fundamentals

C++ Practical Demonstrations

It reflects real-world marketplace logic using clean and structured OOP design.

👨‍💻 Author

Rameez ul Hassan, Abdullah, Ibrahim, Aswad
Final OOP Project – C++
