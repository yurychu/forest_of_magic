#include <fom/fom.hpp>

#include <iostream>

#include <shape_generator/shape_generator.hpp>
#include <scripter/scripter.hpp>


void
fom::print_versions()
{
    std::cout << "FOM: Print versions call." << std::endl;
    // shape generator
    auto shape_generator_version = fom::get_shape_generator_version();
    std::cout << "Shape generator version: " << shape_generator_version << std::endl;

    // scripter
    auto scripter_version = fom::get_scripter_version();
    std::cout << "Scripter version: " << scripter_version << std::endl;

}
