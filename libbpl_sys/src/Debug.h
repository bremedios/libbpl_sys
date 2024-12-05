//
// Created by Bradley Remedios on 11/21/24.
//

#ifndef BPL_SYS_DEBUG_H
#define BPL_SYS_DEBUG_H

#include <iostream>

//#define __ENABLE_BPL_SYS_DEBUG    1

#define ERROR_MSG(msg)  { std::cerr << "ERROR: " << __PRETTY_FUNCTION__ << ":" << msg << std::endl; }

#if defined(__ENABLE_BPL_SYS_DEBUG)
    #define DEBUG_MSG(msg)  { std::cout << "DEBUG: " << __PRETTY_FUNCTION__ << ":" << msg << std::endl; }
#else
    #define DEBUG_MSG(cmd)
#endif // __ENABLE_BPL_SYS_DEBUG

#endif // BPL_SYS_DEBUG_H