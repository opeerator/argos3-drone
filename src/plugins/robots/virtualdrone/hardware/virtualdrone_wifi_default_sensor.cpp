/**
 * @file <argos3/plugins/robots/generic/simulator/virtualdrone_wifi_default_sensor.cpp>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#include "virtualdrone_wifi_default_sensor.h"

#include <argos3/core/utility/networking/tcp_socket.h>
#include <argos3/plugins/robots/virtualdrone/hardware/virtualdrone.h>

namespace argos {

   /****************************************/
   /****************************************/

   CVirtualDroneWifiDefaultSensor::CVirtualDroneWifiDefaultSensor() :
      m_cSocket(CVirtualDrone::GetInstance().GetSocket()) {}

   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultSensor::Init(TConfigurationNode& t_tree) {
      try {
         /* Parent class init */
         CCI_VirtualDroneWifiSensor::Init(t_tree);
         /* Check if the socket is connected */
         if(!m_cSocket.IsConnected()) {
            THROW_ARGOSEXCEPTION("The socket is not connected");
         }
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Error initializing the VirtualDrone WiFi default sensor", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultSensor::Update() {
      /* clear the messages from the interface */
      m_vecMessages.clear();
      /* read in the new messages to the control interface */
      m_vecMessages.emplace_back();
      

      //m_cSocket.ReadByteArray()
   }

   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultSensor::Reset() {
      /* Clear the existing data */
      m_vecMessages.clear();
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CVirtualDroneWifiDefaultSensor,
                   "virtualdrone_wifi", "default",
                   "Michael Allwright [allsey87@gmail.com]",
                   "1.0",
                   "The VirtualDrone WIFI sensor.",
                   "This sensor receives messages from other robots using WiFi",
                   "Usable"
   );

   /****************************************/
   /****************************************/

}
