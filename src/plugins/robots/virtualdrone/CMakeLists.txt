#
# virtualdrone headers
#
# argos3/plugins/robots/virtualdrone/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_CONTROLINTERFACE
  control_interface/ci_virtualdrone_camera_system_sensor.h
  control_interface/ci_virtualdrone_wifi_actuator.h
  control_interface/ci_virtualdrone_wifi_sensor.h)
if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "The virtual drone plugin is a hardware-only plugin")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # argos3/plugins/robots/virtualdrone/hardware
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_HARDWARE
    hardware/virtualdrone.h
    hardware/virtualdrone_camera_system_default_sensor.h
    hardware/virtualdrone_wifi_default_actuator.h
    hardware/virtualdrone_wifi_default_sensor.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# virtualdrone sources
#
# argos3/plugins/robots/virtualdrone/control_interface
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_VIRTUALDRONE
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_CONTROLINTERFACE}
  control_interface/ci_virtualdrone_camera_system_sensor.cpp
  control_interface/ci_virtualdrone_wifi_actuator.cpp
  control_interface/ci_virtualdrone_wifi_sensor.cpp)
if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "The virtual drone plugin is a hardware-only plugin")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # argos3/plugins/robots/virtualdrone/hardware
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_VIRTUALDRONE
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_VIRTUALDRONE}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_HARDWARE}
    hardware/virtualdrone.cpp
    hardware/virtualdrone_camera_system_default_sensor.cpp
    hardware/virtualdrone_wifi_default_actuator.cpp
    hardware/virtualdrone_wifi_default_sensor.cpp
    hardware/main.cpp)
endif(ARGOS_BUILD_FOR_SIMULATOR)

if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "The virtual drone plugin is a hardware-only plugin")
else(ARGOS_BUILD_FOR_SIMULATOR)
  # Create an executable for the robot
  add_executable(argos3 ${ARGOS3_SOURCES_PLUGINS_ROBOTS_VIRTUALDRONE})
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

install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/virtualdrone/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  message(FATAL_ERROR "The virtual drone plugin is a hardware-only plugin")
else(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_VIRTUALDRONE_HARDWARE} DESTINATION include/argos3/plugins/robots/virtualdrone/hardware)
endif(ARGOS_BUILD_FOR_SIMULATOR)

