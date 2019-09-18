/**
 * @file <argos3/plugins/robots/virtualdrone/simulator/virtualdrone_wifi_default_actuator.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef VIRTUALDRONE_WIFI_DEFAULT_ACTUATOR_H
#define VIRTUALDRONE_WIFI_DEFAULT_ACTUATOR_H

namespace argos {
   class CVirtualDroneWifiDefaultActuator;
   class CTCPSocket;
}

#include <argos3/core/hardware/actuator.h>
#include <argos3/plugins/robots/virtualdrone/control_interface/ci_virtualdrone_wifi_actuator.h>

namespace argos {

   class CVirtualDroneWifiDefaultActuator : public CPhysicalActuator,
                                            public CCI_VirtualDroneWifiActuator {
   public:

      CVirtualDroneWifiDefaultActuator();

      virtual ~CVirtualDroneWifiDefaultActuator() {}

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CTCPSocket& m_cSocket;

   };
}

#endif
