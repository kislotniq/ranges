#ifndef __SPTR_H_INCLUDED_
#define __SPTR_H_INCLUDED_

namespace range
{
    /*
      sptr stands for static ptr, i.e. pointer to a data that is never deleted
    */



    // forwarding
    template< class T > class sptr;



    template< class T >
    sptr<T> i_guarantee_this_is_static( const T * arg )
    {
	//paranoid::i_dont_believe_you( arg );

	// variations:
	//   paranoid::dont_trust_him( arg );
	//   paranoid::you_have_no_trust( arg );
	//   paranoid::recheck( arg );

	return sptr<T>( arg );
    }



    template< class T >
    class sptr
    {
    public:
	operator const T * () const
	{ return p; }

    protected:
	friend sptr<T> i_guarantee_this_is_static<>( const T * );

	sptr( const T * arg_p )
	    : p( arg_p )
	{ }

    private:
	const T * p;
    };

};

#endif // __SPTR_H_INCLUDED_
