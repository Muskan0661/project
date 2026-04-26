#include <stdio.h>

int main() {
    int studentID, batch, roll, tickets;
    float totalPrice, discount = 0.0;

    // Input student ID
    printf("Enter Student ID (XXYYYY): ");
    scanf("%d", &studentID);

    // Extract batch and roll number
    batch = studentID / 10000;  // First two digits
    roll = studentID % 10000;   // Last four digits

    // Validate batch number
    if (batch < 21 || batch > 24) {
        printf("Invalid Batch Number! Must be 21, 22, 23, or 24.\n");
        return 1;
    }

    // Validate roll number
    if (roll < 0 || roll > 9999) {
        printf("Invalid Roll Number! Must be 4 digits.\n");
        return 1;
    }

    // Input ticket count
    printf("Enter number of tickets to buy: ");
    scanf("%d", &tickets);

    // Assign price based on batch
    if (batch == 21)
        totalPrice = tickets * 1800;
    else if (batch == 22)
        totalPrice = tickets * 1700;
    else if (batch == 23)
        totalPrice = tickets * 1600;
    else
        totalPrice = tickets * 1500;

    // Apply discount if roll number ends with 10 or 20
    if (roll % 100 == 10) {
        discount = totalPrice * 0.10;
    } else if (roll % 100 == 20) {
        discount = totalPrice * 0.20;
    }

    // Apply bulk purchase condition (only if no lucky number discount is applied)
    if (tickets > 10 && discount == 0) {
        totalPrice -= (totalPrice / tickets);  // One ticket free
    }

    // Deduct discount if applicable
    totalPrice -= discount;

    // Print final amount
    printf("Total price after discount: PKR %.2f\n", totalPrice);

    return 0;
}