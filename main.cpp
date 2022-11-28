#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include "set_of_numbers.h"
//#include "set_of_numbers.cpp"
using namespace std;

int main()
{
    //SetConsoleCP( 1251 );
    //SetConsoleOutputCP( 1251 );
    while ( true )
    {

        bool flag_1 = 1;
        bool flag_2 = 1;
        set_of_numbers set_1( 0 );
        set_of_numbers set_2( 0 );

        while ( true )
        {
            try
            {

                cout << "Start" << endl << "Enter the first set size: " << endl;
                double size_1;
                while( !( cin >> size_1 ) || ( cin.peek() != '\n' ) )
                {

                    cin.clear();
                    while ( cin.get() != '\n' );
                    throw "Text was entered";

                }
                if ( double( int( size_1 ) ) != size_1 ) throw "wrong size ";
                set_of_numbers set_3( size_1 );
                set_1 = set_3;
                cout << "Enter the first set size: " << endl;
                double size_2;
                while( !( cin >> size_2 ) || ( cin.peek() != '\n' ) )
                {

                    cin.clear();
                    while ( cin.get() != '\n' );
                    throw "Text was entered";

                }
                if ( double( int( size_2 ) ) != size_2 ) throw "wrong size ";
                set_of_numbers set_4( size_2 );
                set_2 = set_4;
                break;

            }
            catch ( const char* e )
            {

                cout << e << endl;

            }
            catch ( ... )
            {

                cout << "Something went wrong" << endl;

            }
        }

        cout << endl << "First set: " << endl << set_1 << endl << "Second set: " << endl << set_2 << endl;


        double choice;

        while ( true )
        {

             while ( true )
            {

                cout << endl << "1 - get the value by index"/**/ << endl << "2 - print the sets" << endl << "3 - unite sets" << endl
                << "4 - subtract a set"/**/ << endl << "5 - add a number into a set"/**/ << endl << "6 - delete a number from a set"/**/ << endl
                << "7 - get intersection" << endl << "8 - check presense of a number into a set"/**/ << endl
                << "9 - check occurence of elements"/**/ << endl << "10 - stop" << endl << "11 - start again" << endl;
                while( !( cin >> choice ) || ( cin.peek() != '\n' ) )
                {

                    cin.clear();
                    while ( cin.get() != '\n' );
                    cout << "Text was entered";
                    continue;

                }
                if ( choice > 0 && choice < 12 && double( int( choice ) ) == choice )  break; 
                else
                {

                    cout << "Unknown choice, try again" << endl;
                    continue;

                }

            }

            while ( true )
            {

                double number_of_set;
                if ( choice == 1 || choice == 4 || choice == 5 || choice == 6 || choice == 8 || choice == 9 )
                {

                    while ( true )//Âûáîð ìíîæåñòâà äëÿ äåéñòâèÿ
                    {

                        try
                        {

                            cout << "choice a set - 1 or 2: " << endl;
                            while( !( cin >> number_of_set ) || ( cin.peek() != '\n' ) )
                            {

                                cin.clear();
                                while ( cin.get() != '\n' );
                                throw "Text was entered";

                            } 
                            if ( ( number_of_set == 1 || number_of_set == 2 ) && double( int( number_of_set ) ) == number_of_set ) break;
                            else throw "Non-existent set was choosen";

                        }
                        catch ( const char * e )
                        {

                            cout << e << endl;

                        }
                        catch ( ... )
                        {

                            cout << "Something went wrong" << endl;

                        }

                    }

                    if ( choice == 1 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double index;
                                    cout << "Enter index: " << endl;
                                    while( !( cin >> index ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( index ) ) != index ) throw "Not correct index";
                                    cout << "An element of the first set with index " << index << " - " << set_1[index - 1] << endl;
                                    break;

                                }
                                else
                                {

                                    double index;
                                    cout << "Enter index: " << endl;
                                    while( !( cin >> index ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( index ) ) != index ) throw "Not correct index";
                                    cout << "An element of the second set with index " << index << " - " << set_2[index - 1] << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 4 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    set_of_numbers set_3 = set_1 - set_2;
                                    cout << "Set " << set_1 << " minus set " << set_2 << " : " << endl << set_3 << endl;
                                    break;

                                }
                                else
                                {

                                    set_of_numbers set_3 = set_2 - set_1;
                                    cout << "Set " << set_2 << " minus set " << set_1 << " : " << endl << set_3 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;
                                break;

                            }
                            catch( ... )
                            {

                                cout << "Something went wrong" << endl;
                                break;

                            }

                        }
                        break;

                    }

                    if ( choice == 5 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    set_1 += value;
                                    cout << "Changed set:" << endl << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    set_2 += value;
                                    cout << "Changed set:" << endl << set_2 << endl;
                                    break;

                                    }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 6 )
                        {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    set_1 -= value;
                                    cout << "Changed set:" << endl << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    set_2 -= value;
                                    cout << "Changed set" << endl << set_2 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 8 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    if ( set_1.presence( value ) == -1 ) cout << "The set doesn't have such a value" << endl;
                                    else cout << "The set has such a value" << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Enter integer: " << endl;
                                    while( !( cin >> value ) || ( cin.peek() != '\n' ) )
                                    {

                                        cin.clear();
                                        while ( cin.get() != '\n' );
                                        throw "Text was entered";

                                    } 
                                    if ( double( int( value ) ) != value ) throw "Not integer was entered";
                                    if ( set_2.presence( value ) == -1 ) cout << "The set doesn't have such a value" << endl;
                                    else cout << "The set has such a value" << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 9 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                        
                                    if ( set_1.occurrence_of_elements( set_2 ) == true ) cout << "Set " << set_2 << " contains all the elements of set " << set_1 << endl;
                                    else cout << "Set " << set_2 << " doesn't contain all the elements of set " << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    if ( set_2.occurrence_of_elements( set_1 ) == true ) cout << "Set " << set_1 << " contains all the elements of set " << set_2 << endl;
                                    else cout << "Set " << set_1 << " doesn't contain all the elements of set " << set_2 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;
                                break;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;
                                break;

                            }

                        }
                        break;

                    }//+++

                }

                else
                {

                    if ( choice == 2 )
                    {

                        cout << "First set:" << endl << set_1 << endl << "Second set:" << endl << set_2 << endl;
                        break;

                    }

                    if ( choice == 7 )
                    {

                        cout << "The intersection of  sets" << endl << set_1 << endl << "and" << endl << set_2 << endl << "The result: ";
                        set_of_numbers set_3 = set_1.intersection( set_2 );
                        cout << set_3;
                        break;

                    }

                    if ( choice == 3 )
                    {

                        cout << "THe union of sets" << endl << set_1 << endl << "and" << endl << set_2 << endl << "The result: ";
                        set_of_numbers set_3 = set_1 + set_2;
                        cout << set_3;
                        break;

                    }

                    if ( choice == 10 )
                    {

                        flag_1 = 0; break;

                    }

                    if ( choice == 11 ) 
                    {

                        flag_2 = 0; break;

                    }

                }

                }

            if ( flag_1 == 0 || flag_2 == 0 ) break;

            }

        if ( flag_1 == 0 ) break;

    }

    return 0;

}
