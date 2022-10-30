#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

class set_of_numbers
{
    private:
        int size;
        int count;
        int *array;

    public:
        int presence( const int &number ) const
        {

            for ( int i = 0; i < this->count; i++ )
            {
                if ( this->array[i] == number )
                    return i;
            }
            return -1;

        } // Проверка наличия

        int & operator [] ( const int &index ) const
        {

            if ( index > count - 1 || index < 0 )
                throw "Неверный индекс\n";
            return array[index];

        } // Обращение по индексу

        set_of_numbers( int size = 0 )
        {
            size = size;
            count = 0;
            array = new int[size];
            for ( int i = 0; i < size; i++ )
            {
                while (1)
                {

                    int number;
                    cout << "Введите целое число: ";
                    cin >> number;
                    if ( this->presence( number ) != 1 )
                    {
                        cout << "Число" << number << "не уникальное" << endl;
                        continue;
                    }
                    else
                    {
                        array[i] = number;
                        count++;
                        break;
                    }
                }
            }
        } // Конструктор

        set_of_numbers( const set_of_numbers &other_set )
        {

            this->size = other_set.size;
            this->count = other_set.count;
            this->array = new int[this->size];
            for ( int i = 0; i < other_set.count; i++ )
            {
                this->array[i] = other_set.array[i];
            }

        } // Конструктор копирования

        void add( const int &number )
        {

            if ( this->presence(number) != -1 )
                throw "Введенное число не уникальное\n";
            if ( this->count == this->size )
            {
                int *old_arr = new int[this->size];
                for ( int k = 0; k < this->count; k++ )
                {
                    old_arr[k] = this->array[k];
                }
                this->array = new int[this->size + 10];
                for ( int k = 0; k < this->count; k++ )
                {
                    this->array[k] = old_arr[k];
                }
                this->size += 10;
                delete[] old_arr;
                this->array[count++] = number;
            }
            else
                this->array[count++] = number;

        } // Добавление числа в массив

        void delete_( const int &number )
        {

            int value = this->presence( number );
            if ( value != -1 )
            {

                int *old_arr = new int[this->size];
                for ( int k = 0; k < this->size; k++ )
                {
                    old_arr[k] = this->array[k];
                }
                this->array = new int[--this->size];
                for ( int k = 0; k < value; k++ )
                {
                    this->array[k] = old_arr[k];
                }
                for ( int k = value + 1; k < this->size; k++ )
                {
                    this->array[k] = old_arr[k];
                }
                delete[] old_arr;
                this->count--;
            }
            else
                throw "Такого числа нет\n";

        } // Удаление числа из массива

        void print() const
        {
            for ( int i = 0; i < count; i++ )
            {
                cout << array[i] << endl;
            }
        }

        set_of_numbers &operator + ( const set_of_numbers &set_1 )
        {

            set_of_numbers new_set( 0 );
            new_set.size = this->count + set_1.count;
            new_set.array = new int[new_set.size];
            for ( int i = 0; i < this->count; i++ )
            {
                new_set.array[i] = this->array[i];
                new_set.count++;
            }
            for ( int i = 0; i < set_1.count; i++ )
            {
                if ( ( this->presence( set_1.array[i] ) ) == -1 )
                {
                    new_set.array[new_set.count++] = set_1.array[i];
                }
            }
            return new_set;

        } // Сложение двух массивов

        set_of_numbers & operator - ( const set_of_numbers &set_1 )
        {
            set_of_numbers new_set( 0 );
            new_set = *this;
            for ( int i = 0; i < set_1.count; i++ )
            {
                try
                {

                    new_set.delete_( set_1.array[i] );

                }
                catch ( const char *e )
                {

                    continue;
                }
                catch ( ... )
                {

                    throw "Something went wrong\n";

                }
            }
            return new_set;
        } // Вычитание двух массивов

        void operator + ( const int &number )
        {

            try
            {
                this->add( number );
            }
            catch ( const char *e )
            {
                throw "Такое число уже есть\n";
            }
            catch ( ... )
            {

                throw "Something went wrong\n";
            }

        } // Прибавить число в массив

        void operator += ( const int &number )
        {
            try
            {
                this->add( number );
            }
            catch ( const char *e )
            {
                throw "Такое число уже есть\n";
            }
            catch ( ... )
            {
                throw "Something went wrong\n";
            }
        } // Прибавить число в массив

        void operator - ( const int &number )
        {

            try
            {
                this->delete_( number );
            }
            catch ( const char *e )
            {
                throw e;
            }
            catch ( ... )
            {
                throw "Something went wrong";
            }

        } // Удалить число из массива

        void operator -= ( const int &number )
        {
            try
            {
                this->delete_( number );
            }
            catch ( const char *e )
            {
                throw e;
            }
            catch ( ... )
            {
                throw "Something went wrong";
            }
        } // Удалить число из массива


        set_of_numbers &intersection( const set_of_numbers &set_2 ) const
        {

            set_of_numbers new_arr( 0 );
            for ( int i = 0; i < this->count; i++ )
            {

                if ( set_2.presence( this->array[i] ) == -1 )
                    new_arr += this->array[i];

            }

            return new_arr;
        } // Пересечение

        bool operator == ( const set_of_numbers &set_2 ) const
        {

            if( this->count != set_2.count ) return false;
            for( int i = 0; i < this->count; i++ )
            {
                if( this->array[i] != set_2.array[i] ) return false;
            }
            return true;

        }

        bool occurrence_of_elements( const set_of_numbers &set_2 ) const
        {
            if( ( this->intersection( set_2 ) ) == *this ) return true;
            return false;
        };

};

int main()
{
    setlocale( LC_ALL, "Russian" );
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
    printf("Start\n Введите размерность масива: \n");
    int size_1;
    scanf("%d", &size_1);
    Set_of_numbers arr1(size_1);
    printf("%d", arr1[3]);
    return 0;
}