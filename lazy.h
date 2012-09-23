#ifndef __LAZY_H_INCLUDED_
#define __LAZY_H_INCLUDED_

namespace alch
{

    template< class X, class Y >
    class lazy
    {
    public:
	lazy( X (*arg_fun)(Y), const Y & arg_val )
	    : val( arg_fun, arg_val )
	{ }

	X exec() const
	{ return val.fe()( val.cl() ); }

    private:
	const fecl< X (*)(Y), const Y & > val;
    };

} // namespace range

#endif
