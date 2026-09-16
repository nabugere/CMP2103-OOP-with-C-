# credit_card.cpp

Checks if a credit card number is valid, using the Luhn algorithm. It asks
the user for a number and prints whether it's valid.

## How it works

A card number is valid if all of these are true:

1. It has 13 to 16 digits (`getSize`).
2. It starts with a known issuer prefix (`prefixMatched`): Visa (4), MasterCard (5), American Express (37), or Discover (6).
3. The Luhn checksum works out: double every second digit counting from the right, add the digits together if doubling gives a two-digit number, add the rest of the digits as they are, and the total must divide evenly by 10.

## Functions

| Function | Purpose |
|---|---|
| `isValid(number)` | Runs all three checks and returns the result. |
| `getSize(d)` | Counts the digits in a number. |
| `prefixMatched(number, d)` | Checks if `number` starts with the digits of `d`. |
| `getPrefix(number, k)` | Returns the first `k` digits of `number`. |
| `sumOfDoubleEvenPlace(number)` | Adds up the doubled digits (every second digit from the right). |
| `sumOfOddPlace(number)` | Adds up the digits that aren't doubled. |
| `getDigit(number)` | Turns a two-digit number into the sum of its digits (e.g. `16 -> 1 + 6 = 7`). |

## Example

```
Enter a credit card number as an integer: 4408041234567893
The card number is valid.
```

## Notes

Input is read as `long long`, so a number starting with 0 would lose that digit. This isn't handled in the code.

The naming is a bit confusing: position 0 is the rightmost digit, so "even place" in `sumOfDoubleEvenPlace` actually means the 2nd, 4th, 6th... digits from the right, which is what the Luhn algorithm asks for.
