# Design Order Management System for E-commerce

The system should implement four main functions:

1. `addProduct(productId, quantity)`
2. `createOrder(orderId, list of product ids and their corresponding quantities)`
3. `confirmOrder(orderId)`
4. `getStock(productId)`

The task seemed straightforward, but the interviewer specified that inventory should be blocked when `createOrder` is called and stock should be reduced when `confirmOrder` is called. Initially, I was a bit confused and only partially understood the requirement. The interviewer left the call and was replaced by HR for proctoring, mentioning they would return before the interview concluded.

I implemented the solution correctly, but for inventory locking, I initially created a `cancelOrder` function. This function would reduce inventory at order creation and refill it if the order was canceled. The interviewer was not satisfied with this approach. After some thought, I proposed using two variables: one for the fully available product count and another for the product count that is in an order but not yet confirmed. I discussed this approach and the necessary changes with the interviewer, who was pleased with it. However, time ran out, and I was unable to make any changes or run test cases. The feedback was positive regarding my overall low-level design (LLD), but I was advised to improve on clarifying requirements and managing time effectively.

## Plan of Action

- **Product**: id, stock level
- **Inventory**: manages stock, blocks inventory on creating order, reduces stock on confirmation
- **Order**: represents order id, list of product-quantity pairs, status
- **Order Manager**: manages orders

done