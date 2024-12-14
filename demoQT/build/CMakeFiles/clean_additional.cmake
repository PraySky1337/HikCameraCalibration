# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtParameterAdjustment_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtParameterAdjustment_autogen.dir/ParseCache.txt"
  "QtParameterAdjustment_autogen"
  )
endif()
