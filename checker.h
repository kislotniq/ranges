#ifndef __CHECKER_H_INCLUDED_
#define __CHECKER_H_INCLUDED_

/*
  This class is used to produce compilation errors when it's template parameter
  has size that is different from the size_of(void*), i.e. 4 bytes on 32-bit
  machines and 8 bytes on 64-bit machines.

  This is useful (i hope so) in those situations when you must be sure, that
  template parameter of some class X is exactly 4 (or 8) bytes long.

  Why would you want to do that?
  To ensure that you passed a pointer, not a whole object =)

  This is just a self-checking measure, it may be not applicable to
  all situations.

  Usage example:
    template< class T >
    class some_class
    {
    public:
      ...
    private:
      paranoid::checker< sizeof(T) > size_check;
    };

  It will cause compilation error if sizeof(T) != sizeof( void* ),
  sizeof(void*) is the size of a pointer.
*/

namespace paranoid
{

    template< size_t size >
    class ptr_size
    {
    public:
	ptr_size( int compilation_error )
	{ }
    };

    template<>
    class ptr_size< sizeof(void*) >
    {
    public:
	ptr_size()
	{ }
    };



    template< size_t size >
    class half_ptr_size
    {
    public:
	half_ptr_size( int compilation_error )
	{ }
    };

    template<>
    class half_ptr_size< sizeof(void*) / 2 >
    {
    public:
	half_ptr_size()
	{ }
    };



    template< size_t size >
    class double_ptr_size
    {
    public:
	double_ptr_size( int compilation_error )
	{ }
    };

    template<>
    class double_ptr_size< sizeof(void*) * 2 >
    {
    public:
	double_ptr_size()
	{ }
    };

} // namespace paranoid

#endif // __CHECKER_H_INCLUDED_
