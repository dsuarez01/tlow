include(FetchContent)

set(ORT_VERSION "1.21.0")
set(ORT_BASE_URL "https://github.com/microsoft/onnxruntime/releases/download/v${ORT_VERSION}")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # universal2 covers both arm64 and x86_64, and avoids macOS Sequoia issues
    set(ORT_URL "${ORT_BASE_URL}/onnxruntime-osx-universal2-${ORT_VERSION}.tgz")
    set(ORT_LIB "libonnxruntime.${ORT_VERSION}.dylib")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(ORT_URL "${ORT_BASE_URL}/onnxruntime-linux-x64-${ORT_VERSION}.tgz")
    set(ORT_LIB "libonnxruntime.so.${ORT_VERSION}")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(ORT_URL "${ORT_BASE_URL}/onnxruntime-win-x64-${ORT_VERSION}.zip")
    set(ORT_LIB "onnxruntime.dll")
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

FetchContent_Declare(
    onnxruntime
    URL ${ORT_URL}
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(onnxruntime)

add_library(OnnxRuntime::OnnxRuntime SHARED IMPORTED GLOBAL)
set_target_properties(OnnxRuntime::OnnxRuntime PROPERTIES
    IMPORTED_LOCATION "${onnxruntime_SOURCE_DIR}/lib/${ORT_LIB}"
    INTERFACE_INCLUDE_DIRECTORIES "${onnxruntime_SOURCE_DIR}/include"
)