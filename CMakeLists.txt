cmake_minimum_required(VERSION 3.16)
project(wbqp_codegen_vendor)

# Consume catkin vars if a tool passes them, to avoid "unused variable" warnings
set(CATKIN_INSTALL_INTO_PREFIX_ROOT OFF CACHE BOOL "Compatibility var (ignored)")
set(CATKIN_SYMLINK_INSTALL OFF CACHE BOOL "Compatibility var (ignored)")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# We’ll compile mixed C/C++ since MATLAB emitted .c and .cpp
enable_language(C CXX)

find_package(ament_cmake REQUIRED)

# Helper to collect sources safely (exclude examples/html/mex/etc.)
function(collect_codegen_sources OUT_VAR DIR)
  file(GLOB_RECURSE ALL
    "${DIR}/*.c" "${DIR}/*.cpp" "${DIR}/*.cc" "${DIR}/*.cxx" "${DIR}/*.hpp" "${DIR}/*.h")
  set(FILTERED "")
  foreach(f ${ALL})
    string(FIND "${f}" "/examples/" HAS_EXAMPLE)
    string(FIND "${f}" "/html/"     HAS_HTML)
    string(FIND "${f}" "/interface/" HAS_IFACE)   # these are mex stubs; we don't need them
    string(FIND "${f}" ".mex"       HAS_MEX)
    string(FIND "${f}" ".mat"       HAS_MAT)
    string(FIND "${f}" ".rsp"       HAS_RSP)
    string(FIND "${f}" ".mk"        HAS_MK)
    string(FIND "${f}" ".bat"       HAS_BAT)
    if(HAS_EXAMPLE EQUAL -1 AND HAS_HTML EQUAL -1 AND HAS_IFACE EQUAL -1
       AND HAS_MEX EQUAL -1 AND HAS_MAT EQUAL -1 AND HAS_RSP EQUAL -1
       AND HAS_MK EQUAL -1 AND HAS_BAT EQUAL -1)
      list(APPEND FILTERED "${f}")
    endif()
  endforeach()
  set(${OUT_VAR} "${FILTERED}" PARENT_SCOPE)
endfunction()

# Common include dirs for all three
set(CODEGEN_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/codegen")

# --- Suppress the noisy warning only for this generated TU ---
set(SET_PROB_FILE ${CODEGEN_ROOT}/wbqp_solve/setProblemType.cpp)
if (EXISTS ${SET_PROB_FILE})
  message(STATUS "Suppressing -Waggressive-loop-optimizations for: ${SET_PROB_FILE}")
  # Either of these works; pick one:

  # Option 1: COMPILE_FLAGS
  set_source_files_properties(${SET_PROB_FILE}
    PROPERTIES COMPILE_FLAGS "-Wno-aggressive-loop-optimizations")

  # Option 2: COMPILE_OPTIONS (newer CMake)
  # set_source_files_properties(${SET_PROB_FILE}
  #   PROPERTIES COMPILE_OPTIONS "-Wno-aggressive-loop-optimizations")
else()
  message(WARNING "Expected file not found: ${SET_PROB_FILE}")
endif()

include_directories(
  "${CODEGEN_ROOT}/wbqp_init"
  "${CODEGEN_ROOT}/wbqp_solve"
  "${CODEGEN_ROOT}/WholeBodyJacobian"
)

# Build one static lib per function
collect_codegen_sources(WBQP_INIT_SRCS "${CODEGEN_ROOT}/wbqp_init")
add_library(wbqp_init STATIC ${WBQP_INIT_SRCS})
target_compile_features(wbqp_init PUBLIC c_std_99 cxx_std_17)
target_include_directories(wbqp_init PUBLIC
  $<BUILD_INTERFACE:${CODEGEN_ROOT}/wbqp_init>
  $<INSTALL_INTERFACE:include/wbqp_init>
)

collect_codegen_sources(WBQP_SOLVE_SRCS "${CODEGEN_ROOT}/wbqp_solve")
add_library(wbqp_solve STATIC ${WBQP_SOLVE_SRCS})
target_compile_features(wbqp_solve PUBLIC c_std_99 cxx_std_17)
target_include_directories(wbqp_solve PUBLIC
  $<BUILD_INTERFACE:${CODEGEN_ROOT}/wbqp_solve>
  $<INSTALL_INTERFACE:include/wbqp_solve>
)

collect_codegen_sources(WBJ_SRCS "${CODEGEN_ROOT}/WholeBodyJacobian")
add_library(whole_body_jacobian STATIC ${WBJ_SRCS})
target_compile_features(whole_body_jacobian PUBLIC c_std_99 cxx_std_17)
target_include_directories(whole_body_jacobian PUBLIC
  $<BUILD_INTERFACE:${CODEGEN_ROOT}/WholeBodyJacobian>
  $<INSTALL_INTERFACE:include/WholeBodyJacobian>
)

# Some generated code uses math/time; link m if needed
if(UNIX)
  target_link_libraries(wbqp_init m)
  target_link_libraries(wbqp_solve m)
  target_link_libraries(whole_body_jacobian m)
endif()

# Install headers (all .h) into per-function subfolders
install(DIRECTORY ${CODEGEN_ROOT}/wbqp_init/
        DESTINATION include/wbqp_init
        FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CODEGEN_ROOT}/wbqp_solve/
        DESTINATION include/wbqp_solve
        FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CODEGEN_ROOT}/WholeBodyJacobian/
        DESTINATION include/WholeBodyJacobian
        FILES_MATCHING PATTERN "*.h")

# Install libraries
install(TARGETS wbqp_init wbqp_solve whole_body_jacobian
        EXPORT wbqp_codegen_vendorTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

ament_export_libraries(wbqp_init wbqp_solve whole_body_jacobian)
ament_export_include_directories(include)

# Export for downstream packages
ament_export_targets(wbqp_codegen_vendorTargets HAS_LIBRARY_TARGET)
ament_export_include_directories(include)
ament_package()
