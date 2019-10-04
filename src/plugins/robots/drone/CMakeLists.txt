#
# drone headers
#
# argos3/plugins/robots/drone/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_CONTROLINTERFACE
  control_interface/ci_drone_camera_system_sensor.h
  control_interface/ci_drone_wifi_actuator.h
  control_interface/ci_drone_wifi_sensor.h)
if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "Simulation not yet supported")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # argos3/plugins/robots/drone/hardware
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_HARDWARE
    hardware/drone.h
    hardware/drone_camera_system_default_sensor.h
    hardware/drone_wifi_default_actuator.h
    hardware/drone_wifi_default_sensor.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# drone sources
#
# argos3/plugins/robots/drone/control_interface
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_DRONE
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_CONTROLINTERFACE}
  control_interface/ci_drone_camera_system_sensor.cpp
  control_interface/ci_drone_wifi_actuator.cpp
  control_interface/ci_drone_wifi_sensor.cpp)
if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "Simulation not yet supported")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # argos3/plugins/robots/drone/hardware
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_DRONE
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_DRONE}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_HARDWARE}
    hardware/drone.cpp
    hardware/drone_camera_system_default_sensor.cpp
    hardware/drone_wifi_default_actuator.cpp
    hardware/drone_wifi_default_sensor.cpp
    hardware/main.cpp)
endif(ARGOS_BUILD_FOR_SIMULATOR)

if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "Simulation not yet supported")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # Create an executable for the robot
  add_executable(argos3 ${ARGOS3_SOURCES_PLUGINS_ROBOTS_DRONE})
  target_link_libraries(argos3
    ${ARGOS_CORE_LIBRARY}
    ${LUA_LIBRARIES}
    ${PTHREADS_LIBRARY}
    ${APRILTAG_LIBRARY})
  install(TARGETS argos3
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/argos3
    ARCHIVE DESTINATION lib/argos3)
endif(ARGOS_BUILD_FOR_SIMULATOR)

install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/drone/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "Simulation not yet supported")
else(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_DRONE_HARDWARE} DESTINATION include/argos3/plugins/robots/drone/hardware)
endif(ARGOS_BUILD_FOR_SIMULATOR)

