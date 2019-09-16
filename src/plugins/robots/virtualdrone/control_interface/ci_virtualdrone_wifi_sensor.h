/**
 * @file <argos3/plugins/robots/virtualdrone/control_interface/ci_virtualdrone_wifi_sensor.h>
 *
 * @author Michael Allwright <allsey87@gmail.com>
 */

#ifndef CCI_VIRTUALDRONE_WIFI_SENSOR_H
#define CCI_VIRTUALDRONE_WIFI_SENSOR_H

namespace argos {
   class CCI_VirtualDroneWifiSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/datatypes/byte_array.h>

#include <list>

namespace argos {

   class CCI_VirtualDroneWifiSensor : public CCI_Sensor {

   public:

      CCI_VirtualDroneWifiSensor() {}

      virtual ~CCI_VirtualDroneWifiSensor() {}

      const std::vector<CByteArray>& GetMessages() {
         return m_vecMessages;
      }

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
      
      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      std::vector<CByteArray> m_vecMessages;

   };

}

#endif
