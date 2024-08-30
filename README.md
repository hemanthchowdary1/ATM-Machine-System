# ATM Banking System

## Overview

This project is a basic ATM banking system implemented in C++. It simulates an ATM machine with features for withdrawing money, depositing funds, and checking the account balance. The application uses a file-based approach to manage account balances.

## Features

- **PIN Verification**: Secure access using a default PIN (123).
- **Withdrawals**: Allows users to withdraw money if sufficient funds are available.
- **Deposits**: Enables users to deposit money into their account.
- **Balance Inquiry**: Provides users with their current account balance.
- **File-Based Database**: Account balance is stored in a text file (`BDO Database.txt`).
- **Error Handling**: Includes basic error handling for file operations and input validation.

## Usage

1. **Run the Program**: Compile and execute the `ATM_Banking_System.cpp` file.

2. **Enter Your Card**: You will be prompted to enter your PIN.

3. **PIN Verification**: Enter the PIN (default is `123`).

4. **Choose a Transaction**:
   - **Withdraw**: Enter the amount to withdraw.
   - **Deposit**: Enter the amount to deposit.
   - **Balance Inquiry**: View your current balance.
   - **Quit**: Exit the program.

5. **File Management**: The program reads and writes to `BDO Database.txt`. Ensure this file exists in the same directory as the executable.
