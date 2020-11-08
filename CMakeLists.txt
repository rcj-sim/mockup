
add_executable(mockup)
target_sources(mockup PRIVATE mockup.cpp Viewer.cpp World.cpp Thing.cpp Field.cpp Ball.cpp Robot.cpp)

target_include_directories(mockup PRIVATE ${BULLET_INCLUDE_DIRS})
target_link_libraries(mockup PRIVATE ${BULLET_LIBRARIES})

target_include_directories(mockup PRIVATE ${OPENSCENEGRAPH_INCLUDE_DIRS})
target_link_libraries(mockup PRIVATE ${OPENSCENEGRAPH_LIBRARIES})
target_link_libraries(mockup PRIVATE ${OSGVIEWER_LIBRARY})
target_link_libraries(mockup PRIVATE ${OSGGA_LIBRARY})

