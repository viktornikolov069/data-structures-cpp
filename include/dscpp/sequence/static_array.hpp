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

        template <typename... Values>
        constexpr static_array(Values... values)
        {
            static_assert(sizeof...(Values) <= Size, "Too many initializers");
            static_assert((std::is_constructible_v<Values, T> && ...), "All values must be of type --> T");
            std::array<T, sizeof...(Values)> temp = {values...};
            std::copy(temp.begin(), temp.end(), m_elements);
        }

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