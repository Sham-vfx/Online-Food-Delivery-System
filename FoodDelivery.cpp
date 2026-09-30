#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

// ========================================
// FUNCTION: GET VALID NUMBER WITH RANGE
// ========================================
int getChoice(string prompt, int minimum, int maximum)
{
    int choice;

    while (true)
    {
        cout << prompt;
        cin >> choice;

        // If user enters letters or symbols
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number.\n";
        }
        else if (choice < minimum || choice > maximum)
        {
            cout << "Invalid choice. Please enter a number between "
                 << minimum << " and " << maximum << ".\n";
        }
        else
        {
            return choice;
        }
    }
}

// ========================================
// FUNCTION: GET VALID QUANTITY
// ========================================
int getQuantity()
{
    int quantity;

    while (true)
    {
        cout << "Enter quantity: ";
        cin >> quantity;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number.\n";
        }
        else if (quantity <= 0)
        {
            cout << "Quantity must be greater than 0.\n";
        }
        else
        {
            return quantity;
        }
    }
}

// ========================================
// FUNCTION: SELECT FOOD ITEM
// ========================================
void selectFood(int category, string &foodName, double &price)
{
    int item;

    switch (category)
    {
        // ================================
        // LOCAL FOOD
        // ================================
        case 1:
            cout << "\n--- Local Food Menu ---\n";
            cout << "1. Nasi Lemak       RM8.00\n";
            cout << "2. Fried Rice       RM10.00\n";
            cout << "3. Mee Goreng       RM9.00\n";

            item = getChoice("Enter item choice: ", 1, 3);

            switch (item)
            {
                case 1:
                    foodName = "Nasi Lemak";
                    price = 8.00;
                    break;

                case 2:
                    foodName = "Fried Rice";
                    price = 10.00;
                    break;

                case 3:
                    foodName = "Mee Goreng";
                    price = 9.00;
                    break;
            }

            break;

        // ================================
        // FAST FOOD
        // ================================
        case 2:
            cout << "\n--- Fast Food Menu ---\n";
            cout << "1. Chicken Burger   RM12.00\n";
            cout << "2. Fried Chicken    RM15.00\n";
            cout << "3. French Fries     RM7.00\n";

            item = getChoice("Enter item choice: ", 1, 3);

            switch (item)
            {
                case 1:
                    foodName = "Chicken Burger";
                    price = 12.00;
                    break;

                case 2:
                    foodName = "Fried Chicken";
                    price = 15.00;
                    break;

                case 3:
                    foodName = "French Fries";
                    price = 7.00;
                    break;
            }

            break;

        // ================================
        // WESTERN FOOD
        // ================================
        case 3:
            cout << "\n--- Western Food Menu ---\n";
            cout << "1. Chicken Chop     RM18.00\n";
            cout << "2. Spaghetti        RM16.00\n";
            cout << "3. Fish and Chips   RM20.00\n";

            item = getChoice("Enter item choice: ", 1, 3);

            switch (item)
            {
                case 1:
                    foodName = "Chicken Chop";
                    price = 18.00;
                    break;

                case 2:
                    foodName = "Spaghetti";
                    price = 16.00;
                    break;

                case 3:
                    foodName = "Fish and Chips";
                    price = 20.00;
                    break;
            }

            break;

        // ================================
        // DRINKS
        // ================================
        case 4:
            cout << "\n--- Drinks Menu ---\n";
            cout << "1. Iced Tea         RM4.00\n";
            cout << "2. Coffee           RM5.00\n";
            cout << "3. Mineral Water    RM2.00\n";

            item = getChoice("Enter item choice: ", 1, 3);

            switch (item)
            {
                case 1:
                    foodName = "Iced Tea";
                    price = 4.00;
                    break;

                case 2:
                    foodName = "Coffee";
                    price = 5.00;
                    break;

                case 3:
                    foodName = "Mineral Water";
                    price = 2.00;
                    break;
            }

            break;
    }
}

// ========================================
// MAIN PROGRAM
// ========================================
int main()
{
    const int MAX_ITEMS = 20;

    // Cart information
    string orderedFood[MAX_ITEMS];
    int orderedQuantity[MAX_ITEMS];
    double orderedPrice[MAX_ITEMS];
    double orderedTotal[MAX_ITEMS];

    int itemCount = 0;

    int category;
    int quantity;
    int addMore;

    int distanceChoice;
    int voucherChoice;
    int paymentChoice;

    double price;
    double subtotal = 0.00;
    double deliveryFee = 0.00;
    double discount = 0.00;
    double total = 0.00;

    string foodName;
    string paymentMethod;

    cout << fixed << setprecision(2);

    // ========================================
    // PROGRAM TITLE
    // ========================================
    cout << "========================================\n";
    cout << "      ONLINE FOOD DELIVERY SYSTEM\n";
    cout << "========================================\n";

    // ========================================
    // ORDERING LOOP
    // ========================================
    do
    {
        cout << "\nChoose Food Category:\n";
        cout << "1. Local Food\n";
        cout << "2. Fast Food\n";
        cout << "3. Western Food\n";
        cout << "4. Drinks\n";

        category = getChoice("Enter choice: ", 1, 4);

        // Reset variables for each new item
        foodName = "";
        price = 0.00;

        // Select food
        selectFood(category, foodName, price);

        cout << "\n";

        // Enter quantity
        quantity = getQuantity();

        // Store item in cart
        orderedFood[itemCount] = foodName;
        orderedQuantity[itemCount] = quantity;
        orderedPrice[itemCount] = price;
        orderedTotal[itemCount] = price * quantity;

        // Add to subtotal
        subtotal += orderedTotal[itemCount];

        itemCount++;

        cout << "\nItem added to cart successfully!\n";

        // ====================================
        // CHECK CART LIMIT
        // ====================================
        if (itemCount >= MAX_ITEMS)
        {
            cout << "\nMaximum number of items reached.\n";
            addMore = 2;
        }
        else
        {
            cout << "\nDo you want to add another item?\n";
            cout << "1. Yes\n";
            cout << "2. No\n";

            addMore = getChoice("Enter choice: ", 1, 2);
        }

    } while (addMore == 1);

    // ========================================
    // DELIVERY DISTANCE
    // ========================================
    cout << "\nChoose Delivery Distance:\n";
    cout << "1. Below 5 km       RM3.00\n";
    cout << "2. 5 - 10 km        RM5.00\n";
    cout << "3. Above 10 km      RM8.00\n";

    distanceChoice = getChoice("Enter choice: ", 1, 3);

    if (distanceChoice == 1)
    {
        deliveryFee = 3.00;
    }
    else if (distanceChoice == 2)
    {
        deliveryFee = 5.00;
    }
    else
    {
        deliveryFee = 8.00;
    }

    // ========================================
    // VOUCHER
    // ========================================
    cout << "\nDo you have a RM2 voucher?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";

    voucherChoice = getChoice("Enter choice: ", 1, 2);

    if (voucherChoice == 1)
    {
        discount = 2.00;
    }
    else
    {
        discount = 0.00;
    }

    // ========================================
    // PAYMENT METHOD
    // ========================================
    cout << "\nChoose Payment Method:\n";
    cout << "1. Cash\n";
    cout << "2. Credit/Debit Card\n";
    cout << "3. E-Wallet\n";

    paymentChoice = getChoice("Enter choice: ", 1, 3);

    switch (paymentChoice)
    {
        case 1:
            paymentMethod = "Cash";
            break;

        case 2:
            paymentMethod = "Credit/Debit Card";
            break;

        case 3:
            paymentMethod = "E-Wallet";
            break;
    }

    // ========================================
    // CALCULATE FINAL TOTAL
    // ========================================
    total = subtotal + deliveryFee - discount;

    if (total < 0)
    {
        total = 0;
    }

    // ========================================
    // ORDER SUMMARY
    // ========================================
    cout << "\n========================================\n";
    cout << "              ORDER SUMMARY\n";
    cout << "========================================\n";

    for (int i = 0; i < itemCount; i++)
    {
        cout << i + 1 << ". " << orderedFood[i] << "\n";

        cout << "   Unit Price : RM"
             << orderedPrice[i] << "\n";

        cout << "   Quantity   : "
             << orderedQuantity[i] << "\n";

        cout << "   Item Total : RM"
             << orderedTotal[i] << "\n";

        cout << "----------------------------------------\n";
    }

    cout << "Subtotal       : RM" << subtotal << "\n";
    cout << "Delivery Fee   : RM" << deliveryFee << "\n";
    cout << "Discount       : RM" << discount << "\n";
    cout << "Payment Method : " << paymentMethod << "\n";

    cout << "========================================\n";
    cout << "TOTAL          : RM" << total << "\n";
    cout << "========================================\n";

    cout << "\nOrder placed successfully!\n";
    cout << "Thank you for using our food delivery system!\n\n";

    // ========================================
    // KEEP WINDOW OPEN
    // ========================================
    system("pause");

    return 0;
}