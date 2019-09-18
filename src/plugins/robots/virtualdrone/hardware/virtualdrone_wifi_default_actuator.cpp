/**
 * @file <argos3/plugins/robots/virtualdrone/simulator/virtualdrone_wifi_default_actuator.cpp>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#include "virtualdrone_wifi_default_actuator.h"

#include <argos3/core/utility/networking/tcp_socket.h>
#include <argos3/plugins/robots/virtualdrone/hardware/virtualdrone.h>

namespace argos {

   /****************************************/
   /****************************************/

   CVirtualDroneWifiDefaultActuator::CVirtualDroneWifiDefaultActuator() :
      m_cSocket(CVirtualDrone::GetInstance().GetSocket()) {}

   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultActuator::Init(TConfigurationNode& t_tree) {
      try {
         /* Parent class init */
         CCI_VirtualDroneWifiActuator::Init(t_tree);
         if(!m_cSocket.IsConnected()) {
            THROW_ARGOSEXCEPTION("The socket is not connected");
         }
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Error initializing the VirtualDrone WiFi default actuator", ex);
      }
   }

   
   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultActuator::Update() {
      if(!m_lstMessages.empty()) {
         /* Flush data from the control interface */
         m_lstMessages.clear();
      }
      CByteArray c;
      c << std::string("hello world");
      //m_cSocket.SendByteArray(c);

      const char data[] = "hello world";
      m_cSocket.SendBuffer(reinterpret_cast<const UInt8*>(data), 11);
   }

   /****************************************/
   /****************************************/

   void CVirtualDroneWifiDefaultActuator::Reset() {
      m_lstMessages.clear();
   }

   /****************************************/
   /****************************************/

   REGISTER_ACTUATOR(CVirtualDroneWifiDefaultActuator,
                  "virtualdrone_wifi", "default",
                  "Michael Allwright [allsey87@gmail.com]",
                  "1.0",
                  "The VirtualDrone WiFi actuator.",
                  "This actuator sends messages to other robots using WiFi",
                  "Usable"
   );

   /****************************************/
   /****************************************/

}
   
