#ifndef __RANGE_H_INCLUDED_
#define __RANGE_H_INCLUDED_

namespace range
{
    template< class T >
    class inclusive
    {
    public:
	inclusive( const T & start, const T & end )
	    : thing( start, end )
	{ }

	const T & start() const
	{ return thing.foo(); }

	const T & end() const
	{ return thing.bar(); }

	bool in_bounds( const T & value ) const
	{ return (value >= start()) && (value <= end()); }

	size_t size() const
	{ return end - start + 1; }

    private:
	foobar<T> thing;
    };

} // namespace range

#endif // __RANGE_H_INCLUDED_
