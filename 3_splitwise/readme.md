Requirements:
- User: Each user should have a userId, name, email, and mobile number.
- Expense: Can be of type EQUAL, EXACT, or PERCENT.
- Users can add any amount, choose any type of expense, and split it with any of the available users.
- The percentage and amount provided can have decimals up to two decimal places.
- For PERCENT type, ensure the total sum of percentage shares equals 100.
- For EXACT type, ensure the total sum of shares equals the total amount.
- The application should be able to display expenses for a single user and balances for all users.
- When displaying balances, show the balances of a user with all other users where there is a non-zero balance.
- Amounts should be rounded to two decimal places. For example, if User1 paid 100 and the amount is split equally among 3 people, assign 33.34 to the first person and 33.33 to the others.





#Tests

1. Initial Balance Check (No Expenses Added)
cpp
Copy
Edit
SHOW
Expected Output:

yaml
Copy
Edit
No balances
2. Equal Split (One Person Pays for All)
cpp
Copy
Edit
EXPENSE u1 1000 4 u1 u2 u3 u4 EQUAL
SHOW
SHOW u1
SHOW u4
Expected Output:

yaml
Copy
Edit
u2 owes u1: 250
u3 owes u1: 250
u4 owes u1: 250
For SHOW u1:

yaml
Copy
Edit
u2 owes u1: 250
u3 owes u1: 250
u4 owes u1: 250
For SHOW u4:

yaml
Copy
Edit
u4 owes u1: 250
3. Exact Split (Different Amounts for Different People)
cpp
Copy
Edit
EXPENSE u1 1250 2 u2 u3 EXACT 370 880
SHOW
SHOW u1
Expected Output:

yaml
Copy
Edit
u2 owes u1: 620
u3 owes u1: 1130
u4 owes u1: 250
4. Percent Split (Based on Custom Percentages)
cpp
Copy
Edit
EXPENSE u4 1200 4 u1 u2 u3 u4 PERCENT 40 20 20 20
SHOW
SHOW u1
SHOW u4
Expected Output:

yaml
Copy
Edit
u1 owes u4: 230
u2 owes u1: 620
u2 owes u4: 240
u3 owes u1: 1130
u3 owes u4: 240
For SHOW u1:

yaml
Copy
Edit
u1 owes u4: 230
u2 owes u1: 620
u3 owes u1: 1130
For SHOW u4:

yaml
Copy
Edit
u1 owes u4: 230
u2 owes u4: 240
u3 owes u4: 240
5. Another Equal Split After Some Balances Exist
cpp
Copy
Edit
EXPENSE u2 600 3 u1 u2 u3 EQUAL
SHOW
SHOW u2
Expected Output:

yaml
Copy
Edit
u1 owes u2: 200
u3 owes u2: 200
u1 owes u4: 230
u2 owes u1: 420
u2 owes u4: 240
u3 owes u1: 1130
u3 owes u4: 240
For SHOW u2:

yaml
Copy
Edit
u1 owes u2: 200
u3 owes u2: 200
u2 owes u1: 420
u2 owes u4: 240
6. Edge Case: Checking Balance for a User With No Debts
cpp
Copy
Edit
SHOW u5
Expected Output:

yaml
Copy
Edit
No balances
7. Large Transactions With Different Expense Types
cpp
Copy
Edit
EXPENSE u3 2000 4 u1 u2 u3 u4 EXACT 500 500 500 500
SHOW
Expected Output:

yaml
Copy
Edit
u1 owes u3: 500
u2 owes u3: 500
u4 owes u3: 500
8. Edge Case: Incorrect Percentage Total
cpp
Copy
Edit
EXPENSE u1 500 3 u2 u3 u4 PERCENT 30 30 30
Expected Output:

bash
Copy
Edit
Error: Percentage split does not sum to 100.
9. Edge Case: Incorrect Exact Sum
cpp
Copy
Edit
EXPENSE u2 600 3 u1 u3 u4 EXACT 100 100 300
Expected Output:

bash
Copy
Edit
Error: Exact split amounts do not sum to total expense.
Final Test: Show Final Balances
cpp
Copy
Edit
SHOW