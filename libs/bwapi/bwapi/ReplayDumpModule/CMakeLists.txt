include_directories(
  ../include 
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_library(ReplayDumpModule SHARED
  Source/BWRepDump.cpp
  Source/CombatTracker.cpp
  Source/Dll.cpp
  Source/GameData.cpp
  Source/OrderData.cpp
  Source/Utils.cpp
  )

target_link_libraries(ReplayDumpModule BWAPILIB)
