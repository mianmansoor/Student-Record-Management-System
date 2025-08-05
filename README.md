# 🎓 Student Record Management System

A C++ console-based Student Record Management System for managing student data, marks, and fee challans using a Binary Search Tree (BST).

## 📌 Features

- 🔐 **Login Authentication** (Default: `user` / `asd123`)
- ➕ **Add Student Record**
- 🔍 **Search Student by Enrollment**
- 🗑️ **Delete Student Record**
- 📋 **Display All Records**
- ✏️ **Modify Existing Record**
- 🧮 **Enter Student Marks & Calculate Result**
- 💰 **Generate Fee Challan**

## 🧠 Data Structure

- The system stores all student records in a **Binary Search Tree (BST)**, enabling fast insertion, search, and deletion based on the enrollment number.

## 📂 Structure

Each student record stores:
- Enrollment Number
- Name
- Address
- Phone Number
- CNIC
- Section
- Subject Marks: Maths, English, Science, Urdu
- Result: Total & Percentage
- Fee Details & Challan

## 🖥️ How to Run

1. **Compile the code:**

   ```bash
   g++ -o StudentRecordSystem main.cpp
````

2. **Run the executable:**

   ```bash
   ./StudentRecordSystem
   ```

3. **Login credentials (hardcoded):**

   * Username: `user`
   * Password: `asd123`

> 📝 Make sure your compiler supports C++11 or above.

## 🛠️ Functional Overview

| Option | Description                         |
| ------ | ----------------------------------- |
| 1      | Add a new student record            |
| 2      | Search student by enrollment number |
| 3      | Delete student record               |
| 4      | Display all student records         |
| 5      | Enter subject-wise marks            |
| 6      | Generate fee challan                |
| 7      | Modify an existing record           |
| 8      | Exit the program                    |

## 📷 Sample Output

```
------------ LEADER HIGH SCHOOL ------------
******* STUDENT RECORD MANAGEMENT SYSTEM ********
1. Add a Student Record
2. Search For Records/Results
3. Delete Node
...
Enter Your Choice: 2
Enter enrollment to search: 1234

Enrollment: 1234
Name: Ali Khan
Address: Lahore
Phone Number: 03001234567
CNIC: 35202-1234567-1
---------------------------------------------
----------------- Results ----------------
Maths: 85
English: 78
Science: 90
Urdu: 75
Total Marks: 328 /400
Percentage: 82%
```

## 📚 Concepts Used

* Binary Search Tree (BST)
* Recursion
* File I/O (if extended)
* Console-based UI
* Input validation
* String handling

## 🔧 Future Improvements

* 🔄 File saving/loading of records
* 🖼️ GUI integration using libraries like SFML or Qt
* 📊 Dynamic subject entry using maps or vectors
* 🧪 Unit testing and input sanitization
* 📑 Export results/challan to PDF or text file

---

## 🤝 Contributing

Feel free to fork and improve the project. Pull requests are welcome!

## 📝 License

This project is licensed under the MIT License.

```
