/**
 * @file <argos3/plugins/robots/virtualdrone/hardware/virtualdrone.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef VIRTUALDRONE_H
#define VIRTUALDRONE_H

namespace argos {
   class CLuaController;
}

#include <argos3/core/hardware/sensor.h>
#include <argos3/core/hardware/actuator.h>
#include <argos3/core/utility/math/rng.h>
#include <argos3/core/utility/networking/tcp_socket.h>
#include <argos3/core/utility/configuration/argos_configuration.h>

namespace argos {

   class CVirtualDrone {

   public:
      static CVirtualDrone& GetInstance() {
         static CVirtualDrone cVirtualDrone;
         return cVirtualDrone;
      }

      void SetSignal(int n_signal) {
         m_bSignalRaised = true;
         m_nSignal = n_signal;
      }

      void Init(TConfigurationNode& t_tree,
                const std::string& str_controller_id);
      void Destroy();
      void InitFramework(TConfigurationNode& t_tree);
      void InitController(TConfigurationNode& t_tree,
                          const std::string& str_controller_id);
      void InitHardware();


      void Execute();

      UInt32 GetTicksPerSec() {
         return m_unTicksPerSec;
      }

      CTCPSocket& GetSocket() {
         return m_cSocket;
      }

   private:

      CVirtualDrone() :
         m_bSignalRaised(false),
         m_nSignal(0),
         m_pcRNG(nullptr),
         m_unTicksPerSec(0),
         m_pcController(nullptr) {}

      virtual ~CVirtualDrone() {}

   private:
      /* signal handling variables */
      bool m_bSignalRaised;
      int m_nSignal;
      /* pointer to the RNG */
      CRandom::CRNG* m_pcRNG;
      /* target tick length for the controller */
      UInt32 m_unTicksPerSec;
      /* pointer to the controller */
      CLuaController* m_pcController;
      /* the vector of actuators */
      std::vector<CPhysicalActuator*> m_vecActuators;
      /* the vector of sensors */
      std::vector<CPhysicalSensor*> m_vecSensors;
      /* the TCP socket for WiFi communication */
      CTCPSocket m_cSocket;

      CPhysicalSensor* m_pcCamera;
   };

}

#endif
