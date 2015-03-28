set(SOURCES
    stdneb.cc 
    main.cc)

add_executable(HelloWorldConsole ${SOURCES})
target_link_libraries(HelloWorldConsole NebulaXFoundation)
set_target_properties(HelloWorldConsole PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdneb.h")
cotire(HelloWorldConsole)
