# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/object_viewer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/object_viewer_autogen.dir/ParseCache.txt"
  "object_viewer_autogen"
  )
endif()
