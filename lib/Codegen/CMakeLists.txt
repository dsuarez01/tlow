# define targets, point target to include dirs needed

# for Common
add_subdirectory(Common)
add_library(tlowCodegen KernelRegistry.cpp)

# for Targets
option(TLOW_ENABLE_CPU  "Enable CPU backend"  ON)
option(TLOW_ENABLE_GPU  "Enable GPU backend"  OFF)
option(TLOW_ENABLE_ASIC "Enable ASIC backend" OFF)

if(TLOW_ENABLE_CPU)
    add_subdirectory(Targets/CPU)
    target_link_libraries(tlowCodegen PRIVATE tlowCodegenCPU)
endif()
if(TLOW_ENABLE_GPU)
    add_subdirectory(Targets/GPU)
    target_link_libraries(tlowCodegen PRIVATE tlowCodegenGPU)
endif()
if(TLOW_ENABLE_ASIC)
    add_subdirectory(Targets/ASIC)
    target_link_libraries(tlowCodegen PRIVATE tlowCodegenASIC)
endif()

target_link_libraries(tlowCodegen PRIVATE tlowDialect tlowCodegenCommon)