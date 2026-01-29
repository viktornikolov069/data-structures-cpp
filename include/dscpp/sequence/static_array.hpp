#ifndef DSCPP_STATIC_ARRAY_HPP
#define DSCPP_STATIC_ARRAY_HPP

#include <cstddef>

namespace dscpp
{
    template <typename T, std::size_t Size>
    class static_array
    {
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = T &;
        using const_reference = const T &;
        using pointer = T *;

        static_array() = default;

        [[nodiscard]] constexpr size_type size() const noexcept
        {
            return Size;
        }

        constexpr bool empty() const noexcept
        {
            return Size == 0;
        }

        [[nodiscard]] constexpr reference operator[](size_type pos) noexcept
        {
            return m_elements[pos];
        }

        [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept
        {
            return m_elements[pos];
        }

    private:
        T m_elements[Size]{};
    };
} // namespace dscpp

#endif // DSCPP_STATIC_ARRAY_HPP