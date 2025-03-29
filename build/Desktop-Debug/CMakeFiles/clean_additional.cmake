# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HiKa_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HiKa_autogen.dir/ParseCache.txt"
  "HiKa_autogen"
  )
endif()
