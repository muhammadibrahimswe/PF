<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows"/>
  <img src="https://img.shields.io/badge/Compiler-MinGW_GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white" alt="MinGW GCC"/>
  <img src="https://img.shields.io/badge/Paradigm-Procedural-orange?style=for-the-badge" alt="Procedural"/>
</p>

<h1 align="center">🏦 Bank Management System (BMS)</h1>

<p align="center">
  A fully-featured, console-based <strong>Bank Management System</strong> built in <strong>procedural C++</strong> as a Programming Fundamentals semester project. The system simulates real-world banking operations across three distinct user interfaces — <em>Admin</em>, <em>Customer</em>, and <em>ATM</em> — with persistent file-based storage and a polished, color-coded terminal UI.
</p>

---

## ✨ Key Features

### 🔐 Admin / Manager Portal
| Feature | Description |
|---|---|
| Secure Login | Credential-based authentication with masked password input |
| Customer CRUD | Add, view, search, edit, and delete customer accounts |
| Banking Operations | Perform deposits, withdrawals, and inter-account fund transfers |
| Transaction Audit Log | View complete transaction history across all accounts |
| Bank Statistics | Aggregated reports — total balance, account breakdowns, transaction count |
| Account Security | Lock / Unlock customer accounts |

### 👤 Customer Self-Service
| Feature | Description |
|---|---|
| Self-Registration | Open a new account with CNIC uniqueness validation |
| Secure Login | 3-attempt limit with automatic account lockout on failure |
| Profile & Balance | View account details and check balance |
| Deposits & Withdrawals | Self-service transactions with balance verification |
| Fund Transfers | Inter-account transfers with dual transaction logging |
| Password Management | Change password with complexity re-validation |
| Transaction History | View personal transaction records |
| Zakat Auto-Deduction | Automatic 2.5% Zakat deduction when balance exceeds PKR 3,000,000 (Nisab threshold) |

### 🏧 ATM Simulation
| Feature | Description |
|---|---|
| PIN Authentication | Masked 4-digit PIN entry with 3-attempt security |
| Balance Inquiry | Real-time balance check with Zakat evaluation |
| Cash Withdrawal | Custom-amount withdrawals with balance validation |
| Fast Cash | Preset quick withdrawals — PKR 500 / 1,000 / 5,000 / 10,000 |
| Mini Statement | Last 5 transactions at a glance |
| PIN Management | Secure PIN change with old PIN verification |

---

## 🏗️ Project Structure

```
BMS/
├── main.cpp                  # Program entry point — main menu routing
├── headers/
│   ├── structs.h             # Data structures (Customer, Transaction)
│   ├── globals.h             # Global constants & configuration
│   ├── utils.h               # UI utilities, validation, formatting
│   ├── filehandling.h        # File I/O & search operations
│   ├── admin.h               # Admin module declarations
│   ├── customer.h            # Customer module declarations
│   └── atm.h                 # ATM module declarations
├── modules/
│   ├── utils.cpp             # UI rendering, input masking, animations
│   ├── filehandling.cpp      # Persistent storage engine (pipe-delimited flat files)
│   ├── admin.cpp             # Admin portal — full CRUD & banking ops
│   ├── customer.cpp          # Customer self-service — registration, login, transactions
│   └── atm.cpp               # ATM simulation — PIN auth, fast cash, mini statement
├── Documentation-MD.md       # Comprehensive technical documentation (Markdown)
├── Documentation-pdf.pdf     # Comprehensive technical documentation (PDF)
└── README.md                 # You are here
```

---

## 🧱 System Architecture

```
┌─────────────────────────────────────────────────┐
│                 PRESENTATION LAYER               │
│    Main Menu  │  Admin UI  │ Customer UI │  ATM  │
├─────────────────────────────────────────────────┤
│               BUSINESS LOGIC LAYER               │
│   admin.cpp  │  customer.cpp  │  atm.cpp         │
├─────────────────────────────────────────────────┤
│             DATA PERSISTENCE LAYER               │
│   filehandling.cpp  →  customers.txt             │
│                     →  transactions.txt          │
├─────────────────────────────────────────────────┤
│                UTILITIES LAYER                   │
│   utils.cpp  (Colors, Masking, Validation, UI)   │
└─────────────────────────────────────────────────┘
```

---

## ⚙️ Prerequisites

- **OS:** Windows 7 / 8 / 10 / 11
- **Compiler:** [MinGW GCC](https://www.mingw-w64.org/) (g++ with C++11 or later)
- **Windows Headers:** `<windows.h>`, `<conio.h>` (included with MinGW)

---

## 🚀 Build & Run

**Compile:**
```bash
g++ -o bms.exe main.cpp modules/utils.cpp modules/filehandling.cpp modules/admin.cpp modules/customer.cpp modules/atm.cpp
```

**Run:**
```bash
./bms.exe
```

> [!TIP]
> For development builds with warnings enabled:
> ```bash
> g++ -Wall -Wextra -o bms.exe main.cpp modules/utils.cpp modules/filehandling.cpp modules/admin.cpp modules/customer.cpp modules/atm.cpp
> ```

---

## 💾 Data Storage

The system uses **pipe-delimited flat files** for persistent storage:

**`customers.txt`**
```
accNo|name|cnic|phone|address|password|pin|balance|accountType|isLocked
```

**`transactions.txt`**
```
txnID|accNo|type|amount|dateTime
```

Transaction types: `Deposit`, `Withdrawal`, `Transfer-Out`, `Transfer-In`, `ATM-Withdrawal`, `ATM-FastCash`, `Zakat-Deduction`

---

## 🔒 Security Features

- **Masked Input** — Passwords and PINs are hidden with `*` during entry
- **Password Complexity** — Minimum 8 characters with uppercase, lowercase, digit, and special character
- **Login Attempt Limits** — 3 failed attempts trigger automatic account lockout
- **Account Lock/Unlock** — Admin-controlled account freezing
- **Input Sanitization** — Stream error handling prevents invalid input crashes

---

## 🕌 Zakat Auto-Deduction

The system implements an Islamic banking feature:
- **Nisab Threshold:** PKR 3,000,000
- **Zakat Rate:** 2.5%
- **Trigger:** Automatically evaluated during balance inquiry (Customer & ATM)
- **Tracking:** One-time deduction per account, verified against transaction history

---

## 📖 Documentation

This project includes comprehensive technical documentation covering system architecture, module breakdowns, data structures, flowcharts, function references, security design, UI specifications, and a complete testing plan.

- 📄 [**Markdown Version**](Documentation-MD.md) — Best for viewing directly on GitHub
- 📕 [**PDF Version**](Documentation-pdf.pdf) — Best for downloading and printing

---

## 🛠️ Tech Stack

| Component | Technology |
|---|---|
| Language | C++ (Procedural) |
| Compiler | MinGW GCC |
| Platform | Windows Console |
| Storage | Pipe-delimited text files |
| UI | Windows Console API (colors, cursor control) |
| Input Masking | `<conio.h>` (`getch()`) |

---

## ⚠️ Known Limitations

- **Windows-only** — Uses `<windows.h>` and `<conio.h>` APIs
- **Flat file storage** — No database engine; not suitable for production use
- **Plaintext passwords** — Stored without hashing or encryption
- **Static arrays** — Fixed-size arrays (`MAX_CUSTOMERS = 100`, `MAX_TRANSACTIONS = 1000`)
- **Single admin account** — Hardcoded credentials

---

## 📝 License

This project was developed as an academic semester project for **Programming Fundamentals (PF)**. Feel free to use it as a reference for learning purposes.

---

<p align="center">
  <strong>Built with ❤️ in C++</strong>
</p>
