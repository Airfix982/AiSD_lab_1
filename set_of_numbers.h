#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <cmath>

class set_of_numbers
{

    private:

        int size;
        int count;
        int* array;

    public:

        int presence ( const int& number ) const;

        int & operator [] ( const int& index ) const;

        set_of_numbers ( int size = 0 );

        void operator = ( const set_of_numbers& other_set );

        void add ( const int & number );

        void delete_ ( const int& number );

        void print( ) const;

        set_of_numbers & operator + ( const set_of_numbers & set_1 );

        set_of_numbers & operator - ( const set_of_numbers & set_1 );

        void operator + ( const int & number );

        void operator += ( const int & number );

        void operator - ( const int & number );

        void operator -= ( const int & number );

        set_of_numbers & intersection ( const set_of_numbers & set_2 ) const;

        bool operator == ( const set_of_numbers & set_2 ) const;

        bool operator != ( const set_of_numbers & set_2 ) const;

        bool occurrence_of_elements( const set_of_numbers & set_2 ) const;

};