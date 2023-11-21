# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/Painty_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Painty_autogen.dir/ParseCache.txt"
  "Painty_autogen"
  )
endif()
