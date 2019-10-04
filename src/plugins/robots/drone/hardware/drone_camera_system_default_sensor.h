/*
 * @file <argos3/plugins/robots/drone/hardware/drone_camera_system_default_sensor.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 * @author Weixu Zhu (Harry) - <zhuweixu_harry@126.com>
 */

#ifndef DRONE_CAMERA_SYSTEM_DEFAULT_SENSOR_H
#define DRONE_CAMERA_SYSTEM_DEFAULT_SENSOR_H

/* forward declarations */
namespace argos {
   class CDroneCameraSystemDefaultSensor;
}

struct apriltag_family;
struct apriltag_detector;
struct v4l2_buffer;

#include <array>
#include <chrono>

#include <apriltag/apriltag_pose.h>
#include <apriltag/common/image_u8.h>

#include <argos3/core/hardware/sensor.h>
#include <argos3/core/utility/math/quaternion.h>
#include <argos3/core/utility/math/rng.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/math/vector3.h>

#include <argos3/plugins/robots/drone/control_interface/ci_drone_camera_system_sensor.h>

namespace argos {

   class CDroneCameraSystemDefaultSensor : public CPhysicalSensor,
                                           public CCI_DroneCameraSystemSensor {

   public:

      CDroneCameraSystemDefaultSensor();

      virtual ~CDroneCameraSystemDefaultSensor();

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Destroy();

      virtual void Enable();

      virtual void Disable();

      virtual void Update();

   private:

      ELedState DetectLed(const CVector3& c_position);

      /* calibration data */
      CVector2 m_cFocalLength;
      CVector2 m_cPrincipalPoint;
      CVector3 m_cPositionOffset;
      CQuaternion m_cOrientationOffset;
      CSquareMatrix<3> m_cCameraMatrix;

      std::array<std::pair<UInt32, void*>, 2> m_arrBuffers;
      std::array<std::pair<UInt32, void*>, 2>::iterator m_itCurrentBuffer;
      std::array<std::pair<UInt32, void*>, 2>::iterator m_itNextBuffer;

      ::image_u8_t* m_ptImage;
      ::apriltag_family* m_ptTagFamily;
      ::apriltag_detector* m_ptTagDetector;
      ::apriltag_detection_info_t m_tTagDetectionInfo;

      /* camera device handle */
      SInt32 m_nCameraHandle;

      /* time at initialization */
      std::chrono::steady_clock::time_point m_tpInit;

      /****************************************/
      /****************************************/

   };
}

#endif
