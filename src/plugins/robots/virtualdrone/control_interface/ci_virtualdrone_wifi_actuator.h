/**
 * @file <argos3/plugins/robots/virtualdrone/control_interface/ci_virtualdrone_wifi_actuator.h>
 *
 * @author Michael Allwright <allsey87@gmail.com>
 */

#ifndef CCI_VIRTUALDRONE_WIFI_ACTUATOR_H
#define CCI_VIRTUALDRONE_WIFI_ACTUATOR_H

namespace argos {
   class CCI_VirtualDroneWifiActuator;
}

#include <argos3/core/control_interface/ci_actuator.h>
#include <argos3/core/utility/datatypes/byte_array.h>

#include <list>

namespace argos {

   class CCI_VirtualDroneWifiActuator : public CCI_Actuator {

   public:

      CCI_VirtualDroneWifiActuator() {}

      virtual ~CCI_VirtualDroneWifiActuator() {}

      virtual void Enqueue(const CByteArray& c_data) {
         m_lstMessages.emplace_back(c_data);
      }

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
#endif

   protected:

      std::list<CByteArray> m_lstMessages;

   };

}

#endif
