// Problem 1.cpp : Lambda expressions to sort a list of struct Product 
//                 based on price. Product has name and price

#include <iostream>
#include <string>
#include <algorithm>

struct Product
{
    std::string name;
    double price;
	char currency;
};

int main()
{
	// List of products with different currencies and prices
    Product products[] = { {"Laptop", 1399.99, '$'},
                           {"Tablet", 299.99, '£'},
                           {"Smartphone", 499.99, '€'},
						   {"Smartwatch", 249.99, '$'},
                           {"Headphones", 199.99, '€'} };

	// Lambda to convert prices to a common currency (EUR)
    auto toEur = [](double price, char currency) {
        switch (currency) {
        case '$': return price * 0.85; // USD to EUR
        case '£': return price * 1.15; // GBP to EUR
        case '€': return price;         // EUR to EUR
        default: return price;          // Unknown currency, no conversion
        }
        };

    // Sort products by price using a lambda expression
    std::sort(std::begin(products), std::end(products), [&](const Product& a, const Product& b) {
        return toEur(a.price, a.currency) < toEur(b.price, b.currency);
        });

    // Print sorted products
    for (const auto& product : products)
    {
        std::cout << product.name << ": " << toEur(product.price, product.currency) << " Euro\n";
    }
	return 0;
}