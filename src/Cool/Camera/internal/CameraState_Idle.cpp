#include "CameraState_Idle.h"
#include "CameraState_Rotation.h"
#include "CameraState_Translation.h"
#include "../Camera.h"
#include <Cool/App/Input.h>

namespace Cool {

CameraState_Idle::CameraState_Idle(Camera& camera)
	: CameraState(camera)
{}

void CameraState_Idle::onWheelDown(int mods) {
	if (mods & GLFW_MOD_SHIFT){
		m_camera.setState<CameraState_Translation>();
	}
	else {
		m_camera.setState<CameraState_Rotation>();
	}
}

void CameraState_Idle::onWheelScroll(float dl){
	m_camera.m_distToLookAt *= pow(0.93f, dl);
	m_camera.onTransformChanged();
}

} // namespace Cool