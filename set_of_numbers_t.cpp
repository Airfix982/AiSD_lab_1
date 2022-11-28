#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include "set_of_numbers.h"
using namespace std;

template<typename T>
set_of_numbers<T>::~set_of_numbers()
{

    delete[] array;

}

template<typename T>
int set_of_numbers<T>::presence( const T& number ) const
{

    for ( int i = 0; i < this->count; i++ )
    {

        if ( this->array[i] == number )
            return i;

    }
    return -1;

}

template<typename T>
T& set_of_numbers<T>::operator [] ( const int& index ) const
{

    if ( index > count - 1 || index < 0 ) throw "Not correct index\n";
    return array[index];

}

template<typename T>
set_of_numbers<T>::set_of_numbers( int size )
{

    this->size = size;
    count = 0;
    array = new T[size];

}

template<typename T>
set_of_numbers<T>::set_of_numbers( const set_of_numbers<T>& other_set )
{

    this->size = other_set.size;
    this->count = other_set.count;
    this->array = new T[this->size];
    for ( int i = 0; i < this->count; i++ )
    {

        this->array[i] = other_set.array[i];

    }

}

template<typename T>
void set_of_numbers<T>::operator = ( const set_of_numbers<T>& other_set )
{

    this->size = other_set.size;
    this->count = other_set.count;
    this->array = new T[this->size];
    for ( int i = 0; i < other_set.count; i++ )
    {

        this->array[i] = other_set.array[i];

    }

}

template<typename T>
void set_of_numbers<T>::add( const T& number )
{

    if ( this->presence( number ) != -1 ) throw "The value isn't unic\n";
    if ( this->count == this->size )
    {

        T* old_arr = new T[this->size];
        for ( int k = 0; k < this->count; k++ )
        {

            old_arr[k] = this->array[k];

        }
        this->array = new T[this->size + 10];
        for ( int k = 0; k < this->count; k++ )
        {

            this->array[k] = old_arr[k];

        }
        this->size += 10;
        delete[] old_arr;
        this->array[count++] = number;

    }

    else this->array[count++] = number;

} 

template<typename T>
void set_of_numbers<T>::delete_( const T& number )
{

    int value = this->presence( number );
    if ( value != -1 )
    {

        T* old_arr = new T[this->size];
        for ( int k = 0; k < this->size; k++ )
        {

            old_arr[k] = this->array[k];

        }
        this->array = new T[--this->size];
        for ( int k = 0; k < value; k++ )
        {

            this->array[k] = old_arr[k];

        }
        for ( int k = value + 1; k < this->size + 1; k++ )
        {

            this->array[k - 1] = old_arr[k];

        }
        delete[] old_arr;
        this->count--;

    }
    else throw "The set doesn't contain such a number\n";

} 

template<typename T>
set_of_numbers<T> set_of_numbers<T>::operator + ( const set_of_numbers<T>& set_1 )
{

    set_of_numbers<T> new_set( 0 );
    new_set.size = this->count + set_1.count;
    new_set.array = new T[new_set.size];
    for ( int i = 0; i < this->count; i++ )
    {

        new_set.array[i] = this->array[i];
        new_set.count++;

    }
    for ( int i = 0; i < set_1.count; i++ )
    {

        if ( ( this->presence( set_1.array[i] ) ) == -1)
        {

            new_set.array[new_set.count++] = set_1.array[i];

        }

    }
    return new_set;

} 

template<typename T>
set_of_numbers<T> set_of_numbers<T>::operator - ( const set_of_numbers<T>& set_1 )
{

    set_of_numbers<T> new_set( 0 );
    new_set = *this;
    for ( int i = 0; i < set_1.count; i++ )
    {

        try
        {

            new_set.delete_( set_1.array[i] );

        }
        catch ( const char* e )
        {

            continue;

        }
        catch ( ... )
        {

            throw "Something went wrong\n";

        }

    }
    return new_set;

}

template<typename T>
void set_of_numbers<T>::operator + ( const T& number )
{

    try
    {

        this->add( number );

    }
    catch ( const char* e )
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

} 

template<typename T>
void set_of_numbers<T>::operator += ( const T& number )
{

    try
    {

        this->add( number );

    }
    catch (const char* e)
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

}

template<typename T>
void set_of_numbers<T>::operator - ( const T& number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char* e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

}

template<typename T>
void set_of_numbers<T>::operator -= ( const T& number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char* e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

}

template<typename T>
set_of_numbers<T> set_of_numbers<T>::intersection( const set_of_numbers<T>& set_2 ) const
{

    set_of_numbers<T> new_arr( 0 );
    for ( int i = 0; i < this->count; i++ )
    {

        if ( set_2.presence( this->array[i] ) != -1 ) new_arr += this->array[i];

    }
    return new_arr;

} 

template<typename T>
bool set_of_numbers<T>::operator == ( const set_of_numbers<T>& set_2 ) const
{

    if ( this->count != set_2.count ) return false;
    for ( int i = 0; i < this->count; i++ )
    {

        if ( this->array[i] != set_2.array[i] ) return false;

    }
    return true;

}

template<typename T>
bool set_of_numbers<T>::operator != ( const set_of_numbers<T>& set_2 ) const
{

    if ( this->count != set_2.count ) return true;
    for ( int i = 0; i < this->count; i++ )
    {

        if ( this->array[i] != set_2.array[i] ) return true;

    }
    return false;

}

template<typename T>
bool set_of_numbers<T>::occurrence_of_elements( const set_of_numbers<T>& set_2 ) const
{

    for ( int i = 0; i < this->count; i++ )
    {

        if ( set_2.presence( this->array[i] ) == -1 ) return false;

    }
    return true;

};

ostream& operator << ( ostream& os, const set_of_numbers<int>& set )
{

    for ( int i = 0; i < set.count; i++ )
    {

        os << set.array[i] << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<float>& set)
{

    for (int i = 0; i < set.count; i++)
    {

        os << set.array[i] << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<string>& set)
{

    for (int i = 0; i < set.count; i++)
    {

        os << set.array[i] << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<pair<int, double>>& set)
{

    for (int i = 0; i < set.count; i++)
    {

        os << "<" << set.array[i].first << ", " << set.array[i].second << ">" << " ";

    }
    return os;

}