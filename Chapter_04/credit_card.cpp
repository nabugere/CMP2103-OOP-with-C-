#include <iostream>
using namespace std;

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

bool isValid(long long number)
{
    if (number <= 0)
        return false;

    int size = getSize(number);
    if (size < 13 || size > 16)
        return false;

    if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) && !prefixMatched(number, 6))
        return false;

    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return total % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    int position = 0;
    long long n = number;

    while (n > 0)
    {
        int digit = n % 10;

        if (position % 2 == 1)
        {
            sum += getDigit(digit * 2);
        }

        n /= 10;
        position++;
    }

    return sum;
}

int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

int sumOfOddPlace(long long number)
{
    int sum = 0;
    int position = 0;
    long long n = number;

    while (n > 0)
    {
        if (position % 2 == 0)
        {
            sum += n % 10;
        }

        n /= 10;
        position++;
    }

    return sum;
}

bool prefixMatched(long long number, int d)
{
    int dSize = getSize(d);
    return getPrefix(number, dSize) == d;
}

int getSize(long long d)
{
    if (d == 0)
        return 1;

    int count = 0;
    while (d > 0)
    {
        d /= 10;
        count++;
    }

    return count;
}

long long getPrefix(long long number, int k)
{
    if (k <= 0)
        return 0;

    int size = getSize(number);
    if (size <= k)
        return number;

    long long divisor = 1;
    for (int i = 0; i < size - k; i++)
    {
        divisor *= 10;
    }

    return number / divisor;
}

int main()
{
    long long number;

    cout << "Enter a credit card number as an integer: ";
    cin >> number;

    if (isValid(number))
        cout << "The card number is valid." << endl;
    else
        cout << "The card number is invalid." << endl;

    return 0;
}
