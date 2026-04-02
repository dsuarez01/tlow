add_executable(tlow-opt main.cpp)

target_link_libraries(tlow-opt PRIVATE
    MLIROptLib
    MLIRRegisterAllDialects
    tlowCodegen
    tlowTransforms
)

install(TARGETS tlow-opt DESTINATION bin COMPONENT tlow)