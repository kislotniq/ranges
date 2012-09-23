#ifndef __STR_H_INCLUDED_
#define __STR_H_INCLUDED_

namespace range
{
    class str
    {
    public:
	str( const char * start, const size_t size );
	str( const char * start );

	operator const char * () const;
	size_t len() const;

	const iter<char> get_iter() const;

    private:
	size_t count_len( const char * s ) const;

	const mem_area<char> val;
    };

} // namespace range

#endif // __STR_H_INCLUDED_
