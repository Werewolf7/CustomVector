#pragma once

#include <cstddef>
#include <memory>
#include <iterator>
#include <initializer_list>

template <typename _Type, typename _Allocator = std::allocator<_Type>>
class Vector {
public:
	/*
	* Member types according to cppreference
	*/
	using value_type = _Type;
	using allocator_type = _Allocator;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = typename std::allocator_traits<_Allocator>::pointer;
	using const_pointer = typename std::allocator_traits<_Allocator>::const_pointer;
	class iterator;
	class const_iterator;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	/*
	* Member functions according to cppreference
	*/

	constexpr Vector() noexcept(noexcept(_Alllocator()));
	constexpr explicit Vector(const _Allocator& alloc) noexcept;
	constexpr Vector(size_type count,
		const _Type& value = _Type(),
		const _Allocator& alloc = _Allocator()
	);
	constexpr explicit Vector(size_type count, 
		const _Allocator& alloc = _Allocator()
	);
	template <typename _InputIt> Vector(_InputIt first, 
		_InputIt last,
		const _Allocator& alloc = _Allocator()
	);
	constexpr Vector(const Vector& other_vector);
	constexpr Vector(const Vector& other_vector, const _Allocator& alloc);
	constexpr Vector(Vector&& other_vector) noexcept;
	constexpr Vector(Vector&& other_vector, const _Allocator& alloc);
	constexpr Vector(std::initializer_list<_Type> init_list,
		const _Allocator& alloc = _Allocator()
	);

	constexpr ~Vector();

	constexpr Vector& operator = (const Vector& other_vector);
	constexpr Vector& operator = (Vector&& other_vector) noexcept(noexcept(std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value ||
		std::allocator_traits<Allocator>::is_always_equal::value)
		);
	constexpr Vector& operator = (std::initializer_list<_Type> init_list);

	constexpr void assign(size_type count, const _Type& value);
	template <typename InputIt> constexpr void assign(InputIt first, InputIt last);
	constexpr void assign(std::initializer_list<_Type> init_list);

	constexpr allocator_type_get_allocator() const noexcept;

	/*
	* Element access
	*/

	/*
	* Iterators
	*/

	/*
	* Capacity
	*/

	/*
	* Modifiers
	*/

};