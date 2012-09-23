#ifndef __FECL_H_INCLUDED_
#define __FECL_H_INCLUDED_

// alch stands for alchemy
namespace alch
{

    template< class X, class Y >
    class fecl
    {
    public:
	fecl( const X & arg_fe, const Y & arg_cl )
	    : m_fe( arg_fe ),
	      m_cl( arg_cl )
	{ }

	const X & fe() const
	{ return m_fe; }

	const Y & cl() const
	{ return m_cl; }

    private:
	const X & m_fe;
	const Y & m_cl;
    };

} // namespace alch

#endif // __FECL_H_INCLUDED_
