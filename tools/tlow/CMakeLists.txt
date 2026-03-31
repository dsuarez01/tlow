add_executable(tlow 
    main.cpp
)

target_link_libraries(tlow PRIVATE
    tlowFrontend
    OnnxRuntime::OnnxRuntime
)