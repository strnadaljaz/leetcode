#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size()-1;
    int carry;

    do {
        carry = (digits[i] + 1) / 10;
        digits[i] = (digits[i] + 1) % 10;
        --i;
    } while(carry != 0 && i >= 0); 

    if (carry != 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main()
{
    cout << "Hello world";
    
    return 0;
}