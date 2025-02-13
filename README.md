# Client Management System
- A C++ console application for managing 🏦 banking clients and system users with role-based permissions. 
This system allows performing transactions, managing client data, and controlling user access levels.
## Main Menu 📜 
- ![Menu Client](https://github.com/TariqCodeBit/photoProfile/blob/main/Screenshot%202025-01-29%20211334.png) 
## Example Client Entry
- ![Ex add Data Client](https://github.com/TariqCodeBit/photoProfile/blob/main/Screenshot%202025-01-29%20213407.png)

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
- ![File Format clients](https://githin/Screenshot%202025-01-29%20213503.png)
    - 📄 Users.txt 🔐 – Stores user credentials & permissions 🛡️
- ![file format Users]()
### Security Features
- Login authentication system
- Role-based access control
- Permission levels using bitmasking

## Permissions System
The system uses bitwise permissions:
- `Full Access (-1)`: All permissions
- `Show Clients (1)`: View client list
- `Add Clients (2)`: Add new clients
- `Delete Clients (4)`: Remove clients
- `Update Clients (8)`: Modify client info
- `Find Clients (16)`: Search clients
- `Transactions (32)`: Deposit/Withdraw
- `Manage Users (64)`: User administration

## Requirements
1. C++ Compiler
2. Standard C++ Lipraries (iostream,fstream,vector,iomanip,string)
- code Clone
~~~
git clone https://github.com/TariqCodeBit/Bank-

~~~


   
