#ifndef __FOOBAR_H_INCLUDED_
#define __FOOBAR_H_INCLUDED_

namespace range
{

    template< class T >
    class foobar
    {
    public:
	foobar( const T & arg_foo, const T & arg_bar )
	    : val( arg_foo, arg_bar )
	{ }

	const T & foo() const
	{ return val.fe(); }

	const T & bar() const
	{ return val.cl(); }

    private:
	const alch::fecl< T, T > val;
    };

} // namespace range

#endif // __FOOBAR_H_INCLUDED_
