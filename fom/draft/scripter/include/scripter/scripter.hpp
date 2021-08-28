#ifndef FOREST_OF_MAGIC_SCRIPTER_HPP
#define FOREST_OF_MAGIC_SCRIPTER_HPP

#include <string>


#define SCRIPTER_VERSION "0.0.1"

namespace fom
{
    std::string get_scripter_version();
    void run_script(const std::string & script_name);

}




#endif //FOREST_OF_MAGIC_SCRIPTER_HPP
