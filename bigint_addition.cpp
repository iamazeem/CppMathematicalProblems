// ----------------------------- 
// MathUtils::BigInt -> Addition
// Addition of Two Large Numbers
// -----------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>

namespace MathUtils {

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::size_t;

class BigInt
{
public:
    explicit BigInt( void )
    {
        cout << "-------------------------------\n"
             << " Addition of Two Large Numbers \n"
             << "-------------------------------\n" << endl;
    }

    void getInput( void )
    {
        cout << "Enter 1st number: " << endl;
        cin  >> _num1;
        cout << "Enter 2nd number: " << endl;
        cin  >> _num2;
        cout << "------------------------------" << endl;
    }

    const bool isValidInput( void )
    {
        if ( !isValidNumber( _num1 ) )
        {
            cerr << "ERROR: " << _num1 << " is invalid!" << endl;
            return false;
        }

        if ( !isValidNumber( _num2 ) )
        {
            cerr << "ERROR: " << _num2 << " is invalid!" << endl;
            return false;
        }

        return true;
    }

    void printSum( void )
    {
        const size_t maxLen = std::max( _num1.length(), _num2.length() );

        /* Reverse both numbers for addition of individual digits */
        std::reverse( _num1.begin(), _num1.end() );
        std::reverse( _num2.begin(), _num2.end() );

        string sum = "";
        unsigned carry = 0;

        /* Calculate sum for large numbers */
        for ( size_t i = 0; i < maxLen; ++i )
        {
            const unsigned digit1 = ( i < _num1.length() ) ? ( _num1[i] - '0' ) : 0;
            const unsigned digit2 = ( i < _num2.length() ) ? ( _num2[i] - '0' ) : 0;
            const unsigned dgtSum = digit1 + digit2 + carry;

            carry = ( dgtSum > 9 ) ? 1 : 0;
            sum += ( '0' + dgtSum % 10 );
        }

        if ( carry ) { sum += '1'; }

        std::reverse( sum.begin(), sum.end() );
        cout << "Sum: " << sum << endl;
    }

private:
    bool isValidNumber( const string& num )
    {
        for ( size_t i = 0; i < _num1.length(); ++i )
        {
            if ( !isdigit( _num1[i] ) ) { return false; }
        }

        return true;
    }

    /* Data Members */

    string    _num1;
    string    _num2;
};

} /* MathUtils */


int main( void )
{
    using MathUtils::BigInt;

    BigInt bigIntAddition;

    bigIntAddition.getInput();
    if ( bigIntAddition.isValidInput() )
    {
        bigIntAddition.printSum();
    }

    return EXIT_SUCCESS;
}
