#include <iostream>
#include <cstdlib>

#include "sptr.h"
#include "fecl.h"

#include "foobar.h"
#include "range.h"
#include "mem-area.h"
#include "iter.h"
#include "checker.h"
#include "str.h"

#include "lazy.h"



void assert( bool condition, const char * text )
{
    if( ! condition )
    {
	std::cerr << "assert failed for: " << text << std::endl;
	exit(1);
    }
}



void test_the_range()
{
    std::clog << "Testing the range::inclusive class... ";

    range::inclusive<int> the_range( 15, 26 );

    assert( the_range.in_bounds(20), "range::inclusive::in_bounds(), 1" );
    assert( the_range.in_bounds(15), "range::inclusive::in_bounds(), 2" );
    assert( the_range.in_bounds(26), "range::inclusive::in_bounds(), 3" );

    assert( ! the_range.in_bounds(27), "range::inclusive::in_bounds(), 4" );
    assert( ! the_range.in_bounds(14), "range::inclusive::in_bounds(), 5" );


    assert( the_range.start() == 15, "range::inclusive::start()" );
    assert( the_range.end()   == 26, "range::inclusive::start()" );

    std::clog << "ok\n";
}



void test_the_mem_area()
{
    std::clog << "Testing the range::mem_area class... ";

    int raw_int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int * raw_int_arr = & raw_int_array[0];

    range::mem_area<int> int_array( raw_int_arr, 10 );

    assert( int_array.first_el() == raw_int_array, "range::mem_area::first_el()" );
    assert( int_array.last_el()  == raw_int_array + 9, "range::mem_area::last_el()" );

    std::clog << "ok\n";
}



bool test_the_iter()
{
    std::clog << "Testing the range::iter class... ";

    int raw_int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    range::mem_area<int> int_array( raw_int_array, 10 );

    range::iter<int> iter( int_array );

    for( size_t i = 0; i < 10; ++i )
    {
	assert( iter.valid(), "range::iter::valid" );
	assert( *iter == i, "range::iter::operator*" );

	++iter;
    }

    ++iter;
    assert( ! iter.valid(), "range::iter::valid, 2" );

    std::clog << "ok\n";
}



void test_the_sptr()
{
    std::clog << "Testing the range::sptr class... ";

    const char * raw_str = "Raw str";

    range::sptr<char> ptr = range::i_guarantee_this_is_static( raw_str );

    const char * check = ptr;

    assert( raw_str == check, "range::sptr::operator const T *" );

    std::clog << "ok\n";
}



const char & first_char_o( const char * p )
{
    return *p;
}



void test_the_lazy()
{
    std::clog << "Testing the alch::lazy class... ";

    const char * raw_text = "some random text";

    alch::lazy< const char&, const char * > extractor( first_char_o, raw_text );

    const char & fun_result = extractor.exec();

    assert( &fun_result == raw_text, "alch::lazy::exec" );
    assert( &fun_result == &first_char_o( raw_text ), "alch::lazy::?" );

    std::clog << "ok\n";
}



template< class T >
class cons_cell
{
public:
    cons_cell( const T & arg_car, const T & arg_cdr )
	: v( arg_car, arg_cdr )
    { }

    const T & car() const
    { return v.foo(); }

    const T & cdr() const
    { return v.bar(); }

private:
    const range::foobar< const T & > v;
};



void test_the_str()
{
    std::clog << "Testing the range::str class... ";

    const char * raw_str = "text";

    const range::str str( raw_str );

    const char * again_raw_str = str;

    assert( str.len() == 4, "range::str::len" );
    assert( again_raw_str == raw_str, "range::str::operator const char *" );

    size_t counter = 0;
    range::iter<char> iter( str.get_iter() );
    while( iter.valid() )
    {
	++iter;
	++counter;
	assert( *iter == raw_str[counter], "range::str::get_iter1" );
    }
    const bool valid_counter =    counter == str.len()
	                       && counter == 4;
    assert( valid_counter, "range::str::get_iter2" );
    

    std::clog << "ok\n";
}



int main()
{
    const char * raw_query = "http://127.0.0.1/query/q=word1%20word2%20word3&len=10";

    test_the_range();
    test_the_mem_area();
    test_the_iter();
    test_the_sptr();
    test_the_lazy();
    test_the_str();

    return 0;
}
