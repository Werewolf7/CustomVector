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
	template <typename _InputIt> constexpr void assign(_InputIt first, _InputIt last);
	constexpr void assign(std::initializer_list<_Type> init_list);

	constexpr allocator_type_get_allocator() const noexcept;

	/*
	* Element access
	*/
	constexpr reference_at(size_type pos);
	constexpr const_reference_at(size_type pos);

	constexpr reference operator[] (size_type pos) const;
	constexpr const_reference operator[] (size_type pos) const;

	constexpr reference front();
	constexpr const_reference front() const;

	constexpr reference back();
	constexpr const_reference back() const;

	constexpr _Type* data() noexcept;
	constexpr const _Type* data() const noexcept;

	/*
	* Iterators
	*/
	constexpr iterator begin() noexcept;
	constexpr const_iterator begin() const noexcept;
	constexpr const_iterator cbegin() const noexcept;

	constexpr iterator end() noexcept;
	constexpr const_iterator end() const noexcept;
	constexpr const_iterator cend() const noexcept;

	constexpr reverse_iterator rbegin() noexcept;
	constexpr const_reverse_iterator rbegin() const noexcept;
	constexpr const_reverse_iterator crbegin() const noexcept;

	constexpr reverse_iterator rend() noexcept;
	constexpr const_reverse_iterator rend() const noexcept;
	constexpr const_reverse_iterator crend() const noexcept;

	/*
	* Capacity
	*/

	[[nodiscard]] constexpr bool empty() const noexcept;

	constexpr size_type size() const noexcept;

	constexpr size_type max_size() const noexcept;

	constexpr void reserve(size_type new_capacity);

	constexpr size_type capacity() const noexcept;

	constexpr void shrink_to_fit();

	/*
	* Modifiers
	*/
	constexpr void clear() noexcept;

	constexpr iterator insert(const_iterator pos, const _Type& value);
	constexpr iterator insert(const_iterator pos, const _Type&& value);
	constexpr iterator insert(const_iterator pos, size_type count, const _Type& value);
	template<typename _InputIt> constexpr iterator insert(const_iterator pos, _InputIt first, _InputIt last);
	constexpr iterator insert(const_iterator pos, std::initializer_list<_Type> init_list);

	template<typename... Args> constexpr iterator emplace(const_iterator pos, Args&&... args);

	constexpr iterator erase(const_iterator pos);
	constexpr iterator erase(const_iterator first, const_iterator last);

	constexpr void push_back(const _Type& value);
	constexpr void pussh_back(_Type&& value);

	template<typename... Args> constexpr reference emplace_back(Args&&... args);

	constexpr void pop_back();

	constexpr void resize(size_type count);
	constexpr void resize(size_type count, const value_type& value);

	constexpr void swap(Vector& other_vecor) noexcept(noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value ||
		std::allocator_traits<Allocator>::is_always_equal::value)
		);
};