add_executable(tlow-opt
    main.cpp
)

target_link_libraries(tlow-opt PRIVATE
    MLIROptLib
    tlowCodegen
    tlowTransforms
)