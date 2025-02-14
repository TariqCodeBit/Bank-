# Client Management System
- A C++ console application for managing 🏦 banking clients and system users with role-based permissions. 
This system allows performing transactions, managing client data, and controlling user access levels.
## Main Menue 📜 
- ![Menu Client](https://github.com/TariqCodeBit/photoProfile/blob/main/Screenshot%202025-02-13%20150648.png) 
## Transactions Menue 📜 
- ![Menue Transactions](https://github.com/TariqCodeBit/photoProfile/blob/main/Screenshot%202025-02-13%20150710.png)
## Manage Menue 📜 
- ![Menue Manage](https://github.com/TariqCodeBit/photoProfile/blob/main/Screenshot%202025-02-13%20150729.png)
## Features

- **Client Management**
  - 📄 Show all clients (Account Number, PIN, Name, Phone, Balance)
  - ➕ Add new clients with unique account numbers
  - ❌ Delete clients by account number
  - ✏️ Update client information
  - 🔍 Find clients by account number

- **Banking Transactions**
  - 💰 Deposit funds
  - 💸 Withdraw funds (with balance validation)
  - 📊 Show total balances across all accounts

- **User Management (Admin Only)🛠️**
  - 🆕 Create new users with specific permissions 🔑👤
  - 📋 List/✏️ Update/ 🗑️ Delete existing users
  - 🔍 Find users by username

- **Data Persistence**
  - 📁 Automatic saving to `Clients.txt`
  - 🔄 Real-time data synchronization
  - #//# delimiter-based storage format
  ### File Structure 📂
    - 📄 Clients.txt 🏦 – Stores client records 📜
      - "#//#"
    - 📄 Users.txt 🔐 – Stores user credentials & permissions 🛡️
      - "#//#"


## Requirements
1. C++ Compiler
2. Standard C++ Lipraries (iostream,fstream,vector,iomanip,string)
- code Clone
~~~
git clone https://github.com/TariqCodeBit/Bank-

~~~
## Author
- The Game was developed by **Tarek**.



   
