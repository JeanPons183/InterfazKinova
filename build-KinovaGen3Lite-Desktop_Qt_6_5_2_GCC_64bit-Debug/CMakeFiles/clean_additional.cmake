# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/KinovaGen3LiteApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/KinovaGen3LiteApp_autogen.dir/ParseCache.txt"
  "KinovaGen3LiteApp_autogen"
  )
endif()
