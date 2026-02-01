#ifndef DSCPP_MAX_ELEMENT_HPP
#define DSCPP_MAX_ELEMENT_HPP

#include <string>
#include <expected>

template <typename T>
constexpr std::expected<typename T::value_type, std::string> max_element(const T &arr) noexcept
{
    if (arr.empty())
    {
        return std::unexpected("Array is empty!");
    }
    auto greaterElement = arr[0];

    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > greaterElement)
        {
            greaterElement = arr[i];
        }
    }

    return greaterElement;
}

#endif // DSCPP_MAX_ELEMENT_HPP