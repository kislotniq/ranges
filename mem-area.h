#ifndef __MEM_AREA_H_INCLUDED_
#define __MEM_AREA_H_INCLUDED_

namespace range
{

    template< class T >
    class mem_area
    {
    public:
	mem_area( const T * start, const T * end_inclusive )
	    : area( *start, *end_inclusive )
	{ }

	mem_area( const T * start, const size_t elements )
	    : area( *start, *(start + elements - 1) )
	{ }

	const T * first_el() const
	{ return & area.start(); }

	const T * last_el() const
	{ return & area.end(); }

    private:
	const inclusive<const T> area;
    };

} // namespace range

#endif // __MEM_AREA_H_INCLUDED_
