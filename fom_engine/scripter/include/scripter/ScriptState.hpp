#ifndef FOREST_OF_MAGIC_SCRIPTSTATE_HPP
#define FOREST_OF_MAGIC_SCRIPTSTATE_HPP

#include <lua.hpp>


namespace fom
{
    class ScriptState
    {
    private:
        lua_State * m_L;

    public:
        ScriptState();
        ~ScriptState();
    };

}




#endif //FOREST_OF_MAGIC_SCRIPTSTATE_HPP
