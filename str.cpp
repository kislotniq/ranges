#include <iostream>

#include "fecl.h"
#include "foobar.h"
#include "range.h"
#include "mem-area.h"
#include "iter.h"

#include "str.h"



range
::str::str( const char * start, const size_t size )
    : val( start, size )
{ }

range
::str::str( const char * start )
    : val( start, count_len( start ) )
{ }

size_t range
::str::len() const
{
    return val.last_el() - val.first_el() + 1;
}

range
::str::operator const char * () const
{
    return val.first_el();
}

const range::iter<char> range
::str::get_iter() const
{
    return iter<char>( val );
}

size_t range
::str::count_len( const char * s ) const
{
    size_t i = 0;
    while( s[i] )
	++i;
    return i;
}
