/**
    Calculates RANDOM_NUMBER, a pseudo-random number between the constant values of MAX_NUM and
    MIN_NUM (inclusive).

    It uses the rand() function to generate a pseudo-random number which is previously seeded by
    the srand() function. The seed must be a non-constant number, so we use the time() member
    function of the <ctime> library (which, when NULL is passed as the argument, determines the
    number of seconds passed since Jan 1, 1970).

    We then find a random number in desired range by computing rand()%(MAX_NUM-MIN_NUM+1)+MIN_NUM.
    The "x mod y" operator works by dividing x by y, but instead of returning the quotient, it
    returns the remainder. Therefore, the function would return a value between 0 and y-1
    (inclusive).

    The y-1 value can be represented algebraically using the MIN_NUM and MAX_NUM numbers. By
    finding the difference between the MIN_NUM and MAX_NUM numbers and adding 1, we obtain a value
    that, when plugged into x mod y, can produce a range of numbers equal to the length of the
    range of numbers between MIN_NUM and MAX_NUM (inclusive).

    However, the numbers this will return are shifts by -MIN_NUM, because the mod function by
    default returns values from 0 to y. Therefore, outside the mod function, we add MIN_NUM to the
    value of rand()%(MAX_NUM-MIN_NUM+1), which then shifts our range back to the desired values.
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    
    const int MIN_NUM = 0, MAX_NUM = 999;
    int random_number;

    srand(time(NULL));
    random_number = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

    cout << random_number << endl;

    return 0;
}
