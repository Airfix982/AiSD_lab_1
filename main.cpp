#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include "set_of_numbers.h"
//#include "set_of_numbers.cpp"
using namespace std;

int main()
{
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
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

                cout << "Start" << endl << "Введите размерность первого масива: " << endl;
                double size_1;
                cin >> size_1;
                if ( double( int( size_1 ) ) != size_1 ) throw "Неверная размерность ";
                set_of_numbers set_3( size_1 );
                set_1 = set_3;
                cout << "Введите размерность второго масива: " << endl;
                int size_2;
                cin >> size_2;
                if ( double( int( size_2 ) ) != size_2 ) throw "Неверная размерность ";
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

        cout << endl << "Первое множество: " << endl;
        set_1.print();
        cout << "Второе множество: " << endl;
        set_2.print();
        cout << endl;


        double choice;

        while ( true )
        {

             while ( true )
            {

                cout << "1 - получить число по индексу"/**/ << endl << "2 - распечатать множества" << endl << "3 - объединить множества" << endl
                << "4 - вычесть множество"/**/ << endl << "5 - добавить число во множество"/**/ << endl << "6 - удалить число из множества"/**/ << endl
                << "7 - вычислить пересечение двух множеств" << endl << "8 - проверить наличие числа во множестве"/**/ << endl
                << "9 - проверить, что одно множество является подмножеством другого"/**/ << endl << "10 - закончить" << endl << "11 - начать заново" << endl;
                cin >> choice;
                if ( choice > 0 && choice < 12 && double( int( choice ) ) == choice )  break; 
                else
                {

                    cout << "Неизвестный выбор, попробуйте еще раз" << endl;
                    continue;

                }

            }

            while ( true )
            {

                double number_of_set;
                if ( choice == 1 || choice == 4 || choice == 5 || choice == 6 || choice == 8 || choice == 9 )
                {

                    while ( true )//Выбор множества для действия
                    {

                        try
                        {

                            cout << "Выберите множество - 1 или 2: " << endl;
                            cin >> number_of_set;
                            if ( ( number_of_set == 1 || number_of_set == 2 ) && double( int( number_of_set ) ) == number_of_set ) break;
                            else throw "Выбрано несуществующее множество";

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
                                    cout << "Введите индeкс: " << endl;
                                    cin >> index;
                                    if ( double( int( index ) ) != index ) throw "Неверный индекс";
                                    cout << "Элемент 1го множества с индексом " << index << " - " << set_1[index - 1] << endl;
                                    break;

                                }
                                else
                                {

                                    int index;
                                    cout << "Введите индeкс: " << endl;
                                    cin >> index;
                                    if ( double( int( index ) ) != index ) throw "Неверный индекс";
                                    cout << "Элемент 2го множества с индексом " << index << " - " << set_2[index - 1] << endl;
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
                                    cout << "Множество 1 минус множество 2:" << endl;
                                    set_3.print( );
                                    break;

                                }
                                else
                                {

                                    set_of_numbers set_3 = set_2 - set_1;
                                    cout << "Множество 2 минус множество 1:" << endl;
                                    set_3.print( );
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
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    set_1 += value;
                                    cout << "Измененное множество \n";
                                    set_1.print( );
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    set_2 += value;
                                    cout << "Измененное множество \n";
                                    set_2.print( );
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
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    set_1 -= value;
                                    cout << "Измененное множество \n";
                                    set_1.print( );
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    set_2 -= value;
                                    cout << "Измененное множество \n";
                                    set_2.print( );
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
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    if ( set_1.presence( value ) == -1 ) cout << "Taкого числа нет" << endl;
                                    else cout << "Taкое число есть" << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Введите целое число: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Введено нецелое число";
                                    if ( set_2.presence( value ) == -1 ) cout << "Taкого числа нет" << endl;
                                    else cout << "Taкое число есть" << endl;
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

                                        
                                    if ( set_1.occurrence_of_elements( set_2 ) == true ) cout << "Множество 2 содержит все элементы множества 1" << endl;
                                    else cout << "Множество 2 содержит не все элементы множества 1" << endl;
                                    break;

                                }
                                else
                                {

                                    if ( set_2.occurrence_of_elements( set_1 ) == true ) cout << "Множество 1 содержит все элементы множества 2" << endl;
                                    else cout << "Множество 1 содержит не все элементы множества 2" << endl;
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

                        cout << "Первое множество:" << endl;
                        set_1.print( );
                        cout << endl << "Второе множество:" << endl;;
                        set_2.print( );
                        cout << endl;
                        break;

                    }

                    if ( choice == 7 )
                    {

                        cout << "Пересечение множеств \n";
                        set_1.print( );
                        set_2.print( );
                        cout << "Результат: ";
                        set_of_numbers set_3 = set_1.intersection( set_2 );
                        set_3.print( );
                        break;

                    }

                    if ( choice == 3 )
                    {

                        cout << "Объединение множеств \n";
                        set_1.print( );
                        set_2.print( );
                        cout << "Результат: ";
                        set_of_numbers set_3 = set_1 + set_2;
                        set_3.print( );
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
