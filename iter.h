#ifndef __ITER_H_INCLUDED_
#define __ITER_H_INCLUDED_

namespace range
{

    template< class T >
    class iter
    {
    public:
	iter( const mem_area<T> & arg_area )
	    : area( arg_area ),
	      p( arg_area.first_el() )
	{ }

	bool valid() const
	{ return p <= area.last_el(); }

	const T * operator++()
	{ return ++p; }

	const T & operator*() const
	{ return *p; }

    private:
	const T * p;
	const range::mem_area<T> & area;
    };

} // namespace range

#endif // __ITER_H_INCLUDED_
