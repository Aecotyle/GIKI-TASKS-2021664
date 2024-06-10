#include <iostream>
using namespace std;
int main()
{
    float salePrice, purchasePrice, no_shares, service_charges, amount_invested;
    float loss, profit;
    //user input
    cout << "How many shares you sold: ";
    cin >> no_shares;
    cout << "What was sale price: $";
    cin >> salePrice;
    cout << "What was the purchasing price: $";
    cin >> purchasePrice;
    //service charges
    service_charges = (salePrice * no_shares) * (1.5 / 100);
    cout << "Your service charges: $" << service_charges << endl;
    //amount invested
    amount_invested = no_shares * purchasePrice;
    cout << "The amount invested: $" << amount_invested << endl;

    // profit and loss calculations
    loss = (no_shares * (purchasePrice - salePrice)) - service_charges;
    profit = (no_shares * (salePrice - purchasePrice)) - service_charges;

    //display amount of profit or loss
    if (purchasePrice * no_shares > (salePrice * no_shares - service_charges))
        cout << "The amount of loss: $" << loss << endl;
    else
        cout << "The amount of profit: $" << profit << endl;

    return 0;

    //reg no. 2021468
}