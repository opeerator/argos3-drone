/**
 * @file <argos3/plugins/robots/virtualdrone/simulator/virtualdrone_wifi_default_sensor.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef VIRTUALDRONE_WIFI_DEFAULT_SENSOR_H
#define VIRTUALDRONE_WIFI_DEFAULT_SENSOR_H

namespace argos {
   class CVirtualDroneWifiDefaultSensor;
   class CControllableEntity;
   class CRadioEntity;
}

#include <argos3/plugins/robots/virtualdrone/control_interface/ci_virtualdrone_wifi_sensor.h>
#include <argos3/core/hardware/sensor.h>

namespace argos {

   class CVirtualDroneWifiDefaultSensor : public CPhysicalSensor,
                                          public CCI_VirtualDroneWifiSensor {

   public:

      CVirtualDroneWifiDefaultSensor();

      virtual ~CVirtualDroneWifiDefaultSensor() {}

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   };
}

#endif
