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