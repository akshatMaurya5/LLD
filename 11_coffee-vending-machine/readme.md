## Classes, Interfaces, and Enumerations

- **Coffee Class**: Represents a coffee type with its name, price, and recipe (ingredients and their quantities).

- **Ingredient Class**: Represents an ingredient used in making coffee, with its name and quantity. It provides a synchronized method to update the quantity.

- **Payment Class**: Represents a payment made by a user, with the amount paid.

- **CoffeeMachine Class**: The main class that manages the coffee vending machine. It follows the Singleton pattern to ensure a single instance of the machine. It initializes the coffee menu and ingredients in its constructor and provides methods to display the menu, select a coffee, dispense coffee, and update ingredient quantities. The `hasEnoughIngredients` method checks if there are sufficient ingredients to make a selected coffee, while the `updateIngredients` method updates the ingredient quantities after dispensing a coffee.

- **CoffeeVendingMachine Class**: The entry point of the application that demonstrates the usage of the coffee vending machine. It creates an instance of the machine, displays the menu, and simulates concurrent user requests using an `ExecutorService`.