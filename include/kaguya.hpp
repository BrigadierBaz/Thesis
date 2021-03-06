#ifndef KAGUYA_LUABINDING_HPP_INCLUDED
#define KAGUYA_LUABINDING_HPP_INCLUDED
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include<string>
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#ifndef KAGUYA_USE_CPP11
#if defined(__cpp_decltype) || __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1800)
#define KAGUYA_USE_CPP11 1
#else
#define KAGUYA_USE_CPP11 0
#endif
#endif


#if KAGUYA_USE_CPP11
#include <functional>
#include <tuple>
#include <memory>
#include <utility>
#include <type_traits>
#include <initializer_list>
#else
#include <boost/function.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>
#endif

//for c++03 implement

#define KAGUYA_VA_ARG(...) __VA_ARGS__

#define KAGUYA_PP_CAT(F,B) F##B

#define KAGUYA_PP_REPEAT0(MACRO)
#define KAGUYA_PP_REPEAT1(MACRO) MACRO(1)
#define KAGUYA_PP_REPEAT2(MACRO) KAGUYA_PP_REPEAT1(MACRO) MACRO(2)
#define KAGUYA_PP_REPEAT3(MACRO) KAGUYA_PP_REPEAT2(MACRO) MACRO(3)
#define KAGUYA_PP_REPEAT4(MACRO) KAGUYA_PP_REPEAT3(MACRO) MACRO(4)
#define KAGUYA_PP_REPEAT5(MACRO) KAGUYA_PP_REPEAT4(MACRO) MACRO(5)
#define KAGUYA_PP_REPEAT6(MACRO) KAGUYA_PP_REPEAT5(MACRO) MACRO(6)
#define KAGUYA_PP_REPEAT7(MACRO) KAGUYA_PP_REPEAT6(MACRO) MACRO(7)
#define KAGUYA_PP_REPEAT8(MACRO) KAGUYA_PP_REPEAT7(MACRO) MACRO(8)
#define KAGUYA_PP_REPEAT9(MACRO) KAGUYA_PP_REPEAT8(MACRO) MACRO(9)
#define KAGUYA_PP_REPEAT10(MACRO) KAGUYA_PP_REPEAT9(MACRO) MACRO(10)
#define KAGUYA_PP_REPEAT(COUNT,MACRO) KAGUYA_PP_CAT(KAGUYA_PP_REPEAT,COUNT)(MACRO)


#define KAGUYA_PP_REV_REPEAT0(MACRO)
#define KAGUYA_PP_REV_REPEAT1(MACRO) MACRO(1)
#define KAGUYA_PP_REV_REPEAT2(MACRO) MACRO(2) KAGUYA_PP_REV_REPEAT1(MACRO)
#define KAGUYA_PP_REV_REPEAT3(MACRO) MACRO(3) KAGUYA_PP_REV_REPEAT2(MACRO)
#define KAGUYA_PP_REV_REPEAT4(MACRO) MACRO(4) KAGUYA_PP_REV_REPEAT3(MACRO)
#define KAGUYA_PP_REV_REPEAT5(MACRO) MACRO(5) KAGUYA_PP_REV_REPEAT4(MACRO)
#define KAGUYA_PP_REV_REPEAT6(MACRO) MACRO(6) KAGUYA_PP_REV_REPEAT5(MACRO)
#define KAGUYA_PP_REV_REPEAT7(MACRO) MACRO(7) KAGUYA_PP_REV_REPEAT6(MACRO)
#define KAGUYA_PP_REV_REPEAT8(MACRO) MACRO(8) KAGUYA_PP_REV_REPEAT7(MACRO)
#define KAGUYA_PP_REV_REPEAT9(MACRO) MACRO(9) KAGUYA_PP_REV_REPEAT8(MACRO)
#define KAGUYA_PP_REV_REPEAT10(MACRO) MACRO(10) KAGUYA_PP_REV_REPEAT9(MACRO)
#define KAGUYA_PP_REVERSE_REPEAT(COUNT,MACRO) KAGUYA_PP_CAT(KAGUYA_PP_REV_REPEAT,COUNT)(MACRO)


#define KAGUYA_PP_REPEAT_DEF0(MACRO)
#define KAGUYA_PP_REPEAT_DEF1(MACRO) MACRO(1)
#define KAGUYA_PP_REPEAT_DEF2(MACRO) KAGUYA_PP_REPEAT_DEF1(MACRO) MACRO(2)
#define KAGUYA_PP_REPEAT_DEF3(MACRO) KAGUYA_PP_REPEAT_DEF2(MACRO) MACRO(3)
#define KAGUYA_PP_REPEAT_DEF4(MACRO) KAGUYA_PP_REPEAT_DEF3(MACRO) MACRO(4)
#define KAGUYA_PP_REPEAT_DEF5(MACRO) KAGUYA_PP_REPEAT_DEF4(MACRO) MACRO(5)
#define KAGUYA_PP_REPEAT_DEF6(MACRO) KAGUYA_PP_REPEAT_DEF5(MACRO) MACRO(6)
#define KAGUYA_PP_REPEAT_DEF7(MACRO) KAGUYA_PP_REPEAT_DEF6(MACRO) MACRO(7)
#define KAGUYA_PP_REPEAT_DEF8(MACRO) KAGUYA_PP_REPEAT_DEF7(MACRO) MACRO(8)
#define KAGUYA_PP_REPEAT_DEF9(MACRO) KAGUYA_PP_REPEAT_DEF8(MACRO) MACRO(9)
#define KAGUYA_PP_REPEAT_DEF10(MACRO) KAGUYA_PP_REPEAT_DEF9(MACRO) MACRO(10)
#define KAGUYA_PP_REPEAT_DEF(COUNT,MACRO) KAGUYA_PP_CAT(KAGUYA_PP_REPEAT_DEF,COUNT)(MACRO)

#define KAGUYA_PP_REPEAT_DEF_VA_ARG0(MACRO, ...)
#define KAGUYA_PP_REPEAT_DEF_VA_ARG1(MACRO, ...) KAGUYA_VA_ARG(MACRO(1,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG2(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG1(MACRO,__VA_ARGS__) MACRO(2,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG3(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG2(MACRO,__VA_ARGS__) MACRO(3,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG4(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG3(MACRO,__VA_ARGS__) MACRO(4,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG5(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG4(MACRO,__VA_ARGS__) MACRO(5,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG6(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG5(MACRO,__VA_ARGS__) MACRO(6,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG7(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG6(MACRO,__VA_ARGS__) MACRO(7,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG8(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG7(MACRO,__VA_ARGS__) MACRO(8,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG9(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG8(MACRO,__VA_ARGS__) MACRO(9,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG10(MACRO, ...) KAGUYA_VA_ARG(KAGUYA_VA_ARG(KAGUYA_PP_REPEAT_DEF_VA_ARG9(MACRO,__VA_ARGS__) MACRO(10,__VA_ARGS__))
#define KAGUYA_PP_REPEAT_DEF_VA_ARG(COUNT,MACRO, ...) KAGUYA_VA_ARG(KAGUYA_PP_CAT(KAGUYA_PP_REPEAT_DEF_VA_ARG,COUNT)(MACRO,__VA_ARGS__))

#define KAGUYA_PP_REPEAT_ARG0(MACRO)
#define KAGUYA_PP_REPEAT_ARG1(MACRO) MACRO(1)
#define KAGUYA_PP_REPEAT_ARG2(MACRO) KAGUYA_PP_REPEAT_ARG1(MACRO), MACRO(2)
#define KAGUYA_PP_REPEAT_ARG3(MACRO) KAGUYA_PP_REPEAT_ARG2(MACRO), MACRO(3)
#define KAGUYA_PP_REPEAT_ARG4(MACRO) KAGUYA_PP_REPEAT_ARG3(MACRO), MACRO(4)
#define KAGUYA_PP_REPEAT_ARG5(MACRO) KAGUYA_PP_REPEAT_ARG4(MACRO), MACRO(5)
#define KAGUYA_PP_REPEAT_ARG6(MACRO) KAGUYA_PP_REPEAT_ARG5(MACRO), MACRO(6)
#define KAGUYA_PP_REPEAT_ARG7(MACRO) KAGUYA_PP_REPEAT_ARG6(MACRO), MACRO(7)
#define KAGUYA_PP_REPEAT_ARG8(MACRO) KAGUYA_PP_REPEAT_ARG7(MACRO), MACRO(8)
#define KAGUYA_PP_REPEAT_ARG9(MACRO) KAGUYA_PP_REPEAT_ARG8(MACRO), MACRO(9)
#define KAGUYA_PP_REPEAT_ARG10(MACRO) KAGUYA_PP_REPEAT_ARG9(MACRO), MACRO(10)
#define KAGUYA_PP_REPEAT_ARG(COUNT,MACRO) KAGUYA_PP_CAT(KAGUYA_PP_REPEAT_ARG,COUNT)(MACRO)
		
#define KAGUYA_PP_VARIADIC_TARG_CONCAT_REP(N) ,KAGUYA_PP_CAT(A,N)
#define KAGUYA_PP_VARIADIC_TARG_REP(N) KAGUYA_PP_CAT(A,N)

#define KAGUYA_PP_TEMPLATE_ARG_REPEAT_CONCAT(N) KAGUYA_PP_REPEAT(N, KAGUYA_PP_VARIADIC_TARG_CONCAT_REP)
#define KAGUYA_PP_TEMPLATE_ARG_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PP_VARIADIC_TARG_REP)


#define KAGUYA_PP_ARG_DEF_CONCAT_REP(N) ,KAGUYA_PP_CAT(A,N) KAGUYA_PP_CAT(a,N)
#define KAGUYA_PP_ARG_DEF_REP(N) KAGUYA_PP_CAT(A,N) KAGUYA_PP_CAT(a,N)

#define KAGUYA_PP_ARG_DEF_REPEAT_CONCAT(N) KAGUYA_PP_REPEAT(N, KAGUYA_PP_ARG_DEF_CONCAT_REP)
#define KAGUYA_PP_ARG_DEF_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PP_ARG_DEF_REP)


#define KAGUYA_PP_ARG_CONCAT_REP(N) ,KAGUYA_PP_CAT(a,N)
#define KAGUYA_PP_ARG_REP(N) KAGUYA_PP_CAT(a,N)

#define KAGUYA_PP_ARG_REPEAT_CONCAT(N) KAGUYA_PP_REPEAT(N, KAGUYA_PP_ARG_CONCAT_REP)
#define KAGUYA_PP_ARG_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PP_ARG_REP)



#define KAGUYA_PP_VARIADIC_TDEF_CONCAT_REP(N) ,KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_VARIADIC_TDEF_REP(N) KAGUYA_PP_CAT(typename A,N)

#define KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N) KAGUYA_PP_REPEAT(N,KAGUYA_PP_VARIADIC_TDEF_CONCAT_REP)
#define KAGUYA_PP_TEMPLATE_DEF_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_VARIADIC_TDEF_REP)



#define KAGUYA_PP_WHILE0(MACRO,R) R
#define KAGUYA_PP_WHILE1(MACRO,R) MACRO(KAGUYA_PP_WHILE0(MACRO,R))
#define KAGUYA_PP_WHILE2(MACRO,R) MACRO(KAGUYA_PP_WHILE1(MACRO,R))
#define KAGUYA_PP_WHILE3(MACRO,R) MACRO(KAGUYA_PP_WHILE2(MACRO,R))
#define KAGUYA_PP_WHILE4(MACRO,R) MACRO(KAGUYA_PP_WHILE3(MACRO,R))
#define KAGUYA_PP_WHILE5(MACRO,R) MACRO(KAGUYA_PP_WHILE4(MACRO,R))
#define KAGUYA_PP_WHILE6(MACRO,R) MACRO(KAGUYA_PP_WHILE5(MACRO,R))
#define KAGUYA_PP_WHILE7(MACRO,R) MACRO(KAGUYA_PP_WHILE6(MACRO,R))
#define KAGUYA_PP_WHILE8(MACRO,R) MACRO(KAGUYA_PP_WHILE7(MACRO,R))
#define KAGUYA_PP_WHILE9(MACRO,R) MACRO(KAGUYA_PP_WHILE8(MACRO,R))
#define KAGUYA_PP_WHILE10(MACRO,R) MACRO(KAGUYA_PP_WHILE9(MACRO,R))
#define KAGUYA_PP_WHILE(COUNT,R,MACRO) KAGUYA_PP_CAT(KAGUYA_PP_WHILE,COUNT)(MACRO,R)


#define KAGUYA_PP_INC0 1
#define KAGUYA_PP_INC1 2
#define KAGUYA_PP_INC2 3
#define KAGUYA_PP_INC3 4
#define KAGUYA_PP_INC4 5
#define KAGUYA_PP_INC5 6
#define KAGUYA_PP_INC6 7
#define KAGUYA_PP_INC7 8
#define KAGUYA_PP_INC8 9
#define KAGUYA_PP_INC9 10
#define KAGUYA_PP_DEC1 0
#define KAGUYA_PP_DEC2 1
#define KAGUYA_PP_DEC3 2
#define KAGUYA_PP_DEC4 3
#define KAGUYA_PP_DEC5 4
#define KAGUYA_PP_DEC6 5
#define KAGUYA_PP_DEC7 6
#define KAGUYA_PP_DEC8 7
#define KAGUYA_PP_DEC9 8
#define KAGUYA_PP_INC(N) KAGUYA_PP_CAT(KAGUYA_PP_INC,N)
#define KAGUYA_PP_DEC(N) KAGUYA_PP_CAT(KAGUYA_PP_DEC,N)

#define KAGUYA_PP_ADD(X,Y) KAGUYA_PP_WHILE(Y,X,KAGUYA_PP_INC)
#define KAGUYA_PP_SUB(X,Y) KAGUYA_PP_WHILE(Y,X,KAGUYA_PP_DEC)



#ifndef KAGUYA_NO_USERDATA_TYPE_CHECK
#define KAGUYA_NO_USERDATA_TYPE_CHECK 0
#endif

#ifndef KAGUYA_USE_RVALUE_REFERENCE
#if KAGUYA_USE_CPP11
#define KAGUYA_USE_RVALUE_REFERENCE 1
#else
#define KAGUYA_USE_RVALUE_REFERENCE 0
#endif
#endif


#ifdef KAGUYA_NO_VECTOR_AND_MAP_TO_TABLE
#define KAGUYA_NO_STD_VECTOR_TO_TABLE
#define KAGUYA_NO_STD_MAP_TO_TABLE
#endif


#ifndef KAGUYA_DETECT_USE_DEPRECATED_FEATURE
#define KAGUYA_DETECT_USE_DEPRECATED_FEATURE 0
#endif

#ifndef KAGUYA_NOEXCEPT
# if KAGUYA_USE_CPP11 && (!defined(_MSC_VER) || _MSC_VER >= 1900)
#  define KAGUYA_NOEXCEPT noexcept
# else
#  define KAGUYA_NOEXCEPT throw()
# endif
#endif

#ifndef KAGUYA_DEPRECATED_FEATURE
#if __cplusplus >= 201402L && defined(__has_cpp_attribute)
#if  __has_cpp_attribute(deprecated)
//C++ standard depecated
#define KAGUYA_DEPRECATED_FEATURE(MSG) [[deprecated(MSG)]]
#endif
#endif
#endif
#ifndef KAGUYA_DEPRECATED_FEATURE
#if defined(_MSC_VER)
//MSVC depecated
#define KAGUYA_DEPRECATED_FEATURE(MSG) __declspec(deprecated(MSG)) 
#elif defined(__GNUC__) || defined(__clang__)
#define KAGUYA_DEPRECATED_FEATURE(MSG) __attribute__((deprecated))
#else
#define KAGUYA_DEPRECATED_FEATURE(MSG)
#endif

#endif

namespace kaguya
{
#if defined(_MSC_VER) && _MSC_VER <= 1500
	typedef unsigned char uint8_t;
	typedef int int32_t;
	typedef long long int64_t;
#endif

	namespace standard
	{
#if KAGUYA_USE_CPP11
		using namespace std;
#define KAGUYA_STATIC_ASSERT static_assert

#else
		using namespace boost;
#define KAGUYA_STATIC_ASSERT BOOST_STATIC_ASSERT_MSG
#endif
	}

#if LUA_VERSION_NUM > 502
	typedef lua_Integer luaInt;
#else
	typedef int32_t luaInt;
#endif
}


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <ostream>
#include <istream>
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>
#include <cstring>

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>

namespace kaguya
{
	/// @addtogroup optional
	///  @{
	
	struct bad_optional_access :std::exception {};
	struct nullopt_t {};

	/// @brief self implement for std::optional(C++17 feature).
	template<class T>class optional
	{
		typedef void (optional::*bool_type)() const;
		void this_type_does_not_support_comparisons() const {}
	public:
		optional() : value_(0) {};
		optional(nullopt_t) : value_(0) {};
		optional(const optional& other) : value_(0)
		{
			if (other)
			{
				value_ = new(&storage_) T(other.value());
			}
		}
		optional(const T& value)
		{
			value_ = new(&storage_) T(value);
		}

		~optional() {
			destruct();
		}
		optional& operator=(nullopt_t) { destruct(); return *this; }
		optional& operator=(const optional& other)
		{
			if (other)
			{
				*this = other.value();
			}
			else
			{
				destruct();
			}
			return *this;
		}
		optional& operator=(const T& value)
		{
			if (value_)
			{
				*value_ = value;
			}
			else
			{
				value_ = new(&storage_) T(value);
			}
			return *this;
		}

#if KAGUYA_USE_CPP11
		optional(optional&& other) :value_(0)
		{
			if (other)
			{
				value_ = new(&storage_) T(std::move(other.value()));
			}
		}
		optional(T&& value)
		{
			value_ = new(&storage_) T(std::move(value));
		}
		optional& operator=(optional&& other)
		{
			if (other)
			{
				*this = std::move(other.value());
			}
			else
			{
				destruct();
			}
			return *this;
		}
		optional& operator=(T&& value)
		{
			if (value_)
			{
				*value_ = std::move(value);
			}
			else
			{
				value_ = new(&storage_) T(std::move(value));
			}
			return *this;
		}
#endif

		operator bool_type() const
		{
			this_type_does_not_support_comparisons();
			return value_ != 0 ? &optional::this_type_does_not_support_comparisons : 0;
		}
		T& value()
		{
			if (value_) { return *value_; }
			throw bad_optional_access();
		}
		const T & value() const
		{
			if (value_) { return *value_; }
			throw bad_optional_access();
		}

#if KAGUYA_USE_CPP11
		template< class U >
		T value_or(U&& default_value)  const
		{
			if (value_) { return *value_; }
			return default_value;
		}
#else
		template< class U >
		T value_or(const U& default_value)const
		{
			if (value_) { return *value_; }
			return default_value;
		}
#endif
		const T* operator->() const { assert(value_); return value_; }
		T* operator->() { assert(value_); return value_; }
		const T& operator*() const { assert(value_); return *value_; }
		T& operator*() { assert(value_); return  *value_; }
	private:
		void destruct()
		{
			if (value_)
			{
				value_->~T(); value_ = 0;
			}
		}

		typename standard::aligned_storage<sizeof(T),
			standard::alignment_of<T>::value>::type storage_;

		T* value_;
	};

	/// @brief specialize optional for reference.
	/// sizeof(optional<T&>) == sizeof(T*)
	template<class T>class optional<T&>
	{
		typedef void (optional::*bool_type)() const;
		void this_type_does_not_support_comparisons() const {}
	public:
		optional() : value_(0) {};
		optional(nullopt_t) : value_(0) {};

		optional(const optional& other) :value_(other.value_) {	}
		optional(T& value) :value_(&value) {	}

		~optional() {
		}
		optional& operator=(nullopt_t) {
			value_ = 0;
			return *this;
		}
		optional& operator=(const optional& other)
		{
			value_ = other.value_;
			return *this;
		}
		optional& operator=(T& value)
		{
			value_ = &value;
			return *this;
		}
		operator bool_type() const
		{
			this_type_does_not_support_comparisons();
			return value_ != 0 ? &optional::this_type_does_not_support_comparisons : 0;
		}
		T& value()
		{
			if (value_) { return *value_; }
			throw bad_optional_access();
		}
		const T & value() const
		{
			if (value_) { return *value_; }
			throw bad_optional_access();
		}

#if KAGUYA_USE_CPP11
		T& value_or(T& default_value)  const
		{
			if (value_) { return *value_; }
			return default_value;
		}
#else
		T& value_or(T& default_value)const
		{
			if (value_) { return *value_; }
			return default_value;
		}
#endif

		const T* operator->() const { assert(value_); return value_; }
		T* operator->() { assert(value_); return value_; }
		const T& operator*() const { assert(value_); return *value_; }
		T& operator*() { assert(value_); return *value_; }
	private:
		T* value_;
	};

	/// @name relational operators
	/// @brief
	///@{
	template< class T >
	bool operator==(const optional<T>& lhs, const optional<T>& rhs)
	{
		if (bool(lhs) != bool(rhs)) { return false; }
		if (bool(lhs) == false) { return true; }
		return lhs.value() == rhs.value();
	}
	template< class T >
	bool operator!=(const optional<T>& lhs, const optional<T>& rhs)
	{
		return !(lhs == rhs);
	}
	template< class T >
	bool operator<(const optional<T>& lhs, const optional<T>& rhs)
	{
		if (!bool(rhs)) { return false; }
		if (!bool(lhs)) { return true; }
		return lhs.value() < rhs.value();
	}
	template< class T >
	bool operator<=(const optional<T>& lhs, const optional<T>& rhs)
	{
		return !(rhs < lhs);
	}
	template< class T >
	bool operator>(const optional<T>& lhs, const optional<T>& rhs)
	{
		return rhs < lhs;
	}
	template< class T >
	bool operator>=(const optional<T>& lhs, const optional<T>& rhs)
	{
		return !(lhs < rhs);
	}
	/// @}

	/// @}
}// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>
#include <vector>
#include <map>


namespace kaguya
{
	namespace traits
	{
		using standard::integral_constant;
		using standard::is_lvalue_reference;
		using standard::remove_reference;
		using standard::remove_pointer;
		using standard::remove_const;
		using standard::is_pointer;
		using standard::is_function;
		using standard::is_floating_point;
		using standard::is_integral;
		using standard::is_enum;
		using standard::is_convertible;
		using standard::is_same;

		/// @brief same std::enable_if
		template<bool B, class T = void>struct enable_if {};
		/// @brief same std::enable_if
		template<class T>struct enable_if<true, T> { 
			///@	T (defined only if Cond is true)
			typedef T type;
		};

		/// @brief same std::is_void
		template< typename T >
		struct is_void :integral_constant<bool, false>
		{
		};
		/// @brief same std::is_void
		template<>
		struct is_void<void> :integral_constant<bool, true>
		{
		};

		/// @brief same std::decay
		template< class T >
		struct decay {
		private:
			typedef typename standard::remove_reference<T>::type U;
		public:
			///@ If T is a reference type, the type referrered to by T.	Otherwise, T.
			typedef typename standard::conditional<
				standard::is_array<U>::value,
				typename standard::remove_extent<U>::type*,
				typename standard::conditional<
				is_function<U>::value,
				typename standard::add_pointer<U>::type,
				typename standard::remove_cv<U>::type
				>::type
			>::type type;
		};

		/// @brief same std::is_const
		template<class T> struct is_const : integral_constant<bool, false> {};
		template<class T> struct is_const<const T> : integral_constant<bool, true> {};

		/// @brief Trait class that identifies whether T is a const reference type.
		template<class T> struct is_const_reference : integral_constant<bool, false> {};
		template<class T> struct is_const_reference<const T&> : integral_constant<bool, true> {};

		/// @brief Obtains the type T without top-level const and reference.
		template< typename T >
		struct remove_const_and_reference {
			/// @brief If T is const or reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};
		/// @brief Obtains the type T without top-level const and reference.
		template< typename T >
		struct remove_const_and_reference<T&> {
			/// @brief If T is const or reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};
		/// @brief Obtains the type T without top-level const and reference.
		template< typename T >
		struct remove_const_and_reference<const T> {
			/// @brief If T is const or reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};
		/// @brief Obtains the type T without top-level const and reference.
		template< typename T >
		struct remove_const_and_reference<const T&> {
			/// @brief If T is const or reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};

		/// @brief Obtains the type T without top-level const reference.
		template< typename T >
		struct remove_const_reference {
			/// @brief If T is const reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};
		/// @brief Obtains the type T without top-level const reference.
		template< typename T >
		struct remove_const_reference<const T&> {
			/// @brief If T is const reference, the same type as T but with the const reference removed.Otherwise, T
			typedef T type;
		};

		/// @brief Trait class that identifies whether T is a std::vector type.
		template<class T> struct is_std_vector : integral_constant<bool, false> {};
		template<class T, class A> struct is_std_vector<std::vector<T, A> > : integral_constant<bool, true> {};

		/// @brief Trait class that identifies whether T is a std::map type.
		template<class T> struct is_std_map : integral_constant<bool, false> {};
		template<class K, class V, class C, class A> struct is_std_map<std::map<K, V, C, A> > : integral_constant<bool, true> {};
	}


	/// @addtogroup lua_type_traits

	/// @ingroup lua_type_traits
	/// @brief If you want to customize the conversion to type of lua yourself ,
	///  implement specialize of this class
	template<typename T, typename Enable = void>
	struct lua_type_traits
	{
		typedef void Registerable;

		typedef typename traits::decay<T>::type NCRT;
		typedef const NCRT& get_type;
		typedef const NCRT& push_type;

		static bool checkType(lua_State* l, int index);
		static bool strictCheckType(lua_State* l, int index);

		static get_type get(lua_State* l, int index);
		static int push(lua_State* l, push_type v);
#if KAGUYA_USE_RVALUE_REFERENCE
		static int push(lua_State* l, NCRT&& v);
#endif
	};


	/// @brief Trait class that identifies whether T is a userdata type.
	template< typename T, typename Enable = void>
	struct is_usertype : traits::integral_constant<bool, false> {};
	template< typename T>
	struct is_usertype<T, typename lua_type_traits<T>::Registerable> : traits::integral_constant<bool, true> {};

	/// @brief Trait class that identifies whether T is a registerable by UserdataMetatable.
	template< typename T>
	struct is_registerable : is_usertype<T> {};
}
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#include <iostream>

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


namespace kaguya
{
	//for lua version compatibility
	namespace compat
	{
#if LUA_VERSION_NUM >= 503
		inline int lua_rawgetp_rtype(lua_State *L, int idx, const void* ptr)
		{
			return lua_rawgetp(L, idx, ptr);
		}
		inline int lua_getfield_rtype(lua_State *L, int idx, const char* k)
		{
			return lua_getfield(L, idx, k);
		}
		inline int lua_gettable_rtype(lua_State *L, int idx)
		{
			return lua_gettable(L, idx);
		}
#elif LUA_VERSION_NUM == 502
		inline int lua_rawgetp_rtype(lua_State *L, int idx, const void* ptr)
		{
			lua_rawgetp(L, idx, ptr);
			return lua_type(L, -1);
		}
#elif LUA_VERSION_NUM < 502
		enum LUA_OPEQ
		{
			LUA_OPEQ,
			LUA_OPLT,
			LUA_OPLE
		};
		inline int lua_compare(lua_State *L, int index1, int index2, int op)
		{
			switch (op)
			{
			case LUA_OPEQ:
				return lua_equal(L, index1, index2);
			case  LUA_OPLT:
				return lua_lessthan(L, index1, index2);
			case  LUA_OPLE:
				return lua_equal(L, index1, index2) || lua_lessthan(L, index1, index2);
			default:
				return 0;
			}
		}

		inline void lua_pushglobaltable(lua_State *L)
		{
			lua_pushvalue(L, LUA_GLOBALSINDEX);
		}
		inline size_t lua_rawlen(lua_State *L, int index)
		{
			int type = lua_type(L, index);
			if (type != LUA_TSTRING && type != LUA_TTABLE && type != LUA_TUSERDATA && type != LUA_TLIGHTUSERDATA)
			{
				return 0;
			}
			return lua_objlen(L, index);
		}

		inline int lua_resume(lua_State *L, lua_State* from, int nargs)
		{
			return ::lua_resume(L, nargs);
		}
		inline int lua_absindex(lua_State *L, int idx)
		{
			return (idx > 0 || (idx <= LUA_REGISTRYINDEX)) ? idx : lua_gettop(L) + 1 + idx;
		}
		inline int lua_rawgetp_rtype(lua_State *L, int idx, const void* ptr)
		{
			int absidx = lua_absindex(L, idx);
			lua_pushlightuserdata(L, (void*)ptr);
			lua_rawget(L, absidx);
			return lua_type(L, -1);
		}
		inline void lua_rawsetp(lua_State *L, int idx, const void* ptr)
		{
			int absidx = lua_absindex(L, idx);
			lua_pushvalue(L, -1);
			lua_pushlightuserdata(L, (void*)ptr);
			lua_replace(L, -3);
			lua_rawset(L, absidx);
		}
		inline void luaL_requiref(lua_State *L, const char *modname,
			lua_CFunction openf, int glb) {

			lua_pushcfunction(L, openf);
			lua_pushstring(L, modname);
			lua_call(L, 1, 1);

			if (glb) {
				lua_pushvalue(L, -1);
				lua_setglobal(L, modname);
			}
		}
		inline lua_Number lua_tonumberx(lua_State *L, int index, int *isnum)
		{
			if (isnum) { *isnum = lua_isnumber(L, index); }
			return lua_tonumber(L, index);
		}
#endif
#if LUA_VERSION_NUM < 503
		inline void lua_seti(lua_State *L, int index, lua_Integer n)
		{
			int absidx = lua_absindex(L, index);
			lua_pushvalue(L, -1);
			lua_pushinteger(L, n);
			lua_replace(L, -3);
			lua_rawset(L, absidx);
		}
		inline int lua_geti(lua_State *L, int index, lua_Integer i)
		{
			int absidx = lua_absindex(L, index);
			lua_pushinteger(L, i);
			lua_rawget(L, absidx);
			return lua_type(L, -1);
		}
		inline int lua_getfield_rtype(lua_State *L, int idx, const char* k)
		{
			lua_getfield(L, idx, k);
			return lua_type(L, -1);
		}
		inline int lua_gettable_rtype(lua_State *L, int idx)
		{
			lua_gettable(L, idx);
			return lua_type(L, -1);
		}
#endif
#if LUA_VERSION_NUM < 501
		void lua_createtable(lua_State *L, int narr, int nrec)
		{
			lua_newtable(L);
		}
#endif
	}

	using namespace compat;
}
namespace kaguya
{
	namespace util
	{
		/// @brief save stack count and restore on destructor
		class ScopedSavedStack {
			lua_State * state_;
			int saved_top_index_;

		public:
			/// @brief save stack count
			/// @param state
			explicit ScopedSavedStack(lua_State * state)
				: state_(state),
				saved_top_index_(state_ ? lua_gettop(state_):0)
			{
			}

			/// @brief save stack count
			/// @param state
			/// @param count stack count
			explicit ScopedSavedStack(lua_State * state, int count)
				: state_(state),
				saved_top_index_(count)
			{}

			/// @brief restore stack count
			~ScopedSavedStack() {
				if (state_) {
					lua_settop(state_, saved_top_index_);
				}
			}

		private:
			ScopedSavedStack(ScopedSavedStack const &);
			ScopedSavedStack & operator=(ScopedSavedStack const &);
		};
		inline void traceBack(lua_State* state, const char* message, int level = 0)
		{
#if LUA_VERSION_NUM >= 502
			luaL_traceback(state, state, message, level);
#else
			lua_pushstring(state, message);
#endif
		}

		inline void stackDump(lua_State *L) {
			int i;
			int top = lua_gettop(L);
			for (i = 1; i <= top; i++) {  /* repeat for each level */
				int t = lua_type(L, i);
				switch (t) {

				case LUA_TSTRING:  /* strings */
					printf("`%s'", lua_tostring(L, i));
					break;

				case LUA_TBOOLEAN:  /* booleans */
					printf(lua_toboolean(L, i) ? "true" : "false");
					break;

				case LUA_TNUMBER:  /* numbers */
					printf("%g", lua_tonumber(L, i));
					break;
				case LUA_TUSERDATA:
					if (luaL_getmetafield(L, i, "__name") == LUA_TSTRING)
					{
						printf("userdata:%s", lua_tostring(L, -1));
						lua_pop(L, 1);
						break;
					}
				default:  /* other values */
					printf("%s", lua_typename(L, t));
					break;

				}
				printf("  ");  /* put a separator */
			}
			printf("\n");  /* end the listing */
		}

		inline void stackValueDump(std::ostream& os, lua_State* state, int stackIndex, int max_recursive = 2)
		{
			stackIndex = lua_absindex(state, stackIndex);
			util::ScopedSavedStack save(state);
			int type = lua_type(state, stackIndex);
			switch (type)
			{
			case LUA_TNONE:
				os << "none";
				break;
			case LUA_TNIL:
				os << "nil";
				break;
			case LUA_TBOOLEAN:
				os << ((lua_toboolean(state, stackIndex) != 0) ? "true" : "false");
				break;
			case LUA_TNUMBER:
				os << lua_tonumber(state, stackIndex);
				break;
			case LUA_TSTRING:
				os << "'" << lua_tostring(state, stackIndex) << "'";
				break;
			case LUA_TTABLE:
			{
				os << "{";
				if (max_recursive <= 1)
				{
					os << "...";
				}
				else
				{
					lua_pushnil(state);
					if ((lua_next(state, stackIndex) != 0))
					{
						stackValueDump(os, state, -2, max_recursive - 1);
						os << "=";
						stackValueDump(os, state, -1, max_recursive - 1);
						lua_pop(state, 1);//pop value

						while (lua_next(state, stackIndex) != 0)
						{
							os << ",";
							stackValueDump(os, state, -2, max_recursive - 1);
							os << "=";
							stackValueDump(os, state, -1, max_recursive - 1);
							lua_pop(state, 1);//pop value
						}
					}
				}
				os << "}";
			}
			break;
			case LUA_TUSERDATA:
			case LUA_TLIGHTUSERDATA:
			case LUA_TTHREAD:
				os << lua_typename(state, type) << "(" << lua_topointer(state, stackIndex) << ")";
				break;
			case LUA_TFUNCTION:
				os << lua_typename(state, type);
				break;
			default:
				os << "unknown type value";
				break;
			}
		}




		inline lua_State* toMainThread(lua_State* state)
		{
#if LUA_VERSION_NUM >= 502
			if (state)
			{
				lua_rawgeti(state, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
				lua_State* mainthread = lua_tothread(state, -1);
				lua_pop(state, 1);
				if (mainthread)
				{
					return mainthread;
				}
			}
#endif
			return state;
		}

#if KAGUYA_USE_CPP11
		inline int push_args(lua_State *l)
		{
			return 0;
		}
		template<class Arg, class...Args>
		inline int push_args(lua_State *l, Arg&& arg, Args&&... args)
		{
			int c = lua_type_traits<typename traits::decay<Arg>::type>::push(l, std::forward<Arg>(arg));
			return c + push_args(l, std::forward<Args>(args)...);
		}
		template<class Arg, class...Args>
		inline int push_args(lua_State *l, const Arg& arg, Args&&... args)
		{
			int c = lua_type_traits<Arg>::push(l, arg);
			return c + push_args(l, std::forward<Args>(args)...);
		}
#else
		inline int push_args(lua_State *l)
		{
			return 0;
		}

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_PUSH_DEF(N) c+=lua_type_traits<KAGUYA_PP_CAT(A,N) >::push(l, KAGUYA_PP_CAT(a,N)); 
#define KAGUYA_PUSH_ARG_DEF(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>\
		inline int push_args(lua_State *l,KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			int c =0;\
			KAGUYA_PP_REPEAT(N,KAGUYA_PUSH_DEF)\
			return c;\
		}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_PUSH_ARG_DEF)
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_PUSH_DEF
#undef KAGUYA_PUSH_ARG_DEF
#endif


#if KAGUYA_USE_CPP11
			template<typename T>
		inline bool one_push(lua_State* state, T&& v)
		{
			int count = util::push_args(state, std::forward<T>(v));
			if (count > 1) { lua_pop(state, count - 1); }
			return count != 0;
		}
#else
			template<typename T>
		inline bool one_push(lua_State* state, const T& v)
		{
			int count = util::push_args(state, v);
			if (count > 1) { lua_pop(state, count - 1); }
			return count != 0;
		}
#endif
	}
}
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <exception>
#include <stdexcept>




namespace kaguya
{
	class LuaException :public std::exception
	{
		int status_;
		std::string what_;
		const char* what_c_;
	public:
		LuaException(int status, const char* what)throw() :status_(status), what_c_(what) {}
		LuaException(int status, const std::string& what) :status_(status), what_(what), what_c_(0) {}
		int status()const throw() { return status_; }
		const char* what() const throw() { return what_c_ ? what_c_ : what_.c_str(); }

		~LuaException()throw() {}
	};
	class KaguyaException :public std::exception
	{
		std::string what_;
		const char* what_c_;
	public:
		KaguyaException(const char* what)throw() : what_c_(what) {}
		KaguyaException(const std::string& what) : what_(what), what_c_(0) {}
		const char* what() const throw() { return what_c_ ? what_c_ : what_.c_str(); }

		~KaguyaException()throw() {}
	};
	class LuaTypeMismatch :public LuaException {
	public:
		LuaTypeMismatch(const char* what)throw() :LuaException(0, what) {}
		LuaTypeMismatch(const std::string& what) :LuaException(0, what) {}
	};
	class LuaMemoryError :public LuaException {
	public:
		LuaMemoryError(int status, const char* what)throw() :LuaException(status, what) {}
		LuaMemoryError(int status, const std::string& what) :LuaException(status, what) {}
	};
	class LuaRuntimeError :public LuaException {
	public:
		LuaRuntimeError(int status, const char* what)throw() :LuaException(status, what) {}
		LuaRuntimeError(int status, const std::string& what) :LuaException(status, what) {}
	};
	class LuaErrorRunningError :public LuaException {
	public:
		LuaErrorRunningError(int status, const char* what)throw() :LuaException(status, what) {}
		LuaErrorRunningError(int status, const std::string& what) :LuaException(status, what) {}
	};
	class LuaGCError :public LuaException {
	public:
		LuaGCError(int status, const char* what)throw() :LuaException(status, what) {}
		LuaGCError(int status, const std::string& what) :LuaException(status, what) {}
	};
	class LuaUnknownError :public LuaException {
	public:
		LuaUnknownError(int status, const char* what)throw() :LuaException(status, what) {}
		LuaUnknownError(int status, const std::string& what) :LuaException(status, what) {}
	};

	class LuaSyntaxError :public LuaException {
	public:
		LuaSyntaxError(int status, const std::string& what) :LuaException(status, what) {}
	};

	namespace except
	{
		void OtherError(lua_State *state, const std::string& message);
		void typeMismatchError(lua_State *state, const std::string& message);
		void memoryError(lua_State *state, const char* message);
		bool checkErrorAndThrow(int status, lua_State *state);
	}
}

namespace kaguya
{
	namespace types
	{
		template<typename T>
		struct typetag {};
	}

	inline void* metatable_name_key() { static int key; return &key; }
	inline void* metatable_type_table_key() { static int key; return &key; }

	template<typename T>
	const std::type_info& metatableType()
	{
		return typeid(typename traits::decay<T>::type);
	}
	template<typename T>
	inline const char* metatableName()
	{
		return metatableType<T>().name();
	}

	struct ObjectWrapperBase
	{
		virtual const void* cget() = 0;
		virtual void* get() = 0;

		virtual const std::type_info& type() = 0;

		virtual const std::type_info& native_type() { return type(); }
		virtual void* native_get() { return get(); }

		ObjectWrapperBase() {}
		virtual ~ObjectWrapperBase() {}
	private:

		//noncopyable
		ObjectWrapperBase(const ObjectWrapperBase&);
		ObjectWrapperBase& operator=(const ObjectWrapperBase&);
	};

	template<class T>
	struct ObjectWrapper : ObjectWrapperBase
	{
#if KAGUYA_USE_CPP11
		template<class... Args>
		ObjectWrapper(Args&&... args) : object_(std::forward<Args>(args)...) {}
#else

		ObjectWrapper() : object_() {}
		template<class Arg1>
		ObjectWrapper(const Arg1& v1) : object_(v1) {}
		template<class Arg1, class Arg2>
		ObjectWrapper(const Arg1& v1, const Arg2& v2) : object_(v1, v2) {}
		template<class Arg1, class Arg2, class Arg3>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3) : object_(v1, v2, v3) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4) : object_(v1, v2, v3, v4) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4, const Arg5& v5) : object_(v1, v2, v3, v4, v5) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4, const Arg5& v5, const Arg6& v6) : object_(v1, v2, v3, v4, v5, v6) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4, const Arg5& v5, const Arg6& v6, const Arg7& v7) : object_(v1, v2, v3, v4, v5, v6, v7) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4, const Arg5& v5, const Arg6& v6, const Arg7& v7, const Arg8& v8) : object_(v1, v2, v3, v4, v5, v6, v7, v8) {}
		template<class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9>
		ObjectWrapper(const Arg1& v1, const Arg2& v2, const Arg3& v3, const Arg4& v4, const Arg5& v5, const Arg6& v6, const Arg7& v7, const Arg8& v8, const Arg9& v9) : object_(v1, v2, v3, v4, v5, v6, v7, v8, v9) {}

#endif

		virtual const std::type_info& type()
		{
			return metatableType<T>();
		}

		virtual void* get()
		{
			return &object_;
		}
		virtual const void* cget()
		{
			return &object_;
		}
	private:
		T object_;
	};


	struct ObjectSharedPointerWrapper : ObjectWrapperBase
	{
		template<typename T>
		ObjectSharedPointerWrapper(const standard::shared_ptr<T>& sptr) :object_(standard::const_pointer_cast<typename standard::remove_const<T>::type>(sptr)), type_(metatableType<T>()),
			shared_ptr_type_(metatableType<standard::shared_ptr<typename traits::decay<T>::type> >()), const_value_(traits::is_const<T>::value) {}
#if KAGUYA_USE_RVALUE_REFERENCE
		template<typename T>
		ObjectSharedPointerWrapper(standard::shared_ptr<T>&& sptr) : object_(std::move(standard::const_pointer_cast<typename standard::remove_const<T>::type>(sptr))), type_(metatableType<T>()),
			shared_ptr_type_(metatableType<standard::shared_ptr<typename traits::decay<T>::type> >()), const_value_(traits::is_const<T>::value) {}
#endif
		virtual const std::type_info& type()
		{
			return type_;
		}
		virtual void* get()
		{
			return  const_value_ ? 0 : object_.get();
		}
		virtual const void* cget()
		{
			return object_.get();
		}
		standard::shared_ptr<void> object()const { return const_value_ ? standard::shared_ptr<void>() : object_; }
		standard::shared_ptr<const void> const_object()const { return object_; }
		const std::type_info& shared_ptr_type()const { return shared_ptr_type_; }


		virtual const std::type_info& native_type()
		{
			return metatableType<standard::shared_ptr<void> >();
		}
		virtual void* native_get() { return &object_; }
	private:
		standard::shared_ptr<void> object_;
		const std::type_info& type_;

		const std::type_info& shared_ptr_type_;
		bool const_value_;
	};

	template<typename T, typename ElementType = typename T::element_type>
	struct ObjectSmartPointerWrapper : ObjectWrapperBase
	{
		ObjectSmartPointerWrapper(const T& sptr) :object_(sptr) {}
#if KAGUYA_USE_RVALUE_REFERENCE
		ObjectSmartPointerWrapper(T&& sptr) : object_(std::move(sptr)) {}
#endif
		virtual const std::type_info& type()
		{
			return metatableType<ElementType>();
		}
		virtual void* get()
		{
			return object_ ? &(*object_) : 0;
		}
		virtual const void* cget()
		{
			return object_ ? &(*object_) : 0;
		}
		virtual const std::type_info& native_type()
		{
			return metatableType<T>();
		}
		virtual void* native_get() { return &object_; }
	private:
		T object_;
	};

	template<class T>
	struct ObjectPointerWrapper : ObjectWrapperBase
	{
		ObjectPointerWrapper(T* ptr) :object_(ptr) {}

		virtual const std::type_info& type()
		{
			return metatableType<T>();
		}
		virtual void* get()
		{
			if (traits::is_const<T>::value)
			{
				return 0;
			}
			return const_cast<void*>(static_cast<const void*>(object_));
		}
		virtual const void* cget()
		{
			return object_;
		}
		~ObjectPointerWrapper()
		{
		}
	protected:
		T* object_;
	};

	//Customizable for ObjectPointerWrapper
	template<class T, class Enable = void>
	struct ObjectPointerWrapperType
	{
		typedef ObjectPointerWrapper<T> type;
	};

	//for internal use
	struct PointerConverter
	{
		template<typename T, typename F>
		static void* base_pointer_cast(void* from)
		{
			return static_cast<T*>(static_cast<F*>(from));
		}
		template<typename T, typename F>
		static standard::shared_ptr<void> base_shared_pointer_cast(const standard::shared_ptr<void>& from)
		{
			return standard::shared_ptr<T>(standard::static_pointer_cast<F>(from));
		}


		typedef void* (*convert_function_type)(void*);
		typedef standard::shared_ptr<void>(*shared_ptr_convert_function_type)(const standard::shared_ptr<void>&);
		typedef std::pair<std::string, std::string> convert_map_key;


		template<typename ToType, typename FromType>
		void add_type_conversion()
		{
			add_function(metatableType<ToType>(), metatableType<FromType>(), &base_pointer_cast<ToType, FromType>);
			add_function(metatableType<standard::shared_ptr<ToType> >(), metatableType<standard::shared_ptr<FromType> >(), &base_shared_pointer_cast<ToType, FromType>);
		}


		template<typename TO>
		TO* get_pointer(ObjectWrapperBase* from)const
		{
			const std::type_info& to_type = metatableType<TO>();
			//unreachable
			//if (to_type == from->type())
			//{
			//	return static_cast<TO*>(from->get());
			//}
			std::map<convert_map_key, std::vector<convert_function_type> >::const_iterator match = function_map_.find(convert_map_key(to_type.name(), from->type().name()));
			if (match != function_map_.end())
			{
				return static_cast<TO*>(pcvt_list_apply(from->get(), match->second));
			}
			return 0;

		}
		template<typename TO>
		const TO* get_const_pointer(ObjectWrapperBase* from)const
		{
			const std::type_info& to_type = metatableType<TO>();
			//unreachable
			//if (to_type == from->type())
			//{
			//	return static_cast<const TO*>(from->cget());
			//}
			std::map<convert_map_key, std::vector<convert_function_type> >::const_iterator match = function_map_.find(convert_map_key(to_type.name(), from->type().name()));
			if (match != function_map_.end())
			{
				return static_cast<const TO*>(pcvt_list_apply(const_cast<void*>(from->cget()), match->second));
			}
			return 0;
		}

		template<typename TO>
		standard::shared_ptr<TO> get_shared_pointer(ObjectSharedPointerWrapper* from)const
		{
			const std::type_info& to_type = metatableType<standard::shared_ptr<typename traits::decay<TO>::type> >();
			//unreachable
//			if (to_type == from->type())
//			{
//				return standard::static_pointer_cast<TO>(from->object());
//			}
			const std::type_info& from_type = from->shared_ptr_type();
			std::map<convert_map_key, std::vector<shared_ptr_convert_function_type> >::const_iterator match = shared_ptr_function_map_.find(convert_map_key(to_type.name(), from_type.name()));
			if (match != shared_ptr_function_map_.end())
			{
				standard::shared_ptr<void> sptr = from->object();

				if (!sptr && standard::is_const<TO>::value)
				{
					sptr = standard::const_pointer_cast<void>(from->const_object());
				}

				return standard::static_pointer_cast<TO>(pcvt_list_apply(sptr, match->second));
			}
			return standard::shared_ptr<TO>();
		}

		template<class T>
		T* get_pointer(ObjectWrapperBase* from, types::typetag<T> tag)
		{
			return get_pointer<T>(from);
		}
		template<class T>
		standard::shared_ptr<T> get_pointer(ObjectWrapperBase* from, types::typetag<standard::shared_ptr<T> > tag)
		{
			ObjectSharedPointerWrapper* ptr = dynamic_cast<ObjectSharedPointerWrapper*>(from);
			if (ptr)
			{
				return get_shared_pointer<T>(ptr);
			}
			return standard::shared_ptr<T>();
		}


		static int deleter(lua_State *state)
		{
			PointerConverter* ptr = (PointerConverter*)lua_touserdata(state, 1);
			ptr->~PointerConverter();
			return 0;
		}

		static PointerConverter& get(lua_State* state)
		{
			static char kaguya_ptrcvt_key_ptr;
			util::ScopedSavedStack save(state);
			lua_pushlightuserdata(state, &kaguya_ptrcvt_key_ptr);
			lua_rawget(state, LUA_REGISTRYINDEX);
			if (lua_isuserdata(state, -1))
			{
				return *static_cast<PointerConverter*>(lua_touserdata(state, -1));
			}
			else
			{
				void* ptr = lua_newuserdata(state, sizeof(PointerConverter));//dummy data for gc call
				PointerConverter* converter = new(ptr) PointerConverter();

				lua_createtable(state, 0, 2);
				lua_pushcclosure(state, &deleter, 0);
				lua_setfield(state, -2, "__gc");
				lua_pushvalue(state, -1);
				lua_setfield(state, -2, "__index");
				lua_setmetatable(state, -2);//set to userdata
				lua_pushlightuserdata(state, &kaguya_ptrcvt_key_ptr);
				lua_pushvalue(state, -2);
				lua_rawset(state, LUA_REGISTRYINDEX);
				return *converter;
			}
		}
	private:
		void add_function(const std::type_info& to_type, const std::type_info& from_type, convert_function_type f)
		{
			std::map<convert_map_key, std::vector<convert_function_type> > add_map;
			for (std::map<convert_map_key, std::vector<convert_function_type> >::iterator it = function_map_.begin();
				it != function_map_.end(); ++it)
			{
				if (it->first.second == to_type.name())
				{
					std::vector<convert_function_type> newlist;
					newlist.push_back(f);
					newlist.insert(newlist.end(), it->second.begin(), it->second.end());
					add_map[convert_map_key(it->first.first, from_type.name())] = newlist;
				}
			}
			function_map_.insert(add_map.begin(), add_map.end());

			std::vector<convert_function_type> flist; flist.push_back(f);
			function_map_[convert_map_key(to_type.name(), from_type.name())] = flist;
		}
		void add_function(const std::type_info& to_type, const std::type_info& from_type, shared_ptr_convert_function_type f)
		{
			std::map<convert_map_key, std::vector<shared_ptr_convert_function_type> > add_map;
			for (std::map<convert_map_key, std::vector<shared_ptr_convert_function_type> >::iterator it = shared_ptr_function_map_.begin();
				it != shared_ptr_function_map_.end(); ++it)
			{
				if (it->first.second == to_type.name())
				{
					std::vector<shared_ptr_convert_function_type> newlist;
					newlist.push_back(f);
					newlist.insert(newlist.end(), it->second.begin(), it->second.end());
					add_map[convert_map_key(it->first.first, from_type.name())] = newlist;
				}
			}
			shared_ptr_function_map_.insert(add_map.begin(), add_map.end());

			std::vector<shared_ptr_convert_function_type> flist; flist.push_back(f);
			shared_ptr_function_map_[convert_map_key(to_type.name(), from_type.name())] = flist;
		}

		void* pcvt_list_apply(void* ptr, const std::vector<convert_function_type>& flist)const
		{
			for (std::vector<convert_function_type>::const_iterator i = flist.begin(); i != flist.end(); ++i)
			{
				ptr = (*i)(ptr);
			}
			return ptr;
		}
		standard::shared_ptr<void> pcvt_list_apply(standard::shared_ptr<void> ptr, const std::vector<shared_ptr_convert_function_type>& flist)const
		{
			for (std::vector<shared_ptr_convert_function_type>::const_iterator i = flist.begin(); i != flist.end(); ++i)
			{

#if KAGUYA_USE_CPP11
				ptr = (*i)(std::move(ptr));
#else
				ptr = (*i)(ptr);
#endif
			}
			return ptr;
		}


		PointerConverter() {}

		std::map<convert_map_key, std::vector<convert_function_type> > function_map_;
		std::map<convert_map_key, std::vector<shared_ptr_convert_function_type> > shared_ptr_function_map_;



		PointerConverter(PointerConverter&);
		PointerConverter& operator=(PointerConverter&);
	};

	namespace detail
	{
		inline bool object_wrapper_type_check(lua_State* l, int index)
		{
#if KAGUYA_NO_USERDATA_TYPE_CHECK
			return lua_isuserdata(l, index) && !lua_islightuserdata(l, index);
#endif
			if (lua_getmetatable(l, index))
			{
				int type = lua_rawgetp_rtype(l, -1, metatable_name_key());
				lua_pop(l, 2);
				return type == LUA_TSTRING;
			}
			return false;
		}
	}

	inline ObjectWrapperBase* object_wrapper(lua_State* l, int index)
	{
		if (detail::object_wrapper_type_check(l, index))
		{
			ObjectWrapperBase* ptr = static_cast<ObjectWrapperBase*>(lua_touserdata(l, index));
			return ptr;
		}
		return 0;
	}

	template<typename RequireType>
	inline ObjectWrapperBase* object_wrapper(lua_State* l, int index, bool convert = true, types::typetag<RequireType> type = types::typetag<RequireType>())
	{
		if (detail::object_wrapper_type_check(l, index))
		{
			ObjectWrapperBase* ptr = static_cast<ObjectWrapperBase*>(lua_touserdata(l, index));

			if (ptr->type() == metatableType<RequireType>())
			{
				return ptr;
			}
			else if (convert)
			{
				PointerConverter& pcvt = PointerConverter::get(l);
				return pcvt.get_pointer(ptr, types::typetag<RequireType>()) ? ptr : 0;
			}
			return 0;
		}
		return 0;
	}

	template<class T>
	T* get_pointer(lua_State* l, int index, types::typetag<T> tag)
	{
		int type = lua_type(l, index);

		if (type == LUA_TLIGHTUSERDATA)
		{
			return (T*)lua_topointer(l, index);
		}
		else if (type != LUA_TUSERDATA)
		{
			return 0;
		}
		else
		{
			ObjectWrapperBase* objwrapper = object_wrapper(l, index);
			if (objwrapper)
			{
				const std::type_info& to_type = metatableType<T>();
				if (objwrapper->type() == to_type)
				{
					return static_cast<T*>(objwrapper->get());
				}
				if (objwrapper->native_type() == to_type)
				{
					return static_cast<T*>(objwrapper->native_get());
				}
				else
				{
					PointerConverter& pcvt = PointerConverter::get(l);
					return pcvt.get_pointer<T>(objwrapper);
				}
			}
		}
		return 0;
	}
	template<class T>
	const T* get_const_pointer(lua_State* l, int index, types::typetag<T> tag)
	{
		int type = lua_type(l, index);

		if (type == LUA_TLIGHTUSERDATA)
		{
			return (T*)lua_topointer(l, index);
		}
		else if (type != LUA_TUSERDATA)
		{
			return 0;
		}
		else
		{
			ObjectWrapperBase* objwrapper = object_wrapper(l, index);
			if (objwrapper)
			{
				if (objwrapper->type() == metatableType<T>())
				{
					return static_cast<const T*>(objwrapper->cget());
				}
				else
				{
					PointerConverter& pcvt = PointerConverter::get(l);
					return pcvt.get_const_pointer<T>(objwrapper);
				}
			}
		}
		return 0;
	}
	template<class T>
	const T* get_pointer(lua_State* l, int index, types::typetag<const T> tag)
	{
		return get_const_pointer<T>(l, index, types::typetag<T>());
	}

	template<class T>
	standard::shared_ptr<T> get_shared_pointer(lua_State* l, int index, types::typetag<T> tag)
	{
		ObjectSharedPointerWrapper* ptr = dynamic_cast<ObjectSharedPointerWrapper*>(object_wrapper(l, index));
		if (ptr)
		{
			const std::type_info& from_type = ptr->shared_ptr_type();
			const std::type_info& to_type = metatableType<standard::shared_ptr<typename traits::decay<T>::type> >();
			if (from_type == to_type)
			{
				if (standard::is_const<T>::value)
				{
					return standard::static_pointer_cast<T>(standard::const_pointer_cast<void>(ptr->const_object()));
				}
				else
				{
					return standard::static_pointer_cast<T>(ptr->object());
				}
			}
			PointerConverter& pcvt = PointerConverter::get(l);
			return pcvt.get_shared_pointer<T>(ptr);
		}
		return standard::shared_ptr<T>();
	}
	inline standard::shared_ptr<void> get_shared_pointer(lua_State* l, int index, types::typetag<void> tag)
	{
		ObjectSharedPointerWrapper* ptr = dynamic_cast<ObjectSharedPointerWrapper*>(object_wrapper(l, index));
		if (ptr)
		{
			return ptr->object();
		}
		return standard::shared_ptr<void>();
	}
	inline standard::shared_ptr<const void> get_shared_pointer(lua_State* l, int index, types::typetag<const void> tag)
	{
		ObjectSharedPointerWrapper* ptr = dynamic_cast<ObjectSharedPointerWrapper*>(object_wrapper(l, index));
		if (ptr)
		{
			return ptr->const_object();
		}
		return standard::shared_ptr<const void>();
	}

	namespace class_userdata
	{
		template<typename T>inline void destructor(T* pointer)
		{
			if (pointer)
			{
				pointer->~T();
			}
		}
		inline bool get_metatable(lua_State* l, const std::type_info& typeinfo)
		{
			int ttype = lua_rawgetp_rtype(l, LUA_REGISTRYINDEX, metatable_type_table_key());//get metatable registry table
			if (ttype != LUA_TTABLE)
			{
				lua_newtable(l);
				lua_rawsetp(l, LUA_REGISTRYINDEX, metatable_type_table_key());
				return false;
			}
			int type = lua_rawgetp_rtype(l, -1, &typeinfo);
			lua_remove(l, -2);//remove metatable registry table
			return type != LUA_TNIL;
		}
		template<typename T>bool get_metatable(lua_State* l)
		{
			return get_metatable(l, metatableType<T>());
		}
		template<typename T>bool available_metatable(lua_State* l)
		{
			util::ScopedSavedStack save(l);
			return get_metatable<T>(l);
		}

		inline bool newmetatable(lua_State* l, const std::type_info& typeinfo, const char* name)
		{
			if (get_metatable(l, typeinfo)) //already register
			{
				return false;  //
			}
			lua_pop(l, 1);
			lua_rawgetp_rtype(l, LUA_REGISTRYINDEX, metatable_type_table_key());//get metatable registry table
			int metaregindex = lua_absindex(l, -1);

			lua_createtable(l, 0, 2);
			lua_pushstring(l, name);
			lua_pushvalue(l, -1);
			lua_setfield(l, -3, "__name");  // metatable.__name = name
			lua_rawsetp(l, -2, metatable_name_key());
			lua_pushvalue(l, -1);
			lua_rawsetp(l, metaregindex, &typeinfo);
			lua_remove(l, metaregindex);//remove metatable registry table

			return true;
		}
		template<typename T>bool newmetatable(lua_State* l)
		{
			return newmetatable(l, metatableType<T>(), metatableName<T>());
		}


		template<typename T>inline int deleter(lua_State *state)
		{
			T* ptr = (T*)lua_touserdata(state, 1);
			ptr->~T();
			return 0;
		}
		struct UnknownType {};
		inline void setmetatable(lua_State* l, const std::type_info& typeinfo)
		{
			//if not available metatable, set unknown class metatable
			if (!get_metatable(l, typeinfo))
			{
				lua_pop(l, 1);
				if (!get_metatable<UnknownType>(l))
				{
					lua_pop(l, 1);
					newmetatable<UnknownType>(l);
					lua_pushcclosure(l, &deleter<ObjectWrapperBase>, 0);
					lua_setfield(l, -2, "__gc");
				}
			}
			lua_setmetatable(l, -2);
		}
		template<typename T>void setmetatable(lua_State* l)
		{
			setmetatable(l, metatableType<T>());
		}
		namespace detail
		{
			inline int call_constructor_metamethod(lua_State* L)
			{
				//function(t,...) return t.new(...) end
				lua_getfield(L,1,"new");
				lua_replace(L, 1);
				lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
				return lua_gettop(L);
			}
		}
		inline void get_call_constructor_metatable(lua_State* L)
		{
			static int key=0;

			int ttype = lua_rawgetp_rtype(L, LUA_REGISTRYINDEX, &key);
			if (ttype != LUA_TTABLE)
			{
				lua_pop(L,1);
				lua_createtable(L, 0, 1);
				lua_pushstring(L, "__call");
				lua_pushcfunction(L, &detail::call_constructor_metamethod);
				lua_rawset(L,-3);
				lua_pushvalue(L, -1);
				lua_rawsetp(L, LUA_REGISTRYINDEX, &key);
			}		
		}
	}
	template<typename T>
	bool available_metatable(lua_State* l, types::typetag<T> type = types::typetag<T>())
	{
		return class_userdata::available_metatable<T>(l);
	}
}

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)



namespace kaguya
{
#if KAGUYA_USE_CPP11
	namespace detail
	{
		template<std::size_t... indexes>struct index_tuple {};
		template<std::size_t first, std::size_t last, class result = index_tuple<>, bool flag = first >= last>
		struct index_range
		{
			using type = result;
		};
		template<std::size_t step, std::size_t last, std::size_t... indexes>
		struct index_range<step, last, index_tuple<indexes...>, false>
			: index_range<step + 1, last, index_tuple<indexes..., step>>
		{};

		template<std::size_t... Indexes,class... Args>
		int push_tuple(lua_State* l, index_tuple<Indexes...> index, std::tuple<Args...>&& v)
		{
			return util::push_args(l, std::get<Indexes>(v)...);
		}
	}

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for std::tuple or boost::tuple
	template<class... Args>
	struct lua_type_traits<standard::tuple<Args...> >
	{
		static int push(lua_State* l, std::tuple<Args...>&& v)
		{
			typename detail::index_range<0, sizeof...(Args)>::type index;
			return detail::push_tuple(l, index, std::forward< std::tuple<Args...> >(v));
		}
	};
#else
#define KAGUYA_PP_GET_DATA(N) standard::get<N-1>(v)
#define KAGUYA_PUSH_TUPLE_DEF(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>\
	struct lua_type_traits<standard::tuple<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)> >\
	{\
		static int push(lua_State* l, const standard::tuple<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)>& v)\
		{\
			return util::push_args(l, KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PP_GET_DATA));\
		}\
	};
	KAGUYA_PP_REPEAT_DEF(9, KAGUYA_PUSH_TUPLE_DEF)
#undef KAGUYA_PP_GET_DATA
#undef KAGUYA_PUSH_TUPLE_DEF
#endif
}


namespace kaguya
{

	//default implements
	template<typename T, typename Enable>
	bool lua_type_traits<T, Enable>::checkType(lua_State* l, int index)
	{
		return object_wrapper<T>(l, index) != 0;
	}
	template<typename T, typename Enable>
	bool lua_type_traits<T, Enable>::strictCheckType(lua_State* l, int index)
	{
		return object_wrapper<T>(l, index, false) != 0;
	}
	template<typename T, typename Enable>
	typename lua_type_traits<T, Enable>::get_type lua_type_traits<T, Enable>::get(lua_State* l, int index)
	{
		const typename traits::remove_reference<T>::type* pointer = get_const_pointer(l, index, types::typetag<typename traits::remove_reference<T>::type>());
		if (!pointer)
		{
			throw LuaTypeMismatch("type mismatch!!");
		}
		return *pointer;
	}
	template<typename T, typename Enable>
	int lua_type_traits<T, Enable>::push(lua_State* l, push_type v)
	{
		typedef ObjectWrapper<typename traits::remove_const_and_reference<T>::type> wrapper_type;
		void *storage = lua_newuserdata(l, sizeof(wrapper_type));
		new(storage) wrapper_type(v);
		class_userdata::setmetatable<T>(l);
		return 1;
	}

#if KAGUYA_USE_RVALUE_REFERENCE

	template<typename T, typename Enable>
	int lua_type_traits<T, Enable>::push(lua_State* l, NCRT&& v)
	{
		typedef ObjectWrapper<typename traits::remove_const_and_reference<T>::type> wrapper_type;
		void *storage = lua_newuserdata(l, sizeof(wrapper_type));
		new(storage) wrapper_type(std::forward<NCRT>(v));
		class_userdata::setmetatable<T>(l);
		return 1;
	}
#endif

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for const reference type
	template<typename T> struct lua_type_traits<T
		, typename traits::enable_if<traits::is_const_reference<T>::value>::type> :lua_type_traits<typename traits::remove_const_reference<T>::type > {};



	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for lvalue reference type
	template<typename REF> struct lua_type_traits < REF
		, typename traits::enable_if<traits::is_lvalue_reference<REF>::value && !traits::is_const<typename traits::remove_reference<REF>::type>::value>::type >
	{
		typedef void Registerable;

		typedef REF get_type;
		typedef REF push_type;
		typedef typename traits::remove_reference<REF>::type T;

		static bool strictCheckType(lua_State* l, int index)
		{
			return object_wrapper<T>(l, index, false) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			if (lua_type(l, index) == LUA_TLIGHTUSERDATA)
			{
				return true;
			}
			return object_wrapper<T>(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			T* pointer = get_pointer(l, index, types::typetag<T>());
			if (!pointer)
			{
				throw LuaTypeMismatch("type mismatch!!");
			}
			return *pointer;
		}
		static int push(lua_State* l, push_type v)
		{
			if (!available_metatable<T>(l))
			{
				lua_pushlightuserdata(l, const_cast<typename traits::remove_const<T>::type*>(&v));
			}
			else
			{
				typedef typename ObjectPointerWrapperType<T>::type wrapper_type;
				void *storage = lua_newuserdata(l, sizeof(wrapper_type));
				new(storage) wrapper_type(&v);
				class_userdata::setmetatable<T>(l);
			}
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for pointer type
	template<typename PTR> struct lua_type_traits < PTR
		, typename traits::enable_if<traits::is_pointer<typename traits::remove_const_reference<PTR>::type>::value && !traits::is_function<typename traits::remove_pointer<PTR>::type>::value>::type >
	{
		typedef void Registerable;

		typedef PTR get_type;
		typedef PTR push_type;
		typedef typename traits::remove_pointer<PTR>::type T;

		static bool strictCheckType(lua_State* l, int index)
		{
			return object_wrapper<T>(l, index, false) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			int type = lua_type(l, index);
			if (type == LUA_TLIGHTUSERDATA
				|| type == LUA_TNIL
				|| type == LUA_TNONE)
			{
				return true;
			}
			return object_wrapper<T>(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			int type = lua_type(l, index);
			if (type == LUA_TUSERDATA || type == LUA_TLIGHTUSERDATA)
			{
				return get_pointer(l, index, types::typetag<T>());
			}

			if (type == LUA_TNIL
				|| type == LUA_TNONE)
			{
				return 0;
			}
			throw LuaTypeMismatch("type mismatch!!");
			return 0;
		}
		static int push(lua_State* l, push_type v)
		{
			if (!v)
			{
				lua_pushnil(l);
			}
			else if (!available_metatable<T>(l))
			{
				lua_pushlightuserdata(l, const_cast<typename traits::remove_const<T>::type*>(v));
			}
			else
			{
				typedef typename ObjectPointerWrapperType<T>::type wrapper_type;
				void *storage = lua_newuserdata(l, sizeof(wrapper_type));
				new(storage) wrapper_type(v);
				class_userdata::setmetatable<T>(l);
			}
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for bool
	template<>	struct lua_type_traits<bool> {
		typedef bool get_type;
		typedef bool push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TBOOLEAN;
		}
		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static bool get(lua_State* l, int index)
		{
			return l && lua_toboolean(l, index) != 0;
		}
		static int push(lua_State* l, bool s)
		{
			lua_pushboolean(l, s);
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for void
	template<>	struct lua_type_traits<void> {
		typedef void* get_type;
		typedef void* push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return true;
		}
		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static get_type get(lua_State* l, int index)
		{
			return 0;
		}
		static int push(lua_State* l, push_type s)
		{
			return 0;
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for reference_wrapper
	template<typename T> struct lua_type_traits<standard::reference_wrapper<T> > {
		typedef const standard::reference_wrapper<T>& push_type;

		static int push(lua_State* l, push_type v)
		{
			return util::push_args(l, &v.get());
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for optional
	template<typename T> struct lua_type_traits<optional<T> > {
		typedef const optional<T>& push_type;
		typedef optional<T> get_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type_traits<T>::strictCheckType(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static get_type get(lua_State* l, int index)KAGUYA_NOEXCEPT
		{
			try
			{
				return lua_type_traits<T>::get(l, index);
			}
			catch (...)
			{
				return get_type();
			}
		}

		static int push(lua_State* l, push_type v)KAGUYA_NOEXCEPT
		{
			if (v)
			{
				return util::push_args(l, v.value());
			}
			else
			{
				lua_pushnil(l);
			}
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for shared_ptr
	template<typename T> struct lua_type_traits<standard::shared_ptr<T> > {
		typedef const standard::shared_ptr<T>& push_type;
		typedef standard::shared_ptr<T> get_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			ObjectSharedPointerWrapper* wrapper = dynamic_cast<ObjectSharedPointerWrapper*>(object_wrapper(l, index));
			const std::type_info& type = metatableType<standard::shared_ptr<typename traits::decay<T>::type > >();
			return wrapper && (wrapper->shared_ptr_type() == type);
		}
		static bool checkType(lua_State* l, int index)
		{
			return get_shared_pointer(l, index, types::typetag<T>()) ||	lua_isnil(l, index);
		}
		static get_type get(lua_State* l, int index)
		{
			if (lua_isnil(l, index)) {
				return get_type();
			}
			return get_shared_pointer(l, index, types::typetag<T>());
		}

		static int push(lua_State* l, push_type v)
		{
			if (v)
			{
				typedef ObjectSharedPointerWrapper wrapper_type;
				void *storage = lua_newuserdata(l, sizeof(wrapper_type));
				new(storage) wrapper_type(v);
				class_userdata::setmetatable<T>(l);
			}
			else
			{
				lua_pushnil(l);
			}
			return 1;
		}
	};
#if KAGUYA_USE_CPP11
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for unique_ptr
	template<typename T, typename Deleter> struct lua_type_traits<std::unique_ptr<T, Deleter> > {
		typedef std::unique_ptr<T, Deleter>&& push_type;
		typedef std::unique_ptr<T, Deleter>& get_type;
		typedef std::unique_ptr<T, Deleter> type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return object_wrapper<type>(l, index,  false) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			return object_wrapper<type>(l, index) != 0 ||
				lua_isnil(l, index);
		}
		static get_type get(lua_State* l, int index)
		{
			type* pointer = get_pointer(l, index, types::typetag<type>());
			if (!pointer)
			{
				throw LuaTypeMismatch("type mismatch!!");
			}
			return *pointer;
		}

		static int push(lua_State* l, push_type v)
		{
			if (v)
			{
				typedef ObjectSmartPointerWrapper<type> wrapper_type;
				void *storage = lua_newuserdata(l, sizeof(wrapper_type));
				new(storage) wrapper_type(std::forward<push_type>(v));
				class_userdata::setmetatable<T>(l);
			}
			else
			{
				lua_pushnil(l);
			}
			return 1;
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for nullptr
	template<>	struct lua_type_traits<std::nullptr_t> {
		typedef const std::nullptr_t& push_type;
		typedef std::nullptr_t get_type;

		static bool checkType(lua_State* l, int index)
		{
			return lua_isnoneornil(l, index);
		}
		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_isnil(l, index);
		}
		static get_type get(lua_State* l, int index)
		{
			if (!lua_isnoneornil(l, index)) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return nullptr;
		}

		static int push(lua_State* l, const std::nullptr_t& v)
		{
			lua_pushnil(l);
			return 1;
		}
	};
#endif

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for ObjectWrapperBase*
	template<>	struct lua_type_traits<ObjectWrapperBase*> {
		typedef ObjectWrapperBase* get_type;
		typedef ObjectWrapperBase* push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return object_wrapper(l, index) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			return object_wrapper(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			return object_wrapper(l, index);
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for native type of luathread(lua_State*)
	template<>	struct lua_type_traits<lua_State*> {
		typedef lua_State* get_type;
		typedef lua_State* push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_isthread(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isthread(l, index);
		}
		static lua_State* get(lua_State* l, int index)
		{
			return lua_tothread(l, index);
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for floating point number value
	template<typename T> struct lua_type_traits < T
		, typename traits::enable_if<traits::is_floating_point<T>::value>::type >
	{
		typedef typename traits::remove_const_reference<T>::type get_type;
		typedef lua_Number push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TNUMBER;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isnumber(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			int isnum=0;
			get_type num = static_cast<T>(lua_tonumberx(l,index,&isnum));
			if (!isnum) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return num;
		}
		static int push(lua_State* l, lua_Number s)
		{
			lua_pushnumber(l, s);
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for integral number value
	template<typename T> struct lua_type_traits<T
		, typename traits::enable_if<traits::is_integral<T>::value>::type>
	{
		typedef typename traits::remove_const_reference<T>::type get_type;
#if LUA_VERSION_NUM >= 503
		typedef lua_Integer push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_isinteger(l, index) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isnumber(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			int isnum = 0;
			get_type num = static_cast<T>(lua_tointegerx(l, index, &isnum));
			if (!isnum) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return num;
		}
		static int push(lua_State* l, lua_Integer s)
		{
			lua_pushinteger(l, s);
			return 1;
		}
#else
		typedef typename lua_type_traits<lua_Number>::push_type push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type_traits<lua_Number>::strictCheckType(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_type_traits<lua_Number>::checkType(l, index);
		}
		static get_type get(lua_State* l, int index)
		{
			return static_cast<get_type>(lua_type_traits<lua_Number>::get(l, index));
		}
		static int push(lua_State* l, push_type s)
		{
			return util::push_args(l, s);
		}
#endif
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for enum
	template<typename T> struct lua_type_traits<T
		, typename traits::enable_if<traits::is_enum<T>::value>::type>
	{
		typedef typename traits::remove_const_reference<T>::type get_type;
		typedef typename traits::remove_const_reference<T>::type push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type_traits<luaInt>::strictCheckType(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_type_traits<luaInt>::checkType(l, index);
		}
		static get_type get(lua_State* l, int index)
		{
			return static_cast<get_type>(lua_type_traits<luaInt>::get(l, index));
		}
		static int push(lua_State* l, push_type s)
		{
			return util::push_args(l, static_cast<typename lua_type_traits<int64_t>::push_type>(s));
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for cstring
	template<>	struct lua_type_traits<const char*> {
		typedef std::string get_type;
		typedef const char* push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TSTRING;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isstring(l, index) != 0;
		}
		static const char* get(lua_State* l, int index)
		{
			const char* buffer = lua_tostring(l, index);
			if (!buffer) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return buffer;
		}
		static int push(lua_State* l, const char* s)
		{
			lua_pushstring(l, s);
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for cstring
	template<int N>	struct lua_type_traits<char[N]> {
		typedef std::string get_type;
		typedef const char* push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TSTRING;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isstring(l, index) != 0;
		}
		static const char* get(lua_State* l, int index)
		{
			const char* buffer = lua_tostring(l, index);
			if (!buffer) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return buffer;
		}
		static int push(lua_State* l, const char s[N])
		{
			lua_pushlstring(l, s, s[N - 1] != '\0' ? N : N - 1);
			return 1;
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for cstring
	template<int N>	struct lua_type_traits<const char[N]> :lua_type_traits<char[N]> {};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for std::string
	template<>	struct lua_type_traits<std::string> {
		typedef std::string get_type;
		typedef const std::string& push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TSTRING;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isstring(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			size_t size = 0;
			const char* buffer = lua_tolstring(l, index, &size);
			if (!buffer) {
				throw LuaTypeMismatch("type mismatch!!");
			}
			return std::string(buffer, size);
		}
		static int push(lua_State* l, const std::string& s)
		{
			lua_pushlstring(l, s.c_str(), s.size());
			return 1;
		}
	};


	struct NewTable {
		NewTable() :reserve_array_(0), reserve_record_(0) {}
		NewTable(int reserve_array, int reserve_record_) :reserve_array_(reserve_array), reserve_record_(reserve_record_) {}
		int reserve_array_;
		int reserve_record_;
	};
	struct NewThread {};
	struct GlobalTable {};
	struct NilValue {};

	struct NoTypeCheck {};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for NewTable, push only
	template<>	struct lua_type_traits<NewTable> {
		static int push(lua_State* l, const NewTable& table)
		{
			lua_createtable(l, table.reserve_array_, table.reserve_record_);
			return 1;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for NewThread, push only
	template<>	struct lua_type_traits<NewThread> {
		static int push(lua_State* l, const NewThread&)
		{
			lua_newthread(l);
			return 1;
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for NilValue, push only
	/// If you using C++11, recommend use nullptr instead.
	template<>	struct lua_type_traits<NilValue> {
		static int push(lua_State* l, const NilValue&)
		{
			lua_pushnil(l);
			return 1;
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for GlobalTable, push only
	template<>	struct lua_type_traits<GlobalTable> {
		static int push(lua_State* l, const GlobalTable&)
		{
			lua_pushglobaltable(l);
			return 1;
		}
	};


	namespace detail
	{
		template<typename Derived>
		class LuaBasicTypeFunctions
		{
			template<class Other> friend class LuaBasicTypeFunctions;
			typedef void (LuaBasicTypeFunctions::*bool_type)() const;
			void this_type_does_not_support_comparisons() const {}

		public:
			enum value_type
			{
				TYPE_NONE = LUA_TNONE,//!< none type
				TYPE_NIL = LUA_TNIL,//!< nil type
				TYPE_BOOLEAN = LUA_TBOOLEAN,//!< boolean type
				TYPE_LIGHTUSERDATA = LUA_TLIGHTUSERDATA,//!< light userdata type
				TYPE_NUMBER = LUA_TNUMBER,//!< number type
				TYPE_STRING = LUA_TSTRING,//!< string type
				TYPE_TABLE = LUA_TTABLE,//!< table type
				TYPE_FUNCTION = LUA_TFUNCTION,//!< function type
				TYPE_USERDATA = LUA_TUSERDATA,//!< userdata type
				TYPE_THREAD = LUA_TTHREAD//!< thread(coroutine) type
			};

			/// @brief If reference value is none or nil return true. Otherwise false.
			bool isNilref_()const {
				int t = type();
				return t == LUA_TNIL || t == LUA_TNONE;
			}

			/// @brief Equivalent to `#` operator for strings and tables with no metamethods.
			/// Follows Lua's reference manual documentation of `lua_rawlen`, ie. types other
			/// than tables, strings or userdatas return 0.
			/// @return Size of table, string length or userdata memory block size.
			size_t size() const {
				lua_State* state = state_();
				if (!state) { return 0; }
				util::ScopedSavedStack save(state);
				int index = pushStackIndex_(state);

				return lua_rawlen(state, index);
			}

			//return type
			int type() const
			{
				lua_State* state = state_();
				if (!state)
				{
					return LUA_TNONE;
				}
				util::ScopedSavedStack save(state);
				return lua_type(state, pushStackIndex_(state));
			}

			//return type name
			const char* typeName()const
			{
				return lua_typename(state_(), type());
			}


			template<typename T>typename lua_type_traits<T>::get_type get()const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				return lua_type_traits<T>::get(state, state ? pushStackIndex_(state) : 0);
			}
			template<typename T,typename U>typename lua_type_traits<T>::get_type value_or(U v)const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				return lua_type_traits<optional<T> >::get(state, state ? pushStackIndex_(state) : 0).value_or(v);
			}

			//deprecated. use get<kaguya::optional<T> >() instead;
			template<typename T>
			typename lua_type_traits<T>::get_type get(bool& was_valid, bool allow_convertible = true)const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int stackindex = pushStackIndex_(state);
				if (allow_convertible)
				{
					was_valid = lua_type_traits<T>::checkType(state, stackindex);
				}
				else
				{
					was_valid = lua_type_traits<T>::strictCheckType(state, stackindex);
				}
				if (was_valid)
				{
					return lua_type_traits<T>::get(state, stackindex);
				}
				else
				{
					return T();
				}
			}
			template<typename T>
			operator T()const
			{
				return get<T>();
			}

			operator bool_type() const
			{
				return (!isNilref_() && get<bool>() == true) ? &LuaBasicTypeFunctions::this_type_does_not_support_comparisons : 0;
			}


			/**
			* @name relational operators
			* @brief
			*/
			//@{
			template<typename OtherDrived>
			inline bool operator==(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				if (isNilref_() || rhs.isNilref_()) { return !isNilref_() == !rhs.isNilref_(); }
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int index = pushStackIndex_(state);
				int rhsindex = rhs.pushStackIndex_(state);
				return lua_compare(state, index, rhsindex, LUA_OPEQ) != 0;
			}
			template<typename OtherDrived>
			inline bool operator<(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				if (isNilref_() || rhs.isNilref_()) { return !isNilref_() != !rhs.isNilref_(); }
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int index = pushStackIndex_(state);
				int rhsindex = rhs.pushStackIndex_(state);
				return lua_compare(state, index, rhsindex, LUA_OPLT) != 0;
			}
			template<typename OtherDrived>
			inline bool operator<=(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				if (isNilref_() || rhs.isNilref_()) { return !isNilref_() == !rhs.isNilref_(); }
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int index = pushStackIndex_(state);
				int rhsindex = rhs.pushStackIndex_(state);
				return lua_compare(state, index, rhsindex, LUA_OPLE) != 0;
			}
			template<typename OtherDrived>
			inline bool operator>=(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				return rhs <= (*this);
			}
			template<typename OtherDrived>
			inline bool operator>(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				return rhs < (*this);
			}
			template<typename OtherDrived>
			inline bool operator!=(const LuaBasicTypeFunctions<OtherDrived>& rhs)const
			{
				return !this->operator==(rhs);
			}

			template<typename T>
			inline typename traits::enable_if<!traits::is_convertible<T*, LuaBasicTypeFunctions<T>*>::value, bool>::type operator==(const T& rhs)const
			{
				if (optional<typename lua_type_traits<T>::get_type> d = checkGet_<T>())
				{
					return *d == rhs;
				}
				return false;
			}
			template<typename T>
			inline typename traits::enable_if<!traits::is_convertible<T*, LuaBasicTypeFunctions<T>*>::value, bool>::type operator!=(const T& rhs)const
			{
				return !((*this) == rhs);
			}
			//@}

			void dump(std::ostream& os)const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::stackValueDump(os, state, stackIndex);
			}
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}
			template<typename T>
			optional<typename lua_type_traits<T>::get_type> checkGet_()const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				int stackindex = pushStackIndex_(state);
				return lua_type_traits<optional<typename lua_type_traits<T>::get_type> >::get(state, stackindex);
			}
		};
		template<typename D>
		inline std::ostream& operator<<(std::ostream& os, const LuaBasicTypeFunctions<D>& ref)
		{
			ref.dump(os);
			return os;
		}
		/**
		* @name relational operators
		* @brief
		*/
		//@{

#define KAGUYA_ENABLE_IF_NOT_LUAREF(RETTYPE) typename traits::enable_if<!traits::is_convertible<T*, LuaBasicTypeFunctions<T>*>::value, RETTYPE>::type
		template<typename D, typename T>
		inline KAGUYA_ENABLE_IF_NOT_LUAREF(bool) operator == (const T& lhs, const LuaBasicTypeFunctions<D>& rhs)
		{
			return rhs == lhs;
		}
		template<typename D, typename T>
		inline KAGUYA_ENABLE_IF_NOT_LUAREF(bool) operator != (const T& lhs, const LuaBasicTypeFunctions<D>& rhs)
		{
			return !(rhs == lhs);
		}
#undef KAGUYA_ENABLE_IF_NOT_LUAREF
		//@}
	}


}

namespace kaguya
{

	inline const char* get_error_message(lua_State *state)
	{
		if (lua_type(state, -1) == LUA_TSTRING)
		{
			const char* message = lua_tostring(state, -1);
			return message ? message : "unknown error";
		}
		else
		{
			return "unknown error";
		}
	}
	inline int lua_pcall_wrap(lua_State* state, int argnum, int retnum)
	{
		int result = lua_pcall(state, argnum, retnum, 0);
		return result;
	}

	struct ErrorHandler
	{
		typedef standard::function<void(int, const char*)> function_type;


		static bool handle(const char* message, lua_State *state)
		{
			function_type handler = getHandler(state);
			if (handler)
			{
				handler(0, message);
				return true;
			}
			return false;
		}
		static bool handle(int status_code, const char* message, lua_State *state)
		{
			function_type handler = getHandler(state);
			if (handler)
			{
				handler(status_code, message);
				return true;
			}
			return false;
		}
		static bool handle(int status_code, lua_State *state)
		{
			function_type handler = getHandler(state);
			if (handler)
			{
				handler(status_code, get_error_message(state));
				return true;
			}
			return false;
		}

		static function_type getHandler(lua_State* state)
		{
			function_type* funptr = getFunctionPointer(state);
			if (funptr)
			{
				return *funptr;
			}
			return function_type();
		}


		static void unregisterHandler(lua_State* state)
		{
			if (state)
			{
				function_type* funptr = getFunctionPointer(state);
				if (funptr)
				{
					*funptr = function_type();
				}
			}
		}
		static void registerHandler(lua_State* state, function_type f)
		{
			if (state)
			{
				function_type* funptr = getFunctionPointer(state);
				if (!funptr)
				{
					util::ScopedSavedStack save(state);
					lua_pushlightuserdata(state, handlerRegistryKey());
					void* ptr = lua_newuserdata(state, sizeof(function_type));//dummy data for gc call
					funptr = new(ptr) function_type();

					//create function_type metatable
					lua_newtable(state);
					lua_pushcclosure(state, &error_handler_cleanner, 0);
					lua_setfield(state, -2, "__gc");
					lua_pushvalue(state, -1);
					lua_setfield(state, -1, "__index");
					lua_setmetatable(state, -2);

					lua_rawset(state, LUA_REGISTRYINDEX);
				}
				*funptr = f;
			}
		}
		
		static void throwDefaultError(int status, const char* message=0)
		{
			switch (status)
			{
			case LUA_ERRSYNTAX:
				throw LuaSyntaxError(status, message ? std::string(message) : "unknown syntax error");
			case LUA_ERRRUN:
				throw LuaRuntimeError(status, message ? std::string(message) : "unknown runtime error");
			case LUA_ERRMEM:
				throw LuaMemoryError(status, message ? std::string(message) : "lua memory allocation error");
			case LUA_ERRERR:
				throw LuaErrorRunningError(status, message ? std::string(message) : "unknown error running error");
#if LUA_VERSION_NUM >= 502
			case LUA_ERRGCMM:
				throw LuaGCError(status, message ? std::string(message) : "unknown gc error");
#endif
			default:
				throw LuaUnknownError(status, message ? std::string(message) : "lua unknown error");
			}
		}
	private:

		static void* handlerRegistryKey()
		{
			static void* key;
			return key;
		}
		static function_type* getFunctionPointer(lua_State* state)
		{
			if (state)
			{
				util::ScopedSavedStack save(state);
				lua_pushlightuserdata(state, handlerRegistryKey());
				lua_rawget(state, LUA_REGISTRYINDEX);
				function_type* ptr = (function_type*)lua_touserdata(state, -1);
				return ptr;
			}
			return 0;
		}

		ErrorHandler() {}

		ErrorHandler(const ErrorHandler&);
		ErrorHandler& operator=(const ErrorHandler&);

		static int error_handler_cleanner(lua_State *state)
		{
			function_type* ptr = (function_type*)lua_touserdata(state, 1);
			ptr->~function_type();
			return 0;
		}
	};

	namespace except
	{
		inline void OtherError(lua_State *state, const std::string& message)
		{
			if (ErrorHandler::handle(message.c_str(), state))
			{
				return;
			}
		}
		inline void typeMismatchError(lua_State *state, const std::string& message)
		{
			if(ErrorHandler::handle(message.c_str(), state))
			{
				return;
			}
		}
		inline void memoryError(lua_State *state, const char* message)
		{
			if (ErrorHandler::handle(message, state))
			{
				return;
			}
		}
		inline bool checkErrorAndThrow(int status, lua_State *state)
		{
			if (status != 0 && status != LUA_YIELD)
			{
				if (ErrorHandler::handle(status, state))
				{
					return false;
				}
				return false;
			}
			return true;
		}
	}
}

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <ostream>


namespace kaguya
{
	/// @brief StackTop tag type
	struct StackTop {};

	namespace Ref
	{
		/// @brief NoMainCheck tag type
		struct NoMainCheck {};

		/// @brief reference to Lua stack value
		class StackRef
		{
		protected:
			lua_State *state_;
			int stack_index_;
			mutable bool pop_;
#if KAGUYA_USE_CPP11
			StackRef(StackRef&& src) :state_(src.state_), stack_index_(src.stack_index_), pop_(src.pop_)
			{
				src.pop_ = false;
			}
			StackRef& operator=(StackRef&& src)
			{
				state_ = src.state_;
				stack_index_ = src.stack_index_;
				pop_ = src.pop_;

				src.pop_ = false;
				return *this;
			}

			StackRef(const StackRef&src) = delete;
			StackRef& operator=(const StackRef&src) = delete;
#else
			StackRef(const StackRef&src) : state_(src.state_), stack_index_(src.stack_index_), pop_(src.pop_)
			{
				src.pop_ = false;
			}
			StackRef& operator=(const StackRef& src)
			{
				if (this != &src)
				{
					state_ = src.state_;
					stack_index_ = src.stack_index_;
					pop_ = src.pop_;

					src.pop_ = false;
				}
				return *this;
			}
#endif
			StackRef(lua_State* s, int index) :state_(s), stack_index_(lua_absindex(s, index)), pop_(true)
			{
			}
			StackRef(lua_State* s, int index, bool pop) :state_(s), stack_index_(lua_absindex(s, index)), pop_(pop)
			{
			}
			StackRef() :state_(0), stack_index_(0), pop_(false)
			{
			}
			~StackRef()
			{
				if (state_ && pop_)
				{
					if (lua_gettop(state_) >= stack_index_ )
					{
						lua_settop(state_, stack_index_ - 1);
					}
				}
			}
		public:


			bool isNilref()const { return state_ == 0 || lua_type(state_, stack_index_) == LUA_TNIL; }

			int push()const
			{
				lua_pushvalue(state_, stack_index_);
				return 1;
			}
			int push(lua_State* state)const
			{
				lua_pushvalue(state_, stack_index_);
				if (state_ != state)
				{
					lua_pushvalue(state_, stack_index_);
					lua_xmove(state_, state, 1);
				}
				return 1;
			}

			int pushStackIndex(lua_State* state)const
			{
				if (state_ != state)
				{
					lua_pushvalue(state_, stack_index_);
					lua_xmove(state_, state, 1);
					return lua_gettop(state);
				}
				else
				{
					return stack_index_;
				}
			}
			lua_State *state()const { return state_; }
		};

		/// @brief Reference to Lua value. Retain reference by LUA_REGISTRYINDEX
		class RegistoryRef
		{
			typedef void (RegistoryRef::*bool_type)() const;
			void this_type_does_not_support_comparisons() const {}


		public:

			RegistoryRef(const RegistoryRef& src) :state_(src.state_)
			{
				if (!src.isNilref())
				{
					src.push(state_);
					ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
				}
				else
				{
					ref_ = LUA_REFNIL;
				}
			}
			RegistoryRef& operator =(const RegistoryRef& src)
			{
				if (this != &src)
				{
					unref();
					state_ = src.state_;
					if (!src.isNilref())
					{
						src.push(state_);
						ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
					}
					else
					{
						ref_ = LUA_REFNIL;
					}
				}
				return *this;
			}
#if KAGUYA_USE_RVALUE_REFERENCE
			RegistoryRef(RegistoryRef&& src)throw() :state_(0), ref_(LUA_REFNIL)
			{
				swap(src);
			}
			RegistoryRef& operator =(RegistoryRef&& src)throw()
			{
				swap(src);
				return *this;
			}
#endif

			RegistoryRef() :state_(0), ref_(LUA_REFNIL) {}
			RegistoryRef(lua_State* state) :state_(state), ref_(LUA_REFNIL) {}


			RegistoryRef(lua_State* state, StackTop, NoMainCheck) :state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
			}

			RegistoryRef(lua_State* state, StackTop) :state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
				state_ = util::toMainThread(state_);
			}

			void swap(RegistoryRef& other)throw()
			{
				std::swap(state_, other.state_);
				std::swap(ref_, other.ref_);
			}

			template<typename T>
			RegistoryRef(lua_State* state, const T& v, NoMainCheck) : state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				util::ScopedSavedStack save(state_);
				util::one_push(state_, v);
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
			}
			template<typename T>
			RegistoryRef(lua_State* state, const T& v) : state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				util::ScopedSavedStack save(state_);
				util::one_push(state_, v);
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
				state_ = util::toMainThread(state_);
			}
#if KAGUYA_USE_CPP11
			template<typename T>
			RegistoryRef(lua_State* state, T&& v, NoMainCheck) : state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				util::ScopedSavedStack save(state_);
				util::one_push(state_, standard::forward<T>(v));
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
			}
			template<typename T>
			RegistoryRef(lua_State* state, T&& v) : state_(state), ref_(LUA_REFNIL)
			{
				if (!state_) { return; }
				util::ScopedSavedStack save(state_);
				util::one_push(state_, standard::forward<T>(v));
				ref_ = luaL_ref(state_, LUA_REGISTRYINDEX);
				state_ = util::toMainThread(state_);
			}
#endif
			~RegistoryRef()
			{
				try
				{
					unref();
				}
				catch (...) {}//can't throw at Destructor
			}

			/// @brief push to Lua stack
			int push()const
			{
				return push(state_);
			}
			/// @brief push to Lua stack
			int push(lua_State* state)const
			{
				if (isNilref())
				{
					lua_pushnil(state);
					return 1;
				}
#if LUA_VERSION_NUM >= 502
				if (state != state_)
				{//state check
					assert(util::toMainThread(state) == util::toMainThread(state_));
				}
#endif
				lua_rawgeti(state, LUA_REGISTRYINDEX, ref_);
				return 1;
			}

			int pushStackIndex(lua_State* state)const
			{
				push(state);
				return lua_gettop(state);
			}
			lua_State *state()const { return state_; }

			bool isNilref()const { return state_ == 0 || ref_ == LUA_REFNIL; }

		protected:
			lua_State *state_;
			int ref_;


			void unref()
			{
				if (!isNilref())
				{
					luaL_unref(state_, LUA_REGISTRYINDEX, ref_);
					ref_ = LUA_REFNIL;
				}
			}
		};

	}
}
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <ostream>


namespace kaguya
{
	class LuaTable;

	class FunctionResults;

	/**
	* status of coroutine
	*/
	enum coroutine_status
	{
		COSTAT_RUNNING,//!< coroutine is running
		COSTAT_SUSPENDED,//!< coroutine is suspended
		COSTAT_NORMAL,//!<
		COSTAT_DEAD//!< coroutine is dead
	};

	namespace detail
	{
		class FunctionResultProxy
		{
		public:
			template<typename RetType>
			static RetType ReturnValue(lua_State* state, int restatus, int retindex, types::typetag<RetType> tag);
			static FunctionResults ReturnValue(lua_State* state, int restatus, int retindex, types::typetag<FunctionResults> tag);
			static void ReturnValue(lua_State* state, int restatus, int retindex, types::typetag<void> tag);
		};



		template<typename Derived>
		class LuaFunctionImpl
		{
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}
			int push_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->push(state);
			}

		public:
			/**
			* set function environment table
			*/
			bool setFunctionEnv(const LuaTable& env);
			/**
			* set function environment to new table
			*/
			bool setFunctionEnv(NewTable env);
			/**
			* get function environment table
			*/
			LuaTable getFunctionEnv()const;

#if KAGUYA_USE_CPP11
			template<class Result, class...Args> Result call(Args&&... args)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return Result();
				}
				int argstart = lua_gettop(state) + 1;
				push_(state);
				int argnum = util::push_args(state, std::forward<Args>(args)...);
				int result = lua_pcall_wrap(state, argnum, LUA_MULTRET);
				except::checkErrorAndThrow(result, state);
				return detail::FunctionResultProxy::ReturnValue(state, result, argstart, types::typetag<Result>());
			}

			template<class...Args> FunctionResults operator()(Args&&... args);
#else

#define KAGUYA_PP_TEMPLATE(N) ,KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_PUSH_ARG_DEF(N) ,KAGUYA_PP_CAT(a,N)
#define KAGUYA_CALL_DEF(N) \
		template<class Result KAGUYA_PP_REPEAT(N,KAGUYA_PP_TEMPLATE)>\
		Result call(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			lua_State* state = state_();\
			if (!state)\
			{\
				except::typeMismatchError(state, "is nil");\
				return Result();\
			}\
			int argstart = lua_gettop(state) + 1;\
			push_(state);\
			int argnum = util::push_args(state KAGUYA_PP_REPEAT(N,KAGUYA_PUSH_ARG_DEF));\
			int result = lua_pcall_wrap(state, argnum, LUA_MULTRET);\
			except::checkErrorAndThrow(result, state);\
			return detail::FunctionResultProxy::ReturnValue(state,result, argstart, types::typetag<Result>());\
		}


			KAGUYA_CALL_DEF(0)
				KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_DEF)


#undef KAGUYA_PUSH_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_RESUME_DEF

#define KAGUYA_TEMPLATE_PARAMETER(N)
#define KAGUYA_FUNCTION_ARGS_DEF(N)
#define KAGUYA_CALL_ARGS(N)

#define KAGUYA_OP_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults operator()(KAGUYA_FUNCTION_ARGS_DEF(N));

				KAGUYA_OP_FN_DEF(0)

#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_CALL_ARGS
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>
#define KAGUYA_FUNCTION_ARGS_DEF(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG)
#define KAGUYA_CALL_ARGS(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PUSH_ARG_DEF)

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PUSH_ARG_DEF(N) KAGUYA_PP_CAT(a,N) 

				KAGUYA_PP_REPEAT_DEF(9, KAGUYA_OP_FN_DEF)
#undef KAGUYA_OP_FN_DEF
#undef KAGUYA_TEMPLATE_PARAMETER

#undef KAGUYA_CALL_ARGS
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_CALL_DEF
#undef KAGUYA_OP_FN_DEF
#endif


		};


		template<typename Derived>
		class LuaThreadImpl
		{
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}

		public:
#if KAGUYA_USE_CPP11
			template<class Result, class...Args> Result resume(Args&&... args)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return Result();
				}
				util::ScopedSavedStack save(state);
				int corStackIndex = pushStackIndex_(state);
				lua_State* thread = lua_type_traits<lua_State*>::get(state, corStackIndex);
				int argstart = 1;//exist function in stack at first resume.
				if (lua_status(thread) == LUA_YIELD)
				{
					argstart = 0;
				}
				util::push_args(thread, std::forward<Args>(args)...);
				int argnum = lua_gettop(thread) - argstart;
				if (argnum < 0) { argnum = 0; }
				int result = lua_resume(thread, state, argnum);
				except::checkErrorAndThrow(result, thread);
				return detail::FunctionResultProxy::ReturnValue(thread, result, 1, types::typetag<Result>());
			}
			template<class...Args> FunctionResults operator()(Args&&... args);
#else


#define KAGUYA_PP_TEMPLATE(N) ,KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_PUSH_ARG_DEF(N) ,KAGUYA_PP_CAT(a,N)

#define KAGUYA_RESUME_DEF(N) \
		template<class Result  KAGUYA_PP_REPEAT(N,KAGUYA_PP_TEMPLATE)>\
		Result resume(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			lua_State* state = state_();\
			if (!state)\
			{\
				except::typeMismatchError(state, "is nil");\
				return Result();\
			}\
			util::ScopedSavedStack save(state);\
			int corStackIndex = pushStackIndex_(state);\
			lua_State* thread = lua_type_traits<lua_State*>::get(state, corStackIndex);\
			int argstart = 1;\
			if (lua_status(thread) == LUA_YIELD)\
			{\
				argstart = 0;\
			}\
			util::push_args(thread KAGUYA_PP_REPEAT(N, KAGUYA_PUSH_ARG_DEF));\
			int argnum = lua_gettop(thread) - argstart;\
			if (argnum < 0) { argnum = 0; }\
			int result = lua_resume(thread, state, argnum);\
			except::checkErrorAndThrow(result, thread);\
			return detail::FunctionResultProxy::ReturnValue(thread,result, 1, types::typetag<Result>());\
		}

			KAGUYA_RESUME_DEF(0)
				KAGUYA_PP_REPEAT_DEF(9, KAGUYA_RESUME_DEF)

#undef KAGUYA_PUSH_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_RESUME_DEF

#define KAGUYA_TEMPLATE_PARAMETER(N)
#define KAGUYA_FUNCTION_ARGS_DEF(N)
#define KAGUYA_CALL_ARGS(N)

#define KAGUYA_OP_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults operator()(KAGUYA_FUNCTION_ARGS_DEF(N));

				KAGUYA_OP_FN_DEF(0)

#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_CALL_ARGS
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>
#define KAGUYA_FUNCTION_ARGS_DEF(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG)
#define KAGUYA_CALL_ARGS(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PUSH_ARG_DEF)

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PUSH_ARG_DEF(N) KAGUYA_PP_CAT(a,N) 

				KAGUYA_PP_REPEAT_DEF(9, KAGUYA_OP_FN_DEF)
#undef KAGUYA_OP_FN_DEF
#undef KAGUYA_TEMPLATE_PARAMETER

#undef KAGUYA_CALL_ARGS
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_CALL_DEF
#undef KAGUYA_OP_FN_DEF
#endif


		/**
		* @return state status
		*/
				int threadStatus()const
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return LUA_ERRRUN;
				}
				util::ScopedSavedStack save(state);
				int corStackIndex = pushStackIndex_(state);
				lua_State* thread = lua_type_traits<lua_State*>::get(state, corStackIndex);

				if (!thread)
				{
					except::typeMismatchError(state, "is not thread");
					return LUA_ERRRUN;
				}
				return lua_status(thread);
			}

			//! deprecate
			int thread_status()const
			{
				return threadStatus();
			}


			/**
			* @return coroutine status
			*/
			coroutine_status costatus(lua_State *l = 0)const
			{
				lua_State* state = state_();
				if (!state)
				{
					return COSTAT_DEAD;
				}
				util::ScopedSavedStack save(state);
				int corStackIndex = pushStackIndex_(state);
				lua_State* thread = lua_type_traits<lua_State*>::get(state, corStackIndex);

				if (!thread)
				{
					except::typeMismatchError(state, "is not thread");
					return COSTAT_DEAD;
				}
				else if (thread == l)
				{
					return COSTAT_RUNNING;
				}
				else
				{
					switch (lua_status(thread))
					{
					case LUA_YIELD:
						return COSTAT_SUSPENDED;
					case 0://LUA_OK
					{
						if (lua_gettop(thread) == 0)
						{
							return COSTAT_DEAD;
						}
						else
						{
							return COSTAT_SUSPENDED;
						}
					}
					default:
						break;
					}
				}
				return COSTAT_DEAD;

			}

			/**
			* @return if coroutine status is dead, return true. Otherwise return false
			*/
			bool isThreadDead()const
			{
				return costatus() == COSTAT_DEAD;
			}
		};
	}
}// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>
#include <algorithm>


namespace kaguya
{
	class LuaRef;
	class LuaStackRef;
	class LuaTable;
	template<typename KEY>
	class TableKeyReference;
	class MemberFunctionBinder;

	namespace detail
	{
		template<typename Derived>
		class LuaTableOrUserDataImpl
		{
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}
			int push_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->push(state);
			}

			template<typename K, typename A>
			struct gettablekey
			{
				typedef K key_type;
				typedef void value_type;
				std::vector<K, A>& v_;
				gettablekey(std::vector<K, A>&v) :v_(v) {}
				void operator ()(K key, const void*)
				{
					v_.push_back(key);
				}
			};
			template<typename V, typename A>
			struct gettablevalue
			{
				typedef void key_type;
				typedef V value_type;
				std::vector<V, A>& v_;
				gettablevalue(std::vector<V, A>&v) :v_(v) {}
				void operator ()(const void*, V value)
				{
					v_.push_back(value);
				}
			};
			template<typename K, typename V, typename C, typename A>
			struct gettablemap
			{
				typedef K key_type;
				typedef V value_type;
				std::map<K, V, C, A>& m_;
				gettablemap(std::map<K, V, C, A>& m) :m_(m) {}
				void operator ()(K key, V value)
				{
					m_[key] = value;
				}
			};


		public:

			/// @brief set metatable
			/// @param table metatable
			bool setMetatable(const LuaTable& table);
			
			/// @brief get metatable
			LuaTable getMetatable()const;


			/// @brief table->*"function_name"() in c++ and table:function_name(); in lua is same
			/// @param function_name function_name in table
			MemberFunctionBinder operator->*(const char* function_name);

			/// @brief value = table[key];
			/// @param key key of table
			/// @return reference of field value
			template<typename T, typename KEY>
			typename lua_type_traits<T>::get_type getField(const KEY& key)const
			{
				lua_State* state = state_();
				typedef typename lua_type_traits<T>::get_type get_type;
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return get_type();
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, key);
				lua_gettable(state, stackIndex);
				return lua_type_traits<T>::get(state, -1);
			}
			/// @brief value = table[key];
			/// @param key key of table
			/// @return reference of field value
			template<typename T>
			typename lua_type_traits<T>::get_type getField(const char* key)const
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return typename lua_type_traits<T>::get_type();
				}
				util::ScopedSavedStack save(state);
				lua_getfield(state, pushStackIndex_(state), key);
				return lua_type_traits<T>::get(state, -1);
			}

			/// @brief value = table[key];
			/// @param key key of table
			/// @return reference of field value
			template<typename T>
			typename lua_type_traits<T>::get_type getField(const std::string& key)const
			{
				return getField(key.c_str());
			}

			/// @brief value = table[key];
			/// @param key key of table
			/// @return reference of field value
			template<typename KEY>
			LuaStackRef getField(const KEY& key)const;

			/// @brief value = rawget(table,key);
			/// @param key key of table
			/// @return reference of field value
			template<typename T, typename KEY>
			typename lua_type_traits<T>::get_type getRawField(const KEY& key)const
			{
				lua_State* state = state_();
				typedef typename lua_type_traits<T>::get_type get_type;
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return get_type();
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, key);
				lua_rawget(state, stackIndex);
				return lua_type_traits<T>::get(state, -1);
			}
			/// @brief value = rawget(table,key);
			/// @param key key of table
			/// @return reference of field value
			template<typename KEY>
			LuaStackRef getRawField(const KEY& key)const;
			
			/// @brief value = rawget(table,key);
			/// @param key key of table
			/// @return reference of field value
			template<typename T>
			typename lua_type_traits<T>::get_type getRawField(luaInt key)const
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return typename lua_type_traits<T>::get_type();
				}
				util::ScopedSavedStack save(state);
				lua_rawgeti(state, pushStackIndex_(state), key);
				return lua_type_traits<T>::get(state, -1);
			}

			/// @brief foreach table fields
			template < class K, class V, class Fun> void foreach_table(Fun f)const
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				lua_pushnil(state);
				while (lua_next(state, stackIndex) != 0)
				{
					lua_pushvalue(state, -2);//backup key
					lua_insert(state, -3);

					typename lua_type_traits<V>::get_type value = lua_type_traits<V>::get(state, -1);
					typename lua_type_traits<K>::get_type key = lua_type_traits<K>::get(state, -2);
					f(key, value);
					lua_pop(state, 2);//pop key and value
				}
			}

			/// @brief foreach table fields
			template < class K, class V, class Fun> void foreach_table_breakable(Fun f)const
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				lua_pushnil(state);
				while (lua_next(state, stackIndex) != 0)
				{
					lua_pushvalue(state, -2);//backup key
					lua_insert(state, -3);

					typename lua_type_traits<V>::get_type value = lua_type_traits<V>::get(state, -1);
					typename lua_type_traits<K>::get_type key = lua_type_traits<K>::get(state, -2);
					bool cont = f(key, value);
					lua_pop(state, 2);//pop key and value
					if (!cont)
					{
						break;
					}
				}
			}

			/// @brief If type is table or userdata, return keys.
			/// @return field keys
			template<typename K, typename A>
			std::vector<K, A> keys()const
			{
				std::vector<K, A> res;
				util::ScopedSavedStack save(state_());
				int stackIndex = pushStackIndex_(state_());
				size_t size = lua_rawlen(state_(), stackIndex);
				res.reserve(size);
				foreach_table<K, void>(gettablekey<K, A>(res));
				return res;
			}

			/// @brief If type is table or userdata, return keys.
			/// @return field keys
			template<typename K >
			std::vector<K> keys()const
			{
				return keys<K, std::allocator<K> >();
			}
			std::vector<LuaRef> keys()const;

			/// @brief If type is table or userdata, return values.
			/// @return field value
			template<typename V, typename A>
			std::vector<V, A> values()const
			{
				std::vector<V, A> res;
				util::ScopedSavedStack save(state_());
				int stackIndex = pushStackIndex_(state_());
				size_t size = lua_rawlen(state_(), stackIndex);
				res.reserve(size);
				foreach_table<void, V>(gettablevalue<V, A>(res));
				return res;
			}

			/// @brief If type is table or userdata, return values.
			/// @return field value
			template<typename V >
			std::vector<V> values()const
			{
				return values<V, std::allocator<V> >();
			}
			std::vector<LuaRef> values()const;

			/// @brief If type is table or userdata, return key value pair.
			/// @return key value pair
			template<typename K, typename V, typename C, typename A >
			std::map<K, V, C, A> map()const
			{
				std::map<K, V, C, A> res;
				foreach_table<K, V>(gettablemap<K, V, C, A>(res));
				return res;
			}

			/// @brief If type is table or userdata, return key value pair.
			/// @return key value pair
			template<typename K, typename V, typename C >
			std::map<K, V, C> map()const
			{
				return map < K, V, C, std::allocator<std::pair<const K, V> > >();
			}

			/// @brief If type is table or userdata, return key value pair.
			/// @return key value pair
			template<typename K, typename V>
			std::map<K, V> map()const
			{
				return map<K, V, std::less<K> >();
			}
			std::map<LuaRef, LuaRef> map()const;

			/// @brief value = table[key];
			/// @param key key of table
			/// @return reference of field value
			template<typename K>
			LuaStackRef operator[](K key)const;


			/// @brief value = table[key];or table[key] = value;
			/// @param key key of table
			/// @return reference of field value
			template<typename K>
			TableKeyReference<K> operator[](K key);
		};

		template<typename Derived>
		class LuaTableImpl
		{
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}
		public:

			/// @brief table[key] = value;
			template<typename K, typename V>
			bool setField(const K& key, const V& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, key);//push table key
				util::one_push(state, value);//push value
				lua_settable(state, stackIndex);//thistable[key] = value
				return true;
			}

			/// @brief table[key] = value;
			template<typename V>
			bool setField(const char* key, const V& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, value);//push value
				lua_setfield(state, stackIndex, key);//thistable[key] = value
				return true;
			}

			/// @brief table[key] = value;
			template<typename V>
			bool setField(const std::string& key, const V& value)
			{
				return setField(key.c_str(), value);
			}
#if KAGUYA_USE_CPP11
			/// @brief table[key] = value;
			template<typename K, typename V>
			bool setField(K&& key, V&& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, std::forward<K>(key));//push table key
				util::one_push(state, std::forward<V>(value));//push value
				lua_settable(state, stackIndex);//thistable[key] = value
				return true;
			}
			/// @brief table[key] = value;
			template<typename V>
			bool setField(const char* key, V&& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, std::forward<V>(value));//push value
				lua_setfield(state, stackIndex, key);//thistable[key] = value
				return true;
			}
			/// @brief rawset(table,key,value)
			template<typename K, typename V>
			bool setRawField(K&& key, V&& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, key);//push table key
				util::one_push(state, value);//push value
				lua_rawset(state, stackIndex);//thistable[key] = value
				return true;
			}
#endif

			/// @brief rawset(table,key,value)
			template<typename K, typename V>
			bool setRawField(const K& key, const V& value)
			{
				lua_State* state = state_();
				if (!state)
				{
					except::typeMismatchError(state, "is nil");
					return false;
				}
				util::ScopedSavedStack save(state);
				int stackIndex = pushStackIndex_(state);
				util::one_push(state, key);//push table key
				util::one_push(state, value);//push value
				lua_rawset(state, stackIndex);//thistable[key] = value
				return true;
			}
		};
	}
}

namespace kaguya
{
	class LuaRef;
	class LuaTable;
	template<typename KEY>
	class TableKeyReference;
	class MemberFunctionBinder;

	namespace detail {

		template<typename Derived>
		class LuaVariantImpl :public LuaTableImpl<Derived>,
			public LuaTableOrUserDataImpl<Derived>,
			public detail::LuaFunctionImpl<Derived>,
			public detail::LuaThreadImpl<Derived>,
			public LuaBasicTypeFunctions<Derived>
		{
		private:
			lua_State* state_()const
			{
				return static_cast<const Derived*>(this)->state();
			}
			int pushStackIndex_(lua_State* state)const
			{
				return static_cast<const Derived*>(this)->pushStackIndex(state);
			}
		public:
			using LuaBasicTypeFunctions<Derived>::type;
			using LuaBasicTypeFunctions<Derived>::typeName;

			/// @brief typetest
			template<typename T>
			bool typeTest()const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				return lua_type_traits<T>::strictCheckType(state, pushStackIndex_(state));
			}
			/// @brief typetest
			template<typename T>
			bool weakTypeTest()const
			{
				lua_State* state = state_();
				util::ScopedSavedStack save(state);
				return lua_type_traits<T>::checkType(state, pushStackIndex_(state));
			}



#if KAGUYA_USE_CPP11
			template<class...Args> FunctionResults operator()(Args&&... args);
#else
#define KAGUYA_TEMPLATE_PARAMETER(N)
#define KAGUYA_FUNCTION_ARGS_DEF(N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)

#define KAGUYA_OP_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults operator()(KAGUYA_FUNCTION_ARGS_DEF(N));

			KAGUYA_OP_FN_DEF(0)

#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_FUNCTION_ARGS_DEF
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>
#define KAGUYA_FUNCTION_ARGS_DEF(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG)

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PUSH_ARG_DEF(N) KAGUYA_PP_CAT(a,N) 

				KAGUYA_PP_REPEAT_DEF(9, KAGUYA_OP_FN_DEF)
#undef KAGUYA_OP_FN_DEF
#undef KAGUYA_TEMPLATE_PARAMETER

#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_CALL_DEF
#undef KAGUYA_OP_FN_DEF
#endif
		};
	}
}
namespace kaguya
{
	namespace util
	{
		template<class Result>
		inline Result get_result_impl(lua_State* l, int startindex, types::typetag<Result>)
		{
			return lua_type_traits<Result>::get(l, startindex);
		}
#if KAGUYA_USE_CPP11
		inline standard::tuple<> get_result_tuple_impl(lua_State* l, int index, types::typetag<standard::tuple<> > tag)
		{
			return standard::tuple<>();
		}
		template<typename T, typename... TYPES>
		inline standard::tuple<T, TYPES...> get_result_tuple_impl(lua_State* l, int index, types::typetag<standard::tuple<T, TYPES...> > tag)
		{
			return standard::tuple_cat(standard::tuple<T>(lua_type_traits<T>::get(l, index)),
				get_result_tuple_impl(l, index + 1, types::typetag<standard::tuple<TYPES...> >()));
		}
		template<typename... TYPES>
		inline standard::tuple<TYPES...> get_result_impl(lua_State* l, int startindex, types::typetag<standard::tuple<TYPES...> > tag)
		{
			return get_result_tuple_impl<TYPES...>(l, startindex, tag);
		}
#else

		inline standard::tuple<> get_result_impl(lua_State *l, int startindex, types::typetag<standard::tuple<> > tag)
		{
			return standard::tuple<>();
		}

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_TARG(N) KAGUYA_PP_CAT(A,N)
#define KAGUYA_GET_DEF(N) lua_type_traits<KAGUYA_PP_CAT(A,N)>::get(l, N + startindex - 1) 
#define KAGUYA_GET_TUPLE_DEF(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>\
		inline standard::tuple<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TARG)> get_result_impl(lua_State *l,int startindex,types::typetag<standard::tuple<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TARG)> >)\
		{\
			return standard::tuple<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TARG) >(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_GET_DEF));\
		}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_GET_TUPLE_DEF)
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_TARG
#undef KAGUYA_GET_DEF
#undef KAGUYA_GET_TUPLE_DEF
#endif

			template<class Result>
		inline Result get_result(lua_State* l, int startindex)
		{
			return get_result_impl(l, startindex, types::typetag<Result>());
		}
		template<>
		inline void get_result<void>(lua_State* l, int startindex)
		{
		}
	}

	/// @addtogroup Lua_reference_types

	/// @ingroup Lua_reference_types
	/// @brief Reference to any Lua data.
	class LuaRef :public Ref::RegistoryRef, public detail::LuaVariantImpl<LuaRef>
	{
	private:
		typedef void (LuaRef::*bool_type)() const;
		void this_type_does_not_support_comparisons() const {}


		static lua_State* toMainThread(lua_State* state)
		{
#if LUA_VERSION_NUM >= 502
			if (state)
			{
				lua_rawgeti(state, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
				lua_State* mainthread = lua_tothread(state, -1);
				lua_pop(state, 1);
				if (mainthread)
				{
					return mainthread;
				}
			}
#endif
			return state;
		}
	public:


		LuaRef(const Ref::RegistoryRef& src) :Ref::RegistoryRef(src)
		{
		}
		LuaRef(const LuaRef& src) :Ref::RegistoryRef(src)
		{
		}
		LuaRef& operator =(const LuaRef& src)
		{
			static_cast<RegistoryRef&>(*this) = src;
			return *this;
		}

#if KAGUYA_USE_CPP11

		LuaRef(LuaRef&& src)throw() :Ref::RegistoryRef(std::move(src)) {}

		LuaRef& operator =(LuaRef&& src)throw()
		{
			swap(src);
			return *this;
		}

		LuaRef(RegistoryRef&& src)throw() :Ref::RegistoryRef(std::move(src)) {}
		template<typename T>
		LuaRef(lua_State* state, T&& v, Ref::NoMainCheck) : Ref::RegistoryRef(state, std::move(v), Ref::NoMainCheck()) {}
		template<typename T>
		LuaRef(lua_State* state, T&& v) : Ref::RegistoryRef(state, std::move(v)) {}
#endif

		LuaRef() {}
		LuaRef(lua_State* state) :Ref::RegistoryRef(state) {}

		LuaRef(lua_State* state, StackTop, Ref::NoMainCheck) :Ref::RegistoryRef(state, StackTop(), Ref::NoMainCheck()) {}

		LuaRef(lua_State* state, StackTop) :Ref::RegistoryRef(state, StackTop())
		{
		}


		template<typename T>
		LuaRef(lua_State* state, const T& v, Ref::NoMainCheck) : Ref::RegistoryRef(state, v, Ref::NoMainCheck()) {}
		template<typename T>
		LuaRef(lua_State* state, const T& v) : Ref::RegistoryRef(state, v) {}

		bool isNilref()const { return state() == 0 || ref_ == LUA_REFNIL; }



		//push to Lua stack
		int push()const
		{
			return push(state());
		}
		int push(lua_State* s)const
		{
			if (isNilref())
			{
				lua_pushnil(s);
				return 1;
			}
#if LUA_VERSION_NUM >= 502
			if (s != state())
			{//state check
				assert(toMainThread(s) == toMainThread(state()));
			}
#endif
			lua_rawgeti(s, LUA_REGISTRYINDEX, ref_);
			return 1;
		}
		int pushStackIndex(lua_State* state)const
		{
			push(state);
			return lua_gettop(state);
		}



		const void* native_pointer()const
		{
			util::ScopedSavedStack save(state());
			push(state());
			return lua_topointer(state(), -1);
		}
		static void putindent(std::ostream& os, int indent)
		{
			while (indent-- > 0)
			{
				os << "  ";
			}
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaRef
	template<>
	struct lua_type_traits<LuaRef>
	{
		typedef LuaRef get_type;
		typedef const LuaRef& push_type;

		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static bool strictCheckType(lua_State* l, int index)
		{
			return false;
		}

		static get_type get(lua_State* l, int index)
		{
			lua_pushvalue(l, index);
			return LuaRef(l, StackTop());
		}
		static int push(lua_State* l, push_type v)
		{
			return v.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaRef
	template<>	struct lua_type_traits<const LuaRef&> :lua_type_traits<LuaRef> {};




	class LuaStackRef :public Ref::StackRef, public detail::LuaVariantImpl<LuaStackRef>
	{
	public:
		LuaStackRef() :Ref::StackRef()
		{
		}
		LuaStackRef(lua_State* s, int index) :Ref::StackRef(s, index, false)
		{
		}
		LuaStackRef(lua_State* s, int index, bool popAtDestruct) :Ref::StackRef(s, index, popAtDestruct)
		{
		}
#if KAGUYA_USE_CPP11
		LuaStackRef(LuaStackRef&& src) : Ref::StackRef(std::move(src))
		{
			src.pop_ = false;
		}
		LuaStackRef& operator=(LuaStackRef&& src)
		{
			if (this != &src)
			{
				Ref::StackRef::operator=(std::move(src));
				src.pop_ = false;
			}
			return *this;
		}
		LuaStackRef(const LuaStackRef&src) = delete;
#else
		LuaStackRef(const LuaStackRef&src) : Ref::StackRef(src)
		{
			src.pop_ = false;
		}
		LuaStackRef& operator=(const LuaStackRef&src)
		{
			if (this != &src)
			{
				Ref::StackRef::operator=(src);
				src.pop_ = false;
			}
			return *this;
		}
#endif
	};



	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaStackRef
	template<>
	struct lua_type_traits<LuaStackRef>
	{
		typedef LuaStackRef get_type;
		typedef const LuaStackRef& push_type;

		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static bool strictCheckType(lua_State* l, int index)
		{
			return false;
		}

		static get_type get(lua_State* l, int index)
		{
			return LuaStackRef(l, index);
		}
		static int push(lua_State* l, push_type v)
		{
			return v.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaStackRef
	template<>	struct lua_type_traits<const LuaStackRef&> :lua_type_traits<LuaStackRef> {};

	/// @ingroup Lua_reference_types
	/// @brief Reference to Lua userdata.
	class  LuaUserData :public Ref::RegistoryRef
		, public detail::LuaTableOrUserDataImpl<LuaUserData>
		, public detail::LuaBasicTypeFunctions<LuaUserData>
	{

		void typecheck()
		{
			int t = type();
			if (t != TYPE_USERDATA && t != TYPE_LIGHTUSERDATA &&t != TYPE_NIL && t != TYPE_NONE)
			{
				except::typeMismatchError(state(), "not user data");
				Ref::RegistoryRef::unref();
			}
		}
	public:
		operator LuaRef() {
			push(state());
			return LuaRef(state(), StackTop());
		}
		LuaUserData(lua_State* state, StackTop) :Ref::RegistoryRef(state, StackTop())
		{
			typecheck();
		}
		template<typename TYPE>
		LuaUserData(lua_State* state, const TYPE& table) : Ref::RegistoryRef(state, table)
		{
			typecheck();
		}
		LuaUserData(lua_State* state) :Ref::RegistoryRef(state, NilValue())
		{
			typecheck();
		}
		LuaUserData()
		{
			typecheck();
		}
		template<typename T>
		bool typeTest()const
		{
			util::ScopedSavedStack save(state());
			return lua_type_traits<T>::strictCheckType(state(), pushStackIndex(state()));
		}
		template<typename T>
		bool weakTypeTest()const
		{
			util::ScopedSavedStack save(state());
			return lua_type_traits<T>::checkType(state(), pushStackIndex(state()));
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaUserData
	template<>	struct lua_type_traits<LuaUserData> {
		typedef LuaUserData get_type;
		typedef LuaUserData push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TUSERDATA;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TUSERDATA || lua_isnil(l, index);
		}
		static LuaUserData get(lua_State* l, int index)
		{
			lua_pushvalue(l, index);
			return LuaUserData(l, StackTop());
		}
		static int push(lua_State* l, const LuaUserData& ref)
		{
			return ref.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaUserData
	template<>	struct lua_type_traits<const LuaUserData&> :lua_type_traits<LuaUserData> {};


	/// @ingroup Lua_reference_types
	/// @brief Reference to Lua table.
	class LuaTable :public Ref::RegistoryRef
		, public detail::LuaTableImpl<LuaTable>
		, public detail::LuaTableOrUserDataImpl<LuaTable>
		, public detail::LuaBasicTypeFunctions<LuaTable>
	{

		void typecheck()
		{
			int t = type();
			if (t != TYPE_TABLE && t != TYPE_NIL && t != TYPE_NONE)
			{
				except::typeMismatchError(state(), "not table");
				Ref::RegistoryRef::unref();
			}
		}
	public:
		operator LuaRef() {
			push(state());
			return LuaRef(state(), StackTop());
		}
		LuaTable(lua_State* state, StackTop) :Ref::RegistoryRef(state, StackTop())
		{
			typecheck();
		}
		LuaTable(lua_State* state, const NewTable& table) :Ref::RegistoryRef(state, table)
		{
			typecheck();
		}
		LuaTable(lua_State* state) :Ref::RegistoryRef(state, NewTable())
		{
			typecheck();
		}
		LuaTable()
		{
			typecheck();
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaTable
	template<>	struct lua_type_traits<LuaTable> {
		typedef LuaTable get_type;
		typedef LuaTable push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_istable(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_istable(l, index) || lua_isnil(l, index);
		}
		static LuaTable get(lua_State* l, int index)
		{
			lua_pushvalue(l, index);
			return LuaTable(l, StackTop());
		}
		static int push(lua_State* l, const LuaTable& ref)
		{
			return ref.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaTable
	template<>	struct lua_type_traits<const LuaTable&> :lua_type_traits<LuaTable> {};

	/// @ingroup Lua_reference_types
	/// @brief Reference to Lua function.
	class LuaFunction :public Ref::RegistoryRef
		, public detail::LuaFunctionImpl<LuaFunction>
		, public detail::LuaBasicTypeFunctions<LuaFunction>
	{
		void typecheck()
		{
			int t = type();
			if (t != TYPE_FUNCTION && t != TYPE_NIL && t != TYPE_NONE)
			{
				except::typeMismatchError(state(), "not function");
				RegistoryRef::unref();
			}
		}

		struct LuaLoadStreamWrapper
		{
			LuaLoadStreamWrapper(std::istream& stream) :preloaded_(false), stream_(stream)
			{
				buffer_.reserve(512);
				skipComment();
				preloaded_ = !buffer_.empty();
			}

			void skipComment()
			{
				//skip bom
				const char* bom = "\xEF\xBB\xBF";
				const char* bomseq = bom;
				char c;
				while (stream_.get(c))
				{
					if (c != *bomseq)// not bom sequence
					{
						buffer_.assign(bom, bomseq);
						buffer_.push_back(c);
						break;
					}
					bomseq++;
					if ('\0' == *bomseq)
					{
						return;
					}
				}

				//skip comment
				if (!buffer_.empty() && buffer_.front() == '#')
				{
					buffer_.clear();
					std::string comment;
					std::getline(stream_, comment);
				}
			}


			static const char *getdata(lua_State *, void *ud, size_t *size) {
				LuaLoadStreamWrapper *loader = static_cast<LuaLoadStreamWrapper *>(ud);

				if (loader->preloaded_)
				{
					loader->preloaded_ = false;
				}
				else
				{
					loader->buffer_.clear();
				}

				char c = 0;
				while (loader->buffer_.size() < loader->buffer_.capacity() && loader->stream_.get(c))
				{
					loader->buffer_.push_back(c);
				}
				*size = loader->buffer_.size();
				return loader->buffer_.empty() ? 0 : &loader->buffer_[0];
			}
		private:
			bool preloaded_;
			std::vector<char> buffer_;
			std::istream& stream_;
		};
	public:

		/// @brief construct with state and function .
		/// @param state pointer to lua_State
		/// @param f execute function for lua thread. e.g. kaguya::function(function_ptr),kaguya::overload(function_ptr)
		template<typename F>
		LuaFunction(lua_State* state, F f) :Ref::RegistoryRef(state, f)
		{
			typecheck();
		}

		/// @brief construct with stack top value.
		/// @param state pointer to lua_State
		LuaFunction(lua_State* state, StackTop) :Ref::RegistoryRef(state, StackTop())
		{
			typecheck();
		}

		/// @brief construct with nil reference.
		LuaFunction()
		{
		}

		/// @brief load lua code .
		/// @param state pointer to lua_State
		/// @param luacode string
		static LuaFunction loadstring(lua_State* state, const std::string& luacode)
		{
			return loadstring(state, luacode.c_str());
		}
		/// @brief load lua code .
		/// @param state pointer to lua_State
		/// @param luacode string
		static LuaFunction loadstring(lua_State* state, const char* luacode)
		{
			util::ScopedSavedStack save(state);
			int status = luaL_loadstring(state, luacode);

			if (status)
			{
				ErrorHandler::handle(status, state);
				lua_pushnil(state);
			}
			return LuaFunction(state, StackTop());
		}


		/// @brief If there are no errors,compiled file as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param state pointer to lua_State
		/// @param file  file path of lua script
		/// @return reference of lua function
		static LuaFunction loadfile(lua_State* state, const std::string& file)
		{
			return loadfile(state, file.c_str());
		}

		/// @brief If there are no errors,compiled file as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param state pointer to lua_State
		/// @param file  file path of lua script
		/// @return reference of lua function
		static LuaFunction loadfile(lua_State* state, const char* file)
		{
			util::ScopedSavedStack save(state);

			int status = luaL_loadfile(state, file);

			if (status)
			{
				ErrorHandler::handle(status, state);
				lua_pushnil(state);
			}
			return LuaFunction(state, StackTop());
		}

		/// @brief If there are no errors,compiled stream as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param state pointer to lua_State
		/// @param stream  stream of lua script data
		/// @param chunkname  use for error message.
		/// @return reference of lua function
		static LuaStackRef loadstreamtostack(lua_State* state, std::istream& stream, const char* chunkname = 0)
		{
			LuaLoadStreamWrapper wrapper(stream);
#if LUA_VERSION_NUM >= 502
			int status = lua_load(state, &LuaLoadStreamWrapper::getdata, &wrapper, chunkname, 0);
#else
			int status = lua_load(state, &LuaLoadStreamWrapper::getdata, &wrapper, chunkname);
#endif
			if (status)
			{
				ErrorHandler::handle(status, state);
				lua_pushnil(state);
			}
			return LuaStackRef(state, -1, true);
		}

		/// @brief If there are no errors,compiled stream as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param state pointer to lua_State
		/// @param stream  stream of lua script data
		/// @param chunkname  use for error message.
		/// @return reference of lua function
		static LuaFunction loadstream(lua_State* state, std::istream& stream, const char* chunkname = 0)
		{
			util::ScopedSavedStack save(state);
			LuaLoadStreamWrapper wrapper(stream);
#if LUA_VERSION_NUM >= 502
			int status = lua_load(state, &LuaLoadStreamWrapper::getdata, &wrapper, chunkname, 0);
#else
			int status = lua_load(state, &LuaLoadStreamWrapper::getdata, &wrapper, chunkname);
#endif
			if (status)
			{
				ErrorHandler::handle(status, state);
				lua_pushnil(state);
			}
			return LuaFunction(state, StackTop());
		}
	};

	/// @ingroup Lua_reference_types
	/// @brief Reference to Lua thread(coroutine).
	class LuaThread :public Ref::RegistoryRef
		, public detail::LuaThreadImpl<LuaThread>
		, public detail::LuaBasicTypeFunctions<LuaThread>
	{
		void typecheck()
		{
			int t = type();
			if (t != TYPE_THREAD && t != TYPE_NIL && t != TYPE_NONE)
			{
				except::typeMismatchError(state(), "not lua thread");
				RegistoryRef::unref();
			}
		}
	public:
		/// @brief construct with stack top value.
		LuaThread(lua_State* state, StackTop) :Ref::RegistoryRef(state, StackTop())
		{
			typecheck();
		}
		/// @brief construct with new thread.
		LuaThread(lua_State* state, const NewThread& t) :Ref::RegistoryRef(state, t)
		{
		}
		/// @brief construct with nil reference.
		LuaThread(lua_State* state) :Ref::RegistoryRef(state, NewThread())
		{
		}
		/// @brief construct with nil reference.
		LuaThread()
		{
		}


		/// @brief set function for thread running.
		void setFunction(const LuaFunction& f)
		{
			typecheck();
			lua_State* corstate = get<lua_State*>();
			lua_settop(corstate, 0);
			f.push(corstate);
		}
	};


}



#if KAGUYA_USE_CPP11
#else
namespace std
{
	template <> inline void swap(kaguya::LuaUserData& a, kaguya::LuaUserData& b)
	{
		a.swap(b);
	}
	template <> inline void swap(kaguya::LuaTable& a, kaguya::LuaTable& b)
	{
		a.swap(b);
	}
	template <> inline void swap(kaguya::LuaFunction& a, kaguya::LuaFunction& b)
	{
		a.swap(b);
	}
	template <> inline void swap(kaguya::LuaThread& a, kaguya::LuaThread& b)
	{
		a.swap(b);
	}
	template <> inline void swap(kaguya::LuaRef& a, kaguya::LuaRef& b)
	{
		a.swap(b);
	}
}
#endif
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>
#include <vector>


#if KAGUYA_USE_CPP11
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>



namespace kaguya
{
	namespace nativefunction
	{
		template<class ThisType, class Res, class... FArgs, class... Args>
		Res invoke_fn(Res(ThisType::*f)(FArgs...), ThisType& this_, Args&&... args)
		{
			return (this_.*f)(std::forward<Args>(args)...);
		}

		template<class ThisType, class... FArgs, class... Args>
		void invoke_fn(void (ThisType::*f)(FArgs...), ThisType& this_, Args&&... args)
		{
			(this_.*f)(std::forward<Args>(args)...);
		}

		template<class ThisType, class Res, class... FArgs, class... Args>
		Res invoke_fn(Res(ThisType::*f)(FArgs...)const, const ThisType& this_, Args&&... args)
		{
			return (this_.*f)(std::forward<Args>(args)...);
		}

		template<class ThisType, class... FArgs, class... Args>
		void invoke_fn(void (ThisType::*f)(FArgs...)const, const ThisType& this_, Args&&... args)
		{
			(this_.*f)(std::forward<Args>(args)...);
		}
		template<class F, class... Args>
		//MSVC 2013 std::result_of is broken.
		auto invoke_fn(F&& f, Args&&... args) -> decltype(f(std::forward<Args>(args)...))
		{
			return f(std::forward<Args>(args)...);
		}

		template<std::size_t... indexes>
		struct index_tuple {};

		template<std::size_t first, std::size_t last, class result = index_tuple<>, bool flag = first >= last>
		struct index_range
		{
			using type = result;
		};

		template<std::size_t step, std::size_t last, std::size_t... indexes>
		struct index_range<step, last, index_tuple<indexes...>, false>
			: index_range<step + 1, last, index_tuple<indexes..., step>>
		{};

		template<class Ret, class... Args>
		struct invoke_signature_type {};

		template<class F>
		struct arg_count;
		template<class R, class... Args>
		struct arg_count<invoke_signature_type<R, Args...> > : traits::integral_constant<size_t, sizeof...(Args)>
		{};
		template<class T>
		struct min_arg_count : arg_count<T> {};
		template<class T>
		struct max_arg_count : arg_count<T> {};

		template<class F>
		struct arg_index_range;

		template<class R, class... Args>
		struct arg_index_range<invoke_signature_type<R, Args...> > : index_range<1, sizeof...(Args)+1>
		{};


		template <typename T>
		struct functor_f_signature {};

		template <typename T, typename Ret, typename... Args>
		struct functor_f_signature<Ret(T::*)(Args...) const> {
			typedef invoke_signature_type<Ret, Args...> type;
		};
		template <typename T, typename Ret, typename... Args>
		struct functor_f_signature<Ret(T::*)(Args...)> {
			typedef invoke_signature_type<Ret, Args...> type;
		};

#if _MSC_VER
		template <typename T>
		struct f_signature : public functor_f_signature<decltype(&T::operator())> {};
#else

		template <typename T, typename Enable = void>
		struct f_signature {};

		template < typename T, typename = void>
		struct has_operator_fn :std::false_type {};
		template < typename T >
		struct has_operator_fn<T, typename std::enable_if<!std::is_same<void, decltype(&T::operator())>::value>::type> :std::true_type {};

		template <typename T>
		struct f_signature<T, typename std::enable_if<has_operator_fn<T>::value>::type>
			: public functor_f_signature<decltype(&T::operator())> {};
#endif


		template <typename T, typename Ret, typename... Args>
		struct f_signature<Ret(T::*)(Args...)> {
			typedef invoke_signature_type<Ret, T&, Args...> type;
		};
		template <typename T, typename Ret, typename... Args>
		struct f_signature<Ret(T::*)(Args...) const> {
			typedef invoke_signature_type<Ret, const T&, Args...> type;
		};
		template<class Ret, class... Args>
		struct f_signature<Ret(*)(Args...)> {
			typedef invoke_signature_type<Ret, Args...> type;
		};

		template<class F, class Ret, class... Args, size_t... Indexes>
		int _call_apply(lua_State* state, F&& f, index_tuple<Indexes...>, invoke_signature_type<Ret, Args...>)
		{
			return util::push_args(state, invoke_fn(f, lua_type_traits<Args>::get(state, Indexes)...));
		}
		template<class F, class... Args, size_t... Indexes>
		int _call_apply(lua_State* state, F&& f, index_tuple<Indexes...>, invoke_signature_type<void, Args...>)
		{
			invoke_fn(f, lua_type_traits<Args>::get(state, Indexes)...);
			return 0;
		}

		inline bool all_true()
		{
			return true;
		}
		template<class Arg, class...Args>bool all_true(Arg f, Args... args)
		{	//check from backward and lazy evaluation
			return all_true(args...) && bool(f);
		}

		inline void join(std::string& result, const char* delim)
		{
		}
		template<class Arg, class...Args>void join(std::string& result, const char* delim, const Arg& str, const Args&... args)
		{
			result += str;
			result += delim;
			join(result, delim, args...);
		}

		template<typename T, size_t Index>
		struct _wcheckeval
		{
			_wcheckeval(lua_State* s) :state(s) {}
			lua_State* state;
			operator bool()
			{
				return lua_type_traits<T>::checkType(state, Index);
			}
		};

		template<typename T, size_t Index>
		struct _scheckeval
		{
			_scheckeval(lua_State* s) :state(s) {}
			lua_State* state;
			operator bool()
			{
				return lua_type_traits<T>::strictCheckType(state, Index);
			}
		};

		template<class R, class... Args, size_t... Indexes>
		bool _ctype_apply(lua_State* state, index_tuple<Indexes...>, invoke_signature_type<R, Args...>)
		{
			return all_true(_wcheckeval<Args, Indexes>(state)...);
		}
		template<class R, class... Args, size_t... Indexes>
		bool _sctype_apply(lua_State* state, index_tuple<Indexes...>, invoke_signature_type<R, Args...>)
		{
			return all_true(_scheckeval<Args, Indexes>(state)...);
		}
		template<class R, class... Args>
		std::string _type_name_apply(invoke_signature_type<R, Args...>)
		{
			std::string result;
			join(result, ",", typeid(Args).name()...);
			return result;
		}

		///! for data member
		template <typename T, typename MemType>
		struct f_signature<MemType T::*> {
			typedef MemType T::*type;
		};
		template<class MemType, class T>
		struct min_arg_count<MemType T::*> : traits::integral_constant<size_t, 1>
		{};
		template<class MemType, class T>
		struct max_arg_count<MemType T::*> : traits::integral_constant<size_t, 2>
		{};
		template <typename T, typename MemType>
		struct arg_index_range<MemType T::*> : index_range<1, 2> {};

		template<class MemType, class T, class unusedindex>
		int _call_apply(lua_State* state, MemType T::* m, unusedindex, MemType T::*)
		{
			T* this_ = lua_type_traits<T*>::get(state, 1);
			if (lua_gettop(state) == 1)
			{
				if (!this_)
				{
					const T& this_ = lua_type_traits<const T&>::get(state, 1);
					if (is_usertype<MemType>::value && !traits::is_pointer<MemType>::value)
					{
						return util::push_args(state, standard::reference_wrapper<const MemType>(this_.*m));
					}
					else
					{
						return util::push_args(state, this_.*m);
					}
				}
				else
				{
					if (is_usertype<MemType>::value && !traits::is_pointer<MemType>::value)
					{
						return util::push_args(state, standard::reference_wrapper<MemType>(this_->*m));
					}
					else
					{
						return util::push_args(state, this_->*m);
					}
				}
			}
			else
			{
				if (!this_)
				{
					throw LuaTypeMismatch("type mismatch!!");
				}
				this_->*m = lua_type_traits<MemType>::get(state, 2);
				return 0;
			}
		}
		template<class MemType, class T, class unusedindex>
		bool _ctype_apply(lua_State* state, unusedindex, MemType T::*)
		{
			if (lua_gettop(state) >= 2)
			{
				//setter typecheck
				return lua_type_traits<MemType>::checkType(state, 2) && lua_type_traits<T>::checkType(state, 1);
			}
			//getter typecheck
			return  lua_type_traits<T>::checkType(state, 1);
		}
		template<class MemType, class T, class unusedindex>
		bool _sctype_apply(lua_State* state, unusedindex, MemType T::*)
		{
			if (lua_gettop(state) >= 2)
			{
				//setter typecheck
				return lua_type_traits<MemType>::strictCheckType(state, 2) && lua_type_traits<T>::strictCheckType(state, 1);
			}
			//getter typecheck
			return lua_type_traits<T>::strictCheckType(state, 1);
		}
		template<class MemType, class T>
		std::string _type_name_apply(MemType T::*)
		{
			return std::string(typeid(T*).name()) + ",[OPT] " + typeid(MemType).name();
		}

		///! for constructor
		template<class ClassType, class... Args>
		struct constructor_signature_type :invoke_signature_type<ClassType, Args...>
		{
		};
		template <class ClassType, class... Args>
		struct f_signature<constructor_signature_type<ClassType, Args...> > {
			typedef constructor_signature_type<ClassType, Args...> type;
		};
		template<class ClassType, class... Args>
		struct arg_index_range<constructor_signature_type<ClassType, Args...> > : index_range<1, sizeof...(Args)+1>
		{};
		template<class ClassType, class... Args>
		struct min_arg_count<constructor_signature_type<ClassType, Args...> > : traits::integral_constant<size_t, sizeof...(Args)>
		{};
		template<class ClassType, class... Args>
		struct max_arg_count<constructor_signature_type<ClassType, Args...> > : traits::integral_constant<size_t, sizeof...(Args)>
		{};

		template <class ClassType, class... Args, size_t... Indexes>
		int _call_apply(lua_State* state, constructor_signature_type<ClassType, Args...>, index_tuple<Indexes...>, constructor_signature_type<ClassType, Args...>)
		{
			typedef ObjectWrapper<ClassType> wrapper_type;
			void *storage = lua_newuserdata(state, sizeof(wrapper_type));
			try { new(storage) wrapper_type(lua_type_traits<Args>::get(state, Indexes)...); }
			catch (...) { lua_pop(state, 1); throw; }

			class_userdata::setmetatable<ClassType>(state);
			return 1;
		}


		template<class F>
		int call(lua_State* state, F&& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			typedef typename arg_index_range<fsigtype>::type index;

			return _call_apply(state, f, index(), fsigtype());
		}
		template<class F>
		bool checkArgTypes(lua_State* state, const F& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			typedef typename arg_index_range<fsigtype>::type index;
			return _ctype_apply(state, index(), fsigtype());
		}
		template<class F>
		bool strictCheckArgTypes(lua_State* state, const F& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			typedef typename arg_index_range<fsigtype>::type index;
			return _sctype_apply(state, index(), fsigtype());
		}

		template<class F>
		std::string argTypesName(const F& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			return _type_name_apply(fsigtype());
		}
		template<class F>
		int minArgCount(const F& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			return min_arg_count<fsigtype>::value;
		}
		template<class F>
		int maxArgCount(const F& f)
		{
			typedef typename traits::decay<F>::type ftype;
			typedef typename f_signature<ftype>::type fsigtype;
			return max_arg_count<fsigtype>::value;
		}

		template< typename T, typename Enable = void>
		struct is_callable : traits::integral_constant<bool, false> {};
		template< typename T>
		struct is_callable<T, typename traits::enable_if<
			!traits::is_same<void, typename f_signature<T>::type>::value
			, void>::type > : traits::integral_constant<bool, true> {};

		template<typename ClassType, typename... Args> struct ConstructorFunction;
		template<typename ClassType, typename... Args> struct ConstructorFunction<ClassType(Args...) >
		{
			typedef constructor_signature_type<ClassType, Args...> type;
		};
		template<typename ClassType, typename... Args> struct ConstructorFunction<ClassType, ClassType(Args...) >//class type check version
		{
			typedef constructor_signature_type<ClassType, Args...> type;
		};

		/*
		template<class arg1, class... args>
		struct typeTuple {
			typedef arg1 first_type;
		};

		template<std::size_t remain, class result, bool flag = remain <= 0>
		struct type_get
		{
			typedef typename result::first_type type;
		};

		template<std::size_t remain, class arg, class... args >
		struct type_get<remain, typeTuple<arg, args...>, false>
			: type_get<remain - 1, typeTuple<args...> >
		{
		};
		template< typename F>
		struct fsig_arg_to_type_tuple;

		template<class Ret, class... Args>
		struct fsig_arg_to_type_tuple<invoke_signature_type<Ret, Args...>>
		{
			typedef typeTuple<Args...> type;
		};
		template< typename F>
		struct fsig_ret_type;

		template<class Ret, class... Args>
		struct fsig_ret_type<invoke_signature_type<Ret, Args...>>
		{
			typedef Ret type;
		};


		template<typename F>
		struct functionArgumentsTypeTuple
		{
			typedef typename fsig_arg_to_type_tuple<typename f_signature<F>::type>::type type;
		};
		template<typename F>
		struct functionResultType
		{
			typedef typename fsig_ret_type<typename f_signature<F>::type>::type type;
		};

		template<int N, typename F>
		struct argumentTypeGet
		{
			typedef typename type_get<N, typename functionArgumentsTypeTuple<F>::type>::type type;
		};*/

	}
	using nativefunction::ConstructorFunction;
}
#else
// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>


namespace kaguya
{
	namespace nativefunction
	{

#if defined(_MSC_VER) && _MSC_VER <= 1700
		//can not detect callable at MSVC
		template< typename T>
		struct is_callable : traits::integral_constant<bool, true> {};
#else
		template< typename T>
		struct is_callable : traits::integral_constant<bool, false> {};
#endif

		inline int call(lua_State* state, void(*f)())
		{
			f();
			return 0;
		}
		template<>struct is_callable< void(*)()> : traits::integral_constant<bool, true> {};

		inline bool checkArgTypes(lua_State* state, void(*f)())
		{
			return true;
		}
		inline bool strictCheckArgTypes(lua_State* state, void(*f)())
		{
			return true;
		}
		inline std::string argTypesName(void(*f)())
		{
			return "";
		}
		inline int minArgCount(void(*f)())
		{
			return 0;
		}
		inline int maxArgCount(void(*f)())
		{
			return 0;
		}

		inline int call(lua_State* state, standard::function<void()> f)
		{
			f();
			return 0;
		}
		template<>struct is_callable<standard::function<void()> > : traits::integral_constant<bool, true> {};
		inline bool checkArgTypes(lua_State* state, standard::function<void()> f)
		{
			return true;
		}
		inline bool strictCheckArgTypes(lua_State* state, standard::function<void()> f)
		{
			return true;
		}
		inline std::string argTypesName(standard::function<void()> f)
		{
			return "";
		}
		inline int minArgCount(standard::function<void()> f)
		{
			return 0;
		}
		inline int maxArgCount(standard::function<void()> f)
		{
			return 0;
		}
#define KAGUYA_GET_OFFSET 
#define KAGUYA_GET_CONCAT_REP(N) ,lua_type_traits<KAGUYA_PP_CAT(A,N)>::get(state, N KAGUYA_GET_OFFSET)
#define KAGUYA_GET_REP(N) lua_type_traits<KAGUYA_PP_CAT(A,N)>::get(state, N KAGUYA_GET_OFFSET)

#define KAGUYA_STRICT_TYPECHECK_REP(N) && lua_type_traits<KAGUYA_PP_CAT(A,N)>::strictCheckType(state, N KAGUYA_GET_OFFSET)
#define KAGUYA_TYPECHECK_REP(N) && lua_type_traits<KAGUYA_PP_CAT(A,N)>::checkType(state, N KAGUYA_GET_OFFSET)
#define KAGUYA_TYPENAME_REP(N) + typeid(KAGUYA_PP_CAT(A,N)).name() + ","

#define KAGUYA_GET_REPEAT_CONCAT(N) KAGUYA_PP_REPEAT(N,KAGUYA_GET_CONCAT_REP)
#define KAGUYA_GET_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_GET_REP)

#define KAGUYA_FUNC_DEF(N) void (*f)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))
#define KAGUYA_FUNC_TYPE(N) void (*)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))
#define KAGUYA_CALL_FN_DEF(N) \
			template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>\
			inline int call(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				f(KAGUYA_GET_REPEAT(N));\
				return 0;\
			}\
			template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N)> : traits::integral_constant<bool, true> {};

		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)
#undef KAGUYA_CALL_FN_DEF
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE
#define KAGUYA_FUNC_DEF(N) Ret (*f)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))
#define KAGUYA_FUNC_TYPE(N) Ret (*)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))
#define KAGUYA_CALL_FN_DEF(N) \
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			inline int call(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return util::push_args(state, f(KAGUYA_GET_REPEAT(N)));\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N)> : traits::integral_constant<bool, true> {};\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool checkArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_TYPECHECK_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool strictCheckArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_STRICT_TYPECHECK_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			std::string argTypesName(KAGUYA_FUNC_DEF(N))\
			{\
				return std::string() KAGUYA_PP_REPEAT(N,KAGUYA_TYPENAME_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int minArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET;\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int maxArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET; \
			}

			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)

#undef KAGUYA_GET_OFFSET
#define KAGUYA_GET_OFFSET + 1
#undef KAGUYA_CALL_FN_DEF
#define KAGUYA_MEM_ATTRBUTE 
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE				
#define KAGUYA_FUNC_DEF(N) void (ThisType::*f)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))KAGUYA_MEM_ATTRBUTE
#define KAGUYA_FUNC_TYPE(N) void (ThisType::*)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))KAGUYA_MEM_ATTRBUTE
#define KAGUYA_CALL_FN_DEF(N) \
			template<typename ThisType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			inline int call(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				KAGUYA_MEM_ATTRBUTE ThisType& this_ = lua_type_traits<KAGUYA_MEM_ATTRBUTE ThisType&>::get(state, 1); \
				(this_.*f)(KAGUYA_GET_REPEAT(N));\
				return 0;\
			}\
			template<typename ThisType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N)> : traits::integral_constant<bool, true> {};

			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)

#undef KAGUYA_MEM_ATTRBUTE
#define KAGUYA_MEM_ATTRBUTE const  
			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)
#undef KAGUYA_MEM_ATTRBUTE


#undef KAGUYA_CALL_FN_DEF
#define KAGUYA_MEM_ATTRBUTE 
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE
#define KAGUYA_FUNC_DEF(N) Ret (ThisType::*f)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))KAGUYA_MEM_ATTRBUTE
#define KAGUYA_FUNC_TYPE(N) Ret (ThisType::*)(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))KAGUYA_MEM_ATTRBUTE
#define KAGUYA_CALL_FN_DEF(N) \
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			inline int call(lua_State* state,KAGUYA_FUNC_DEF(N))\
			{\
				KAGUYA_MEM_ATTRBUTE ThisType& this_ = lua_type_traits<KAGUYA_MEM_ATTRBUTE ThisType&>::get(state, 1); \
				return util::push_args(state, (this_.*f)(KAGUYA_GET_REPEAT(N)));\
			}\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N)> : traits::integral_constant<bool, true> {};\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool checkArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_TYPECHECK_REP) \
				&& lua_type_traits<KAGUYA_MEM_ATTRBUTE ThisType*>::checkType(state, 1);\
			}\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool strictCheckArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true	KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_STRICT_TYPECHECK_REP) \
				&& lua_type_traits<KAGUYA_MEM_ATTRBUTE ThisType*>::strictCheckType(state, 1);\
			}\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			std::string argTypesName(KAGUYA_FUNC_DEF(N))\
			{\
				return typeid(ThisType).name() + std::string(",") KAGUYA_PP_REPEAT(N,KAGUYA_TYPENAME_REP);\
			}\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int minArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET;\
			}\
			template<typename ThisType,typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int maxArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET;\
			}
			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)

#undef KAGUYA_MEM_ATTRBUTE
#define KAGUYA_MEM_ATTRBUTE const  
			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)
#undef KAGUYA_MEM_ATTRBUTE

#undef KAGUYA_GET_OFFSET
#define KAGUYA_GET_OFFSET
#undef KAGUYA_CALL_FN_DEF
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE
#define KAGUYA_FUNC_DEF(N) const standard::function<void (KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>& f
#define KAGUYA_FUNC_TYPE(N) standard::function<void (KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>
#define KAGUYA_CALL_FN_DEF(N) \
			template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>\
			inline int call(lua_State* state,KAGUYA_FUNC_DEF(N))\
			{\
				f(KAGUYA_GET_REPEAT(N));\
				return 0;\
			}\
			template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N) > : traits::integral_constant<bool, true> {};

			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)
#undef KAGUYA_CALL_FN_DEF
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE
#define KAGUYA_FUNC_DEF(N) const standard::function<Ret (KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>& f
#define KAGUYA_FUNC_TYPE(N) standard::function<Ret (KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>
#define KAGUYA_CALL_FN_DEF(N) \
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			inline int call(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return util::push_args(state,f(KAGUYA_GET_REPEAT(N)));\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>struct is_callable<KAGUYA_FUNC_TYPE(N)> : traits::integral_constant<bool, true> {};\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool checkArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_TYPECHECK_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool strictCheckArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_STRICT_TYPECHECK_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			std::string argTypesName(KAGUYA_FUNC_DEF(N))\
			{\
				return std::string() KAGUYA_PP_REPEAT(N,KAGUYA_TYPENAME_REP);\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int minArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET;\
			}\
			template<typename Ret KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int maxArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N  KAGUYA_GET_OFFSET;\
			}
			KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)

			///! for data member
			template<class MemType, class T>
		int call(lua_State* state, MemType T::* m)
		{
			T* this_ = lua_type_traits<T*>::get(state, 1);
			if (lua_gettop(state) == 1)
			{
				if (!this_)
				{
					const T& this_ = lua_type_traits<const T&>::get(state, 1);
					if (is_usertype<MemType>::value && !traits::is_pointer<MemType>::value)
					{
						return util::push_args(state, standard::reference_wrapper<const MemType>(this_.*m));
					}
					else
					{
						return util::push_args(state, this_.*m);
					}
				}
				else
				{
					if (is_usertype<MemType>::value && !traits::is_pointer<MemType>::value)
					{
						return util::push_args(state, standard::reference_wrapper<MemType>(this_->*m));
					}
					else
					{
						return util::push_args(state, this_->*m);
					}
				}
			}
			else
			{
				if (!this_)
				{
					throw LuaTypeMismatch("type mismatch!!");
				}
				this_->*m = lua_type_traits<MemType>::get(state, 2);
				return 0;
			}
		}
#if defined(_MSC_VER) && _MSC_VER <= 1700
		//can not detect callable at MSVC
#else
		template<class MemType, class T>struct is_callable<MemType T::*> : traits::integral_constant<bool, true> {};
#endif

		template<class MemType, class T>
		bool checkArgTypes(lua_State* state, MemType T::* m)
		{
			if (lua_gettop(state) >= 2)
			{
				//setter typecheck
				return lua_type_traits<MemType>::checkType(state, 2) && lua_type_traits<T>::checkType(state, 1);
			}
			//getter typecheck
			return  lua_type_traits<T>::checkType(state, 1);
		}
		template<class MemType, class T>
		bool strictCheckArgTypes(lua_State* state, MemType T::* m)
		{
			bool thistypecheck = lua_type_traits<T>::strictCheckType(state, 1);
			if (thistypecheck && lua_gettop(state) == 2)
			{
				return lua_type_traits<MemType>::strictCheckType(state, 2);
			}
			return thistypecheck;
		}
		template<class MemType, class T>
		std::string argTypesName(MemType T::*)
		{
			return std::string(typeid(T*).name()) + ",[OPT] " + typeid(MemType).name();
		}
		template<class MemType, class T>
		int minArgCount(MemType T::*)
		{
			return 1;
		}
		template<class MemType, class T>
		int maxArgCount(MemType T::*)
		{
			return 2;
		}

		///! for constructor
		struct null_type {};

		template<class ClassType, class A1 = null_type, class A2 = null_type
			, class A3 = null_type, class A4 = null_type, class A5 = null_type
			, class A6 = null_type, class A7 = null_type, class A8 = null_type,
			class A9 = null_type>struct constructor_signature_type {
		};

#undef KAGUYA_CALL_FN_DEF
#undef KAGUYA_FUNC_DEF
#undef KAGUYA_FUNC_TYPE
#define KAGUYA_FUNC_DEF(N)  constructor_signature_type<ClassType KAGUYA_PP_TEMPLATE_ARG_REPEAT_CONCAT(N)>
#define KAGUYA_CALL_FN_DEF(N) \
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			inline int call(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				typedef ObjectWrapper<ClassType> wrapper_type;\
				void *storage = lua_newuserdata(state, sizeof(wrapper_type));\
				try { new(storage) wrapper_type(KAGUYA_GET_REPEAT(N)); }catch (...) { lua_pop(state, 1); throw; }\
				class_userdata::setmetatable<ClassType>(state);\
				return 1;\
			}\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>struct is_callable<KAGUYA_FUNC_DEF(N)> : traits::integral_constant<bool, true> {}; \
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool checkArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_TYPECHECK_REP);\
			}\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			bool strictCheckArgTypes(lua_State* state, KAGUYA_FUNC_DEF(N))\
			{\
				return true KAGUYA_PP_REVERSE_REPEAT(N,KAGUYA_STRICT_TYPECHECK_REP);\
			}\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			std::string argTypesName(KAGUYA_FUNC_DEF(N))\
			{\
				return std::string() KAGUYA_PP_REPEAT(N,KAGUYA_TYPENAME_REP);\
			}\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int minArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N KAGUYA_GET_OFFSET;\
			}\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			int maxArgCount(KAGUYA_FUNC_DEF(N))\
			{\
				return N KAGUYA_GET_OFFSET;\
			}
		KAGUYA_CALL_FN_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_FN_DEF)


			template<class ClassType, class FunType = void> struct ConstructorFunction;

#define KAGUYA_F_TO_CONSIG_TYPE_DEF(N)  constructor_signature_type<ClassType KAGUYA_PP_TEMPLATE_ARG_REPEAT_CONCAT(N)>
#define KAGUYA_F_TO_CONSIG_DEF(N) \
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			struct ConstructorFunction<ClassType(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>\
			{\
				typedef KAGUYA_F_TO_CONSIG_TYPE_DEF(N) type;\
			};\
			template<typename ClassType KAGUYA_PP_TEMPLATE_DEF_REPEAT_CONCAT(N)>\
			struct ConstructorFunction<ClassType,ClassType(KAGUYA_PP_TEMPLATE_ARG_REPEAT(N))>\
			{\
				typedef KAGUYA_F_TO_CONSIG_TYPE_DEF(N) type;\
			};

		KAGUYA_F_TO_CONSIG_DEF(0)
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_F_TO_CONSIG_DEF)
	}
	using nativefunction::ConstructorFunction;
}
#endif

namespace kaguya
{

	struct FunctionImpl
	{
		virtual int invoke(lua_State *state) = 0;
		virtual std::string argTypeNames()const = 0;
		virtual bool checkArgTypes(lua_State* state)const = 0;
		virtual bool strictCheckArgTypes(lua_State* state)const = 0;
		virtual int minArgCount()const=0;
		virtual int maxArgCount()const=0;
		virtual ~FunctionImpl() {}
	};
	struct PolymorphicInvoker
	{
		typedef standard::shared_ptr<FunctionImpl> holder_type;
		PolymorphicInvoker(const holder_type& fptr) :fnc(fptr) {}
		int invoke(lua_State *state)const { return fnc->invoke(state); }
		std::string argTypeNames()const { return fnc->argTypeNames(); }
		bool checkArgTypes(lua_State* state)const { return fnc->checkArgTypes(state); }
		bool strictCheckArgTypes(lua_State* state)const { return fnc->strictCheckArgTypes(state); }
		int minArgCount()const { return fnc->minArgCount(); }
		int maxArgCount()const { return fnc->maxArgCount(); }
		~PolymorphicInvoker() {}
	private:
		holder_type fnc;
	};
	struct PolymorphicMemberInvoker : PolymorphicInvoker{
		PolymorphicMemberInvoker(const holder_type& fptr) :PolymorphicInvoker(fptr) {}
	};

	namespace nativefunction
	{
		inline int call(lua_State* state, const PolymorphicInvoker& f)
		{
			return f.invoke(state);
		}
		inline int call(lua_State* state, PolymorphicInvoker& f)
		{
			return f.invoke(state);
		}
		inline bool checkArgTypes(lua_State* state, const PolymorphicInvoker& f)
		{
			return f.checkArgTypes(state);
		}
		inline bool strictCheckArgTypes(lua_State* state, const PolymorphicInvoker& f)
		{
			return f.strictCheckArgTypes(state);
		}
		inline std::string argTypesName(const PolymorphicInvoker& f)
		{
			return f.argTypeNames();
		}
		inline int minArgCount(const PolymorphicInvoker& f)
		{
			return f.minArgCount();
		}
		inline int maxArgCount(const PolymorphicInvoker& f)
		{
			return f.maxArgCount();
		}

		template<>
		struct is_callable<PolymorphicInvoker>:traits::integral_constant<bool, true> {};


		inline int call(lua_State* state, const PolymorphicMemberInvoker& f)
		{
			return f.invoke(state);
		}
		inline int call(lua_State* state, PolymorphicMemberInvoker& f)
		{
			return f.invoke(state);
		}
		inline bool checkArgTypes(lua_State* state, const PolymorphicMemberInvoker& f)
		{
			return f.checkArgTypes(state);
		}
		inline bool strictCheckArgTypes(lua_State* state, const PolymorphicMemberInvoker& f)
		{
			return f.strictCheckArgTypes(state);
		}
		inline std::string argTypesName(const PolymorphicMemberInvoker& f)
		{
			return f.argTypeNames();
		}
		inline int minArgCount(const PolymorphicMemberInvoker& f)
		{
			return f.minArgCount();
		}
		inline int maxArgCount(const PolymorphicMemberInvoker& f)
		{
			return f.maxArgCount();
		}

		template<>
		struct is_callable<PolymorphicMemberInvoker> :traits::integral_constant<bool, true> {};
	}

	class VariadicArgType
	{
	public:
		VariadicArgType(lua_State* state, int startIndex) :state_(state), startIndex_(startIndex), endIndex_(lua_gettop(state) + 1)
		{
			if (startIndex_ > endIndex_)
			{
				endIndex_ = startIndex_;
			}
		}

		template<typename T>
		operator std::vector<T>()const
		{
			if (startIndex_ >= endIndex_)
			{
				return std::vector<T>();
			}
			std::vector<T> result;
			result.reserve(endIndex_ - startIndex_);
			for (int index = startIndex_; index < endIndex_; ++index)
			{
				result.push_back(lua_type_traits<T>::get(state_, index));
			}
			return result;
		}

		struct reference :public Ref::StackRef, public detail::LuaVariantImpl<reference>
		{
			reference(lua_State* s, int index) :Ref::StackRef(s, index, false)
			{
			}

			const reference* operator->()const
			{
				return this;
			}
		};
		struct iterator
		{
			iterator(lua_State* state, int index) :state_(state), stack_index_(index)
			{
			}
			reference operator*()const
			{
				return reference(state_, stack_index_);
			}
			reference operator->()const
			{
				return reference(state_, stack_index_);
			}
			const iterator& operator++()
			{
				stack_index_++;
				return *this;
			}
			iterator operator++(int)
			{
				return iterator(state_, stack_index_++);
			}

			iterator operator+=(int n)
			{
				stack_index_ += n;
				return iterator(state_, stack_index_);
			}
			/**
			* @name relational operators
			* @brief
			*/
			//@{
			bool operator==(const iterator& other)const
			{
				return state_ == other.state_ && stack_index_ == other.stack_index_;
			}
			bool operator!=(const iterator& other)const
			{
				return !(*this == other);
			}
			//@}
		private:
			lua_State* state_;
			int stack_index_;
		};
		typedef iterator const_iterator;
		typedef reference const_reference;

		iterator begin()
		{
			return iterator(state_, startIndex_);
		}
		iterator end()
		{
			return iterator(state_, endIndex_);
		}
		const_iterator cbegin()
		{
			return const_iterator(state_, startIndex_);
		}
		const_iterator cend()
		{
			return const_iterator(state_, endIndex_);
		}


		template<typename T>
		typename lua_type_traits<T>::get_type at(size_t index)const
		{
			if (index >= size())
			{
				throw std::out_of_range("variadic arguments out of range");
			}
			return lua_type_traits<T>::get(state_, startIndex_ + static_cast<int>(index));
		}

		reference at(size_t index)const
		{
			if (index >= size())
			{
				throw std::out_of_range("variadic arguments out of range");
			}
			return reference(state_, startIndex_ + static_cast<int>(index));
		}

		reference operator[](size_t index)const
		{
			return reference(state_, startIndex_ + static_cast<int>(index));
		}
		size_t size()const
		{
			return endIndex_ - startIndex_;
		}
	private:
		lua_State* state_;
		int startIndex_;
		int endIndex_;
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for VariadicArgType
	template<> struct lua_type_traits<VariadicArgType>
	{
		typedef VariadicArgType get_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return true;
		}
		static bool checkType(lua_State* l, int index)
		{
			return true;
		}
		static get_type get(lua_State* l, int index)
		{
			return VariadicArgType(l, index);
		}
	};

	namespace nativefunction
	{
		static const int MAX_OVERLOAD_SCORE = 255;
		template<typename Fn>uint8_t compute_function_matching_score(lua_State* state, const Fn& fn)
		{
			int argcount = lua_gettop(state);


			if (strictCheckArgTypes(state, fn))
			{
				const int minargcount = minArgCount(fn);
				const int maxargcount = maxArgCount(fn);
				if (minargcount <= argcount && maxargcount >= argcount)
				{
					return MAX_OVERLOAD_SCORE;
				}
				else
				{
					int diff = std::min(std::abs(argcount - minargcount), std::abs(argcount - maxargcount));
					return std::max(100 - diff, 51);
				}
			}
			else if (checkArgTypes(state, fn))
			{
				const int minargcount = minArgCount(fn);
				const int maxargcount = maxArgCount(fn);
				if (minargcount <= argcount && maxargcount >= argcount)
				{
					return 200;
				}
				else
				{
					int diff = std::min(std::abs(argcount - minargcount), std::abs(argcount - maxargcount));
					return std::max(50 - diff, 1);
				}
			}
			else
			{
				return 0;
			}
		}
		inline int pushArgmentTypeNames(lua_State *state, int top)
		{
			for (int i = 1; i <= top; i++) {
				if (i != 1)
				{
					lua_pushliteral(state, ",");
				}

				int type = lua_type(state, i);
				if (type == LUA_TUSERDATA)
				{
					int nametype = luaL_getmetafield(state, i, "__name");
					if (nametype != LUA_TSTRING)
					{
						lua_pop(state, 1);
						lua_pushstring(state, lua_typename(state, type));
					}
				}
				else
				{
					lua_pushstring(state, lua_typename(state, type));
				}
			}
			return lua_gettop(state) - top;
		}
	}



#if KAGUYA_USE_CPP11

	namespace detail
	{
		template<typename Fn, typename... Functions> void function_match_scoring(lua_State* state, uint8_t* score_array, int current_index, const Fn& fn)
		{
			score_array[current_index] = nativefunction::compute_function_matching_score(state, fn);
		}
		template<typename Fn, typename... Functions> void function_match_scoring(lua_State* state, uint8_t* score_array, int current_index, const Fn& fn, const Functions&... fns)
		{
			score_array[current_index] = nativefunction::compute_function_matching_score(state, fn);
			if (score_array[current_index] < nativefunction::MAX_OVERLOAD_SCORE)
			{
				function_match_scoring(state, score_array, current_index + 1, fns...);
			}
		}
		template<typename... Functions> int best_function_index(lua_State* state, const Functions&... fns)
		{
			static const int fncount = sizeof...(fns);
			uint8_t score[fncount] = {};
			function_match_scoring(state, score, 0, fns...);
			uint8_t best_score = 0;
			int best_score_index = -1;
			for (int i = 0; i < fncount; ++i)
			{
				if (best_score < score[i])
				{
					best_score = score[i];
					best_score_index = i;
					if (best_score == nativefunction::MAX_OVERLOAD_SCORE)
					{
						break;
					}
				}
			}
			return best_score_index;
		}
		template<typename Fn> int invoke_index(lua_State* state, int index, int current_index, Fn&& fn)
		{
			return nativefunction::call(state, fn);
		}
		template<typename Fn, typename... Functions> int invoke_index(lua_State* state, int index, int current_index, Fn&& fn, Functions&&... fns)
		{
			if (index == current_index)
			{
				return nativefunction::call(state, fn);
			}
			else
			{
				return invoke_index(state, index, current_index + 1, fns...);
			}
		}

		template<typename Fun> int best_match_invoke(lua_State* state, Fun&& fn)
		{
			return nativefunction::call(state, fn);
		}

		template<typename Fun, typename... Functions> int best_match_invoke(lua_State* state, Fun&& fn, Functions&&... fns)
		{
			int index = best_function_index(state, fn, fns...);
			if (index >= 0)
			{
				assert(size_t(index) <= sizeof...(fns));
				return invoke_index(state, index, 0, fn, fns...);
			}
			else
			{
				throw LuaTypeMismatch("type mismatch!!");
			}
			return 0;
		}

		template<typename TupleType, std::size_t ...S> int invoke_tuple_impl(lua_State* state, TupleType&& tuple, nativefunction::index_tuple<S...>)
		{
			return best_match_invoke(state, std::get<S>(tuple)...);
		}
		template<typename TupleType> int invoke_tuple(lua_State* state, TupleType&& tuple)
		{
			typedef typename std::decay<TupleType>::type ttype;

			typedef typename nativefunction::index_range<0, std::tuple_size<ttype>::value>::type indexrange;

			return invoke_tuple_impl(state, tuple, indexrange());
		}

		template<typename Fun> void  push_arg_typename(lua_State *state,const Fun& fn)
		{
			lua_pushliteral(state, "\t\t");
			lua_pushstring(state, nativefunction::argTypesName(fn).c_str());
			lua_pushliteral(state, "\n");
		}

		template<typename Fun, typename... Functions> void  push_arg_typename(lua_State *state, const Fun& fn, const Functions&... fns)
		{
			lua_pushliteral(state, "\t\t");
			lua_pushstring(state, nativefunction::argTypesName(fn).c_str());
			lua_pushliteral(state, "\n");
			push_arg_typename(state,fns...);
		}
		template<typename TupleType, std::size_t ...S> void  push_arg_typename_tuple_impl(lua_State *state, TupleType&& tuple, nativefunction::index_tuple<S...>)
		{
			return push_arg_typename(state,std::get<S>(tuple)...);
		}
		template<typename TupleType>void push_arg_typename_tuple(lua_State *state, TupleType&& tuple)
		{
			typedef typename std::decay<TupleType>::type ttype;
			typedef typename nativefunction::index_range<0, std::tuple_size<ttype>::value>::type indexrange;

			return push_arg_typename_tuple_impl(state,tuple, indexrange());
		}
	}


#else

	namespace detail
	{
#define KAGUYA_FUNCTION_SCOREING(N) if (currentbestscore < nativefunction::MAX_OVERLOAD_SCORE) {\
		int score = nativefunction::compute_function_matching_score(state, standard::get<N - 1>(tuple));\
		if (currentbestscore < score) {\
			currentbestscore = score;\
			currentbestindex = N;\
		}\
		}
#define KAGUYA_FUNCTION_INVOKE(N) if (currentbestindex == N) {\
			 return nativefunction::call(state,  standard::get<N - 1>(tuple));\
		}\


#define KAGUYA_ARG_PUSH_TYPENAMES(N)lua_pushliteral(state, "\t\t"); lua_pushstring(state, nativefunction::argTypesName(standard::get<N-1>(tuple)).c_str());lua_pushliteral(state, "\n");
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>
#define KAGUYA_TUPLE_INVOKE_DEF(N) \
		KAGUYA_TEMPLATE_PARAMETER(N)\
		int invoke_tuple(lua_State* state, standard::tuple<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)>& tuple)\
		{\
			if(N==1){return nativefunction::call(state,  standard::get<0>(tuple));}\
			int32_t currentbestscore = 0;\
			int32_t currentbestindex = -1;\
			KAGUYA_PP_REPEAT(N, KAGUYA_FUNCTION_SCOREING);\
			KAGUYA_PP_REPEAT(N, KAGUYA_FUNCTION_INVOKE);\
			throw LuaTypeMismatch("type mismatch!!"); \
		}\
		KAGUYA_TEMPLATE_PARAMETER(N)\
		void push_arg_typename_tuple(lua_State *state,standard::tuple<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)>& tuple)\
		{\
			KAGUYA_PP_REPEAT(N, KAGUYA_ARG_PUSH_TYPENAMES);\
		}\

		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_TUPLE_INVOKE_DEF)
#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_TUPLE_INVOKE_DEF
#undef KAGUYA_ARG_TYPENAMES
#undef KAGUYA_FUNCTION_INVOKE
#undef KAGUYA_FUNCTION_SCOREING

			template<typename TupleType> int invoke_tuple(lua_State* state, TupleType& tuple)
		{
			return 0;
		}
	}
#endif



	template<typename FunctionTuple>
	struct FunctionInvokerType
	{
		FunctionTuple functions;
		FunctionInvokerType(const FunctionTuple& t) :functions(t) {}
	};
	template<typename T>
	inline FunctionInvokerType<standard::tuple<T> > function(T f)
	{
		KAGUYA_STATIC_ASSERT(nativefunction::is_callable<typename traits::decay<T>::type>::value, "argument need callable");
		return FunctionInvokerType<standard::tuple<T> >(standard::tuple<T>(f));
	}
	//specialize for lua_CFunction
	inline lua_CFunction function(lua_CFunction f)
	{
		return f;
	}


	template<typename FTYPE, typename T>
	inline FunctionInvokerType<standard::tuple<standard::function<FTYPE> > > function(T f)
	{
		return FunctionInvokerType<standard::tuple<standard::function<FTYPE> > >(standard::tuple<standard::function<FTYPE> >(standard::function<FTYPE>(f)));
	}
#if KAGUYA_USE_CPP11


	template<typename... Functions>
	FunctionInvokerType<standard::tuple<Functions...> > overload(Functions... fns)
	{
		return FunctionInvokerType<standard::tuple<Functions...> >(standard::tuple<Functions...>(fns...));
	}
#else
#define KAGUYA_DEF_TEMPLATE(N) KAGUYA_PP_CAT(typename F,N)
#define KAGUYA_TEMPLATE_ARG_DEF(N) KAGUYA_PP_CAT(F,N)
#define KAGUYA_TUPLE_ARG_DEF(N) KAGUYA_PP_CAT(f,N)
#define KAGUYA_ARG_DEF(N) KAGUYA_PP_CAT(F,N) KAGUYA_PP_CAT(f,N)
#define KAGUYA_FOVERLOAD_DEF(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_DEF_TEMPLATE)>\
		FunctionInvokerType<standard::tuple<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_TEMPLATE_ARG_DEF)> > overload(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_ARG_DEF))\
		{\
			typedef typename standard::tuple<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_TEMPLATE_ARG_DEF)> ttype;\
			return FunctionInvokerType<ttype>(ttype(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_TUPLE_ARG_DEF)));\
		}
	KAGUYA_PP_REPEAT_DEF(9, KAGUYA_FOVERLOAD_DEF)
#undef KAGUYA_DEF_TEMPLATE
#undef KAGUYA_TEMPLATE_ARG_DEF
#undef KAGUYA_TUPLE_ARG_DEF
#undef KAGUYA_ARG_DEF
#undef KAGUYA_FOVERLOAD_DEF
#endif


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctionInvokerType
	template<typename FunctionTuple> struct lua_type_traits<FunctionInvokerType<FunctionTuple> >
	{
		typedef FunctionInvokerType<FunctionTuple> userdatatype;
		typedef const FunctionInvokerType<FunctionTuple>& push_type;

		static const char* build_arg_error_message(lua_State *state,const char* msg, FunctionTuple* tuple)
		{
			int stack_top = lua_gettop(state);
			if (msg) { lua_pushstring(state, msg); }
			lua_pushliteral(state, "Argument mismatch:");
			nativefunction::pushArgmentTypeNames(state, stack_top);

			lua_pushliteral(state, "\t candidate is:\n");
			detail::push_arg_typename_tuple(state, *tuple);

			lua_concat(state, lua_gettop(state) - stack_top);
			return lua_tostring(state,-1);
		}

		static int invoke(lua_State *state)
		{
			FunctionTuple* t = static_cast<FunctionTuple*>(lua_touserdata(state, lua_upvalueindex(1)));

			if (t)
			{
				try {
					return detail::invoke_tuple(state, *t);
				}
				catch (LuaTypeMismatch &) {
					util::traceBack(state, build_arg_error_message(state, "maybe...", t));
				}
				catch (std::exception & e) {
					util::traceBack(state, e.what());
				}
				catch (...) {
					util::traceBack(state, "Unknown exception");
				}
			}
			return lua_error(state);
		}

		inline static int tuple_destructor(lua_State *state)
		{
			FunctionTuple* f = static_cast<FunctionTuple*>(lua_touserdata(state, 1));
			if (f)
			{
				f->~FunctionTuple();
			}
			return 0;
		}

		static int push(lua_State* state, push_type fns)
		{
			void* ptr = lua_newuserdata(state, sizeof(FunctionTuple));
			new(ptr) FunctionTuple(fns.functions);
			lua_createtable(state, 0, 2);
			lua_pushcclosure(state, &tuple_destructor, 0);
			lua_setfield(state, -2, "__gc");
			lua_pushvalue(state, -1);
			lua_setfield(state, -1, "__index");
			lua_setmetatable(state, -2);
			lua_pushcclosure(state, &invoke, 1);

			return 1;
		}
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for c function
	template<typename T> struct lua_type_traits < T
		, typename traits::enable_if<traits::is_function<typename traits::remove_pointer<T>::type>::value>::type >
	{
		static int push(lua_State* l, T f)
		{
			return util::one_push(l, kaguya::function(f));
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for lua_CFunction
	template<> struct lua_type_traits < lua_CFunction >
	{
		typedef lua_CFunction push_type;
		typedef lua_CFunction get_type;
		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_iscfunction(l, index) != 0;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_iscfunction(l, index) != 0;
		}
		static get_type get(lua_State* l, int index)
		{
			return lua_tocfunction(l,index);
		}
		static int push(lua_State* l, lua_CFunction f)
		{
			lua_pushcfunction(l, f);
			return 1;
		}
	};



	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for std::function or boost::function
	template<typename T> struct lua_type_traits<standard::function<T> > {
		typedef const standard::function<T>& push_type;
		typedef standard::function<T> get_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TFUNCTION;
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_type(l, index) == LUA_TFUNCTION;
		}
		static get_type get(lua_State* l, int index)
		{
			if (!l || lua_type(l, index) != LUA_TFUNCTION) {
				return get_type();
			}
			lua_pushvalue(l, index);
			return get_type(LuaFunction(l, StackTop()));
		}

		static int push(lua_State* l, push_type v)
		{
			return util::one_push(l, kaguya::function(v));
		}
	};
}



#define KAGUYA_INTERNAL_OVERLOAD_FUNCTION_GET_REP(N) kaguya::LuaStackRef(state, N)
#define KAGUYA_INTERNAL_OVERLOAD_FUNCTION_GET_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_INTERNAL_OVERLOAD_FUNCTION_GET_REP)


#define KAGUYA_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,FNAME, MINARG, MAXARG,INVOKE_TYPE)\
struct KAGUYA_PP_CAT(GENERATE_NAME,Functor) : kaguya::FunctionImpl\
{\
	virtual int invoke(lua_State *state)\
	{\
		int argcount = lua_gettop(state);\
		KAGUYA_PP_REPEAT_DEF_VA_ARG(KAGUYA_PP_INC(KAGUYA_PP_SUB(MAXARG, MINARG)), INVOKE_TYPE,FNAME,MINARG, MAXARG)\
		throw kaguya::LuaTypeMismatch("argument count mismatch");\
		return 0;\
	}\
	virtual std::string argTypeNames()const { return kaguya::nativefunction::argTypesName(FNAME); }\
	virtual bool checkArgTypes(lua_State* state)const { return true; }\
	virtual bool strictCheckArgTypes(lua_State* state)const { return true; }\
	virtual int minArgCount()const { return MINARG; }\
	virtual int maxArgCount()const { return MAXARG; }\
};\
kaguya::FunctionImpl* KAGUYA_PP_CAT(GENERATE_NAME, FunctorPtr) = new KAGUYA_PP_CAT(GENERATE_NAME, Functor);\
kaguya::PolymorphicInvoker GENERATE_NAME = kaguya::PolymorphicInvoker::holder_type(KAGUYA_PP_CAT(GENERATE_NAME, FunctorPtr));


#define KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_GET_REP(N) kaguya::LuaStackRef(state, N + 1)
#define KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_GET_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_GET_REP)


#define KAGUYA_MEMBER_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,CLASS,FNAME, MINARG, MAXARG,INVOKE_TYPE)\
struct KAGUYA_PP_CAT(GENERATE_NAME,Functor) : kaguya::FunctionImpl\
{\
	virtual int invoke(lua_State *state)\
	{\
		int argcount = lua_gettop(state);\
		CLASS* this_ = kaguya::LuaStackRef(state, 1);\
		KAGUYA_PP_REPEAT_DEF_VA_ARG(KAGUYA_PP_INC(KAGUYA_PP_SUB(MAXARG, MINARG)), INVOKE_TYPE,FNAME,MINARG, MAXARG)\
		throw kaguya::LuaTypeMismatch("argument count mismatch");\
		return 0;\
	}\
	virtual std::string argTypeNames()const { return kaguya::nativefunction::argTypesName(&CLASS::FNAME); }\
	virtual bool checkArgTypes(lua_State* state)const { return true; }\
	virtual bool strictCheckArgTypes(lua_State* state)const { return true; }\
	virtual int minArgCount()const { return MINARG + 1; }\
	virtual int maxArgCount()const { return MAXARG + 1; }\
};\
kaguya::FunctionImpl* KAGUYA_PP_CAT(GENERATE_NAME, FunctorPtr) = new KAGUYA_PP_CAT(GENERATE_NAME, Functor);\
kaguya::PolymorphicMemberInvoker GENERATE_NAME = kaguya::PolymorphicMemberInvoker::holder_type(KAGUYA_PP_CAT(GENERATE_NAME, FunctorPtr));

#define KAGUYA_INTERNAL_OVERLOAD_FUNCTION_INVOKE(N,FNAME,MINARG, MAXARG) if (argcount == KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))) { return kaguya::util::push_args(state, FNAME(KAGUYA_INTERNAL_OVERLOAD_FUNCTION_GET_REPEAT(KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))))); }
#define KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_INVOKE(N,FNAME,MINARG, MAXARG) if (argcount == 1 + KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))) { return kaguya::util::push_args(state, this_->FNAME(KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_GET_REPEAT(KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))))); }


#define KAGUYA_INTERNAL_OVERLOAD_VOID_FUNCTION_INVOKE(N,FNAME,MINARG, MAXARG) if (argcount == KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))) { FNAME(KAGUYA_INTERNAL_OVERLOAD_FUNCTION_GET_REPEAT(KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N)))); return 0; }
#define KAGUYA_INTERNAL_OVERLOAD_MEMBER_VOID_FUNCTION_INVOKE(N,FNAME,MINARG, MAXARG) if (argcount == 1 + KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N))) { this_->FNAME(KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_GET_REPEAT(KAGUYA_PP_ADD(MINARG,KAGUYA_PP_DEC(N)))); return 0; }


/// @brief Generate wrapper function object for count based overloads with nonvoid return function. Include default arguments parameter function
/// @param GENERATE_NAME generate function object name
/// @param FNAME target function name
/// @param MINARG minimum arguments count
/// @param MAXARG maximum arguments count
#define KAGUYA_FUNCTION_OVERLOADS(GENERATE_NAME,FNAME, MINARG, MAXARG) KAGUYA_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,FNAME, MINARG, MAXARG,KAGUYA_INTERNAL_OVERLOAD_FUNCTION_INVOKE)

/// @brief Generate wrapper function object for count based overloads with void return function. Include default arguments parameter function
/// @param GENERATE_NAME generate function object name
/// @param FNAME target function name
/// @param MINARG minimum arguments count
/// @param MAXARG maximum arguments count
#define KAGUYA_VOID_FUNCTION_OVERLOADS(GENERATE_NAME,FNAME, MINARG, MAXARG) KAGUYA_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,FNAME, MINARG, MAXARG,KAGUYA_INTERNAL_OVERLOAD_VOID_FUNCTION_INVOKE)

/// @brief Generate wrapper function object for count based overloads with nonvoid return function. Include default arguments parameter function
/// @param GENERATE_NAME generate function object name
/// @param CLASS target class name
/// @param FNAME target function name
/// @param MINARG minimum arguments count
/// @param MAXARG maximum arguments count
#define KAGUYA_MEMBER_FUNCTION_OVERLOADS(GENERATE_NAME,CLASS,FNAME, MINARG, MAXARG) KAGUYA_MEMBER_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,CLASS,FNAME, MINARG, MAXARG,KAGUYA_INTERNAL_OVERLOAD_MEMBER_FUNCTION_INVOKE)

/// @brief Generate wrapper function object for count based overloads with void return function. Include default arguments parameter function
/// @param GENERATE_NAME generate function object name
/// @param CLASS target class name
/// @param FNAME target function name
/// @param MINARG minimum arguments count
/// @param MAXARG maximum arguments count
#define KAGUYA_MEMBER_VOID_FUNCTION_OVERLOADS(GENERATE_NAME,CLASS,FNAME, MINARG, MAXARG) KAGUYA_MEMBER_FUNCTION_OVERLOADS_INTERNAL(GENERATE_NAME,CLASS,FNAME, MINARG, MAXARG,KAGUYA_INTERNAL_OVERLOAD_MEMBER_VOID_FUNCTION_INVOKE)

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>
#include <iostream>


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <string>
#include <vector>
#include <map>
#include <typeinfo>

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#include <memory>


namespace kaguya
{
	/// @brief any data holder class for push to lua
	class AnyDataPusher
	{
	public:
		int pushToLua(lua_State* state)const
		{
			if (empty())
			{
				lua_pushnil(state);
				return 1;
			}
			else
			{
				return holder_->pushToLua(state);
			}
		}

		AnyDataPusher() : holder_() { }

		template < typename DataType >
		AnyDataPusher(const DataType& v)
			: holder_(new DataHolder<DataType>(v)) { }

#if KAGUYA_USE_CPP11
		AnyDataPusher(AnyDataPusher&& other) : holder_(std::move(other.holder_)) { }
		AnyDataPusher & operator = (AnyDataPusher&& rhs)
		{
			holder_ = std::move(rhs.holder_);
			return *this;
		}
		template < typename DataType >
		AnyDataPusher(DataType&& v)
			: holder_(new DataHolder<DataType>(std::move(v))) { }
#endif
		AnyDataPusher(const AnyDataPusher& other)
			: holder_(other.holder_) { }
		AnyDataPusher& operator = (const AnyDataPusher& other)
		{
			holder_ = other.holder_;
			return *this;
		}

		bool empty()const { return !holder_.get(); }
	private:
		struct DataHolderBase
		{
			virtual int pushToLua(lua_State* data)const = 0;
			//			virtual DataHolderBase * clone(void) = 0;
			virtual ~DataHolderBase() {}
		};
		template < typename Type >
		class DataHolder : public DataHolderBase
		{
			typedef typename traits::decay<Type>::type DataType;
		public:
#if KAGUYA_USE_CPP11
			explicit DataHolder(DataType&& v) : data_(std::forward<DataType>(v)) { }
#else
			explicit DataHolder(const DataType& v) : data_(v){ }
#endif
			virtual int pushToLua(lua_State* state)const
			{
#if KAGUYA_USE_CPP11
				if (!standard::is_copy_constructible<DataType>::value)
				{
					return util::push_args(state, std::move(data_));
				}
#endif
				return util::push_args(state, data_);
			}
		private:
			DataType data_;
		};
		//specialize for string literal
		template<int N>	struct DataHolder<const char[N]> :DataHolder<std::string> {
			explicit DataHolder(const char* v) : DataHolder<std::string>(std::string(v, v[N - 1] != '\0' ? v + N : v + N - 1)) {}
		};
		template<int N>	struct DataHolder<char[N]> :DataHolder<std::string> {
			explicit DataHolder(const char* v) : DataHolder<std::string>(std::string(v, v[N - 1] != '\0' ? v + N : v + N - 1)) {}
		};
		standard::shared_ptr<DataHolderBase> holder_;
	};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for AnyDataPusher
	template<>	struct lua_type_traits<AnyDataPusher> {
		static int push(lua_State* l, const AnyDataPusher& data)
		{
			return data.pushToLua(l);
		}
	};
}


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>
#include <cassert>



namespace kaguya
{
	/// @brief function result value proxy class.
	/// don't direct use.
	class FunctionResults :public Ref::StackRef, public detail::LuaVariantImpl<FunctionResults>
	{
		FunctionResults(lua_State* state, int return_status, int startIndex) :Ref::StackRef(state, startIndex, true), state_(state), resultStatus_(return_status), resultCount_(lua_gettop(state) + 1 - startIndex)
		{
		}
		FunctionResults(lua_State* state, int return_status, int startIndex, int endIndex) :Ref::StackRef(state, startIndex, true), state_(state), resultStatus_(return_status), resultCount_(endIndex - startIndex)
		{
		}
		friend class detail::FunctionResultProxy;
	public:
		FunctionResults() :Ref::StackRef(), state_(0), resultStatus_(0), resultCount_(0)
		{
		}
		FunctionResults(lua_State* state) :Ref::StackRef(state, 0, true), state_(state), resultStatus_(0), resultCount_(0)
		{
		}
#if KAGUYA_USE_CPP11
		FunctionResults(FunctionResults&&src) : Ref::StackRef(std::move(src)), state_(src.state_), resultStatus_(0), resultCount_(src.resultCount_)
		{
			src.state_ = 0;
		}
#else
		FunctionResults(const FunctionResults&src) : Ref::StackRef(src), state_(src.state_), resultCount_(src.resultCount_)
		{
			src.state_ = 0;
		}
#endif

		~FunctionResults()
		{
		}

		struct reference :public Ref::StackRef, public detail::LuaVariantImpl<reference>
		{
			reference(lua_State* s, int index) :Ref::StackRef(s, index, false)
			{
			}

			reference* operator->()
			{
				return this;
			}
			const reference* operator->()const
			{
				return this;
			}
		};
		template<typename T>struct iterator_base
		{
			iterator_base(lua_State* s, int i) : state(s), stack_index(i)
			{
			}
			template<typename U>iterator_base(const iterator_base<U>& other) : state(other.state), stack_index(other.stack_index)
			{
			}
			T operator*()const
			{
				return reference(state, stack_index);
			}
			T operator->()const
			{
				return reference(state, stack_index);
			}
			const iterator_base& operator++()
			{
				stack_index++;
				return *this;
			}
			iterator_base operator++(int)
			{
				return iterator_base(state, stack_index++);
			}

			iterator_base operator+=(int n)
			{
				stack_index += n;
				return iterator_base(state, stack_index);
			}
			/**
			* @name relational operators
			* @brief
			*/
			//@{
			bool operator==(const iterator_base& other)const
			{
				return state == other.state && stack_index == other.stack_index;
			}
			bool operator!=(const iterator_base& other)const
			{
				return !(*this == other);
			}
			//@}
			int index() const { return stack_index; }
		private:
			template<typename U> friend struct iterator_base;
			lua_State* state;
			int stack_index;
		};
		typedef iterator_base<reference> iterator;
		typedef iterator_base<const reference> const_iterator;
		typedef reference const_reference;

		iterator begin()
		{
			return iterator(state_, stack_index_);
		}
		iterator end()
		{
			return iterator(state_, stack_index_ + resultCount_);
		}
		const_iterator begin()const
		{
			return const_iterator(state_, stack_index_);
		}
		const_iterator end()const
		{
			return const_iterator(state_, stack_index_ + resultCount_);
		}
		const_iterator cbegin()const
		{
			return const_iterator(state_, stack_index_);
		}
		const_iterator cend()const
		{
			return const_iterator(state_, stack_index_ + resultCount_);
		}


		template<class Result>
		Result get_result(types::typetag<Result> tag= types::typetag<Result>())const
		{
			return util::get_result<Result>(state_, stack_index_);
		}
		LuaStackRef get_result(types::typetag<LuaStackRef> tag)const
		{
			pop_ = 0;
			return LuaStackRef(state_, stack_index_, true);
		}
		lua_State* state()const { return state_; }

		template<typename T>
		typename lua_type_traits<T>::get_type result_at(size_t index)const
		{
			if (index >= result_size())
			{
				throw std::out_of_range("function result out of range");
			}
			return lua_type_traits<T>::get(state_, stack_index_ + static_cast<int>(index));
		}
		reference result_at(size_t index)const
		{
			if (index >= result_size())
			{
				throw std::out_of_range("function result out of range");
			}
			return reference(state_, stack_index_ + static_cast<int>(index));
		}

		size_t result_size()const
		{
			return resultCount_;
		}

		size_t resultStatus()const
		{
			return resultStatus_;
		}

		operator LuaStackRef()
		{
			pop_ = 0;
			return LuaStackRef(state_, stack_index_,true);
		}

	private:
		mutable lua_State* state_;
		int resultStatus_;
		int resultCount_;

	};

	namespace detail
	{
		template<typename RetType>
		inline RetType FunctionResultProxy::ReturnValue(lua_State* state, int return_status, int retindex, types::typetag<RetType> tag)
		{
			return FunctionResults(state, return_status, retindex).get_result(types::typetag<RetType>());
		}
		inline FunctionResults FunctionResultProxy::ReturnValue(lua_State* state, int return_status, int retindex, types::typetag<FunctionResults> tag)
		{
			return FunctionResults(state, return_status, retindex);
		}
		inline void FunctionResultProxy::ReturnValue(lua_State* state, int return_status, int retindex, types::typetag<void> tag)
		{
			lua_settop(state, retindex - 1);
		}

#if KAGUYA_USE_CPP11
		template<typename Derived>template<class...Args>
		FunctionResults LuaFunctionImpl<Derived>::operator()(Args&&... args)
		{
			return this->template call<FunctionResults>(std::forward<Args>(args)...);
		}

		template<typename Derived>template<class...Args>
		FunctionResults LuaThreadImpl<Derived>::operator()(Args&&... args)
		{
			return this->template resume<FunctionResults>(std::forward<Args>(args)...);
		}
		template<typename Derived>template<class...Args>
		FunctionResults LuaVariantImpl<Derived>::operator()(Args&&... args)
		{
			int t = type();
			if (t == LUA_TTHREAD)
			{
				return this->template resume<FunctionResults>(std::forward<Args>(args)...);
			}
			else if (t == LUA_TFUNCTION)
			{
				return this->template call<FunctionResults>(std::forward<Args>(args)...);
			}
			else
			{
				except::typeMismatchError(state_(), " is not function or thread");
				return FunctionResults(state_());
			}
		}
#else
#define KAGUYA_TEMPLATE_PARAMETER(N)template<typename Derived>
#define KAGUYA_FUNCTION_ARGS_DEF(N)
#define KAGUYA_CALL_ARGS(N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)

#define KAGUYA_OP_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults LuaFunctionImpl<Derived>::operator()(KAGUYA_FUNCTION_ARGS_DEF(N))\
	{\
			return this->template call<FunctionResults>(KAGUYA_CALL_ARGS(N)); \
	}\
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults LuaThreadImpl<Derived>::operator()(KAGUYA_FUNCTION_ARGS_DEF(N))\
	{\
			return this->template resume<FunctionResults>(KAGUYA_CALL_ARGS(N)); \
	}\
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline FunctionResults LuaVariantImpl<Derived>::operator()(KAGUYA_FUNCTION_ARGS_DEF(N))\
	{\
			int t = type();\
			if (t == LUA_TTHREAD)\
			{\
				return this->template resume<FunctionResults>(KAGUYA_CALL_ARGS(N)); \
			}\
			else if (t == LUA_TFUNCTION)\
			{\
				return this->template call<FunctionResults>(KAGUYA_CALL_ARGS(N)); \
			}\
			else\
			{\
				except::typeMismatchError(state_(), " is not function or thread");\
				return FunctionResults(state_());\
			}\
	}

		KAGUYA_OP_FN_DEF(0)

#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_CALL_ARGS
#define KAGUYA_TEMPLATE_PARAMETER(N) template<typename Derived> template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>
#define KAGUYA_FUNCTION_ARGS_DEF(N) KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG)
#define KAGUYA_CALL_ARGS(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PUSH_ARG_DEF)

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PUSH_ARG_DEF(N) KAGUYA_PP_CAT(a,N) 

			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_OP_FN_DEF)
#undef KAGUYA_OP_FN_DEF
#undef KAGUYA_TEMPLATE_PARAMETER

#undef KAGUYA_CALL_ARGS
#undef KAGUYA_FUNCTION_ARGS_DEF
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_CALL_DEF
#undef KAGUYA_OP_FN_DEF
#endif
	}

	inline std::ostream& operator<<(std::ostream& os, const FunctionResults& res)
	{
		for (FunctionResults::const_iterator it = res.begin(); it != res.end(); ++it)
		{
			if (it != res.begin())
			{
				os << ",";
			}
			util::stackValueDump(os, res.state(), it.index());
		}

		return os;
	}


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctionResults
	template<>	struct lua_type_traits<FunctionResults> {
		static int push(lua_State* l, const FunctionResults& ref)
		{
			int size = 0;
			for (FunctionResults::const_iterator it = ref.cbegin(); it != ref.cend(); ++it)
			{
				size += it->push(l);
			}
			return size;
		}
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctionResults::reference
	template<>	struct lua_type_traits<FunctionResults::reference> {
		static int push(lua_State* l, const FunctionResults::reference& ref)
		{
			return ref.push(l);
		}
	};
	template <unsigned int I>
	FunctionResults::reference get(const FunctionResults& res) { return res.result_at(I); }

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaFunction
	template<>	struct lua_type_traits<LuaFunction> {
		typedef LuaFunction get_type;
		typedef LuaFunction push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_isfunction(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isfunction(l, index) || lua_isnil(l, index);
		}
		static LuaFunction get(lua_State* l, int index)
		{
			lua_pushvalue(l, index);
			return LuaFunction(l, StackTop());
		}
		static int push(lua_State* l, const LuaFunction& ref)
		{
			return ref.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaFunction
	template<>	struct lua_type_traits<const LuaFunction&> :lua_type_traits<LuaFunction> {};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaThread
	template<>	struct lua_type_traits<LuaThread> {
		typedef LuaThread get_type;
		typedef LuaThread push_type;

		static bool strictCheckType(lua_State* l, int index)
		{
			return lua_isthread(l, index);
		}
		static bool checkType(lua_State* l, int index)
		{
			return lua_isthread(l, index) || lua_isnil(l, index);
		}
		static LuaThread get(lua_State* l, int index)
		{
			lua_pushvalue(l, index);
			return LuaThread(l, StackTop());
		}
		static int push(lua_State* l, const LuaThread& ref)
		{
			return ref.push(l);
		}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaThread
	template<>	struct lua_type_traits<const LuaThread&> :lua_type_traits<LuaThread> {};



	/**
	* @brief table and function binder.
	* state["table"]->*"fun"() is table:fun() in Lua
	* @param arg... function args
	*/
	class MemberFunctionBinder
	{
	public:
		template<class T>
		MemberFunctionBinder(LuaRef self, T key) :self_(self), fun_(self_.getField(key))
		{
		}

#define KAGUYA_DELEGATE_LUAREF fun_
#define KAGUYA_DELEGATE_FIRST_ARG self_
#define KAGUYA_DELEGATE_FIRST_ARG_C KAGUYA_DELEGATE_FIRST_ARG,

#if KAGUYA_USE_CPP11
		template<class... Args>
		FunctionResults operator()(Args&&... args)
		{
			return KAGUYA_DELEGATE_LUAREF(KAGUYA_DELEGATE_FIRST_ARG_C std::forward<Args>(args)...);
		}

		template<class Result, class... Args>
		Result call(Args&&... args)
		{
			return KAGUYA_DELEGATE_LUAREF.call<Result>(KAGUYA_DELEGATE_FIRST_ARG_C std::forward<Args>(args)...);
		}
#else

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_PUSH_ARG_DEF(N) KAGUYA_PP_CAT(a,N)
#define KAGUYA_OP_FN_DEF(N) \
		template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)> \
		FunctionResults operator()(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			return KAGUYA_DELEGATE_LUAREF(KAGUYA_DELEGATE_FIRST_ARG_C KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PUSH_ARG_DEF));\
		}

		/**
		* @brief If type is function, call lua function.
		* If type is lua thread,start or resume lua thread.
		* Otherwise send error message to error handler
		*/
		FunctionResults operator()()
		{
			return KAGUYA_DELEGATE_LUAREF(KAGUYA_DELEGATE_FIRST_ARG);
		}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_OP_FN_DEF)

#define KAGUYA_CALL_DEF(N) \
		template<class Result,KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)> \
		Result call(KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			return KAGUYA_DELEGATE_LUAREF.call<Result>(KAGUYA_DELEGATE_FIRST_ARG_C KAGUYA_PP_REPEAT_ARG(N, KAGUYA_PUSH_ARG_DEF));\
		}

			template<class Result>
		Result call()
		{
			return KAGUYA_DELEGATE_LUAREF.call<Result>(KAGUYA_DELEGATE_FIRST_ARG);
		}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_CALL_DEF)

#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_PUSH_ARG_DEF
#undef KAGUYA_OP_FN_DEF
#undef KAGUYA_CALL_DEF
#undef KAGUYA_RESUME_DEF
#endif

#undef KAGUYA_DELEGATE_FIRST_ARG_C
#undef KAGUYA_DELEGATE_FIRST_ARG
#undef KAGUYA_DELEGATE_LUAREF

	private:
		LuaRef self_;//Table or Userdata
		LuaFunction fun_;
	};

	typedef MemberFunctionBinder mem_fun_binder;//for backward conpatible
}

#define KAGUYA_PROPERTY_PREFIX "_prop_"

namespace kaguya
{
	template<class A1, class A2 = void
		, class A3 = void, class A4 = void, class A5 = void
		, class A6 = void, class A7 = void, class A8 = void,
		class A9 = void>struct MultipleBase {
	};
}

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


namespace kaguya
{

	namespace nativefunction
	{
		inline std::string argmentTypes(lua_State *state)
		{
			int top = lua_gettop(state);

			std::string result = "";

			for (int i = 1; i <= top; i++) {
				if (i != 1)
				{
					result += ",";
				}

				ObjectWrapperBase* object = object_wrapper(state, i);
				if (object)
				{
					result += object->type().name();
				}
				else
				{
					result += lua_typename(state, lua_type(state, i));
				}
			}
			return result;
		}

		struct BaseInvoker
		{
			virtual int invoke(lua_State *state) = 0;
			virtual std::string argumentTypeNames() = 0;
			virtual uint8_t argsMatchingScore(lua_State* state) = 0;
			virtual ~BaseInvoker() {}
		};

		//! deperecated
		struct FunctorType :standard::shared_ptr<BaseInvoker>
		{
			typedef standard::shared_ptr<BaseInvoker> base_ptr_;
			FunctorType() {}
			FunctorType(const standard::shared_ptr<BaseInvoker>& ptr) :base_ptr_(ptr) {}

			template<typename T>FunctorType(T f) : standard::shared_ptr<BaseInvoker>(create(f))
			{
			}
		private:
			template<typename F>
			struct FunInvoker :BaseInvoker {
				typedef F func_type;
				func_type func_;
				FunInvoker(func_type fun) :func_(fun) {}
				virtual int invoke(lua_State *state)
				{
					int count = call(state, func_);

					return count;

				}
				virtual std::string argumentTypeNames() {
					return argTypesName(func_);
				}
				virtual uint8_t argsMatchingScore(lua_State* state) {
					return compute_function_matching_score(state, func_);
				}
			};
			template<typename F>
			static base_ptr_ create(F fun)
			{
				KAGUYA_STATIC_ASSERT(nativefunction::is_callable<typename traits::decay<F>::type>::value, "argument need callable");

				typedef FunInvoker<F> InvokerType;
				return base_ptr_(new InvokerType(fun));
			}
		};


		inline FunctorType* pick_match_function(lua_State *l)
		{
			int overloadnum = int(lua_tonumber(l, lua_upvalueindex(1)));

			if (overloadnum == 1)
			{
				FunctorType* fun = static_cast<FunctorType*>(lua_touserdata(l, lua_upvalueindex(2)));

				//skip type check for performance
//				if (!fun || !(*fun) || !(*fun)->checktype(l, false))
//				{
//					return 0;
//				}
				return fun;
			}
			FunctorType* match_function = 0;
			uint8_t match_score = 0;
			for (int i = 0; i < overloadnum; ++i)
			{
				FunctorType* fun = static_cast<FunctorType*>(lua_touserdata(l, lua_upvalueindex(i + 2)));
				if (!fun || !(*fun))
				{
					continue;
				}
				uint8_t score = (*fun)->argsMatchingScore(l);
				if (match_score < score)
				{
					match_function = fun;
					match_score = score;
					if (match_score == MAX_OVERLOAD_SCORE)
					{
						return match_function;
					}
				}
			}
			return match_function;
		}

		inline std::string build_arg_error_message(lua_State *l)
		{
			std::string message = "Argument mismatch:" + argmentTypes(l) + "\t candidate is:\n";

			int overloadnum = int(lua_tonumber(l, lua_upvalueindex(1)));
			for (int i = 0; i < overloadnum; ++i)
			{
				FunctorType* fun = static_cast<FunctorType*>(lua_touserdata(l, lua_upvalueindex(i + 2)));
				if (!fun || !(*fun))
				{
					continue;
				}
				message += std::string("\t\t") + (*fun)->argumentTypeNames() + "\n";
			}
			return message;
		}

		inline int functor_dispatcher(lua_State *l)
		{
			FunctorType* fun = pick_match_function(l);
			if (fun && (*fun))
			{
				try {
					return (*fun)->invoke(l);
				}
				catch (LuaTypeMismatch &) {
					util::traceBack(l, (std::string("maybe...") + build_arg_error_message(l)).c_str());
				}
				catch (std::exception & e) {
					util::traceBack(l, e.what());
				}
				catch (...) {
					util::traceBack(l, "Unknown exception");
				}
			}
			else
			{
				util::traceBack(l, build_arg_error_message(l).c_str());
			}
			return lua_error(l);
		}

		inline int functor_destructor(lua_State *state)
		{
			FunctorType* f = static_cast<FunctorType*>(lua_touserdata(state, 1));
			if (f)
			{
				f->~FunctorType();
			}
			return 0;
		}
		
		inline void reg_functor_destructor(lua_State* state)
		{
			if (class_userdata::newmetatable<FunctorType>(state))
			{
				lua_pushcclosure(state, &functor_destructor, 0);
				lua_setfield(state, -2, "__gc");
				lua_setfield(state, -1, "__index");
			}
		}
	}
	typedef nativefunction::FunctorType FunctorType;
	typedef std::vector<FunctorType> FunctorOverloadType;


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctorType(deprecated)
	template<> struct lua_type_traits<FunctorType> {
		typedef FunctorType get_type;
		typedef FunctorType push_type;
		static int push(lua_State* l, const FunctorType& f)
		{
			lua_pushnumber(l, 1);//no overload
			void *storage = lua_newuserdata(l, sizeof(FunctorType));
			new(storage) FunctorType(f);
			class_userdata::setmetatable<FunctorType>(l);
			lua_pushcclosure(l, &nativefunction::functor_dispatcher, 2);
			return 1;
		}
#if KAGUYA_USE_RVALUE_REFERENCE
		static int push(lua_State* l, FunctorType&& f)
		{
			lua_pushnumber(l, 1);//no overload
			void *storage = lua_newuserdata(l, sizeof(FunctorType));
			new(storage) FunctorType(std::forward<FunctorType>(f));
			class_userdata::setmetatable<FunctorType>(l);
			lua_pushcclosure(l, &nativefunction::functor_dispatcher, 2);
			return 1;
		}
#endif
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctorType(deprecated)
	template<>	struct lua_type_traits<const FunctorType&> :lua_type_traits<FunctorType> {};


	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for FunctorOverloadType(deprecated)
	template<>	struct lua_type_traits<FunctorOverloadType> {
		typedef const FunctorOverloadType& push_type;

		static int push(lua_State* l, push_type fns)
		{
			lua_pushnumber(l, static_cast<lua_Number>(fns.size()));
			for (FunctorOverloadType::const_iterator f = fns.begin(); f != fns.end(); ++f)
			{
				void *storage = lua_newuserdata(l, sizeof(FunctorType));
				new(storage) FunctorType(*f);
				class_userdata::setmetatable<FunctorType>(l);
			}
			lua_pushcclosure(l, &nativefunction::functor_dispatcher, static_cast<int>(fns.size() + 1));
			return 1;
		}
	};
}

namespace kaguya
{
	//!ClassMetatable is deprecated. use UserdataMetatable instead.
	template<typename class_type, typename base_class_type = void>
	struct ClassMetatable
	{
		typedef std::vector<FunctorType> FunctorOverloadType;
		typedef std::map<std::string, FunctorOverloadType> FuncMapType;
		typedef std::map<std::string, FunctorType> PropMapType;

		typedef std::map<std::string, AnyDataPusher> MemberMapType;
		typedef std::map<std::string, std::string> CodeChunkMapType;


		ClassMetatable()
		{
			addStaticFunction("__gc", &class_userdata::destructor<ObjectWrapperBase>);

			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value || !traits::is_std_vector<class_type>::value, "std::vector is binding to lua-table by default.If you wants register for std::vector yourself,"
				"please define KAGUYA_NO_STD_VECTOR_TO_TABLE");

			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value || !traits::is_std_map<class_type>::value, "std::map is binding to lua-table by default.If you wants register for std::map yourself,"
				"please define KAGUYA_NO_STD_MAP_TO_TABLE");

			//can not register push specialized class
			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value,
				"Can not register specialized of type conversion class. e.g. std::tuple");
		}

		LuaTable registerClass(lua_State* state)const
		{
			util::ScopedSavedStack save(state);
			if (class_userdata::newmetatable<class_type>(state))
			{
				LuaTable metatable(state, StackTop());
				metatable.push();
				registerMember(state);

				if (!traits::is_same<base_class_type, void>::value || !property_map_.empty())//if base class has property and derived class hasnt property. need property access metamethod
				{
					for (PropMapType::const_iterator it = property_map_.begin(); it != property_map_.end(); ++it)
					{
						if (util::one_push(state, it->second))
						{
							lua_setfield(state, -2, ("_prop_" + it->first).c_str());
						}
					}
					LuaFunction indexfun = kaguya::LuaFunction::loadstring(state, "local arg = {...};local metatable = arg[1];"
						"return function(table, index)"
						//						" if type(table) == 'userdata' then "
						" local propfun = metatable['_prop_'..index];"
						" if propfun then return propfun(table) end "
						//						" end "
						" return metatable[index]"
						" end")(metatable);

					metatable.setField("__index", indexfun);

					LuaFunction newindexfn = LuaFunction::loadstring(state, "local arg = {...};local metatable = arg[1];"
						" return function(table, index, value) "
						" if type(table) == 'userdata' then "
						" local propfun = metatable['_prop_'..index];"
						" if propfun then return propfun(table,value) end "
						" end "
						" rawset(table,index,value) "
						" end")(metatable);
					metatable.setField("__newindex", newindexfn);
				}
				else
				{
					metatable.setField("__index", metatable);
				}

				set_base_metatable(state, metatable, types::typetag<base_class_type>());

				return metatable;
			}
			else
			{
				except::OtherError(state, typeid(class_type*).name() + std::string(" is already registered"));
			}
			return LuaTable();
		}

#if KAGUYA_USE_CPP11
		template<typename... Args>
		ClassMetatable& addConstructor()
		{
			typedef typename nativefunction::constructor_signature_type<class_type, Args...> cons;
			function_map_["new"].push_back(cons());
			return *this;
		}
#else
#define KAGUYA_TEMPLATE_PARAMETER(N)
#define KAGUYA_ADD_CON_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline ClassMetatable& addConstructor()\
	{\
		typedef typename nativefunction::constructor_signature_type<class_type KAGUYA_PP_TEMPLATE_ARG_REPEAT_CONCAT(N)> cons;\
		function_map_["new"].push_back(cons());\
		return *this;\
	}
		KAGUYA_ADD_CON_FN_DEF(0)
#undef KAGUYA_TEMPLATE_PARAMETER
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>
			KAGUYA_PP_REPEAT_DEF(9, KAGUYA_ADD_CON_FN_DEF)
#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_ADD_CON_FN_DEF

#endif
			//variadic arguments constructor(receive const std::vector<LuaRef>&)
			//		template<>ClassMetatable& addConstructor(types::typetag<VariadicArgType>* )
			ClassMetatable& addConstructorVariadicArg()
		{
			typedef typename nativefunction::constructor_signature_type<class_type, VariadicArgType> cons;
			function_map_["new"].push_back(FunctorType(cons()));
			return *this;
		}

#if defined(_MSC_VER) && _MSC_VER <= 1800
		//deprecated
		//can not write  Ret class_type::* f on MSC++2013
		template<typename Fun>
		KAGUYA_DEPRECATED_FEATURE("ClassMetatable is deprecated. use UserdataMetatable instead.") ClassMetatable& addMember(const char* name, Fun f)
		{
			return addMemberFunction(name, f);
		}
		//deprecated
		//can not write  Ret class_type::* f on MSC++2013
		template<typename Fun>
		ClassMetatable& addMemberFunction(const char* name, Fun f)
		{
			if (has_key(name, true))
			{
				//already registered
				return *this;
			}
			addFunction(name, f);
			return *this;
		}
#else
		//deprecated
		template<typename Ret>
		KAGUYA_DEPRECATED_FEATURE("ClassMetatable is deprecated. use UserdataMetatable instead.") ClassMetatable& addMember(const char* name, Ret class_type::* f)
		{
			return addMemberFunction(name, f);
		}
		template<typename Ret>
		ClassMetatable& addMemberFunction(const char* name, Ret class_type::* f)
		{
			if (has_key(name, true))
			{
				//already registered
				return *this;
			}
			addFunction(name, f);
			return *this;
		}
#endif
		//add member property
		template<typename Ret>
		ClassMetatable& addProperty(const char* name, Ret class_type::* mem)
		{
			property_map_[name] = FunctorType(mem);
			return *this;
		}


		//! deprecated
		template<typename Fun>
		ClassMetatable& addStaticMember(const char* name, Fun f)
		{
			return addStaticFunction(name, f);
		}
		//! deprecated
		template<typename Fun>
		ClassMetatable& addStaticFunction(const char* name, Fun f)
		{
			if (has_key(name, true))
			{
				//already registered
				return *this;
			}
			addFunction(name, f);
			return *this;
		}

		//add field to
		ClassMetatable& addCodeChunkResult(const char* name, const std::string& lua_code_chunk)
		{
			code_chunk_map_[name] = lua_code_chunk;
			return *this;
		}


		template<typename Data>
		ClassMetatable& addStaticField(const char* name, const Data& f)
		{
			if (has_key(name))
			{
				//already registered
				return *this;
			}
			member_map_[name] = AnyDataPusher(f);
			return *this;
		}


#if KAGUYA_USE_CPP11
		template<typename Data>
		ClassMetatable& addStaticField(const char* name, Data&& f)
		{
			if (has_key(name))
			{
				//already registered
				return *this;
			}
			member_map_[name] = AnyDataPusher(std::move(f));
			return *this;
		}
#endif

	private:

		void set_base_metatable(lua_State* state, LuaTable& metatable, types::typetag<void>)const
		{
		}
		template<class Base>
		void set_base_metatable(lua_State* state, LuaTable& metatable, types::typetag<Base>)const
		{
			class_userdata::get_metatable<Base>(state);
			metatable.setMetatable(LuaTable(state, StackTop()));

			PointerConverter& pconverter = PointerConverter::get(state);
			pconverter.add_type_conversion<Base, class_type>();
		}

		void set_multiple_base(lua_State* state, LuaTable& metatable, const LuaTable& metabases)const
		{
			LuaTable newmeta(state, NewTable());

			LuaFunction indexfun = kaguya::LuaFunction::loadstring(state, "local arg = {...};local metabases = arg[1];"
				"return function(t, k)"
				" for i = 1,#metabases do "
				" local v = metabases[i][k] "
				" if v then "
				" t[k] = v "
				" return v end "
				" end"
				" end")(metabases);

			newmeta.setField("__index", indexfun);

			metatable.setMetatable(newmeta);

		}
#if KAGUYA_USE_CPP11

		template<typename Base>
		void metatables(lua_State* state, LuaTable& metabases, PointerConverter& pvtreg, types::typetag<MultipleBase<Base> >)const
		{
			class_userdata::get_metatable<Base>(state);
			metabases.setField(metabases.size() + 1, LuaTable(state, StackTop()));
			pvtreg.add_type_conversion<Base, class_type>();
		}
		template<typename Base, typename... Remain>
		void metatables(lua_State* state, LuaTable& metabases, PointerConverter& pvtreg, types::typetag<MultipleBase<Base, Remain...> >)const
		{
			class_userdata::get_metatable<Base>(state);
			metabases.setField(metabases.size() + 1, LuaTable(state, StackTop()));
			pvtreg.add_type_conversion<Base, class_type>();
			metatables(state, metabases, pvtreg, types::typetag<MultipleBase<Remain...> >());
		}

		template<typename... Bases>
		void set_base_metatable(lua_State* state, LuaTable& metatable, types::typetag<MultipleBase<Bases...> > metatypes)const
		{
			PointerConverter& pconverter = PointerConverter::get(state);
			LuaTable metabases(state, NewTable(sizeof...(Bases), 0));
			metatables(state, metabases, pconverter, metatypes);
			set_multiple_base(state, metatable, metabases);
		}

#else
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>
#define KAGUYA_GET_BASE_METATABLE(N) class_userdata::get_metatable<KAGUYA_PP_CAT(A,N)>(state);\
		metabases.setField(metabases.size() + 1, LuaTable(state, StackTop())); \
		pconverter.add_type_conversion<KAGUYA_PP_CAT(A,N),class_type>();
#define KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
		void set_base_metatable(lua_State* state, LuaTable& metatable, types::typetag<MultipleBase<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)> > metatypes)const\
		{\
			PointerConverter& pconverter = PointerConverter::get(state);\
			LuaTable metabases(state, NewTable(N, 0));\
			KAGUYA_PP_REPEAT(N, KAGUYA_GET_BASE_METATABLE); \
			set_multiple_base(state, metatable, metabases);\
		}\

		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF)
#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF
#undef KAGUYA_GET_BASE_METATABLE
#undef KAGUYA_TYPE_CHECK_REP
#endif

			bool has_key(const std::string& key, bool exclude_function = false)
		{
			if (!exclude_function && function_map_.find(key) != function_map_.end())
			{
				return true;
			}
			if (member_map_.find(key) != member_map_.end())
			{
				return true;
			}
			return false;
		}
		void registerFunction(lua_State* state, const char* name, const FunctorOverloadType& func_array)const
		{
			if (util::one_push(state, func_array))
			{
				lua_setfield(state, -2, name);
			}
		}
		void registerField(lua_State* state, const char* name, const AnyDataPusher& value)const
		{
			int count = value.pushToLua(state);
			if (count > 1)
			{
				lua_pop(state, count - 1);
				count = 1;
			}
			if (count == 1)
			{
				lua_setfield(state, -2, name);
			}
		}
		void registerCodeChunk(lua_State* state, const char* name, std::string value)const
		{
			util::ScopedSavedStack save(state);
			int status = luaL_loadstring(state, value.c_str());
			if (!except::checkErrorAndThrow(status, state)) { return; }
			status = lua_pcall_wrap(state, 0, 1);
			if (!except::checkErrorAndThrow(status, state)) { return; }
			lua_setfield(state, -2, name);
		}

		void registerMember(lua_State* state)const
		{
			for (typename FuncMapType::const_iterator it = function_map_.begin(); it != function_map_.end(); ++it)
			{
				registerFunction(state, it->first.c_str(), it->second);
			}
			for (typename MemberMapType::const_iterator it = member_map_.begin(); it != member_map_.end(); ++it)
			{
				registerField(state, it->first.c_str(), it->second);
			}
			for (typename CodeChunkMapType::const_iterator it = code_chunk_map_.begin(); it != code_chunk_map_.end(); ++it)
			{
				registerCodeChunk(state, it->first.c_str(), it->second);
			}
		}
		template<typename Fun>
		ClassMetatable& addFunction(const char* name, Fun f)
		{
			function_map_[name].push_back(FunctorType(f));
			return *this;
		}
		FuncMapType function_map_;
		PropMapType property_map_;
		MemberMapType member_map_;
		CodeChunkMapType code_chunk_map_;
	};
}

namespace kaguya
{
	struct LuaCodeChunk
	{
		LuaCodeChunk(const std::string& src) :code_(src) {}
		LuaCodeChunk(const char* src) :code_(src) {}
		std::string code_;
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaCodeChunk
	template<>	struct lua_type_traits<LuaCodeChunk> {
		static int push(lua_State* state, const LuaCodeChunk& ref)
		{
			int status = luaL_loadstring(state, ref.code_.c_str());
			if (!except::checkErrorAndThrow(status, state)) { return 0; }
			return 1;
		}
	};
	struct LuaCodeChunkResult : LuaCodeChunk {
		LuaCodeChunkResult(const std::string& src) :LuaCodeChunk(src) {}
		LuaCodeChunkResult(const char* src) :LuaCodeChunk(src) {}
	};
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for LuaCodeChunkResult
	template<>	struct lua_type_traits<LuaCodeChunkResult> {
		static int push(lua_State* state, const LuaCodeChunkResult& ref)
		{
			int status = luaL_loadstring(state, ref.code_.c_str());
			if (!except::checkErrorAndThrow(status, state)) { return 0; }
			status = lua_pcall_wrap(state, 0, 1);
			if (!except::checkErrorAndThrow(status, state)) { return 0; }
			return 1;
		}
	};

	namespace detail
	{
		inline bool is_property_key(const char* keyname)
		{
			return keyname && strncmp(keyname, KAGUYA_PROPERTY_PREFIX, sizeof(KAGUYA_PROPERTY_PREFIX) - 1) != 0;
		}
		inline int property_index_function(lua_State* L)
		{
			//Lua
			//local arg = {...};local metatable = arg[1];
			//return function(table, index)
			//if string.find(index,KAGUYA_PROPERTY_PREFIX)~=0 then 
			//local propfun = metatable[KAGUYA_PROPERTY_PREFIX ..index];
			//if propfun then return propfun(table) end 
			//end 
			//return metatable[index]
			//end
			static const int table = 1;
			static const int key = 2;
			static const int metatable = lua_upvalueindex(1);
			const char* strkey = lua_tostring(L, key);

			if (lua_type(L, 1) == LUA_TUSERDATA && is_property_key(strkey))
			{
				int type = lua_getfield_rtype(L, metatable, (KAGUYA_PROPERTY_PREFIX + std::string(strkey)).c_str());
				if (type == LUA_TFUNCTION)
				{
					lua_pushvalue(L, table);
					lua_call(L, 1, 1);
					return 1;
				}
			}
			lua_pushvalue(L, key);
			lua_gettable(L, metatable);
			return 1;
		}
		inline int property_newindex_function(lua_State* L)
		{
			//Lua
			//local arg = {...};local metatable = arg[1];
			// return function(table, index, value) 
			// if type(table) == 'userdata' then 
			// if string.find(index,KAGUYA_PROPERTY_PREFIX)~=0 then 
			// local propfun = metatable[KAGUYA_PROPERTY_PREFIX..index];
			// if propfun then return propfun(table,value) end 
			// end 
			// end 
			// rawset(table,index,value) 
			// end
			static const int table = 1;
			static const int key = 2;
			static const int value = 3;
			static const int metatable = lua_upvalueindex(1);
			const char* strkey = lua_tostring(L, 2);

			if (lua_type(L, 1) == LUA_TUSERDATA && is_property_key(strkey))
			{
				int type = lua_getfield_rtype(L, metatable, (KAGUYA_PROPERTY_PREFIX + std::string(strkey)).c_str());
				if (type == LUA_TFUNCTION)
				{
					lua_pushvalue(L, table);
					lua_pushvalue(L, value);
					lua_call(L, 2, 0);
					return 0;
				}
			}
			lua_pushvalue(L, key);
			lua_pushvalue(L, value);
			lua_rawset(L, table);
			return 0;
		}


		inline int multiple_base_index_function(lua_State* L)
		{
			//Lua
			//local arg = {...};local metabases = arg[1];
			//return function(t, k)
			// for i = 1,#metabases do 
			// local v = metabases[i][k] 
			// if v then 
			// t[k] = v 
			// return v end 
			// end
			//end
			static const int table = 1;
			static const int key = 2;
			static const int metabases = lua_upvalueindex(1);

			lua_pushnil(L);
			while (lua_next(L, metabases) != 0)
			{
				if (lua_type(L, -1) == LUA_TTABLE)
				{
					lua_pushvalue(L, key);
					int type = lua_gettable_rtype(L, -2);
					if (type != LUA_TNIL)
					{
						lua_pushvalue(L, key);
						lua_pushvalue(L, -2);
						lua_settable(L, table);
						return 1;
					}
				}
				lua_settop(L, 3);//pop value
			}
			return 0;
		}
	}

	template<typename class_type, typename base_class_type = void>
	class UserdataMetatable
	{
		typedef std::map<std::string, AnyDataPusher> PropMapType;
		typedef std::map<std::string, AnyDataPusher> MemberMapType;
	public:

		UserdataMetatable()
		{
			addStaticFunction("__gc", &class_userdata::destructor<ObjectWrapperBase>);

			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value || !traits::is_std_vector<class_type>::value, "std::vector is binding to lua-table by default.If you wants register for std::vector yourself,"
				"please define KAGUYA_NO_STD_VECTOR_TO_TABLE");

			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value || !traits::is_std_map<class_type>::value, "std::map is binding to lua-table by default.If you wants register for std::map yourself,"
				"please define KAGUYA_NO_STD_MAP_TO_TABLE");

			//can not register push specialized class
			KAGUYA_STATIC_ASSERT(is_registerable<class_type>::value,
				"Can not register specialized of type conversion class. e.g. std::tuple");
		}

		LuaTable createMatatable(lua_State* state)const
		{
			util::ScopedSavedStack save(state);
			if (!class_userdata::newmetatable<class_type>(state))
			{
				except::OtherError(state, typeid(class_type*).name() + std::string(" is already registered"));
				return LuaTable();
			}
			LuaStackRef metatable(state, -1);
			registerMember(state);

			if (!traits::is_same<base_class_type, void>::value || !property_map_.empty())//if base class has property and derived class hasnt property. need property access metamethod
			{

				if (member_map_.count("__index") == 0)
				{
					metatable.push(state);
					lua_pushcclosure(state, &detail::property_index_function, 1);
					LuaStackRef indexfun(state, -1);
					metatable.setRawField("__index", indexfun);
				}



				if (member_map_.count("__newindex") == 0)
				{
					metatable.push(state);
					lua_pushcclosure(state, &detail::property_newindex_function, 1);
					LuaStackRef newindexfun(state, -1);
					metatable.setRawField("__newindex", newindexfun);
				}
			}
			else
			{
				if (member_map_.count("__index") == 0)
				{
					metatable.setRawField("__index", metatable);
				}
			}

			set_base_metatable(state, metatable, types::typetag<base_class_type>());

			class_userdata::get_call_constructor_metatable(state);
			LuaStackRef call_construct_table(state, -1, true);
			LuaTable basemetatable = metatable.getMetatable();
			if (basemetatable)
			{
				basemetatable.setRawField("__call",call_construct_table.getRawField("__call"));
			}
			else
			{
				metatable.setMetatable(call_construct_table);
			}

			return metatable;
		}


#if KAGUYA_USE_CPP11
		template<typename... ArgTypes>
		UserdataMetatable& setConstructors()
		{
			addOverloadedFunctions("new", typename ConstructorFunction<class_type, ArgTypes>::type()...);
			return *this;
		}
#else
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>		
#define KAGUYA_SET_CON_TYPE_DEF(N) typename ConstructorFunction<class_type,KAGUYA_PP_CAT(A,N)>::type()
#define KAGUYA_SET_CON_FN_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
	inline UserdataMetatable& setConstructors()\
	{\
		addOverloadedFunctions("new",KAGUYA_PP_REPEAT_ARG(N,KAGUYA_SET_CON_TYPE_DEF));\
		return *this;\
	}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_SET_CON_FN_DEF)
#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_SET_CON_FN_DEF
#undef KAGUYA_SET_CON_TYPE_DEF

#endif


		/// @brief add member property with getter function.(experimental)
		/// @param name function name for lua
		/// @param mem bind member data
		template<typename Ret>
		UserdataMetatable& addProperty(const char* name, Ret class_type::* mem)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			property_map_[name] = AnyDataPusher(kaguya::function(mem));
			return *this;
		}

		/// @brief add member property with getter function.(experimental)
		/// @param name function name for lua
		/// @param getter getter function
		template<typename GetType>
		UserdataMetatable& addProperty(const char* name, GetType(class_type::*getter)()const)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			property_map_[name] = AnyDataPusher(kaguya::function(getter));
			return *this;
		}

		/// @brief add member property with setter, getter functions.(experimental)
		/// @param name function name for lua
		/// @param getter getter function
		/// @param setter setter function
		template<typename GetType, typename SetType>
		UserdataMetatable& addProperty(const char* name, GetType(class_type::*getter)()const, void (class_type::*setter)(SetType))
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			property_map_[name] = AnyDataPusher(overload(getter, setter));
			return *this;
		}

		/// @brief add non member function
		/// @param name function name for lua
		/// @param f function
		template<typename Fun>
		UserdataMetatable& addStaticFunction(const char* name, Fun f)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			member_map_[name] = AnyDataPusher(kaguya::function(f));
			return *this;
		}

		/// @brief assign data by return value from evaluate code chunk. 
		/// this function is deprecated.  use addStaticField(kaguya::LuaCodeChunkResult(\"luacode\")).
		KAGUYA_DEPRECATED_FEATURE("addCodeChunkResult is deprecated. use addStaticField(kaguya::LuaCodeChunkResult(\"luacode\")).")
		UserdataMetatable& addCodeChunkResult(const char* name, const std::string& lua_code_chunk)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}

			member_map_[name] = AnyDataPusher(LuaCodeChunkResult(lua_code_chunk));
			return *this;
		}

		/// @brief assign data by argument value. 
		/// @param name name for lua
		/// @param d data
		template<typename Data>
		UserdataMetatable& addStaticField(const char* name, const Data& d)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			member_map_[name] = AnyDataPusher(d);
			return *this;
		}
#if KAGUYA_USE_CPP11
		/// @brief assign overloaded from functions. 
		/// @param name name for lua
		/// @param f functions
		template<typename... Funcs>
		UserdataMetatable& addOverloadedFunctions(const char* name, Funcs... f)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}

			member_map_[name] = AnyDataPusher(overload(f...));

			return *this;
		}

		/// @brief assign data by argument value. 
		/// @param name name for lua
		/// @param d data
		template<typename Data>
		UserdataMetatable& addStaticField(const char* name, Data&& d)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered.");
				return *this;
			}
			member_map_[name] = AnyDataPusher(std::move(d));
			return *this;
		}
#else

#define KAGUYA_PP_TEMPLATE(N) KAGUYA_PP_CAT(typename A,N)
#define KAGUYA_PP_FARG(N) const KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_PP_FUNCS(N) KAGUYA_PP_CAT(a,N)
#define KAGUYA_ADD_OVERLOAD_FUNCTION_DEF(N) template<KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_TEMPLATE)>\
		inline UserdataMetatable& addOverloadedFunctions(const char* name,KAGUYA_PP_REPEAT_ARG(N,KAGUYA_PP_FARG))\
		{\
			if (has_key(name))\
			{\
				throw KaguyaException("already registered.");\
				return *this;\
			}\
			member_map_[name] = AnyDataPusher(kaguya::overload(KAGUYA_PP_ARG_REPEAT(N)));\
			return *this;\
		}
		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_ADD_OVERLOAD_FUNCTION_DEF)
#undef KAGUYA_PP_TEMPLATE
#undef KAGUYA_PP_FARG
#undef KAGUYA_PP_FUNCS
#undef KAGUYA_ADD_OVERLOAD_FUNCTION_DEF
#endif

#if defined(_MSC_VER) && _MSC_VER <= 1800
		//can not write  Ret class_type::* f on MSC++2013
		template<typename Fun>
		UserdataMetatable& addFunction(const char* name, Fun f)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered. if you want function overload,use addOverloadedFunctions");
				return *this;
			}
			member_map_[name] = AnyDataPusher(kaguya::function(f));
			return *this;
		}
#else
		/// @brief assign function
		/// @param name name for lua
		/// @param f pointer to member function.
		template<typename Ret>
		UserdataMetatable& addFunction(const char* name, Ret class_type::* f)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered. if you want function overload,use addOverloadedFunctions");
				return *this;
			}
			member_map_[name] = AnyDataPusher(kaguya::function(f));
			return *this;
		}
#endif
		/// @brief assign function
		/// @param name name for lua
		/// @param f member function object.
		UserdataMetatable& addFunction(const char* name, PolymorphicMemberInvoker f)
		{
			if (has_key(name))
			{
				throw KaguyaException("already registered. if you want function overload,use addOverloadedFunctions");
				return *this;
			}
			member_map_[name] = AnyDataPusher(kaguya::function(f));
			return *this;
		}


#if defined(_MSC_VER) && _MSC_VER <= 1800
		//can not use add at MSVC2013
#else
		template<typename Data>
		KAGUYA_DEPRECATED_FEATURE("add is deprecated. use addStaticField instead.")
			UserdataMetatable& add(const char* name, const Data& d)
		{
			return addStaticField(name, d);
		}

#if KAGUYA_USE_CPP11
		template<typename Data>
		KAGUYA_DEPRECATED_FEATURE("add is deprecated. use addStaticField instead.")
			UserdataMetatable& add(const char* name, Data&& d)
		{
			return addStaticField(name, d);
		}
#endif
		template<typename Ret>
		KAGUYA_DEPRECATED_FEATURE("add is deprecated. use addFunction instead.")
		UserdataMetatable& add(const char* name, Ret class_type::* f)
		{
			return addFunction(name, f);
		}
#endif

	private:

		void set_base_metatable(lua_State* state, LuaStackRef& metatable, types::typetag<void>)const
		{
		}
		template<class Base>
		void set_base_metatable(lua_State* state, LuaStackRef& metatable, types::typetag<Base>)const
		{
			class_userdata::get_metatable<Base>(state);
			metatable.setMetatable(LuaTable(state, StackTop()));

			PointerConverter& pconverter = PointerConverter::get(state);
			pconverter.add_type_conversion<Base, class_type>();
		}

		void set_multiple_base(lua_State* state, LuaStackRef& metatable, const LuaTable& metabases)const
		{
			LuaTable newmeta(state, NewTable());

			metabases.push(state);
			lua_pushcclosure(state, &detail::multiple_base_index_function, 1);
			LuaStackRef indexfun(state, -1);
			newmeta.setField("__index", indexfun);

			metatable.setMetatable(newmeta);

		}
#if KAGUYA_USE_CPP11

		template<typename Base>
		void metatables(lua_State* state, LuaStackRef& metabases, PointerConverter& pvtreg, types::typetag<MultipleBase<Base> >)const
		{
			class_userdata::get_metatable<Base>(state);
			metabases.setRawField(metabases.size() + 1, LuaTable(state, StackTop()));
			pvtreg.add_type_conversion<Base, class_type>();
		}
		template<typename Base, typename... Remain>
		void metatables(lua_State* state, LuaStackRef& metabases, PointerConverter& pvtreg, types::typetag<MultipleBase<Base, Remain...> >)const
		{
			class_userdata::get_metatable<Base>(state);
			metabases.setRawField(metabases.size() + 1, LuaTable(state, StackTop()));
			pvtreg.add_type_conversion<Base, class_type>();
			metatables(state, metabases, pvtreg, types::typetag<MultipleBase<Remain...> >());
		}

		template<typename... Bases>
		void set_base_metatable(lua_State* state, LuaStackRef& metatable, types::typetag<MultipleBase<Bases...> > metatypes)const
		{
			PointerConverter& pconverter = PointerConverter::get(state);

			util::one_push(state, NewTable(sizeof...(Bases), 0));
			LuaStackRef metabases(state, -1, true);
			metatables(state, metabases, pconverter, metatypes);
			set_multiple_base(state, metatable, metabases);
		}

#else
#define KAGUYA_TEMPLATE_PARAMETER(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>
#define KAGUYA_GET_BASE_METATABLE(N) class_userdata::get_metatable<KAGUYA_PP_CAT(A,N)>(state);\
		metabases.setRawField(metabases.size() + 1, LuaTable(state, StackTop())); \
		pconverter.add_type_conversion<KAGUYA_PP_CAT(A,N),class_type>();
#define KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF(N) \
	KAGUYA_TEMPLATE_PARAMETER(N)\
		void set_base_metatable(lua_State* state, LuaStackRef& metatable, types::typetag<MultipleBase<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)> > metatypes)const\
		{\
			PointerConverter& pconverter = PointerConverter::get(state);\
			util::one_push(state, NewTable(N,0));\
			LuaStackRef metabases(state,-1, true);\
			KAGUYA_PP_REPEAT(N, KAGUYA_GET_BASE_METATABLE); \
			set_multiple_base(state, metatable, metabases);\
		}\

		KAGUYA_PP_REPEAT_DEF(9, KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF)
#undef KAGUYA_TEMPLATE_PARAMETER
#undef KAGUYA_MULTIPLE_INHERITANCE_SETBASE_DEF
#undef KAGUYA_GET_BASE_METATABLE
#undef KAGUYA_TYPE_CHECK_REP
#endif

		bool has_key(const std::string& key)
		{
			if (member_map_.count(key) > 0)
			{
				return true;
			}
			if (property_map_.count(key) > 0)
			{
				return true;
			}
			std::string propkey = KAGUYA_PROPERTY_PREFIX + key;
			if (member_map_.count(propkey) > 0)//_prop_keyname is reserved for property
			{
				return true;
			}
			return false;
		}
		void registerField(lua_State* state, const char* name, const AnyDataPusher& value)const
		{
			int count = value.pushToLua(state);
			if (count > 1)
			{
				lua_pop(state, count - 1);
				count = 1;
			}
			if (count == 1)
			{
				lua_setfield(state, -2, name);
			}
		}
		void registerMember(lua_State* state)const
		{
			for (typename MemberMapType::const_iterator it = member_map_.begin(); it != member_map_.end(); ++it)
			{
				registerField(state, it->first.c_str(), it->second);
			}
			for (typename PropMapType::const_iterator it = property_map_.begin(); it != property_map_.end(); ++it)
			{
				registerField(state, (KAGUYA_PROPERTY_PREFIX + it->first).c_str(), it->second);
			}
		}

		PropMapType property_map_;
		MemberMapType member_map_;
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for UserdataMetatable
	template<typename T,typename Base>	struct lua_type_traits<UserdataMetatable<T,Base> > {
		typedef const UserdataMetatable<T, Base>& push_type;

		static int push(lua_State* l, push_type ref)
		{
			return ref.createMatatable(l).push(l);
		}
	};
}

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <map>


namespace kaguya
{
	class State;


	struct table_proxy
	{

#if KAGUYA_USE_CPP11
		template<typename V, typename KEY>
		static void set(lua_State* state, int table_index, const KEY& key, V&& value)
		{
			util::one_push(state, key);
			util::one_push(state, std::forward<V>(value));
			lua_settable(state, table_index);
		}
		template<typename V>
		static void set(lua_State* state, int table_index, const char* key, V&& value)
		{
			util::one_push(state, std::forward<V>(value));
			lua_setfield(state, table_index, key);
		}
		template<typename V>
		static void set(lua_State* state, int table_index, const std::string& key, V&& value)
		{
			util::one_push(state, std::forward<V>(value));
			lua_setfield(state, table_index, key.c_str());
		}

		template<typename V>
		static void set(lua_State* state, int table_index, const luaInt& key, V&& value)
		{
			util::one_push(state, std::forward<V>(value));
			lua_seti(state, table_index, key);
		}
#endif
		template<typename V, typename KEY>
		static void set(lua_State* state, int table_index, const KEY& key, const V& value)
		{
			util::one_push(state, key);
			util::one_push(state, value);
			lua_settable(state, table_index);
		}
		template<typename V>
		static void set(lua_State* state, int table_index, const char* key, const V& value)
		{
			util::one_push(state, value);
			lua_setfield(state, table_index, key);
		}
		template<typename V>
		static void set(lua_State* state, int table_index, const std::string& key, const V& value)
		{
			util::one_push(state, value);
			lua_setfield(state, table_index, key.c_str());
		}

		template<typename V>
		static void set(lua_State* state, int table_index, const luaInt& key, const V& value)
		{
			util::one_push(state, value);
			lua_seti(state, table_index, key);
		}

		template<typename KEY>
		static void get(lua_State* state, int table_index, const KEY& key)
		{
			util::one_push(state, key);
			lua_gettable(state, table_index);
		}
		static void get(lua_State* state, int table_index, const char* key)
		{
			lua_getfield(state, table_index, key);
		}
		static void get(lua_State* state, int table_index, const std::string& key)
		{
			lua_getfield(state, table_index, key.c_str());
		}
		static void get(lua_State* state, int table_index, luaInt key)
		{
			lua_geti(state, table_index, key);
		}
	};


	/**
	* This class is the type returned by members of non-const LuaRef(Table) when directly accessing its elements.
	*/
	template<typename KEY>
	class TableKeyReference : public detail::LuaVariantImpl<TableKeyReference<KEY> >
	{
	public:

		int pushStackIndex(lua_State* state)const
		{
			push(state);
			return lua_gettop(state);
		}
		lua_State* state()const { return state_; }

		friend class LuaRef;
		friend class State;

		//! this is not copy.same assign from referenced value.
		TableKeyReference& operator=(const TableKeyReference& src)
		{
			table_proxy::set(state_, table_index_, key_, src);
			return *this;
		}


		//! assign from T
		template<typename T>
		TableKeyReference& operator=(const T& src)
		{
			table_proxy::set(state_, table_index_, key_, src);

			return *this;
		}
#if KAGUYA_USE_CPP11
		template<typename T>
		TableKeyReference& operator=(T&& src)
		{
			table_proxy::set(state_, table_index_, key_, std::forward<T>(src));
			return *this;
		}
#endif

		bool isNilref()const {
			if (!state_)
			{
				return false;
			}
			util::ScopedSavedStack save(state_);
			push(state_);
			return lua_isnoneornil(state_, -1);
		}

		//! register class metatable to lua and set to table
		template<typename T, typename P>
		void setClass(const ClassMetatable<T, P>& reg)
		{
			set_class(reg);
		}

		//! register class metatable to lua and set to table
		template<typename T, typename P>
		void setClass(const UserdataMetatable<T, P>& reg)
		{
			set_class(reg);
		}

		//! set function 
		template<typename T>
		void setFunction(T f)
		{
			table_proxy::set(state_, table_index_, key_, kaguya::function(f));
		}

		//deprecated
		LuaRef getValue()const
		{
			util::ScopedSavedStack save(state_);
			push(state_);
			return lua_type_traits<LuaRef>::get(state_, -1);
		}


		int push(lua_State* state)const
		{
			if (lua_type(state_, table_index_) != LUA_TTABLE)
			{
				lua_pushnil(state);
				return 1;
			}

			table_proxy::get(state_, table_index_, key_);

			if (state_ != state)
			{
				lua_xmove(state_, state, 1);
			}
			return 1;

		}

		int push()const
		{
			return push(state_);
		}

		int type()const
		{
			util::ScopedSavedStack save(state_);
			push();
			return lua_type(state_, -1);
		}

		~TableKeyReference()
		{
			if (state_)
			{
				lua_settop(state_, stack_top_);
			}
		}

		///!constructs the reference. Accessible only to kaguya::LuaRef itself 
		TableKeyReference(const TableKeyReference& src) : state_(src.state_), stack_top_(src.stack_top_), table_index_(src.table_index_), key_(src.key_)
		{
			src.state_ = 0;
		}

		///!constructs the reference. Accessible only to kaguya::LuaRef itself 
		TableKeyReference(lua_State* state, int table_index, KEY key, int revstacktop) : state_(state), stack_top_(revstacktop), table_index_(table_index), key_(key)
		{
		}
	private:
		template<typename T, typename P>
		void set_class(const ClassMetatable<T, P>& reg)
		{
			nativefunction::reg_functor_destructor(state_);
			LuaRef table(state_, NewTable());
			table.setMetatable(reg.registerClass(state_));
			*this = table;
		}

		template<typename T, typename P>
		void set_class(const UserdataMetatable<T, P>& reg)
		{
			table_proxy::set(state_, table_index_, key_, reg.createMatatable(state_));
		}


		///!constructs the reference. Accessible only to kaguya::LuaRef itself 
		TableKeyReference(lua_State* state, int table_index, const KEY& key, int revstacktop, const NoTypeCheck&) : state_(state), stack_top_(revstacktop), table_index_(table_index), key_(key)
		{
		}

		TableKeyReference(const LuaTable& table, const KEY& key) : state_(table.state()), stack_top_(lua_gettop(state_)), key_(key)
		{
			util::one_push(state_, table);
			util::one_push(state_, key);
			table_index_ = stack_top_ + 1;
		}
		TableKeyReference(const LuaRef& table, const KEY& key) : state_(table.state()), stack_top_(lua_gettop(state_)), key_(key)
		{
			util::one_push(state_, table);
			util::one_push(state_, key);
			table_index_ = stack_top_ + 1;
			int t = lua_type(state_, table_index_);
			if (t != LUA_TTABLE)
			{
				except::typeMismatchError(state_, lua_typename(state_, t) + std::string(" is not table"));
			}
		}

		mutable lua_State* state_;//mutable for RVO unsupported compiler
		int stack_top_;
		int table_index_;
		KEY key_;
	};

	template<typename KEY>
	inline std::ostream& operator<<(std::ostream& os, const TableKeyReference<KEY>& ref)
	{
		lua_State* state = ref.state();
		util::ScopedSavedStack save(state);
		int stackIndex = ref.pushStackIndex(state);
		util::stackValueDump(os, state, stackIndex);
		return os;
	}

	namespace detail {
		template<typename T>
		inline bool LuaFunctionImpl<T>::setFunctionEnv(const LuaTable& env)
		{
			lua_State* state = state_();
			if (!state)
			{
				return false;
			}
			util::ScopedSavedStack save(state);
			int stackIndex = pushStackIndex_(state);
			int t = lua_type(state, stackIndex);
			if (t != LUA_TFUNCTION)
			{
				except::typeMismatchError(state, lua_typename(state, t) + std::string(" is not function"));
				return false;
			}
			env.push(state);
#if LUA_VERSION_NUM >= 502
			lua_setupvalue(state, stackIndex, 1);
#else
			lua_setfenv(state, stackIndex);
#endif
			return true;
		}
		template<typename T>
		inline bool LuaFunctionImpl<T>::setFunctionEnv(NewTable env)
		{
			return setFunctionEnv(LuaTable(state_()));
		}

		template<typename T>
		inline LuaTable LuaFunctionImpl<T>::getFunctionEnv()const
		{
			lua_State* state = state_();
			util::ScopedSavedStack save(state);
			if (!state)
			{
				except::typeMismatchError(state, "is nil");
				return LuaTable();
			}
			int stackIndex = pushStackIndex_(state);
			int t = lua_type(state, stackIndex);
			if (t != LUA_TFUNCTION)
			{
				except::typeMismatchError(state, lua_typename(state, t) + std::string(" is not function"));
				return LuaTable();
			}
#if LUA_VERSION_NUM >= 502
			lua_getupvalue(state, stackIndex, 1);
#else
			lua_getfenv(state, stackIndex);
#endif
			return LuaTable(state, StackTop());
		}

		template<typename T>
		bool LuaTableOrUserDataImpl<T>::setMetatable(const LuaTable& table)
		{
			lua_State* state = state_();
			if (!state)
			{
				except::typeMismatchError(state, "is nil");
				return false;
			}
			util::ScopedSavedStack save(state);
			int stackindex = pushStackIndex_(state);
			int t = lua_type(state, stackindex);
			if (t != LUA_TTABLE && t != LUA_TUSERDATA)
			{
				except::typeMismatchError(state, lua_typename(state, t) + std::string(" is not table"));
				return false;
			}
			table.push();
			return lua_setmetatable(state, stackindex) != 0;
		}
		template<typename T>
		LuaTable LuaTableOrUserDataImpl<T>::getMetatable()const
		{
			lua_State* state = state_();
			if (!state)
			{
				except::typeMismatchError(state, "is nil");
				return LuaTable();
			}
			util::ScopedSavedStack save(state);
			int stackindex = pushStackIndex_(state);
			int t = lua_type(state, stackindex);
			if (t != LUA_TTABLE && t != LUA_TUSERDATA)
			{
				except::typeMismatchError(state, lua_typename(state, t) + std::string(" is not table"));
				return LuaTable();
			}
			if (!lua_getmetatable(state, stackindex))
			{
				lua_pushnil(state);
			}
			return LuaTable(state, StackTop());
		}
		template<typename T>
		MemberFunctionBinder LuaTableOrUserDataImpl<T>::operator->*(const char* function_name)
		{
			push_(state_());
			return MemberFunctionBinder(LuaRef(state_(), StackTop()), function_name);
		}


		template<typename T> template <typename KEY>
		LuaStackRef LuaTableOrUserDataImpl<T>::getField(const KEY& key)const
		{
			lua_State* state = state_();
			if (!state)
			{
				except::typeMismatchError(state, "is nil");
				return LuaStackRef();
			}
			push_(state);
			util::one_push(state, key);//push key
			lua_gettable(state, -2);//get table[key]
			lua_remove(state, -2);//remove table
			return LuaStackRef(state, -1, true);
		}
		template<typename T> template <typename KEY>
		LuaStackRef LuaTableOrUserDataImpl<T>::getRawField(const KEY& key)const
		{
			lua_State* state = state_();
			if (!state)
			{
				except::typeMismatchError(state, "is nil");
				return LuaStackRef();
			}
			push_(state);
			util::one_push(state, key);//push key
			lua_rawget(state, -2);//get table[key]
			lua_remove(state, -2);//remove table
			return LuaStackRef(state, -1, true);
		}

		template<typename T> template<typename KEY>
		LuaStackRef LuaTableOrUserDataImpl<T>::operator[](KEY key)const
		{
			return getField(key);
		}

		template<typename T>
		std::vector<LuaRef> LuaTableOrUserDataImpl<T>::values()const
		{
			return values<LuaRef>();
		}
		template<typename T>
		std::vector<LuaRef> LuaTableOrUserDataImpl<T>::keys()const
		{
			return keys<LuaRef>();
		}
		template<typename T>
		std::map<LuaRef, LuaRef> LuaTableOrUserDataImpl<T>::map()const
		{
			return map<LuaRef, LuaRef>();
		}

		template<typename T> template <typename K>
		TableKeyReference<K> LuaTableOrUserDataImpl<T>::operator[](K key)
		{
			lua_State* state = state_();
			int stack_top = lua_gettop(state);
			int stackindex = pushStackIndex_(state);
			return TableKeyReference<K>(state, stackindex, key, stack_top);
		}
	}

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for TableKeyReference<KEY>
	template<typename KEY>
	struct lua_type_traits<TableKeyReference<KEY> > {
		static int push(lua_State* l, const TableKeyReference<KEY>& ref)
		{
			return ref.push(l);
		}
	};

#ifndef KAGUYA_NO_STD_VECTOR_TO_TABLE

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for std::vector<T, A>
	template<typename T, typename A>
	struct lua_type_traits<std::vector<T, A> >
	{
		typedef std::vector<T, A> get_type;
		typedef const std::vector<T, A>& push_type;

		struct checkTypeForEach
		{
			checkTypeForEach(bool& valid) :valid_(valid) {}
			bool& valid_;
			bool operator()(const LuaStackRef& k, const LuaStackRef& v)
			{
				valid_ = k.typeTest<size_t>() && v.weakTypeTest<T>();
				return valid_;
			}
		};
		struct strictCheckTypeForEach
		{
			strictCheckTypeForEach(bool& valid) :valid_(valid) {}
			bool& valid_;
			bool operator()(const LuaStackRef& k, const LuaStackRef& v)
			{
				valid_ = k.typeTest<size_t>() && v.typeTest<T>();
				return valid_;
			}
		};

		static bool checkType(lua_State* l, int index)
		{
			LuaStackRef table(l, index);
			if (table.type() != LuaRef::TYPE_TABLE) { return false; }

			bool valid = true;
			table.foreach_table_breakable<LuaStackRef, LuaStackRef>(checkTypeForEach(valid));
			return valid;
		}
		static bool strictCheckType(lua_State* l, int index)
		{
			LuaStackRef table(l, index);
			if (table.type() != LuaRef::TYPE_TABLE) { return false; }

			bool valid = true;
			table.foreach_table_breakable<LuaStackRef, LuaStackRef>(strictCheckTypeForEach(valid));
			return valid;
		}

		static get_type get(lua_State* l, int index)
		{
			if (lua_type(l, index) != LUA_TTABLE)
			{
				except::typeMismatchError(l, std::string("type mismatch"));
				return get_type();
			}
			return LuaStackRef(l, index).values<T>();
		}
		static int push(lua_State* l, push_type v)
		{
			lua_createtable(l, int(v.size()), 0);
			int count = 1;//array is 1 origin in Lua
			for (typename std::vector<T, A>::const_iterator it = v.begin(); it != v.end(); ++it)
			{
				util::one_push(l, *it);
				lua_rawseti(l, -2, count++);
			}
			return 1;
		}
	};
#endif

#ifndef KAGUYA_NO_STD_MAP_TO_TABLE
	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for std::map<K, V, C, A>
	template<typename K, typename V, typename C, typename A>
	struct lua_type_traits<std::map<K, V, C, A> >
	{
		typedef std::map<K, V, C, A> get_type;
		typedef const std::map<K, V, C, A>& push_type;

		struct checkTypeForEach
		{
			checkTypeForEach(bool& valid) :valid_(valid) {}
			bool& valid_;
			bool operator()(const LuaStackRef& k, const LuaStackRef& v)
			{
				valid_ = k.weakTypeTest<K>() && v.weakTypeTest<V>();
				return valid_;
			}
		};
		struct strictCheckTypeForEach
		{
			strictCheckTypeForEach(bool& valid) :valid_(valid) {}
			bool& valid_;
			bool operator()(const LuaStackRef& k, const LuaStackRef& v)
			{
				valid_ = k.typeTest<K>() && v.typeTest<V>();
				return valid_;
			}
		};
		static bool checkType(lua_State* l, int index)
		{
			LuaStackRef table(l, index);
			if (table.type() != LuaRef::TYPE_TABLE) { return false; }

			bool valid = true;
			table.foreach_table_breakable<LuaStackRef, LuaStackRef>(checkTypeForEach(valid));
			return valid;
		}
		static bool strictCheckType(lua_State* l, int index)
		{
			LuaStackRef table(l, index);
			if (table.type() != LuaRef::TYPE_TABLE) { return false; }

			bool valid = true;
			table.foreach_table_breakable<LuaStackRef, LuaStackRef>(strictCheckTypeForEach(valid));
			return valid;
		}

		static get_type get(lua_State* l, int index)
		{
			if (lua_type(l, index) != LUA_TTABLE)
			{
				except::typeMismatchError(l, std::string("type mismatch"));
				return get_type();
			}
			return LuaStackRef(l, index).map<K, V>();
		}
		static int push(lua_State* l, push_type v)
		{
			lua_createtable(l, 0, int(v.size()));
			for (typename std::map<K, V, C, A>::const_iterator it = v.begin(); it != v.end(); ++it)
			{
				util::one_push(l, it->first);
				util::one_push(l, it->second);
				lua_rawset(l, -3);
			}
			return 1;
		}
	};
#endif

#if KAGUYA_USE_CPP11
	struct TableDataElement {
		typedef std::pair<AnyDataPusher, AnyDataPusher> keyvalue_type;

		template<typename Value>
		TableDataElement(Value value) :keyvalue(keyvalue_type(AnyDataPusher(), value)) {}

		template<typename Key, typename Value>
		TableDataElement(Key key, Value value) : keyvalue(keyvalue_type(key, value)) {}
		std::pair<AnyDataPusher, AnyDataPusher> keyvalue;
	};

	struct TableData {
		typedef std::pair<AnyDataPusher, AnyDataPusher> data_type;

		TableData(std::initializer_list<TableDataElement> list) :elements(list.begin(), list.end()) {}
		std::vector<TableDataElement> elements;
	};

	/// @ingroup lua_type_traits
	/// @brief lua_type_traits for TableData
	template<>
	struct lua_type_traits<TableData> {
		static int push(lua_State* l, const TableData& list)
		{
			lua_createtable(l, int(list.elements.size()), int(list.elements.size()));
			int count = 1;//array is 1 origin in Lua
			for (auto&& v : list.elements)
			{
				if (v.keyvalue.first.empty())
				{
					util::one_push(l, v.keyvalue.second);
					lua_rawseti(l, -2, count++);
				}
				else
				{
					util::one_push(l, v.keyvalue.first);
					util::one_push(l, v.keyvalue.second);
					lua_rawset(l, -3);
				}
			}
			return 1;
		}
	};
#endif
}

namespace kaguya
{
	/// @addtogroup State
	/// @{

	/// @brief Load library info type @see State::openlibs @see State::State(const LoadLibs &libs)
	typedef std::pair<std::string, lua_CFunction> LoadLib;

	/// @brief Load libraries info @see State::openlibs @see State::State(const LoadLibs &libs)
	typedef std::vector<LoadLib> LoadLibs;

	/// @brief return no load library type @see State::State(const LoadLibs &libs)
	inline LoadLibs NoLoadLib() { return LoadLibs(); }

	/// @brief All load standard libraries type @see State::openlibs
	struct AllLoadLibs {};

	template<typename Allocator>
	void * AllocatorFunction(void *ud,
		void *ptr,
		size_t osize,
		size_t nsize)
	{
		Allocator* allocator = static_cast<Allocator*>(ud);
		if (nsize == 0)
		{
			allocator->deallocate(ptr, osize);
		}
		else if (ptr)
		{
			return allocator->reallocate(ptr, nsize);
		}
		else
		{
			return allocator->allocate(nsize);
		}
		return 0;
	}

	struct DefaultAllocator
	{
		typedef void* pointer;
		typedef size_t size_type;
		pointer allocate(size_type n)
		{
			return std::malloc(n);
		}
		pointer reallocate(pointer p, size_type n)
		{
			return std::realloc(p,n);
		}
		void deallocate(pointer p, size_type n)
		{
			std::free(p);
		}
	};

	///@ lua_State wrap class
	class State
	{
		standard::shared_ptr<void> allocator_holder_;
		lua_State *state_;
		bool created_;

		//non copyable
		State(const State&);
		State& operator =(const State&);



		static int initializing_panic(lua_State *L) {
			ErrorHandler::throwDefaultError(lua_status(L), lua_tostring(L, -1));
			return 0;  // return to Lua to abort 
		}
		static int default_panic(lua_State *L) {
			if (ErrorHandler::handle(lua_status(L), L))
			{
				return 0;
			}
			fprintf(stderr, "PANIC: unprotected error in call to Lua API (%s)\n", lua_tostring(L, -1));
			fflush(stderr);
			return 0;  // return to Lua to abort 
		}
		static void stderror_out(int status, const char* message)
		{
			std::cerr << message << std::endl;
		}

		template<typename Libs>void init(const Libs& lib)
		{
			if (state_)
			{
				lua_atpanic(state_, &initializing_panic);
				try
				{
					if (!ErrorHandler::getHandler(state_))
					{
						setErrorHandler(&stderror_out);
					}
					openlibs(lib);
					lua_atpanic(state_, &default_panic);
				}
				catch (const LuaException&)
				{
					lua_close(state_); state_ = 0;
				}
			}
		}

	public:
		
		/// @brief create Lua state with lua standard library
		State() :allocator_holder_(), state_(luaL_newstate()), created_(true)
		{
			init(AllLoadLibs());
		}

		/// @brief create Lua state with lua standard library. Can not use this constructor at luajit. error message is 'Must use luaL_newstate() for 64 bit target'
		/// @param allocator allocator for memory allocation @see DefaultAllocator
		template<typename Allocator>
		State(standard::shared_ptr<Allocator> allocator) :allocator_holder_(allocator), state_(lua_newstate(&AllocatorFunction<Allocator>, allocator_holder_.get())), created_(true)
		{
			init(AllLoadLibs());
		}

		/// @brief create Lua state with (or without) libraries.
		/// @param libs load libraries 
		/// e.g. LoadLibs libs;libs.push_back(LoadLib("libname",libfunction));State state(libs);
		/// e.g. State state({{"libname",libfunction}}); for c++ 11
		State(const LoadLibs& libs) : allocator_holder_(), state_(luaL_newstate()), created_(true)
		{
			init(libs);
		}

		/// @brief create Lua state with (or without) libraries. Can not use this constructor at luajit. error message is 'Must use luaL_newstate() for 64 bit target'
		/// @param libs load libraries 
		/// @param allocator allocator for memory allocation @see DefaultAllocator
		template<typename Allocator>
		State(const LoadLibs& libs, standard::shared_ptr<Allocator> allocator) : allocator_holder_(allocator), state_(lua_newstate(&AllocatorFunction<Allocator>, allocator_holder_.get())), created_(true)
		{
			init(libs);
		}

		/// @brief construct using created lua_State. 
		/// @param lua created lua_State. It is not call lua_close() in this class
		State(lua_State* lua) :state_(lua), created_(false)
		{
			if (state_)
			{
				if (!ErrorHandler::getHandler(state_))
				{
					setErrorHandler(&stderror_out);
				}
			}
		}
		~State()
		{
			if (created_ && state_)
			{
				lua_close(state_);
			}
		}

		/// @brief set error handler for lua error.
		void setErrorHandler(standard::function<void(int statuscode, const char*message)> errorfunction)
		{
			if (!state_) { return; }
			util::ScopedSavedStack save(state_);
			ErrorHandler::registerHandler(state_, errorfunction);
		}


		/// @brief load all lua standard library
		void openlibs(AllLoadLibs = AllLoadLibs())
		{
			if (!state_) { return; }
			luaL_openlibs(state_);
		}

		/// @brief load lua library
		LuaStackRef openlib(const LoadLib& lib)
		{
			if (!state_) { return LuaStackRef(); }
			luaL_requiref(state_, lib.first.c_str(), lib.second, 1);
			return LuaStackRef(state_, -1, true);
		}
		/// @brief load lua library
		LuaStackRef openlib(std::string name, lua_CFunction f)
		{
			return openlib(LoadLib(name, f));
		}

		
		
		/// @brief load lua libraries
		void openlibs(const LoadLibs& libs)
		{
			for (LoadLibs::const_iterator it = libs.begin(); it != libs.end(); ++it)
			{
				openlib(*it);
			}
		}

		/// @brief If there are no errors,compiled file as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param file  file path of lua script
		/// @return reference of lua function
		LuaFunction loadfile(const std::string& file)
		{
			return LuaFunction::loadfile(state_, file);
		}
		/// @brief If there are no errors,compiled file as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param file  file path of lua script
		/// @return reference of lua function
		LuaFunction loadfile(const char* file)
		{
			return LuaFunction::loadfile(state_, file);
		}


		/// @brief If there are no errors,compiled stream as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param stream stream of lua script
		/// @param chunkname chunkname of lua script
		/// @return reference of lua function
		LuaFunction loadstream(std::istream& stream, const char* chunkname=0)
		{
			return LuaFunction::loadstream(state_, stream, chunkname);
		}
		/// @brief Loads and runs the given stream.
		/// @param stream stream of lua script
		/// @param chunkname chunkname of lua script
		/// @param env execute env table
		/// @return If there are no errors, returns true.Otherwise return false
		bool dostream(std::istream& stream, const char* chunkname = 0, const LuaTable& env = LuaTable())
		{
			util::ScopedSavedStack save(state_);
			LuaStackRef f = LuaFunction::loadstreamtostack(state_,stream,chunkname);
			if (!f)
			{//load failed
				return false;
			}
			if (!env.isNilref())
			{
				f.setFunctionEnv(env);
			}

			FunctionResults ret= f.call<FunctionResults>();
			return !ret.resultStatus();
		}

		/// @brief If there are no errors,compiled string as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param str lua code
		/// @return reference of lua function
		LuaFunction loadstring(const std::string& str)
		{
			return LuaFunction::loadstring(state_, str);
		}
		/// @brief If there are no errors,compiled string as a Lua function and return.
		///  Otherwise send error message to error handler and return nil reference
		/// @param str lua code
		/// @return reference of lua function
		LuaFunction loadstring(const char* str)
		{
			return LuaFunction::loadstring(state_, str);
		}

		/// @brief Loads and runs the given file.
		/// @param file file path of lua script
		/// @param env execute env table
		/// @return If there are no errors, returns true.Otherwise return false
		bool dofile(const std::string& file, const LuaTable& env = LuaTable())
		{
			return dofile(file.c_str(), env);
		}

		/// @brief Loads and runs the given file.
		/// @param file file path of lua script
		/// @param env execute env table
		/// @return If there are no errors, returns true.Otherwise return false
		bool dofile(const char* file, const LuaTable& env = LuaTable())
		{
			util::ScopedSavedStack save(state_);

			int status = luaL_loadfile(state_, file);

			if (status)
			{
				ErrorHandler::handle(status, state_);
				return false;
			}

			if (!env.isNilref())
			{//register _ENV
				env.push();
#if LUA_VERSION_NUM >= 502
				lua_setupvalue(state_, -2, 1);
#else
				lua_setfenv(state_, -2);
#endif
			}

			status = lua_pcall_wrap(state_, 0, LUA_MULTRET);
			if (status)
			{
				ErrorHandler::handle(status, state_);
				return false;
			}
			return true;
		}


		/// @brief Loads and runs the given string.
		/// @param str lua script cpde
		/// @param env execute env table
		/// @return If there are no errors, returns true.Otherwise return false
		bool dostring(const char* str, const LuaTable& env = LuaTable())
		{
			util::ScopedSavedStack save(state_);

			int status = luaL_loadstring(state_, str);
			if (status)
			{
				ErrorHandler::handle(status, state_);
				return false;
			}
			if (!env.isNilref())
			{//register _ENV
				env.push();
#if LUA_VERSION_NUM >= 502
				lua_setupvalue(state_, -2, 1);
#else
				lua_setfenv(state_, -2);
#endif
			}
			status = lua_pcall_wrap(state_, 0, LUA_MULTRET);
			if (status)
			{
				ErrorHandler::handle(status, state_);
				return false;
			}
			return true;
		}
		/// @brief Loads and runs the given string.
		/// @param str lua script cpde
		/// @param env execute env table
		/// @return If there are no errors, returns true.Otherwise return false
		bool dostring(const std::string& str, const LuaTable& env = LuaTable())
		{
			return dostring(str.c_str(), env);
		}

		/// @brief Loads and runs the given string.
		/// @param str lua script cpde
		/// @return If there are no errors, returns true.Otherwise return false
		bool operator()(const std::string& str)
		{
			return dostring(str);
		}

		/// @brief Loads and runs the given string.
		/// @param str lua script cpde
		/// @return If there are no errors, returns true.Otherwise return false
		bool operator()(const char* str)
		{
			return dostring(str);
		}

		/// @brief return element reference from global table
		/// @param str table key
		/// @return proxy class for reference to table.
		TableKeyReference<std::string> operator[](const std::string& str)
		{
			int stack_top = lua_gettop(state_);
			util::push_args(state_, GlobalTable());
			int table_index = stack_top + 1;
			return TableKeyReference<std::string>(state_, table_index, str, stack_top, NoTypeCheck());
		}

		
		/// @brief return element reference from global table
		/// @param str table key
		/// @return proxy class for reference to table.
		
		TableKeyReference<const char*> operator[](const char* str)
		{
			int stack_top = lua_gettop(state_);
			util::push_args(state_, GlobalTable());
			int table_index = stack_top + 1;
			return TableKeyReference<const char*>(state_, table_index, str, stack_top, NoTypeCheck());
		}

		
		/// @brief return global table
		/// @return global table.		
		LuaTable globalTable()
		{
			return newRef(GlobalTable());
		}

		
		/// @brief create new Lua reference from argument value
		/// @return Lua reference.		
		template<typename T>
		LuaRef newRef(const T& value)
		{
			return LuaRef(state_, value);
		}
#if KAGUYA_USE_CPP11
		
		/// @brief create new Lua reference from argument value
		/// @return Lua reference.		
		template<typename T>
		LuaRef newRef(T&& value)
		{
			return LuaRef(state_, std::forward<T>(value));
		}
#endif

		
		/// @brief create new Lua table 
		/// @return Lua table reference.		
		LuaTable newTable()
		{
			return LuaTable(state_);
		}
		
		/// @brief create new Lua table
		/// @param reserve_array reserved array count
		/// @param reserve_record reserved record count
		/// @return Lua table reference.		
		LuaTable newTable(int reserve_array, int reserve_record)
		{
			return LuaTable(state_, NewTable(reserve_array, reserve_record));
		}

		
		/// @brief create new Lua thread
		/// @return Lua thread reference.		
		LuaThread newThread()
		{
			return LuaThread(state_);
		}
		
		/// @brief create new Lua thread with lua function
		/// @param f function
		/// @return Lua thread reference.		
		LuaThread newThread(const LuaFunction& f)
		{
			LuaThread cor(state_);
			cor.setFunction(f);
			return cor;
		}

		
		/// @brief argument value push to stack.
		/// @param value value		
		template<typename T>
		void pushToStack(T value)
		{
			util::push_args(state_, value);
		}
		
		/// @brief pop from stack.
		/// @return reference to pop value.	
		LuaRef popFromStack()
		{
			return LuaRef(state_, StackTop());
		}

		/// @brief Garbage Collection of Lua 
		struct GCType
		{
			GCType(lua_State* state) :state_(state) {}
			
			/// @brief Performs a full garbage-collection cycle.			
			void collect()
			{
				lua_gc(state_, LUA_GCCOLLECT, 0);
			}
			/// @brief Performs an incremental step of garbage collection.
			/// @return If returns true,the step finished a collection cycle.
			bool step()
			{
				return lua_gc(state_, LUA_GCSTEP, 0) == 1;
			}
			
			/// @brief Performs an incremental step of garbage collection.
			/// @param size the collector will perform as if that amount of memory (in KBytes) had been allocated by Lua.
			bool step(int size)
			{
				return lua_gc(state_, LUA_GCSTEP, size) == 1;
			}
			
			/// @brief enable gc			
			void restart() { enable(); }
			
			/// @brief disable gc			
			void stop() { disable(); }

			
			/// @brief returns the total memory in use by Lua in Kbytes.			
			int count()const { return lua_gc(state_, LUA_GCCOUNT, 0); }

			
			/// @brief sets arg as the new value for the pause of the collector. Returns the previous value for pause.
			int steppause(int value) { return lua_gc(state_, LUA_GCSETPAUSE, value); }
			
			///  @brief sets arg as the new value for the step multiplier of the collector. Returns the previous value for step.
			int setstepmul(int value) { return lua_gc(state_, LUA_GCSETSTEPMUL, value); }

			
			/// @brief enable gc
			void enable()
			{
				lua_gc(state_, LUA_GCRESTART, 0);
			}

			
			/// @brief disable gc
			void disable()
			{
				lua_gc(state_, LUA_GCSTOP, 0);
			}
#if LUA_VERSION_NUM >= 502
			
			/// @brief returns a boolean that tells whether the collector is running
			bool isrunning()const { return isenabled(); }
			
			/// @brief returns a boolean that tells whether the collector is running
			bool isenabled()const
			{
				return lua_gc(state_, LUA_GCISRUNNING, 0) != 0;
			}
#endif

		private:
			lua_State* state_;
		};

		// /@brief  return Garbage collection interface.
		GCType gc()const
		{
			return GCType(state_);
		}
		/// @brief performs a full garbage-collection cycle.
		void garbageCollect()
		{
			gc().collect();
		}

		/// @brief returns the current amount of memory (in Kbytes) in use by Lua.
		size_t useKBytes()const
		{
			return size_t(gc().count());
		}



		
		/// @brief create Table and push to stack.
		/// using for Lua module
		/// @return return Lua Table Reference
		LuaTable newLib()
		{
			LuaTable newtable = newTable();
			newtable.push(state_);
			return newtable;
		}

		
		/// @brief return lua_State*.
		/// @return lua_State*
		lua_State *state() { return state_; };

		
		/// @brief check valid lua_State.
		bool isInvalid() const { return !state_; }
	};

	/// @}
}

// Copyright satoren
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)



namespace kaguya
{

	template<typename RefTuple, typename GetTuple>
	struct ref_tuple
	{
		RefTuple tref;
		ref_tuple(const RefTuple& va) :tref(va) {}
		void operator=(const FunctionResults& fres)
		{
			tref = fres.get_result(types::typetag<GetTuple>());
		}
		template<class T>
		void operator=(const T& fres)
		{
			tref = fres;
		}
	};
#if KAGUYA_USE_CPP11
	template<class... Args>
	ref_tuple<standard::tuple<Args&...>, standard::tuple<Args...>> tie(Args&... va)
	{
		typedef standard::tuple<Args&...> RefTuple;
		typedef standard::tuple<Args...> GetTuple;
		return ref_tuple<RefTuple, GetTuple>(RefTuple(va...));
	}
#else
#define KAGUYA_VARIADIC_REFARG_REP(N) KAGUYA_PP_CAT(A,N)& KAGUYA_PP_CAT(a,N)
#define KAGUYA_VARIADIC_TREFARG_REP(N) KAGUYA_PP_CAT(A,N)&
#define KAGUYA_TEMPLATE_REFARG_REPEAT(N) KAGUYA_PP_REPEAT_ARG(N, KAGUYA_VARIADIC_TREFARG_REP)
#define KAGUYA_REF_TUPLE(N) standard::tuple<KAGUYA_TEMPLATE_REFARG_REPEAT(N)>
#define KAGUYA_GET_TUPLE(N) standard::tuple<KAGUYA_PP_TEMPLATE_ARG_REPEAT(N)>
#define KAGUYA_REF_TUPLE_DEF(N) template<KAGUYA_PP_TEMPLATE_DEF_REPEAT(N)>\
	ref_tuple<KAGUYA_REF_TUPLE(N), KAGUYA_GET_TUPLE(N) > tie(KAGUYA_PP_REPEAT_ARG(N, KAGUYA_VARIADIC_REFARG_REP))\
	{\
		return ref_tuple<KAGUYA_REF_TUPLE(N), KAGUYA_GET_TUPLE(N) >(KAGUYA_REF_TUPLE(N)(KAGUYA_PP_ARG_REPEAT(N)));\
	}

	KAGUYA_PP_REPEAT_DEF(9, KAGUYA_REF_TUPLE_DEF)
#undef KAGUYA_VARIADIC_REFARG_REP
#undef KAGUYA_TEMPLATE_REFARG_REPEAT
#undef KAGUYA_REF_TUPLE
#undef KAGUYA_GET_TUPLE
#undef KAGUYA_REF_TUPLE_DEF
#endif
}

#endif// KAGUYA_LUABINDING_HPP_INCLUDED
