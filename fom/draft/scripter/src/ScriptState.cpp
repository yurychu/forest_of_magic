#include <ScriptState.hpp>

#include <cassert>


fom::ScriptState::ScriptState()
        : m_L(nullptr)
{
    m_L = luaL_newstate();
    assert(m_L);

}

fom::ScriptState::~ScriptState()
{

}
