add_executable(tlow 
    main.cpp
    compile.cpp
    run.cpp
)

target_link_libraries(tlow PRIVATE
    tlowRuntime
    tlowImporter
    tlowTransforms
    tlowCodegen
)