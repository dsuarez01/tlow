add_executable(tlow 
    main.cpp
)

target_link_libraries(tlow PRIVATE
    tlowFrontend
    OnnxRuntime::OnnxRuntime
)

install(TARGETS tlow DESTINATION bin COMPONENT tlow)