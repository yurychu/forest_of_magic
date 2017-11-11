#ifndef FOREST_OF_MAGIC_EXCEPTIONS_HPP
#define FOREST_OF_MAGIC_EXCEPTIONS_HPP

#include <stdexcept>
#include <type_traits>


namespace fom {

    class ExceptionEngine : public std::runtime_error
    {
    public:
        explicit ExceptionEngine(const std::string & msg) : std::runtime_error(msg){;}
        ExceptionEngine(const ExceptionEngine & obj) noexcept : std::runtime_error(obj) {;}
    };

}
#endif //FOREST_OF_MAGIC_EXCEPTIONS_HPP
