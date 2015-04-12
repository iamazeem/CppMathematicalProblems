// Perfect Number Test
// Written by: AZEEM

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isPerfect( unsigned long long number );
bool isPrime( unsigned long long number );

int main()
{
    const unsigned long long pNums[] =
    {
        45, 66, 28, 21324123, 54564754, 8589869056, 43241234324, 33550336
    };
    const unsigned pNumsSize = sizeof( pNums ) / sizeof( pNums[0] );

    for( unsigned i = 0; i < pNumsSize; ++i )
    {
        cout << setw(20) << pNums[i] << " is: ";
        cout << ( isPerfect( pNums[i] ) ? "Perfect" : "Not Perfect" ) << endl;
    }

    return 0;
}

bool isPerfect( unsigned long long number )
{
    if( number & 1 ) return false;

    unsigned long long num = 0L, n = 0L, m = 0L;
    for( register unsigned i = 2; num <= number; (i == 2 ? ++i : i += 2) )
    {
        n = (1 << i) - 1;
        if( isPrime(i) && isPrime(n) )
        {
            m = 1 << (i-1);
            num = n * m;
            if( num == number ) return true;
        }
    }
    return false;
}

bool isPrime( unsigned long long number )
{
    for( register unsigned i = 2; i <= sqrt(number); ++i )
    {
        if( number % i == 0 ) return false;
    }
    return true;
}
